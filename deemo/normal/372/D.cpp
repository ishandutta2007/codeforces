//Nobody knows me, I'm cold, walk down this road all alone.

#include<cstdio>
#include<cmath>
#include<algorithm>
#include<utility>
#include<vector>
#include<set>

using namespace std;

const int max_n = 1e5 + 10;
const int LOG = 18;

int n, k, ans, sum;
vector<int>	adj[max_n];
int par[max_n][LOG + 2];
int depth[max_n], mp[max_n], s_t[max_n], sz;
set<int>	st;

void dfs(int v, int p, int d){
	mp[sz] = v;
	s_t[v] = sz++;
	depth[v] = d;
	par[v][0] = p;
	for (int u:adj[v])
		if (u != p)
			dfs(u, v, d + 1);
}

void init(){
	for (int i = 1; i <= LOG; i++)
		for (int j = 0; j < n; j++)
			if (par[j][i - 1] == -1)
				par[j][i] = -1;
			else
				par[j][i] = par[par[j][i - 1]][i - 1];
}

int lca(int v, int u){
	if (depth[v] < depth[u])	swap(u, v);
	for (int i = LOG; i >= 0; i--)
		if (depth[v] - (1 << i) >= depth[u])	v = par[v][i];
	if (v == u)	return	v;
	for (int i = LOG; i >= 0; i--)
		if (par[v][i] != par[u][i])
			v = par[v][i], u = par[u][i];
	return	par[v][0];
}

void add(int v){
	if (st.empty()){
		st.insert(s_t[v]);
		return;
	}

	set<int>::iterator it1 = st.upper_bound(s_t[v]);
	if (it1 == st.end())	it1 = st.begin();

	set<int>::iterator it2 = st.upper_bound(s_t[v]);
	if (it2 == st.begin())	it2 = st.end();
	else	it2--;
	if (it2 == st.end())	it2--;

	int a = mp[*it1], b = mp[*it2];
	int p = lca(a, b);
	sum -= depth[a] + depth[b] - depth[p] * 2;

	p = lca(a, v);
	sum += depth[a] + depth[v] - depth[p] * 2;

	p = lca(b, v);
	sum += depth[b] + depth[v] - depth[p] * 2;
	st.insert(s_t[v]);
}

void erase(int v){
	if (st.size() == 1){
		st.clear();
		return;
	}

	set<int>::iterator it1 = st.upper_bound(s_t[v]);
	if (it1 == st.end())	it1 = st.begin();

	set<int>::iterator it2 = st.upper_bound(s_t[v]);
	it2--;
	if (it2 == st.begin())	it2 = st.end();
	else	it2--;
	if (it2 == st.end())	it2--;

	int a = mp[*it1], b = mp[*it2];
	int p = lca(a, b);
	sum += depth[a] + depth[b] - depth[p] * 2;

	p = lca(a, v);
	sum -= depth[a] + depth[v] - depth[p] * 2;

	p = lca(b, v);
	sum -= depth[b] + depth[v] - depth[p] * 2;
	st.erase(s_t[v]);
}

int main(){
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n - 1; i++){
		int a, b;	scanf("%d%d", &a, &b);	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0, -1, 0);
	init();
	k = (k - 1) * 2;

	int b = 0, e = 0;
	while (b < n){
		while (e < n && sum <= k)
			add(e++);
		if (sum > k)
			erase(--e);
		ans = max(ans, e - b);
		erase(b++);
	}
	printf("%d\n", ans);
	return 0;
}