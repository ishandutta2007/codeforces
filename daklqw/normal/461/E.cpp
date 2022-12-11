#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;
const int UP = 11;
typedef long long LL;
int nxt[MAXN * UP][4], tot;
char buf[MAXN];
LL S; int n;
void gmi(LL & x, LL y) { x > y ? x = y : 0; }
struct mat {
	LL A[4][4];
	friend mat operator * (mat a, mat b) {
		mat r;
		memset(r.A, 0x3f, sizeof r.A);
		const LL INFL = r.A[0][0];
		for (int i = 0; i != 4; ++i)
			for (int j = 0; j != 4; ++j) {
				LL & t = r.A[i][j];
				for (int k = 0; k != 4; ++k)
					gmi(t, a.A[i][k] + b.A[k][j]);
				t = std::min(t, INFL);
			}
		return r;
	}
} tr;
void dfs(int u, int fir, int lst, int dep = 0) {
	if (!u) {
		gmi(tr.A[fir][lst], dep - 1);
		return ;
	}
	if (dep == UP) return ;
	for (int i = 0; i != 4; ++i)
		dfs(nxt[u][i], fir, i, dep + 1);
}
bool judge(LL b) {
	mat a = tr, r;
	memset(r.A, 0, sizeof r.A);
	for (; b; b >>= 1, a = a * a) if (b & 1) r = r * a;
	bool can = false;
	for (int i = 0; i != 4; ++i)
		for (int j = 0; j != 4; ++j)
			can |= r.A[i][j] + 1 <= S;
	return can;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> S >> buf; n = strlen(buf);
	tot = 1;
	for (int i = 0; i < n; ++i) {
		int now = 1;
		for (int j = i; j < i + UP && j < n; ++j) {
			int & nt = nxt[now][buf[j] - 'A'];
			if (!nt) nt = ++tot;
			now = nt;
		}
	}
	memset(tr.A, 0x3f, sizeof tr.A);
	for (int i = 0; i < 4; ++i)
		dfs(nxt[1][i], i, i, 1);
	LL l = 0, r = S, ans = -1;
	while (l <= r) {
		LL mid = l + r >> 1;
		if (judge(mid)) ans = mid + 1, l = mid + 1;
		else r = mid - 1;
	}
	std::cout << ans << std::endl;
	return 0;
}