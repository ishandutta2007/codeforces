#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string,int> l;
    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;
        if(l.find(temp)==l.end()){
            l.insert(pair<string,int>(temp,0));
            cout << "OK\n";
        }else{
            l.find(temp)->second++;
            cout << temp << l.find(temp)->second << '\n';
        }
    }
    return 0;
}