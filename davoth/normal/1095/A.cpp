#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s,r;
    cin >> s;
    int i=1;
    while(!s.empty()){
        r.push_back(s[0]);
        s.erase(s.begin(),s.begin()+i);
        i++;
    }
    cout << r;
    return 0;
}