#include <iostream>
#include <cstdio>
#include<vector>

using namespace std;
typedef int var;

int main() {
    //freopen("debug.in", "r", stdin);
    //freopen("debug.out", "w", stdout);

    string s;
    vector<var> AB, BA;
    cin>>s;

    for(var i=0; s[i+1]; i++) {
        if(s[i] == 'A' && s[i+1] == 'B')
            AB.push_back(i);
        if(s[i] == 'B' && s[i+1] == 'A')
            BA.push_back(i);
    }

    if(!AB.size() || !BA.size()) {
        cout << "NO";
        return 0;
    }

    var i1 = 0, i2 = 0;

    if(AB.front() < BA.back() - 1 || BA.front() < AB.back() - 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}