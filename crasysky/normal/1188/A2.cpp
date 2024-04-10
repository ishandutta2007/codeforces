#include <iostream>
#include <vector>
#include <cstdio>
#define Pr pair <int, int>
#define mp make_pair 
#define fi first
#define se second
using namespace std;
const int maxn = 1e6 + 6;
vector < Pr > G[maxn];
int out, m, d[maxn], ans[maxn][3], leaf[maxn][2];
void add_m(int u, int v, int d){
	ans[++ m][0] = u, ans[m][1] = v, ans[m][2] = d;
}
void add_link(int u, int l, int d){
	if (u == out){
		add_m(u, l, d);
		return;
	}
	int a = l, b = leaf[u][0] == l ? leaf[u][1] : leaf[u][0], c = out;	
	add_m(a, c, d / 2), add_m(a, b, d / 2), add_m(b, c, -d / 2);
}
void dfs(int u, int f, int l){
	if (G[u].size() == 1 && f){
		leaf[u][0] = u;
		return;
	}
	for (int i = 0; i < G[u].size(); ++ i){
		int v = G[u][i].fi;
		if (v != f){
			dfs(v, u, l);
			if (leaf[u][0])
				leaf[u][1] = leaf[v][0];
			else
				leaf[u][0] = leaf[v][0];
		}
	}
	for (int i = 0; i < G[u].size(); ++ i){
		int v = G[u][i].fi;
		if (v != f){
			int d = G[u][i].se;
			if (G[v].size() == 1)
				add_link(u, v, G[u][i].se);
			else{
				add_link(u, leaf[v][0], G[u][i].se);
				add_link(v, leaf[v][0], -G[u][i].se);
			}
		}
	}
}
int main(){
	int n;
	cin >> n;
	for (int i = 1; i < n; ++ i){
		int u, v, c;
		cin >> u >> v >> c;
		G[u].push_back(mp(v, c));
		G[v].push_back(mp(u, c));
		++ d[u], ++ d[v];
	}
	for (int i = 1; i <= n; ++ i)
		if (d[i] == 2){
			cout << "NO" << endl;
			return 0;
		}
	for (int i = 1; i <= n; ++ i)
		if (G[i].size() == 1){
			out = i, dfs(i, 0, i);
			break;
		}	
	cout << "YES" << endl;
	cout << m << endl;
	for (int i = 1; i <= m; ++ i)
		cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
}