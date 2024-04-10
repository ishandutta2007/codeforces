#include <bits/stdc++.h>
using namespace std;
#define int long long

int msb(int a){return 63-__builtin_clzll(a);}

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++)
        cin >> arr[i];
    for(int m = 0; m<(1<<n); ++m){
        for(int i = 0; i<n; i++)
            if(m&(1<<i)) arr[i] = -arr[i];
        vector<int> dp(1<<n, 0);
        for(int mask = 1; mask<(1<<n); ++mask){
            dp[mask] = dp[mask^(1<<msb(mask))]+arr[msb(mask)];
            if(dp[mask] == 0)
                return void(cout << "YES" << '\n');
        }
        for(int i = 0; i<n; i++)
            if(m&(1<<i)) arr[i] = -arr[i];
    }
    cout << "NO" << '\n';
}

signed main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}