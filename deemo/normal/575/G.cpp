//Without the mask, Where will you hide?

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

const int MAXN = 1e5 + 10;
const int INF = 1e9 + 2;

int n, m, lv[MAXN], q[MAXN], par[MAXN], mn = INF, p[MAXN];
bool mark[MAXN], vis[MAXN];
vector<pair<int, int>>	adj[MAXN];
vector<int>	vec, out;
string ans = "";

void dfs(int v){
	if (vis[v])	return;
	vis[v] = 1;
	if (lv[v] < mn){
		vec.clear();
		vec.push_back(v);
		mn = lv[v];
	}
	else if (mn == lv[v])	vec.push_back(v);

	for (pair<int, int>	e:adj[v])
		if (e.second == 0)	dfs(e.first);
}

void bfs(int r){
	fill(lv, lv + MAXN, INF);
	lv[r] = 0;
	int h = 0, t = 0;
	q[t++] = r;
	while (h < t){
		int v = q[h++];
		for (pair<int, int>	e:adj[v])
			if (lv[e.first] > lv[v] + 1){
				lv[e.first] = lv[v] + 1;
				q[t++] = e.first;
			}
	}

	dfs(n - 1);
}

void bfs2(){
	int h = 0, t = 0;
	for (int v:vec)	par[v] = -1, q[t++] = v;
	while (h < t){
		int sz = t - h, mini = 20;
		for (int i = h; i < t; i++){
			int v = q[i];
			for (pair<int, int>	e:adj[v]){
				if (lv[e.first] + 1 == lv[v])
					mini = min(mini, e.second);
			}
		}

		if (mini != 20 && (mini != 0 || (int)ans.size() != 0))
			ans += char(mini + '0');

		for (int i = h; i < h + sz; i++){
			int v = q[i];
			for (pair<int, int>	e:adj[v])
				if (e.second == mini && lv[e.first] + 1 == lv[v])
					if (!mark[e.first]){
						mark[e.first] = 1;
						q[t++] = e.first;
						par[e.first] = v;
					}
		}
		h += sz;
	}
}

void show2(int v){
	if (p[v] == -1)	return;
	show2(p[v]);
	out.push_back(v);
}

void show(int v){
	out.push_back(v);
	if (par[v] == -1){
		if (v != n - 1){
			int h = 0, t = 0;
			q[t++] = v;
			fill(lv, lv + MAXN, INF);
			p[v] = -1, lv[v] = 0;
			while (h < t){
				int u = q[h++];
				for (pair<int, int>	e:adj[u])
					if (e.second == 0 && lv[e.first] > lv[u] + 1){
						lv[e.first] = lv[u] + 1;
						q[t++] = e.first;
						p[e.first] = u;
					}
			}
			show2(n - 1);
		}
		return;
	}
	show(par[v]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	while (m--){
		int a, b, c;	cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});//Can't find yourself.. Lost in your Lie!!!
	}
	bfs(0);
	bfs2();

	if ((int)ans.size() == 0)	ans = "0";
	cout << ans << "\n";
	show(0);
	cout << (int)out.size() << "\n";
	for (int v:out)
		cout << v << " ";
	cout << "\n";
	return	0;	
}