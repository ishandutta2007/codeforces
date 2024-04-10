#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

typedef long long li;

const int N = 300 * 1000 + 13;
const int INF = 1e9;

int dp[N][2];

int n, k;
int a[N], b[N];

int get(int pa, int pb, int a, int b){
	int ans = INF;
	
	if (pa <= k){
		int tot = pa + a;
		int cnt = (tot + k - 1) / k - 1;
		if (b == cnt)
			ans = min(ans, tot - cnt * k);
		else if (b > cnt && b <= a * li(k))
			ans = min(ans, 1);
	}
	
	if (pb <= k){
		int cnt = (a + k - 1) / k - 1;
		if (b == cnt)
			ans = min(ans, a - cnt * k);
		else if (b > cnt && b <= (a - 1) * li(k) + (k - pb))
			ans = min(ans, 1);
	}
	
	return ans;
}

int main() {
	scanf("%d%d", &n, &k);
	forn(i, n) scanf("%d", &a[i]);
	forn(i, n) scanf("%d", &b[i]);
	
	forn(i, N) forn(j, 2) dp[i][j] = INF;
	dp[0][0] = 0;
	dp[0][1] = 0;
	forn(i, n){
		dp[i + 1][0] = get(dp[i][0], dp[i][1], a[i], b[i]);
		dp[i + 1][1] = get(dp[i][1], dp[i][0], b[i], a[i]);
	}
	
	puts(dp[n][0] <= k || dp[n][1] <= k ? "YES" : "NO");
	return 0;
}