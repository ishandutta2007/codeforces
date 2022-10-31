#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 500 + 7;
const int MOD = 998244353;

int n, k;
int dp[2][N][N];
int cnt[N];
int pr[N];

void add(int &a, int b){
    a += b;
    if (a >= MOD)
        a -= MOD;
}

int main() {
    scanf("%d%d", &n, &k);
    
    dp[0][0][0] = 1;
    forn(ii, n){
        int i = ii & 1;
        int ni = i ^ 1;
        memset(dp[ni], 0, sizeof(dp[ni]));
        forn(j, n + 1){
            forn(k, n + 1){
                add(dp[ni][j + 1][max(j + 1, k)], dp[i][j][k]);
                add(dp[ni][1][max(1, k)], dp[i][j][k]);
            }
        }
    }
    
    forn(i, n + 1)
        forn(j, n + 1)
            add(cnt[i], dp[n & 1][j][i]);
    
    forn(i, n + 1){
        add(pr[i + 1], pr[i]);
        add(pr[i + 1], cnt[i]);
    }
    
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        add(ans, cnt[i] * (long long)(pr[min(n + 1, (k - 1) / i + 1)]) % MOD);
    
    ans = (ans * (long long)((MOD + 1) / 2)) % MOD;
    printf("%d\n", ans);
    
    return 0;
}