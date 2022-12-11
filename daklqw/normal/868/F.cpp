#include <bits/stdc++.h>

const int MAXN = 100010;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
LL f[MAXN], g[MAXN];
int hav[MAXN], A[MAXN], n, K;
LL ans = 0;
void dec(int x) { ans -= hav[x]-- - 1; }
void add(int x) { ans += ++hav[x] - 1; }
int nl, nr;
void moveto(int L, int R) {
	while (nl > L) add(A[--nl]);
	while (nr < R) add(A[++nr]);
	while (nl < L) dec(A[nl++]);
	while (nr > R) dec(A[nr--]);
}
int getbest(int l, int r, int u) {
	LL minn = INFL; int at = 0;
	for (int i = l; i <= r; ++i) {
		moveto(i, u);
		if (g[i - 1] + ans < minn)
			at = i, minn = g[i - 1] + ans;
	}
	f[u] = minn;
	return at;
}
void solve(int l, int r, int L, int R) {
	int mid = l + r >> 1;
	int at = getbest(L, std::min(R, mid), mid);
	if (l == r) return ;
	solve(l, mid, L, at);
	solve(mid + 1, r, at, R);
}
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);
	std::cin >> n >> K;
	memset(f, 0x3f, sizeof f);
	memset(g, 0x3f, sizeof g);
	f[0] = 0;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	nl = nr = hav[A[1]] = 1;
	for (int i = 1; i <= K; ++i) {
		memcpy(g, f, n + 1 << 3);
		memset(f, 0, n + 1 << 3);
		solve(1, n, getbest(1, 1, 1), getbest(1, n, n));
	}
	std::cout << f[n] << std::endl;
	return 0;
}