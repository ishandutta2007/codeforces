#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cnt=0;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0; i<n; i++){
        if(s[i]=='A') cnt ++;
    }
    if(cnt*2>n) cout << "Anton";
    else if(n>cnt*2) cout << "Danik";
    else cout << "Friendship";
    return 0;
}