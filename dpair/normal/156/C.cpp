#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
int dp[2505][105];

int dfs(int sig, int res){
    if(sig > res * 25) return 0;
    if(res == 1) return 1;
    if(~dp[sig][res]) return dp[sig][res];
    dp[sig][res] = 0;
    for (register int i = 0;i <= 25 && i <= sig;i ++) dp[sig][res] = (dp[sig][res] + dfs(sig - i, res - 1)) % MOD;
    return dp[sig][res];
}
char s[105];
int main(){
    int t;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &t);
    while(t --){
        scanf("%s", s + 1);
        int sig = 0, n = strlen(s + 1);
        for (register int i = 1;i <= n;i ++){
            sig += s[i] - 97;
        }
        printf("%d\n", (dfs(sig, n) - 1 + MOD) % MOD);
    }
}