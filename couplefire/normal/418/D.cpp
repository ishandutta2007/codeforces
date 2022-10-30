#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100005;
vector<pair<int, int> > qq[MAX];
vector<int> adj[MAX];
int par[20][MAX], d[MAX], st[MAX], fi[MAX], ans[MAX], num;
int mx[4 * MAX], lazy[4 * MAX];
int n, q;
void shift(int v)
{
	mx[2 * v] += lazy[v];
	mx[2 * v + 1] += lazy[v];
	lazy[2 * v] += lazy[v];
	lazy[2 * v + 1] += lazy[v];
	lazy[v] = 0;
}
void add(int l, int r, int val, int v, int s, int e)
{
	if (l <= s && e <= r)
	{
		mx[v] += val;
		lazy[v] += val;
		return;
	}
	if (e <= l || r <= s)
		return;
	shift(v);
	int mid = (s + e) / 2;
	add(l, r, val, 2 * v, s, mid);
	add(l, r, val, 2 * v + 1, mid, e);
	mx[v] = max(mx[2 * v], mx[2 * v + 1]);
}
int get_max(int l, int r, int v, int s, int e)
{
	if (l <= s && e <= r)
		return mx[v];
	if (e <= l || r <= s)
		return 0;
	shift(v);
	int mid = (s + e) / 2;
	return max(get_max(l, r, 2 * v, s, mid), get_max(l, r, 2 * v + 1, mid, e));
}
void dfs(int p, int v)
{
	par[0][v] = p;
	for (int i = 1; i < 20; i++)
		par[i][v] = par[i - 1][par[i - 1][v]];
	st[v] = num++;
	for (int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if (u != p)
		{
			d[u] = d[v] + 1;
			dfs(v, u);
		}
	}
	fi[v] = num;
	add(st[v], st[v] + 1, d[v], 1, 0, n);
}
int get_parent(int v, int k)
{
	for (int i = 0; i < 20; i++)
		if ((1 << i) & k)
			v = par[i][v];
	return v;
}
int lca(int u, int v)
{
	if (d[u] < d[v])
		swap(u, v);
	u = get_parent(u, d[u] - d[v]);
	if (u == v)
		return u;
	for (int i = 19; i >= 0; i--)
		if (par[i][u] != par[i][v])
		{
			u = par[i][u];
			v = par[i][v];
		}
	return par[0][v];
}
int get_mid(int u, int v)
{
	int p = lca(u, v);
	int dist = d[u] + d[v] - 2 * d[p];
	dist /= 2;
	if (dist <= d[u] - d[p])
		return get_parent(u, dist);
	dist -= d[u] - d[p];
	dist = d[v] - d[p] - dist;
	return get_parent(v, dist);
}
bool is_child(int v, int p)
{
	return (st[p] <= st[v] && fi[v] <= fi[p]);
}
int get(int u, int v)
{
	int	mid = get_mid(u, v);
	int p = lca(u, v);
	if (is_child(v, mid))
		mid = get_parent(v, d[v] - d[mid] - 1);
	if (is_child(u, mid))
		return get_max(st[mid], fi[mid], 1, 0, n);
	int ans = 0;
	if (0 < st[mid])
		ans = max(ans, get_max(0, st[mid], 1, 0, n));
	if (fi[mid] < n)
		ans = max(ans, get_max(fi[mid], n, 1, 0, n));
	return ans;
}
void go(int p, int v)
{
	for (int i = 0; i < qq[v].size(); i++)
		ans[qq[v][i].second] = max(ans[qq[v][i].second], get(v, qq[v][i].first));
	for (int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if (u == p)
			continue;
		add(0, n, 1, 1, 0, n);
		add(st[u], fi[u], -2, 1, 0, n);
		go(v, u);
		add(st[u], fi[u], 2, 1, 0, n);
		add(0, n, -1, 1, 0, n);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, 0);
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		qq[u].push_back(make_pair(v, i));
		qq[v].push_back(make_pair(u, i));
	}
	go(0, 0);
	for (int i = 0; i < q; i++)
		cout << ans[i] << "\n";
	return 0;
}