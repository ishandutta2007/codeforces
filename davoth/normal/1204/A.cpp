#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int c=0;
    cin >> s;
    for(int i=1; i<s.size(); i++){
        if(s[i]=='1') c=1;
    }
    int l=0;
    if(c==1 || (s.size()-1)%2==1) l=1;
    cout << (s.size()-1)/2+l;
    return 0;
}