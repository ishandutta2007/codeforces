#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

const int jt = 998244353;
void inline add(int &a, int b) { a += b - jt; a += (a >> 31) & jt; }
void inline sub(int &a, int b) { a -= b; a += (a >> 31) & jt; }
void inline mul(int &a, int b) { a = 1ll * a * b % jt; }
int inline Add(int a, int b) { return a + b >= jt ? a + b - jt : a + b; }
int inline Sub(int a, int b) { return a - b < 0 ? a - b + jt : a - b; }
int inline Mul(int a, int b) { return 1ll * a * b % jt; }

int N;
vector<int> nei[300005];
int dp[300005][3];

void dfs(int now, int lst) {
	dp[now][2] = 1;
	for (int to : nei[now]) {
		if (to == lst) continue;
		dfs(to, now);
		int ndp[3] = {0, 0, 0};
		rep(i, 3) add(ndp[i], Mul(Add(dp[to][1], dp[to][2]), dp[now][i]));
		add(ndp[0], Mul(dp[to][1], Add(dp[now][0], dp[now][2])));
		add(ndp[1], Mul(dp[to][1], dp[now][1]));
		add(ndp[1], Mul(Add(dp[to][0], dp[to][2]), Add(dp[now][0], dp[now][2])));
		dp[now][0] = ndp[0];
		dp[now][1] = ndp[1];
		dp[now][2] = ndp[2];
	}
}

int main() {
	scanf("%d", &N);
	repi(i, N - 1) {
		int u, v; scanf("%d%d", &u, &v);
		nei[u].push_back(v);
		nei[v].push_back(u);
	}
	dfs(1, 0);
	printf("%d\n", Add(dp[1][1], dp[1][2]));
	return 0;
}