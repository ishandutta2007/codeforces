#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int pos = 0;
        while(pos<n && s[pos]=='?') ++pos;
        for(int i = pos+1; i<n; ++i){
            if(s[i]!='?') continue;
            if(s[i-1]=='R') s[i]='B';
            else s[i]='R';
        }
        for(int i = pos-1; i>=0; --i){
            if(i==n-1){
                s[i]='R'; continue;
            }
            if(s[i+1]=='R') s[i] = 'B';
            else s[i] = 'R';
        }
        cout << s << '\n';
    }
}