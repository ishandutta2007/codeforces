#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>

using namespace std;

typedef long long ll;

const int max_n = 1e5 + 10;
const int LOG = 18;

int n, q;
int depth[max_n], s_t[max_n], f_t[max_n], sz;
ll level[max_n], ans;
int par[max_n][LOG + 2], mp[2 * max_n];
set<int>	st;
vector<pair<int, int>>	adj[max_n];

void dfs(int v, int p, int d, ll lv){
	mp[sz] = v;
	s_t[v] = sz++;
	depth[v] = d;
	level[v] = lv;
	par[v][0] = p;
	for (pair<int, int>	e:adj[v])
		if (e.first != p)
			dfs(e.first, v, d + 1, lv + e.second);
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
	if (u == v)	return	v;
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
	int a = mp[*it2], b = mp[*it1];

	int p = lca(a, b);
	ans -= level[a] + level[b] - level[p] * 2;
	
	p = lca(a, v);
	ans += level[a] + level[v] - level[p] * 2;

	p = lca(b, v);
	ans += level[b] + level[v] - level[p] * 2;
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
	int a = mp[*it2], b = mp[*it1];

	int p = lca(a, b);
	ans += level[a] + level[b] - level[p] * 2;
	
	p = lca(a, v);
	ans -= level[a] + level[v] - level[p] * 2;

	p = lca(b, v);
	ans -= level[b] + level[v] - level[p] * 2;
	st.erase(s_t[v]);

}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++){
		int a, b, c;	scanf("%d%d%d", &a, &b, &c);	a--, b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	dfs(0, -1, 0, 0);
	init();

	scanf("%d", &q);
	while (q--){
		char type;	scanf("%1s", &type);
		if (type == '?')
			printf("%I64d\n", ans/2);
		if (type == '+'){
			int v;	scanf("%d", &v);	v--;
			add(v);
		}
		if (type == '-'){
			int v;	scanf("%d", &v);	v--;
			erase(v);
		}
	}
	return 0;
}