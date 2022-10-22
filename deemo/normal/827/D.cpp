#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<numeric>
#include<set>
#include<cstring>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second
#define tm alksdfj

const int MAXN = 2e5 + 10;
const int MAXE = 2e5 + 20;
const int LOG = 18;

int n, m, depth[MAXN], par[LOG][MAXN], mx[LOG][MAXN], comp[MAXN];
int from[2 * MAXE], to[2 * MAXE], prv[2 * MAXE], w[2 * MAXE], head[MAXN], picked[2 * MAXE], ed[2 * MAXE], ec;
vector<pair<pii, int>>	adj[MAXN];
int s_t[MAXN], f_t[MAXN], tm, sz[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> st;
//set<pair<int, int>>	st;
int ans[MAXN*2];

void add_edge(int u, int v, int c){from[ec] = u, to[ec] = v, w[ec] = c, prv[ec] = head[u];	head[u] = ec++;}

bool cmp(int e1, int e2){return	w[e1] < w[e2];}

int get_comp(int v){
	if (v == comp[v])	return	v;
	return	comp[v] = get_comp(comp[v]);
}

void merge(int u, int v, int c, int e){
	if (get_comp(u) == get_comp(v))	return;
	if (e & 1)	e ^= 1;
	picked[e] = 1;
	adj[u].push_back({{v, c}, e});
	adj[v].push_back({{u, c}, e});
	comp[get_comp(u)] = get_comp(v);
}

int plant(int v, int p = -1, int de = 0, int ww = 0){
	s_t[v] = tm++;
	par[0][v] = p;
	mx[0][v] = ww;
	depth[v] = de;
	sz[v] = 1;
	for (auto xx:adj[v]){
		auto e = xx.F;
		if (e.first != p)	sz[v] += plant(e.first, v, de + 1, e.second);
	}
	f_t[v] = tm;
	return	sz[v];
}

void init(){
	for (int i = 1; i < LOG; i++)
		for (int j = 0; j < n; j++)
			if (par[i - 1][j] == -1)
				par[i][j] = -1, mx[i][j] = mx[i - 1][j];
			else
				par[i][j] = par[i - 1][par[i - 1][j]], mx[i][j] = max(mx[i - 1][j], mx[i - 1][par[i - 1][j]]);
}

int get(int u, int v){
	if (depth[u] < depth[v])	swap(u, v);
	int ret = 0;
	for (int i = LOG - 1; i >= 0; i--)
		if (depth[u] - (1 << i) >= depth[v])
			ret = max(mx[i][u], ret), u = par[i][u];
	if (u == v)	return	ret;
	for (int i = LOG - 1; i >= 0; i--)
		if (par[i][u] != par[i][v])	
			ret = max(ret, max(mx[i][u], mx[i][v])), u = par[i][u], v = par[i][v];
	return	max(ret, max(mx[0][u], mx[0][v]));
}

void add(int v, int p = -1){
	for (int e = head[v]; e != -1; e = prv[e])
		if (to[e] != p && (s_t[to[e]] < s_t[v] || s_t[to[e]] >= f_t[v]))	st.push({w[e], to[e]});
	for (auto xx:adj[v]){
		auto e = xx.F;
		if (p != e.first)	add(e.first, v);
	}
}

void dfs(int v, int p = -1, bool fl = 0, int pp =-1){
	int maxi = -1, ind = -1, ti=-1;
	for (auto xx:adj[v]){
		auto e = xx.F;
		if (e.first != p && sz[e.first] > maxi)	maxi = sz[e.first], ind = e.first, ti=xx.S;
	}
	for (auto xx:adj[v]){
		auto e = xx.F;
		if (e.first != p && e.first != ind)	dfs(e.first, v, 0, xx.S);
	}
	if (ind != -1)	dfs(ind, v, 1, ti);
	for (auto xx:adj[v]){
		auto e = xx.F;
		if (e.first != p && e.first != ind)	add(e.first, v);
	}

	for (int e = head[v]; e != -1; e = prv[e])
		if (to[e] != p && (s_t[to[e]] < s_t[v] || s_t[to[e]] >= f_t[v]))	st.push({w[e], to[e]});

	while (st.size() && s_t[st.top().second] >= s_t[v] && s_t[st.top().second] < f_t[v])	st.pop();

	if (pp != -1){
		if (st.empty())	ans[pp]=ans[pp^1]= -1;
		else ans[pp] = ans[pp^1] = st.top().first-1;
	}
	if (!fl)
		while (st.size()) st.pop();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	memset(head, -1, sizeof(head));
	while (m--){
		int a, b, c;	cin >> a >> b >> c;	a--, b--;
		add_edge(a, b, c);
		add_edge(b, a, c);
	}
	iota(comp, comp + n, 0);
	iota(ed, ed + ec, 0);
	sort(ed, ed + ec, cmp);
	for (int e = 0; e < ec; e++)
		merge(from[ed[e]], to[ed[e]], w[ed[e]], ed[e]);
	plant(0);
	init();
	for (int e = 0; e < ec; e += 2)
		if (picked[e] == 0){
			int maxi = get(from[e], to[e]);
			ans[e] = maxi-1;
		}
	dfs(0);

	for (int e = 0; e < ec; e += 2)
		cout << ans[e] << " ";
	cout << "\n";
	return	0;
}