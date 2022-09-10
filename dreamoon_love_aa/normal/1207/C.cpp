#include<bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
char s[200005];
long long dp[200005][3];
int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, a, b;
        scanf("%d%d%d", &n, &a, &b);
        scanf("%s", s);
        dp[0][1] = b;
        dp[0][2] = INF;
        for(int i = 1; i <= n; i++) {
            if(s[i] == '1' || s[i-1] == '1') {
                dp[i][1] = INF;
                dp[i][2] = min(dp[i-1][2], dp[i-1][1] + a) + 2 * b;
            }
            else {
                dp[i][1] = min(dp[i-1][1], dp[i-1][2] + a) + b;
                dp[i][2] = min(dp[i-1][2], dp[i-1][1] + a) + 2 * b;
            }
        }
        printf("%lld\n", dp[n][1] + (long long)n * a);
    }
}