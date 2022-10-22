#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 25830;
int dp[N];

int32_t main(){
	int h = 0;
	dp[0] = 2;
	for (int i = 1; i < N; i++){
		dp[i] = dp[i - 1] + 2 + i * 3;
		if (dp[i] >= 1e9){
			h = i + 1;
			break;
		}
	}
	int t; 
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d", &n);
		int ans = 0;
		while (n >= 2){
			int i = *(upper_bound(dp, dp + h, n) - 1);
			ans ++;
			n -= i;
		}
		printf("%d\n", ans);
	}
}