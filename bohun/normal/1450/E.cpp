#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
#define mp make_pair

using ll = long long;
using namespace std;

const int N = 205;

int n, m, p[N], c[N], d[N][N];

int find(int x) {
	if (x == p[x]) return x;
	int fa = p[x];
	p[x] = find(fa);
	c[x] ^= c[fa];
	return p[x];
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) rep(j, 1, n) d[i][j] = i == j ? 0 : 1e9;
	rep(i, 1, n) p[i] = i;
	while (m--) {
		int a, b, t;
		scanf("%d%d%d", &a, &b, &t);
		int pa = find(a);
		int pb = find(b);
		if (pa == pb) {
			if (c[a] == c[b]) return puts("NO"), 0;
		}
		else {
			p[pa] = pb;
			c[pa] = c[a] ^ c[b] ^ 1;
		}
		if (t == 0) d[a][b] = d[b][a] = 1;
		if (t == 1) d[a][b] = 1, d[b][a] = -1;
	}
	rep(k, 1, n)
		rep(i, 1, n)
			rep(j, 1, n)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	rep(i, 1, n) if (d[i][i] < 0) return puts("NO"), 0;
	pair<int, int> best = {0, 0};
	rep(i, 1, n) rep(j, 1, n) best = max(best, {d[i][j], i});
	printf("YES\n%d\n", best.fi);
	rep(i, 1, n) printf("%d ", 2020 + d[best.se][i]);
	return 0;
}