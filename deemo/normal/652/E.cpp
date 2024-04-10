//Mazra'e too khaabe..

#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

const int MAXN = 6e5 + 10;

int n, m, from[2 * MAXN], to[2 * MAXN], type[2 * MAXN], prv[2 * MAXN], head[MAXN], ec;
int depth[MAXN], col[MAXN], g;
bool vis[MAXN], ct[2 * MAXN], fnd[MAXN];
vector<pair<int, bool>>	adj[MAXN];

void add_edge(int u, int v, bool t){
	from[ec] = u, to[ec] = v, type[ec] = t, prv[ec] = head[u], head[u] = ec++;
	from[ec] = v, to[ec] = u, type[ec] = t, prv[ec] = head[v], head[v] = ec++;
}

int rmv_edge(int v = 0, int p = -1, int de = 0){
	int mn = de;
	depth[v] = de;
	vis[v] = 1;
	for (int e = head[v]; ~e; e = prv[e]){
		if (e == p)	continue;
		if (vis[to[e]])
			mn = min(mn, depth[to[e]]);
		else{
			int z = rmv_edge(to[e], e^1, de + 1);
			if (z > de)
				ct[e] = ct[e^1] = 1;
			mn = min(mn, z);
		}
	}
	return mn;
}

void f_comp(int v){
	vis[v] = 1;
	col[v] = g;
	for (int e = head[v]; ~e; e = prv[e])
		if (!ct[e]){
			fnd[g] |= type[e];
			if (!vis[to[e]])
				f_comp(to[e]);
		}
}

bool get(int v, int des, int p = -1, bool ff = 0){
	if (fnd[v])	ff = 1;
	if (v == des)	return	ff;
	for (auto u:adj[v])
		if (u.first ^ p && get(u.first, des, v, ff | u.second))	return	true;
	return	0;
}	

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(head, -1, sizeof(head));
	cin >> n >> m;
	while (m--){
		int a, b, c;	cin >> a >> b >> c, a--, b--;
		add_edge(a, b, c);
	}
	rmv_edge();
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++)
		if (!vis[i])	f_comp(i), g++;
	for (int e = 0; e < ec; e += 2)
		if (ct[e]){
			adj[col[from[e]]].push_back({col[to[e]], type[e]});
			adj[col[to[e]]].push_back({col[from[e]], type[e]});
		}
	int a, b;	cin >> a >> b, a--, b--;	a = col[a], b = col[b];
	if (get(a, b))
		cout << "YES\n";
	else
		cout << "NO\n";
	return	0;
}