#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define _rep(i,a,b) for (int i=(a); i>=(b); i--)
#define val first
#define cost second
#define lc (o << 1)
#define rc (o << 1 | 1)
#define mid ((l + r) >> 1)
using namespace std;

inline int read() {
	char ch = getchar(); int x = 0, op = 1;
	while (ch < '0' || '9' < ch) { if (ch == '-') op = -1; ch = getchar(); }
	while ('0' <= ch && ch <= '9') { x = x*10 + ch-'0'; ch = getchar(); }
	return op * x;
}

const int maxdep = 16, maxn = 30009;
const int base = 10000019, MOD = 1000000007;
int power[maxn], v[maxn], w[maxn], L[maxn], R[maxn], flag[maxn];
vector<pair<int,int> > T[maxn<<2];
long long dp[maxdep][1009];
int n, K, Q, m, t, a, b, ans;

void update(int o, int l, int r, int x, int y, int v, int w) {
	if (l == x && y == r) {
		T[o].push_back(make_pair(v, w)); return;
	}
	if (x <= mid) update(lc, l, mid, x, min(y, mid), v, w);
	if (mid+1 <= y) update(rc, mid+1, r, max(mid+1, x), y, v, w);
}

void solve(int o, int dep, int l, int r) {
	memset(dp[dep], 0, sizeof dp[dep]); 
	if (dep) rep (i, 1, K) dp[dep][i] = dp[dep-1][i];
	if (!T[o].empty())
		rep (i, 0, T[o].size()-1)
			_rep (j, K, T[o][i].cost)
				dp[dep][j] = max(dp[dep][j], dp[dep][j-T[o][i].cost] + T[o][i].val);
	if (l == r) {
		if (flag[l]) {
			ans = 0;
			rep (i, 1, K) 
				ans = (ans + 1LL * dp[dep][i] % MOD * power[i-1]) % MOD;
			printf("%d\n", ans);
		}
		return;
	}
	solve(lc, dep+1, l, mid); solve(rc, dep+1, mid+1, r);
}

int main() {
	m = n = read(); K = read();
	power[0] = 1;
	rep (i, 1, K) power[i] = 1LL * power[i-1] * base % MOD;
	rep (i, 1, n) { v[i] = read(); w[i] = read(); }
	Q = read();
	rep (i, 1, n) { L[i] = 1; R[i] = Q; }
	rep (i, 1, Q) {
		t = read();
		if (t == 1) {
			v[++m] = read(); w[m] = read();
			L[m] = i; R[m] = Q;
		}
		else if (t == 2) R[read()] = i;
		else flag[i] = 1;
	}
	rep (i, 1, m)
		update(1, 1, Q, L[i], R[i], v[i], w[i]);
	solve(1, 0, 1, Q);
	return 0;
}