#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    map<string,bool> a;
    map<string,string> b;
    string c[6]={"purple", "green", "blue", "orange", "red", "yellow"};
    b["purple"]="Power";
    b["green"]="Time";
    b["blue"]="Space";
    b["orange"]="Soul";
    b["red"]="Reality";
    b["yellow"]="Mind";
    a["purple"]=false;
    a["green"]=false;
    a["blue"]=false;
    a["orange"]=false;
    a["red"]=false;
    a["yellow"]=false;
    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;
        a[temp]=true;
    }
    cout << 6-n << '\n';
    for(int i=0; i<6; i++){
        if(!a[c[i]]){
            cout << b[c[i]] << '\n';
        }
    }
    return 0;
}