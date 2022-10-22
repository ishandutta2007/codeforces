//Bones, sinking like stones all that we fought for..

#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>
#include<functional>

using namespace std;

const int MAXN = 1e5 + 10;
const int LOG = 19;
const int INF = 5e8;

int n, k, sz, sec[MAXN], ss[MAXN];
int depth[MAXN], par[LOG][MAXN];
vector<pair<int, int>>	adj[MAXN];
pair<int, int>	d[MAXN], pu[MAXN];
bool pic[MAXN];

void go(int v, int p = -1, int de = 0){
	depth[v] = de;
	par[0][v] = p;
	for (auto u:adj[v])
		if (u.first^p)	go(u.first, v, de + 1);
}

void init(){
	for (int w = 1; w < LOG; w++)
		for (int v = 0; v < n; v++)
			if (par[w - 1][v] == -1)	
				par[w][v] = par[w - 1][v];
			else
				par[w][v] = par[w - 1][par[w - 1][v]];
}

int lca(int u, int v){
	if (depth[u] < depth[v])	swap(u, v);
	for (int w = LOG - 1; w >= 0; w--)
		if (depth[u] - (1<<w) >= depth[v])	u = par[w][u];
	if (u == v)	return	u;
	for (int w = LOG - 1; w >= 0; w--)
		if (par[w][u] != par[w][v])	u = par[w][u], v = par[w][v];
	return	par[0][v];
}

void down(int v, int p = -1){
	d[v] = {-INF, -INF};
	pu[v] = {-INF, -INF};
	if (pic[v])	d[v] = {0, v}, pu[v] = {0, v};

	for (auto u:adj[v])
		if (u.first ^ p){
			down(u.first, v);

			if (pu[u.first].first < d[v].first + u.second)
				pu[u.first] = {d[v].first + u.second, d[v].second};

			if (d[v].first < d[u.first].first + u.second)
				d[v] = d[u.first], d[v].first += u.second;
			else if (d[v].first == d[u.first].first + u.second)
				d[v].second = v;
		}

	pair<int, int> z(-INF, -INF);
	for (int i = adj[v].size() - 1; i >= 0; i--){
		auto u = adj[v][i];
		if (u.first ^ p){
			if (pu[u.first].first < z.first + u.second)
				pu[u.first] = {z.first + u.second, z.second};
			else if (pu[u.first].first == z.first + u.second)
				pu[u.first].second = v;

			if (z.first < d[u.first].first + u.second)
				z = {d[u.first].first + u.second, d[u.first].second};
			else if (z.first == d[u.first].first + u.second)
				z.second = v;
		}
	}
}

void add(int u, int v){
	int p = lca(u, v);
	ss[u]++, ss[v]++;
	ss[p]--;
	if (p)	ss[par[0][p]]--;
}

void up(int v, int p = -1, int w = 0){
	if (~p){
		if (pu[v].first < pu[p].first + w)
			pu[v] = {pu[p].first + w, pu[p].second};
		else if (pu[v].first == pu[p].first + w)
			pu[v].second = p;
	}
	if (pic[v] && pu[v].first ^ d[v].first)
		add(v, pu[v].first>d[v].first?pu[v].second:d[v].second);

	for (auto u:adj[v])
		if (u.first ^ p)
			up(u.first, v, u.second);
}

int run(int v, int p = -1){
	int sm = ss[v];
	for (auto u:adj[v])
		if (u.first^p)	sm += run(u.first, v);
	if (!pic[v])
		sec[sz++] = sm;
	return sm;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;	for (int i = 0; i < k; i++)	{int x; cin >> x, x--, pic[x] = 1;}
	for (int i = 0; i < n - 1; i++){
		int a, b, c;	cin >> a >> b >> c;	a--, b--;	adj[a].push_back({b, c}), adj[b].push_back({a, c});}
	go(0);
	init();
	down(0);
	up(0);
	run(0);
	sort(sec, sec + sz, greater<int>());
	cout << sec[0] << " ";
	int ans = 1;
	for (int i = 1; i < sz && sec[i] == sec[0]; i++)	ans++;
	cout << ans << "\n";
	return	0;
}