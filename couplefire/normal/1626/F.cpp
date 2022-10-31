#include <bits/stdc++.h>
using namespace std;

const int MX = 12252240;
const int MOD = 998244353;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}

int dp[2][MX+1], pw[18];
int n, a0, x, y, k, mod;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> a0 >> x >> y >> k >> mod;
    pw[0] = 1;
    for(int i = 1; i<=k; ++i)
        pw[i] = mul(pw[i-1], n);
    for(int i = 1; i<=k; ++i){
        int cur = i&1, nxt = 1-cur;
        memset(dp[cur], 0, sizeof dp[cur]);
        for(int j = 0; j<=MX; ++j)
            inc(dp[cur][j], mul(dp[nxt][j], n-1)),
            inc(dp[cur][j], add(mul(pw[i-1], j), dp[nxt][j-j%(k+1-i)]));
    }
    int ans = 0;
    for(int i = 0; i<n; ++i){
        inc(ans, add(dp[k&1][a0%MX], mul(a0/MX*MX, mul(k, pw[k-1]))));
        a0 = (1ll*a0*x+y)%mod;
    }
    cout << ans << '\n';
}