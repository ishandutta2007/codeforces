#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; string s; cin >> n >> s;
    int id = -1;
    for(int i = 0; i<n; ++i)
        if(s[i]=='0') id = i;
    if(id<0){
        cout << 1 << ' ' << n-1 << ' ' << 2 << ' ' << n << '\n';
        return;
    }
    if(id<n/2){
        cout << id+1 << ' ' << n << ' ' << id+2 << ' ' << n << '\n';
        return;
    }
    cout << 1 << ' ' << id+1 << ' ' << 1 << ' ' << id << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}