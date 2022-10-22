#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int r=0,p=0;
    for(int i=0; i<n-1; i++){
        if(s[i]=='F' && s[i+1]=='S') p++;
        else if(s[i]=='S' && s[i+1]=='F') r++;
    }
    if(r>p) cout << "YES";
    else cout << "NO";
    return 0;
}