#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N, K;
int a[205];
vector<int> nei[205];
int dp[205][205], ndp[205];

void dfs(int now, int lst) {
	dp[now][K] = 0;
	for (int to : nei[now]) {
		if (to == lst) continue;
		dfs(to, now);
		memset(ndp, -Inf, sizeof(ndp));
		rep(i, K + 1) rep(j, K + 1) if (i + j + 1 >= K) ndp[min(i, j + 1)] = max(ndp[min(i, j + 1)], dp[now][i] + dp[to][j]);
		memcpy(dp[now], ndp, sizeof(ndp));
	}
	dp[now][0] = max(dp[now][0], dp[now][K] + a[now]);
}

int main() {
	scanf("%d%d", &N, &K); ++K;
	repi(i, N) scanf("%d", a + i);
	repi(i, N - 1) {
		int u, v; scanf("%d%d", &u, &v);
		nei[u].push_back(v);
		nei[v].push_back(u);
	}
	memset(dp, -Inf, sizeof(dp));
	dfs(1, 0);
	printf("%d\n", *max_element(dp[1], dp[1] + K + 1));
	return 0;
}