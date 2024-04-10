#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
 
using ll = long long;
using namespace std;

const int N = 111;

int n, a[N], b[N], dp[2][N][N * N];

void clear(int x) {
	for (int cnt = 0; cnt <= n; ++cnt)
		for (int s = 0; s <= 100 * n; ++s) 
			dp[x][cnt][s] = -1e9;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", b + i, a + i);
	
	
	clear(0);
	dp[0][0][0] = 0;
	
	for (int i = 0; i < n; ++i) {
		int prv = i % 2, nxt = (i + 1) % 2;
		clear(nxt);
		for (int cnt = 0; cnt <= i; ++cnt)
			for (int s = 0; s <= 100 * n; ++s) {
				if (dp[prv][cnt][s] == -1e9)
					continue;
				
				dp[nxt][cnt][s] = max(dp[nxt][cnt][s], dp[prv][cnt][s]);
				
				dp[nxt][cnt + 1][s + a[i]] = max(dp[nxt][cnt + 1][s + a[i]], dp[prv][cnt][s] + b[i]);
			}	
	}
	int A = accumulate(a, a + n, 0);		
	for (int i = 1; i <= n; ++i) {
		double out = 0.0;
		for (int s = 0; s <= 100 * n; ++s)
			if (dp[n % 2][i][s] != -1e9) {
				double score = s + min((double) dp[n % 2][i][s] - s, (double) (A - s) / 2);
				out = max(out, score);
			}
		printf("%.10f ", out);
	}
	
	return 0;
}