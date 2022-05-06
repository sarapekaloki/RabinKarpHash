#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<tuple>

using namespace std;

int hashF(string str){
    int index = 0;
    for (int i = 0; i < str.size(); ++i) {
        index = index + pow(3,i) * int(str[i]);
    }
    return index;
}
vector<tuple<int,int>> RabinKarpHash(string str){

    ifstream long_str;
    long_str.open("C:\\Users\\SARAMARQUEZ\\Desktop\\Ing Ciencias Computacionales\\6to Semestre\\Algoritmos\\RabinKarpHash\\texto.txt");
    string line;
    vector<tuple<int, int>> line_index;
    int lookingFor = hashF(str);
    int lenght = str.size();
    int currentLine = 1;

    while (getline(long_str, line)) {
        int currentHash = hashF(line.substr(0,lenght));

        if (currentHash == lookingFor){
            line_index.push_back({currentLine,0});
        }
        for (int i = 0; i < line.size()-lenght; ++i) {
            currentHash = (currentHash - int(line[i]))/3 + pow(3,lenght-1)*int(line[i+lenght]);
            if (currentHash == lookingFor){
                line_index.push_back({currentLine,i+1});
            }
        }
        currentLine++;
    }
    long_str.close();

    return line_index;
}
void print(vector<tuple<int,int>> mi_vect){
    cout<<"line & index"<<endl;
    for (auto& currentTuple:mi_vect) {
        cout << get<0>(currentTuple) << ' ' << get<1>(currentTuple) <<endl;
    }

}



int main() {
    vector<tuple<int,int>> line_indexes = RabinKarpHash("la");
    print(line_indexes);
    return 0;
}
