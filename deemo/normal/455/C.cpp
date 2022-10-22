#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<numeric>
#include<utility>

using namespace std;

const int MAXN = 3e5 + 100;

int n, m, q;
int comp[MAXN];
int save[MAXN];
vector<int>	vec, adj[MAXN];
bool mark[MAXN];
int depth[MAXN];

int get_comp(int v){
	if (comp[v] == v)	
		return	v;
	return	
		comp[v] = get_comp(comp[v]);
}

void merge(int u, int v){
	if (get_comp(u) == get_comp(v))	return;
	
	int z = save[get_comp(u)], zz = save[get_comp(v)];
	save[get_comp(v)] = max(max(z, zz), z / 2 + bool(z % 2 == 1) + zz / 2 + bool(zz % 2 == 1) + 1);
	comp[get_comp(u)] = get_comp(v);
}

int dfs(int v, int de = 0){
	mark[v] = 1;
	vec.push_back(v);
	depth[v] = de;
	int ret = de;
	for (int u:adj[v])
		if (!mark[u])
			ret = max(ret, dfs(u, de + 1));
	return	ret;
}

int get(int r){
	vec.clear();
	dfs(r);

	int maxi = 0, ind = -1;
	for (int u:vec){
		if (maxi <= depth[u])
			maxi = depth[u], ind = u;
		mark[u] = 0;
		comp[u] = r;
	}
	return	dfs(ind);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	while (m--){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		if (!mark[i])
			save[i] = get(i);

	while (q--){
		int type;	cin >> type;
		if (type == 1){
			int v;	cin >> v;	v--;
			cout << save[get_comp(v)] << "\n";
		}
		else{
			int u, v;	cin >> u >> v;	v--, u--;
			merge(u, v);
		}
	}
	return 0;
}