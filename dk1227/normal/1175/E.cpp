#include<bits/stdc++.h>
using namespace std;
const int maxn(600005);
int n, m, l, r, mx, a[maxn], dp[maxn][25];
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &l, &r);
        a[l] = max(a[l], r);
    	mx = max(mx, r);
    }
    for(int i = 1; i <= mx; i++)
		a[i] = max(a[i], a[i - 1]);
    for(int i = 0; i <= mx; i++)
		dp[i][0] = a[i];
    for(int i = 1; i <= 20; i++)
        for(int j = 0; j <= mx; j++)
			dp[j][i] = dp[dp[j][i - 1]][i - 1];
    for(int k = 1; k <= m; k++) {
        scanf("%d%d", &l, &r);
        int ans = 0;
        for(int i = 20; i >= 0; i--)
            if(dp[l][i] < r) {
                ans += 1 << i;
                l = dp[l][i];
            }
        if(a[l] >= r)
			printf("%d\n", ans + 1);
        else 
			printf("-1\n");
    }
    return 0;
}