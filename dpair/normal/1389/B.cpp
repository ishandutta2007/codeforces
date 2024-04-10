#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;
int a[100010], n, z, m;
int dp[100010][6][2];

inline int mx(int x, int y) {return x > y ? x : y;}
int main(){
	int t;
	scanf("%d", &t);
	while(t --){
		scanf("%d%d%d", &n, &m, &z);
		for (register int i = 1;i <= n;i ++) scanf("%d", &a[i]);
		int ans = -1;
		for (register int k = 0;k <= z;k ++){
			for (register int i = 1;i <= n;i ++){
				dp[i][k][0] = mx(dp[i - 1][k][0], dp[i - 1][k][1]) + a[i];
				if(k > 0 && i < n) dp[i][k][1] = dp[i + 1][k - 1][0] + a[i];
				if(i + (k << 1) - 1 == m){
					ans = mx(ans, mx(dp[i][k][0], dp[i][k][1]));
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
}