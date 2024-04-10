#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;

signed main(){
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<int> pw(n+1); pw[0] = 1;
    for(int i = 1; i<=n; i++)
        pw[i] = 2*pw[i-1]%MOD;
    int _ = n;
    vector<int> basis;
    for(int i = 0; i<n; i++){
        int a; cin >> a;
        for(auto x : basis)
            a = min(a, a^x);
        if(a){
            int id = 0;
            while(id < (int)basis.size() && basis[id] > a) ++id;
            basis.insert(basis.begin()+id, a);
        }
    }
    n = basis.size();
    vector<int> ans(2*m+1, 0);
    if(n <= 20){
        for(int mask = 0; mask<(1ll<<n); mask++){
            int val = 0;
            for(int i = 0; i<n; i++)
                if(mask&(1ll<<i)) val ^= basis[i];
            ans[__builtin_popcountll(val)]++;
        }
    } else{
        vector<bool> good(m);
        for(auto x : basis)
            for(int i = m-1; i>=0; i--)
                if(x&(1ll<<i)){
                    good[i] = 1;
                    break;
                }
        for(int i = 0; i<n; i++)
            for(int j = i+1; j<n; j++)
                basis[i] = min(basis[i], basis[i]^basis[j]);
        vector<int> stuff(n, 0);
        for(int i = 0; i<n; i++){
            int cnt = 0;
            for(int j = 0; j<m; j++)
                if(!good[j]){
                    if(basis[i]&(1ll<<j)) stuff[i] += (1ll<<cnt);
                    cnt++;
                }
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n+1, vector<int>((1ll<<(m-n)), 0)));
        dp[0][1][stuff[0]] = dp[0][0][0] = 1;
        for(int i = 1; i<n; i++)
            for(int j = 0; j<=n; j++)
                for(int k = 0; k<(1ll<<(m-n)); k++){
                    dp[i][j][k] = dp[i-1][j][k];
                    if(j) dp[i][j][k] += dp[i-1][j-1][k^stuff[i]];
                }
        for(int i = 0; i<=n; i++)
            for(int j = 0; j<(1ll<<(m-n)); j++)
                ans[i+__builtin_popcount(j)] += dp[n-1][i][j];
    }
    for(int i = 0; i<=m; i++)
        cout << (ans[i]%MOD)*pw[_-n]%MOD << " ";
    cout << '\n';
}