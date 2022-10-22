#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 1e5 + 100;
const int M = 310;
const int p = (1 << 17);

int n, m;
int a[N];
int l[M], r[M];

int lazy[2 * p];
int mini[2 * p];

void push(int v) {
	for (auto u : {2 * v, 2 * v + 1}) {
		lazy[u] += lazy[v];
		mini[u] += lazy[v];
	}
	lazy[v] = 0;
}

void add(int x, int y, int z, int v = 1, int l = 0, int r = p - 1) {
	if (x <= l && r <= y) {
		mini[v] += z;
		lazy[v] += z;
		return;
	}
	push(v);
	int m = (l + r) / 2;
	if (x <= m) add(x, y, z, 2 * v, l, m);
	if (m < y) add(x, y, z, 2 * v + 1, m + 1, r);
	mini[v] = min(mini[2 * v], mini[2 * v + 1]);
}

vector <pair<int, pair<int, int>>> v[N];

int main() {	
	scanf ("%d%d", &n, &m);
	rep(i, 0, p - 1) 
		if (!(1 <= i && i <= n)) add(i, i, 1e9);
	rep(i, 1, n) {
		scanf ("%d", a + i);
		add(i, i, a[i]);
	}
	rep(i, 1, m) {
		scanf ("%d%d", l + i, r + i);
		v[l[i]].pb({1, {l[i], r[i]}});
		v[r[i] + 1].pb({-1, {l[i], r[i]}});
		add(l[i], r[i], -1);
	}
	pair<int, int> best = {-1, -1};
	rep(i, 1, n) {
		for (auto it : v[i])
			add(it.se.fi, it.se.se, it.fi);
		best = max(best, {a[i] - mini[1], i});
	}
	printf ("%d\n", best.fi);
	vector <int> f;
	rep(i, 1, m) if (r[i] < best.se || l[i] > best.se) f.pb(i);
	printf ("%d\n", ss(f));
	for (auto it : f) printf ("%d ", it);
	

	return 0;
}