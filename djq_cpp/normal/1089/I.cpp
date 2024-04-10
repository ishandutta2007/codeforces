#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 400;

int MOD;
int fac[405], inv[405];
int dp[405];
int pw[405][405];

void gen_dp()
{
    fac[0] = 1;
    rep1(i, MAXN) fac[i] = 1LL * fac[i - 1] * (i + 1) % MOD;
    inv[1] = 1;
    for(int i = 2; i <= MAXN; i ++) inv[i] = MOD - 1LL * MOD / i * inv[MOD % i] % MOD; 
    
    dp[0] = 1;
    rep1(i, MAXN) rep1(j, i)
    dp[i] = (dp[i] - 1LL * dp[i - j] * fac[j] % MOD + MOD) % MOD;
    
    pw[0][0] = 1;
    rep1(i, MAXN) rep(j0, MAXN) rep(j1, MAXN)
    if(j0 + j1 < MAXN) pw[i][j0 + j1] = (pw[i][j0 + j1] + 1LL * pw[i - 1][j0] * dp[j1]) % MOD;
}

int solve(int n)
{
    if(n == 2) return 2;
    return (MOD * 2 - 1LL * pw[n][n - 1] * inv[n] % MOD + (n & 1 ? 2 : -2)) % MOD;
}

int main()
{
    int T, n;
    scanf("%d%d", &T, &MOD);
    gen_dp();
    while(T --) {
        scanf("%d", &n);
        printf("%d\n", solve(n));
    }
    return 0;
}