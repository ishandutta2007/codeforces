#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 200005;

int n, arr[N];
int ans;

void dnc(int l, int r){
    if(l == r) return;
    int m = l+(r-l)/2;
    int cur = abs(arr[m]-arr[m+1]);
    vector<int> rs(r-m), ls(m-l+1);
    rs[0] = 0, ls[0] = 0;
    for(int i = 1; i<r-m; ++i)
        rs[i] = __gcd(rs[i-1], abs(arr[i+m]-arr[i+m+1]));
    for(int i = 1; i<m-l+1; ++i)
        ls[i] = __gcd(ls[i-1], abs(arr[m-i]-arr[m-i+1]));
    int lit = m-l, rit = 0;
    while(lit>=0 && rit<r-m){
        while(lit>=0 && __gcd(__gcd(ls[lit], rs[rit]), cur)==1ll) --lit;
        if(lit<0) break;
        ans = max(ans, rit+lit+2);
        rit++;
    }
    dnc(l, m); dnc(m+1, r);
}

void solve(){
    cin >> n; ans = 1;
    for(int i = 0; i<n; ++i)
        cin >> arr[i];
    dnc(0, n-1);
    cout << ans << '\n';
}

signed main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}