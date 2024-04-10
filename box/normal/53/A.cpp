#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string b; string t;

int main() {
    cin >> t; int n; cin >> n;
    while(n--) {
        string v; cin >> v;
        if(v.length() < t.length()) continue;
        bool ok = true;
        for(int i=0; i<t.length(); i++) {
            if(v[i] != t[i]) ok = false;
        }
        if(!ok) continue;
        if(b == "" || v < b) b = v;
    }
    if(b != "") cout << b << endl;
    else cout << t << endl;
}