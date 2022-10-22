#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<utility>

using namespace std;

const int MAXN = 1e5 + 10;

int n, sz[MAXN], ver[MAXN], de[MAXN], nxt[MAXN];
vector<int>	adj[MAXN], sec[MAXN];

void input(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

bool cmp(int u, int v){return	(int)adj[u].size() > (int)adj[v].size();}

void plant(int v, int p = -1){
	int cnt = 0;
	for (int u:adj[v])
		if (u != p)	cnt++, plant(u, v);

	sz[v] = cnt;
	for (int u:adj[v])
		if (u != p)
			sz[v] = max(sz[v], sz[u]);
}

bool solve(int v, int p = -1, int c = 2){
	sec[v].clear();
	for (int u:adj[v])
		if (u != p){
			if (sz[u] > 2)
				sec[v].push_back(u);
			else
				for (int w:adj[u])
					if (w != v && sz[w] > 1){
						sec[v].push_back(u);
						break;
					}
		}

	if (sec[v].size() > c)	return	false;
	for (int u:sec[v])
		if (!solve(u, v, 1))	return	false;
	return	true;
}

int main(){
	input();
	iota(ver, ver + n, 0);
	sort(ver, ver + n, cmp);

	plant(ver[0]);
	if (solve(ver[0]))
		cout << "Yes\n";
	else{
		int w = -1;
		for (int u:adj[ver[0]])	
			if (sz[u] > 1){
				w = u;
				break;
			}
		if (w != -1){
			plant(w);
			if (solve(w))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else cout << "No\n";
	}
	return	0;
}