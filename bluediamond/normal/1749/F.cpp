#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef ONPC
mt19937 rng(228);
#else
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = (int)2e5 + 7;
const int KK = 19;
int n;
int p[N];
int dep[N];
int euler_tour[2 * N];
int tour_sz;
int first_time_on_tour[N];
int last_time_on_tour[N];
int lg2[2 * N];
vector<int> g[N];
pair<int, int> tab_lca[2 * N][KK];
int sub[N];


void dfs_lca(int a, int pr = -1)
{
	vector<int> kds;
	sub[a] = 1;
	p[a] = pr;
	euler_tour[++tour_sz] = a;
	first_time_on_tour[a] = last_time_on_tour[a] = tour_sz;
	for (auto& b : g[a])
	{
		if (b == pr) continue;
		kds.push_back(b);
		dep[b] = 1 + dep[a];
		dfs_lca(b, a);
		sub[a] += sub[b];
		euler_tour[++tour_sz] = a;
		last_time_on_tour[a] = tour_sz;
	}
	g[a] = kds;
}

void lcaTM()
{
	dfs_lca(1);
	for (int i = 2; i <= tour_sz; i++)
	{
		lg2[i] = 1 + lg2[i / 2];
	}
	for (int i = 1; i <= tour_sz; i++)
	{
		tab_lca[i][0] = { dep[euler_tour[i]], euler_tour[i] };
	}
	for (int k = 1; (1 << k) <= tour_sz; k++)
	{
		for (int i = 1; i + (1 << k) - 1 <= tour_sz; i++)
		{
			tab_lca[i][k] = min(tab_lca[i][k - 1], tab_lca[i + (1 << (k - 1))][k - 1]);
		}
	}
}

int lca(int a, int b)
{
	if (first_time_on_tour[a] > last_time_on_tour[b])
	{
		swap(a, b);
	}
	a = first_time_on_tour[a];
	b = last_time_on_tour[b];
	int k = lg2[b - a + 1];
	return min(tab_lca[a][k], tab_lca[b - (1 << k) + 1][k]).second;
}

int dist(int a, int b) {
	return dep[a] + dep[b] - 2 * dep[lca(a, b)];
}

const int K = 23;
ll all[N][K];
ll aib[K][N];

void addaib(int tp, int i, ll x) {
	while (i < N) {
		aib[tp][i] += x;
		i += i & (-i);
	}
}

ll getaib(int tp, int i) {
	ll sol = 0;
	while (i) {
		sol += aib[tp][i];
		i -= i & (-i);
	}
	return sol;
}

int curcol = 0;
int y;
bool difcol[N];
int col[N], fi[N], ls[N], id[N];

void build1(int a) {
	int c = 0;
	for (auto& b : g[a]) {
		if (sub[b] > sub[c])c = b;
		build1(b);
	}
	for (auto& b : g[a]) {
		if (b != c)difcol[b] = 1;
	}
}

void build2(int a) {
	id[a] = ++y;
	if (difcol[a]) {
		col[a] = ++curcol;
		fi[curcol] = a;
	}
	else {
		assert(p[a] != -1);
		assert(1 <= p[a] && p[a] <= n);
		col[a] = col[p[a]];
	}

	ls[curcol] = a;
	for (auto& b : g[a]) {
		if (difcol[b] == 0)build2(b);
	}
	for (auto& b : g[a]) {
		if (difcol[b] == 1)build2(b);
	}
}

void op(int a, int dist, ll g) {
	while (a != -1) {
		int first = fi[col[a]];
		int low = id[first];
		int high = id[a];
		addaib(dist, low, g);
		addaib(dist, high + 1, -g);
		a = p[first];
	}
	return;
	while (a != -1) {
		all[a][dist] += g;
		a = p[a];
	}
}

int main()
{
#ifndef ONPC
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif

	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	lcaTM();
	difcol[1] = 1;
	build1(1);
	build2(1);

	int q;
	cin >> q;
	for (int iq = 1; iq <= q; iq++) {
		int tp;
		cin >> tp;
		assert(tp == 1 || tp == 2);
		if (tp == 1) {
			int v;
			cin >> v;
			assert(1 <= v && v <= n);
			ll sol = 0;
			for (int d = 0; d < K && v != -1; d++) {
				sol += all[v][d];
				sol += getaib(d, id[v]);
				v = p[v];
			}
			cout << sol << "\n";
			continue;
		}
		assert(tp == 2);
		int a, b;
		ll g;
		int dist;
		cin >> a >> b >> g >> dist;
		int c = lca(a, b);
		op(a, dist, g);
		op(b, dist, g);
		op(c, dist, -2 * g);
		//cout<<"lmao\n";
		for (int j = 0; j <= dist; j++) {
			all[c][j] += g;
		}
		int sub = 0;
		while (p[c] != -1 && dist - sub >= 0) {
			sub++;
			int init = c;
			c = p[c];
			for (int j = 0; j <= dist - sub; j++) {
				all[c][j] += g;
				// la depth j de c => la depth j-1 de init
				if (j - 1 >= 0) {
					all[init][j - 1] -= g;
				}
			}
		}
	}
}




/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */