#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>
#include<cstring>

using namespace std;

const int MAXN = 1e5 + 10;

int n, s[MAXN], from[2 * MAXN], w[2 * MAXN], to[2 * MAXN], prv[2 * MAXN], head[MAXN], ec, cc, g, tg, lst[2] = {-1, -1};
bool col[MAXN], vis[MAXN];
set<pair<int, int>>	st[2];

void add_edge(int u, int v, int uv){
	from[ec] = u, to[ec] = v, w[ec] = uv, prv[ec] = head[u], head[u] = ec++;
	from[ec] = v, to[ec] = u, w[ec] = uv, prv[ec] = head[v], head[v] = ec++;
}

void dfs(int v){
	cc++;
	vis[v] = 1;
	lst[col[v]] = v;
	for (int e = head[v]; e != -1; e = prv[e])
		if (!vis[to[e]])	dfs(to[e]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	bool fl = 0;
	for (int i = 0; i < n; i++){
		cin >> col[i] >> s[i];
		if (s[i])	st[col[i]].insert({s[i], i});
		if (s[i])	fl = 1;
	}

	memset(head, -1, sizeof(head));
	while (st[0].size())
		for (bool x = 0; ; x = !x){
			if (st[x].begin()->first <= st[!x].begin()->first){
				int v = st[x].begin()->second, u = st[!x].begin()->second;
				st[x].erase(st[x].begin());
				st[!x].erase(st[!x].begin());
				add_edge(u, v, s[v]);
				s[u] -= s[v], s[v] = 0;
				if (s[u])
					st[!x].insert({s[u], u});
				break;
			}
			if (x)	break;
		}
	if (!fl){
		for (int i = 1; i < n; i++)
			if (col[0] != col[i])	add_edge(0, i, 0);
		int i = 0;
		for (; col[i] == col[0]; i++);
		for (int j = 1; j < n; j++)
			if (col[j] == col[0])	add_edge(j, i, 0);
	}
	else{
		for (int i = 0; i < n; i++)
			if (!vis[i]){
				cc = 0;
				dfs(i);
				if (cc > 1)	break;
				g++;
			}

		memset(vis, 0, sizeof(vis));
		tg = g;
		for (int i = 0; i < n; i++)
			if (!vis[i]){
				if (g != tg)
					add_edge(lst[!col[i]], i, 0);
				dfs(i), g++;
			}
	}	

	for (int i = 0; i < ec; i += 2)
		cout << from[i]+1 << " " << to[i]+1 << " " << w[i] << "\n";
	return 0;
}