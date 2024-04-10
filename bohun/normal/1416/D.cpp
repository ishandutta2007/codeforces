#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
 
using ll = long long;
using ld = long double;
using namespace std;

const int N = 1e6 + 20;
const int T = 1 << 20;

int n, m, q, inv[N], p[N], a[N], b[N], type[N], x[N], par[N], in[N], out[N], qq[N], tree[T + T];
bool kil[N];

int Find(int x) {
	if (par[x] == x) return x;
	return par[x] = Find(par[x]);
}

void Onion(int x, int y) {
	par[Find(x)] = Find(y);
}

vector <int> G[N];

void dfs(int v) {
	in[v] = ++*in;
	for (auto u : G[v])
		dfs(u);
	out[v] = *in;
}

void sett(int x, int val) {
	x += T;
	tree[x] = val;
	for (x /= 2; x; x /= 2)
		tree[x] = max(tree[2 * x], tree[2 * x + 1]);
}

int query(int l, int r) {
	int res = 0;
	for (l += T, r += T + 1; l < r; l /= 2, r /= 2) {
		if (l & 1) res = max(res, tree[l++]);
		if (r & 1) res = max(res, tree[--r]);
	}
	return res;
}
 
int main() {
	scanf ("%d%d%d", &n, &m, &q);
	rep(i, 1, n)
		scanf ("%d", p + i), inv[p[i]] = i;
	rep(i, 1, m) 
		scanf ("%d%d", a + i, b + i);
	rep(i, 1, q) {
		scanf ("%d%d", type + i, x + i);
		if (type[i] == 2) kil[x[i]] = true;
	}
	rep(i, 1, m)
		if (!kil[i]) {
			type[++q] = 2;
			x[q] = i;
		}
	rep(i, 1, n) par[i] = i;
	int m = n;
	per(i, 1, q) {
		if (type[i] == 1)
			qq[i] = Find(x[i]);
		if (type[i] == 2) {
			int u = Find(a[x[i]]), v = Find(b[x[i]]);
			if (u != v) {
				m++;
				par[m] = m;
				G[m].pb(u);
				G[m].pb(v);
				Onion(u, m);
				Onion(v, m);
			}
		}
	}
	per(i, 1, m) if (!in[i]) dfs(i);
	rep(i, 1, n) sett(in[i], p[i]);
	rep(i, 1, q)
		if (type[i] == 1) {
			int ans = query(in[qq[i]], out[qq[i]]);
			if (ans)
				sett(in[inv[ans]], 0);
			printf ("%d\n", ans);
		}
	return 0;
}