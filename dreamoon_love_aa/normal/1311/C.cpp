#include<bits/stdc++.h>
const int MAX_LEN = 200000;
char s[MAX_LEN + 1];
int dp[MAX_LEN];
int solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    for(int i = 0; i < n; i++) dp[i] = 0;
    for(int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        dp[x - 1]++;
    }
    dp[n - 1] ++;
    for(int i = n - 2; i >= 0; i--) {
        dp[i] += dp[i + 1];
    }
    long long an[26] = {};
    for(int i = 0; i < n; i++) {
        an[s[i] - 'a'] += dp[i];
    }
    for(int i = 0; i < 26; i++) printf("%lld%c", an[i], " \n"[i == 25]);
}
int main() {
    int T;
    scanf("%d", &T);
    for(int cs = 1; cs <= T; cs++) {
        solve();
    }
    return 0;
}