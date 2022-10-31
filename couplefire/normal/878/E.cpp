#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5, M = 18, mod = 1e9 + 7;


int n, m, a[N], l, r, pref[N], p[N], op[N], pr[M][N], dp[M][N];

inline int get(int l, int r){
    if(l > r){
        return 0;
    }
    int ans = 0;
    for(int i = M - 1; i >= 0; i--){
        if(pr[i][r] >= l){
            ans = (ans + dp[i][r]) % mod;
            r = pr[i][r];
        }
    }
    if(l <= r){
        ans += ((pref[r] - pref[l - 1] + mod) * op[l - 1]) % mod;
        ans %= mod;
    }
    return ans;
}

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    p[0] = op[0] = 1;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        p[i] = (p[i - 1] * 2) % mod;
        op[i] = (op[i - 1] * (mod + 1) / 2) % mod;
        pref[i] = (pref[i - 1] + p[i] * (a[i] + mod)) % mod;
    }
    for(int i = 1; i <= n; i++){
        int sum = 0;
        for(int j = i; j >= 1; j--){
            sum = (sum + a[j]) * 2;
            if(sum <= 0){
                pr[0][i] = j - 1;
                dp[0][i] = (sum % mod + mod) % mod;
                break;
            }
            else if(sum >= mod + mod){
                pr[0][i] = -1;
                break;
            }
        }
    }
    for(int i = 1; i < M; i++){
        for(int j = 1; j <= n; j++){
            if(pr[i - 1][j] == -1){
                pr[i][j] = -1;
            }
            else{
                pr[i][j] = pr[i - 1][pr[i - 1][j]];
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][pr[i - 1][j]]) % mod;
            }
        }
    }
    for(int i = 1; i <= m; i++){
        cin >> l >> r;
        cout << ((a[l] + get(l + 1, r)) % mod + mod) % mod << "\n";
    }
}