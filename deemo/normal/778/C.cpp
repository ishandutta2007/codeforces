#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAXN = 5e5 + 10;
const int C = 26;

int n, sub[MAXN], cc[MAXN], depth[MAXN], tot[MAXN];
vector<int> adj[MAXN];
int tr[MAXN][C], mk[MAXN][C], sz, root, gg;

void plant(int v){
	sub[v] = 1;
	for (int u:adj[v])
		plant(u), sub[v] += sub[u];
}

bool cmp(int u, int v){return sub[u] > sub[v];}

int tt;
pair<int, int> sec[MAXN];
void add(int v, int cur = root){
	for (int u:adj[v]){
		if (mk[cur][cc[u]] != gg)
			mk[cur][cc[u]] = gg, tr[cur][cc[u]] = ++sz, sec[tt++] = {cur, cc[u]};
		add(u, tr[cur][cc[u]]);
	}
}

void dfs(int v, int de = 0, bool type = 0){
	tot[de] += sub[v]-1;
	sort(adj[v].begin(), adj[v].end(), cmp);
	for (int i = 1; i < adj[v].size(); i++) dfs(adj[v][i], de+1);
	if (adj[v].size()){
		dfs(adj[v][0], de+1, 1);
	//	int prv = root;
	//	root = ++sz;
	//	tr[root][cc[adj[v][0]]] = prv;
		int tsz = sz; tt = 0;
		for (int i = 1; i < adj[v].size(); i++) add(adj[v][i]);
		depth[de] += sz;

		if (type){
			sz = tsz;
			for (int i = 0; i < tt; i++)
				mk[sec[i].F][sec[i].S] = gg-1;
			tt = 0;

			int prv = root;
			root = ++sz;
			mk[root][cc[adj[v][0]]] = gg;
			tr[root][cc[adj[v][0]]] = prv;

			int cur = root;
			for (int i = 1; i < adj[v].size(); i++){
				int u = adj[v][i];
				if (mk[cur][cc[u]] != gg)
					mk[cur][cc[u]] = gg, tr[cur][cc[u]] = ++sz, sec[tt++] = {cur, cc[u]};
				add(u, tr[cur][cc[u]]);
			}
		}
		else
			sz = root = 0, gg++;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int a, b; char c;	cin >> a >> b >> c, a--, b--;
		cc[b] = int(c - 'a');
		adj[a].push_back(b);
	}
	plant(0);
	gg++;
	dfs(0, 0, 1);

	int mx = -1;
	int ans = -1;
	for (int de = 0; de < MAXN; de++)
		if (mx < tot[de] - depth[de]){
			mx = tot[de] - depth[de];
			ans = de+1;
		}
	cout << n-mx << "\n";
	cout << ans << "\n";
	return 0;
}