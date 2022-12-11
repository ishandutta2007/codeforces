#include <bits/stdc++.h>

const int MAXN = 1e6 + 10;
const int INF = 0x3f3f3f3f;
int nxt[MAXN][26], fail[MAXN], R[MAXN], tot, lst;
char buf[MAXN];
int L;
int find(int x) {
	while (buf[L] != buf[L - 1 - R[x]]) x = fail[x];
	return x;
}
int diff[MAXN], slink[MAXN];
int at[MAXN];
void extend(int x) {
	buf[++L] = x - 'a';
	int now = find(lst), & nt = nxt[now][x];
	if (!nt) {
		int fx = nxt[find(fail[now])][x];
		R[nt = ++tot] = R[now] + 2;
		fail[nt] = fx;
		diff[nt] = R[nt] - R[fx];
		slink[nt] = diff[nt] == diff[fx] ? slink[fx] : nt;
	}
	at[L] = lst = nt;
}
int f[MAXN], frm[MAXN];
typedef std::pair<int, int> pi;
pi g[MAXN];
void gmi(pi & x, pi y) { if (x > y) x = y; }
int main() {
	static char S[MAXN], T[MAXN];
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> S >> T;
	int _L = strlen(S);
	*buf = 255, R[1] = -1, fail[0] = 1; diff[0] = -12243;
	tot = lst = 1;
	for (int i = 0; i < _L; ++i)
		extend(S[i]), extend(T[i]);
	for (int i = 1; i <= L; ++i) {
		int p = at[i];
		pi cur(INF, -1);
		while (p) {
			pi dp = slink[p] == p ? pi(INF, -1) : g[fail[p]];
			int S = slink[p], at = i - R[S];
			pi tar(f[at] + 1, at);
			if (at & 1) tar.first = INF;
			gmi(g[p] = dp, tar);
			if (i % 2 == 0) gmi(cur, g[p]);
			p = fail[slink[p]];
		}
		if (i % 2 == 0) {
			if (buf[i] == buf[i - 1])
				gmi(cur, pi(f[i - 2], i - 2));
			std::tie(f[i], frm[i]) = cur;
		}
	}
	if (f[L] > L) {
		std::cout << -1 << std::endl;
		exit(0);
	}
	std::cout << f[L] << '\n';
	int now = L;
	while (now) {
		int l = now - frm[now];
		if (l != 2) {
			std::cout << (frm[now] + 2 >> 1) << ' ' << (now >> 1) << '\n';
		}
		assert(l % 2 == 0);
		now = frm[now];
	}
	return 0;
}