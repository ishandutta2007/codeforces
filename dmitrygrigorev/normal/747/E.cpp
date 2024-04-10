#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <fstream>
using namespace std;
string str;
vector<string> comments;
vector<int> moneys;
vector<bool> used;
vector<vector<string> > answers;
int p;
void recursion(int level){
    p ++;
    used[p] = true;
    if (answers.size() < level){
        vector<string> help;
        help.push_back(comments[p]);
        answers.push_back(help);
    }
    else{
        answers[level-1].push_back(comments[p]);
    }
    int assos = moneys[p];
    while (assos > 0){
        recursion(level + 1);
        assos -= 1;
    }
}
int main(){
    cin >> str;
    string s = "";
    bool integer = false;
    for (int i=0;i<str.size();i++){
        if (str[i] != ','){
            s += str[i];
        }
        else{
            if (integer){
                 istringstream iss (s, istringstream::in);
                 int val;
                 iss >> val;
                 moneys.push_back(val);
            }
            else{
                comments.push_back(s);
            }
            s = "";
            integer = 1 - integer;
        }
    }
    istringstream iss (s, istringstream::in);
    int val;
    iss >> val;
    p = -1;
    moneys.push_back(val);
    for (int i=0;i<comments.size();i++){
        used.push_back(false);
    }
    for (int i=0;i<comments.size();i++){
            if (!used[i]){
    recursion(1);
            }
    }
    cout << answers.size() << endl;
    for (int i=0;i<answers.size();i++){
        for (int j=0;j<answers[i].size();j++){
            cout << answers[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}