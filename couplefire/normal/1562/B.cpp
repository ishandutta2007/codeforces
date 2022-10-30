#include <bits/stdc++.h>
using namespace std;

bool isP[100];

void solve(){
    int n; string s; cin >> n >> s;
    for(int i = 0; i<n; ++i){
        if(s[i]=='1' || s[i]=='4' || s[i]=='6' || s[i]=='8' || s[i]=='9'){
            cout << 1 << '\n';
            cout << s[i] << '\n';
            return;
        }
    }
    for(int i = 0; i<n; ++i){
        for(int j = i+1; j<n; ++j){
            if(!isP[10*(s[i]-'0')+(s[j]-'0')]){
                cout << 2 << '\n';
                cout << to_string(10*(s[i]-'0')+(s[j]-'0')) << '\n';
                return;
            }
        }
    }
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    for(int i = 2; i<100; ++i){
        isP[i] = 1;
        for(int j = 2; j<i; ++j)
            if(i%j==0) isP[i] = 0;
    }
    int t; cin >> t;
    while(t--) solve();
}