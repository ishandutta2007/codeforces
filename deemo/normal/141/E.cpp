#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<numeric>

using namespace std;

typedef long long ll;

#define type second.first
#define num second.second
#define Edge pair<pair<int, int>, pair<char, int>>

const int max_n = 1e3 + 10;
const int max_m = 1e5 + 100;
const int LOG = 12;

int n, m, t1, t2;
int comp[max_n], par[max_n][LOG + 2];
int depth[max_n], par_num[max_n];
bool mark[max_m];
vector<pair<int, int>>	adj[max_n];
vector<Edge>	vec;

int get_comp(int v){
	if (comp[v] == v)	return	v;
	return	comp[v] = get_comp(comp[v]);
}

bool add(Edge e){
	pair<int, int> temp = e.first;
	if (get_comp(temp.first) == get_comp(temp.second))	return	false;
	adj[temp.first].push_back({temp.second, e.num});
	adj[temp.second].push_back({temp.first, e.num});
	comp[get_comp(temp.first)] = get_comp(temp.second);
	return	true;
}	

void dfs(int v, int p, int d){
	depth[v] = d;
	par[v][0] = p;
	for (pair<int, int> e:adj[v]){
		int u = e.first;
		if (u == p)	continue;
		par_num[u] = e.second;
		dfs(u, v, d + 1);
	}
}

void init(){
	for (int i = 1; i < LOG; i++)
		for (int j = 0; j < n; j++)
			if (par[j][i - 1] == -1)
				par[j][i] = -1;
			else	
				par[j][i] = par[par[j][i - 1]][i - 1];
}

int lca(int v, int u){
	if (depth[v] < depth[u])	swap(u, v);
	for (int i = LOG - 1; i >= 0; i--)
		if (depth[v] - (1 << i) >= depth[u])	v = par[v][i];
	if (v == u)	return	v;
	for (int i = LOG - 1; i >= 0; i--)
		if (par[v][i] != par[u][i])	v = par[v][i], u = par[u][i];
	return	par[v][0];
}	

void build(){
	par_num[0] = -1;
	dfs(0, -1, 0);
	init();
}

bool valid(Edge e, char needed){
	int v = e.first.first, u = e.first.second;
	int p = lca(u, v);
	while (v != p){
		if (vec[par_num[v]].type != needed){
			mark[par_num[v]] = 0;
			mark[e.num] = 1;
			adj[v].erase(find(adj[v].begin(), adj[v].end(), make_pair(par[v][0], par_num[v])));
			adj[par[v][0]].erase(find(adj[par[v][0]].begin(), adj[par[v][0]].end(), make_pair(v, par_num[v])));
			adj[v].push_back(make_pair(u, e.num));
			adj[u].push_back(make_pair(v, e.num));
			return true;
		}
		v = par[v][0];
	}
	while (u != p){
		if (vec[par_num[u]].type != needed){
			mark[par_num[u]] = 0;
			mark[e.num] = 1;
			adj[u].erase(find(adj[u].begin(), adj[u].end(), make_pair(par[u][0], par_num[u])));
			adj[par[u][0]].erase(find(adj[par[u][0]].begin(), adj[par[u][0]].end(), make_pair(u, par_num[u])));
			adj[v].push_back(make_pair(u, e.num));
			adj[u].push_back(make_pair(v, e.num));
			return	true;
		}
		u = par[u][0];
	}
	return	false;
}

int main(){
	scanf("%d%d", &n, &m);
	if (n % 2 == 0){
		printf("-1\n");
		return 0;
	}
	iota(comp, comp + n, 0);

	vec.resize(m);
	for (int i = 0; i < m; i++){
		int a, b;	char t;	scanf("%d %d %c", &a, &b, &t);	a--, b--;
		vec[i] = {{a, b}, {t, i}};
		if (add(vec[i])){
			mark[i] = 1;
			if (vec[i].type == 'S')	t1++;
			else	t2++;
		}
	}
	if (t1 + t2 < n - 1){
		printf("-1\n");
		return	0;
	}		
	build();
	char needed = t1 > t2 ? 'M': 'S';

	for (Edge e:vec){
		if (t1 == t2)	break;
		if (mark[e.num])	continue;
		if (e.type != needed)	continue;
		if (valid(e, needed)){
			if (needed == 'M')	t1--, t2++;
			else	t1++, t2--;
			build();
		}
	}
	if (t1 != t2){
		printf("-1\n");
		return 0;
	}
	printf("%d\n", n - 1);
	for (int i = 0; i < m; i++)
		if (mark[i])	printf("%d ", i + 1);
	printf("\n");
	return 0;
}