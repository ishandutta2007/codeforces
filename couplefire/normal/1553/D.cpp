#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s, t; cin >> s >> t;
    int n = s.length(), m = t.length();
    if(n<m) return void(cout << "NO" << '\n');
    bool good = 1;
    for(int i = ((n-m)&1), j = 0; i<n; i++){
        if(!good){good = 1; continue;}
        if(j<m && s[i]==t[j]) ++j;
        else good = 0;
        if(j==m) return void(cout << "YES" << '\n');
    }
    cout << "NO" << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}