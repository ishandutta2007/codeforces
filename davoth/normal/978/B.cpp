#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,r=0;
    string s;
    cin >> n >> s;
    for(int i=0; i<n-2; i++){
        if(s[i]=='x' && s[i+1]=='x' && s[i+2]=='x') r++;
    }
    cout << r;
    return 0;
}