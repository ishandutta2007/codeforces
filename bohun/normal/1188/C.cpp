#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cout << #x << " = " << x << endl
 
using namespace std;

const int mod = 998244353;

int n, k;
int dp[1001][1001];
int a[1001];		
 
int main() {
	scanf("%d %d", &n, &k);
	int MAX = 0;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		MAX = max(MAX, a[i]);
	}
	int ans = 0;
	sort(a + 1, a + n + 1);
	for(int i = 1; (k - 1) * i <= MAX; ++i) {
		dp[0][0] = 1;
		int wsk = 0;
		for(int g = 1; g <= n; ++g) {
			while(a[g] - a[wsk + 1] >= i) 
				wsk += 1;
			for(int j = 0; j <= k; ++j)
				dp[g][j] = dp[g - 1][j];
			for(int j = 1; j <= k; ++j)
				dp[g][j] = (dp[g][j] + dp[wsk][j - 1]) % mod;
		}
		ans = (ans + dp[n][k]) % mod;
	}
	printf("%d", ans);
	
			
		
	
 
	return 0;
}