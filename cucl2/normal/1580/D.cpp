#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N, M;
ll a[4005];
int ls[4005], rs[4005], sz[4005];
ll dp[4005][4005];

int buildtree(int l, int r) {
	if (l > r) return 0;
	int rt = min_element(a + l, a + r + 1) - a;
	ls[rt] = buildtree(l, rt - 1);
	rs[rt] = buildtree(rt + 1, r);
	return rt;
}

void dfs(int now) {
	if (ls[now]) dfs(ls[now]);
	if (rs[now]) dfs(rs[now]);
	// if (sz[ls[now]] > sz[rs[now]]) swap(ls[now], rs[now]);
	sz[now] = sz[ls[now]] + sz[rs[now]] + 1;
	for (int i = 0; i <= sz[now]; ++i) dp[now][i] = -1e18;
	for (int i = 0; i <= sz[ls[now]]; ++i) for (int j = 0; j <= sz[rs[now]]; ++j) {
		dp[now][i + j] = max(dp[now][i + j], dp[ls[now]][i] + dp[rs[now]][j] - a[now] * i * j * 2);
	}
	for (int i = sz[now]; i; --i) dp[now][i] = max(dp[now][i], dp[now][i - 1] + a[now] * M - a[now] * (i * 2 - 1));
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i) scanf("%lld", a + i);
	int rt = buildtree(1, N);
	for (int i = 1; i <= N; ++i) dp[0][i] = -1e18;
	dfs(rt);
	printf("%lld\n", dp[rt][M]);
	return 0;
}