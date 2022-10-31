#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s, t; cin >> s >> t;
    int ns = s.length(), nt = t.length();
    int len = ns*nt/__gcd(ns, nt);
    string res1 = "", res2 = "";
    for(int i = 0; i<len/ns; i++) res1+=s;
    for(int i = 0; i<len/nt; i++) res2+=t;
    if(res1 == res2) cout << res1 << endl;
    else cout << -1 << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}