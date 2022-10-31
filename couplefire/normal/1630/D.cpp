#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    long long tot = 0;
    vector<int> arr(n);
    for(int i = 0; i<n; ++i)
        cin >> arr[i], tot += abs(arr[i]);
    int val = 0;
    for(int i = 0; i<m; ++i){
        int b; cin >> b;
        val = __gcd(val, b);
    }
    vector<int> par(val, 0);
    for(int i = 0; i<n; ++i)
        if(arr[i]<0) par[i%val] ^= 1;
    vector<int> mn(val, 1e9);
    for(int i = 0; i<n; ++i)
        mn[i%val] = min(mn[i%val], abs(arr[i]));
    long long s1 = 0, s2 = 0;
    for(int i = 0; i<val; ++i)
        if(par[i]) s1 += mn[i];
        else s2 += mn[i];
    cout << tot-2ll*min(s1, s2) << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}