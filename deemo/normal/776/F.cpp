#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 5e5 + 10;

int n, m, comp[MAXN];
vector<pair<int, int>> adj[MAXN];
vector<int> G[MAXN];
bool vis[MAXN];
pair<pair<int, int>, int> mx[MAXN], ord[MAXN];
int sec[MAXN], gec[MAXN], sz, tt, ff;

void go(int u, pair<int, int> e, int de = 0){
	if (vis[e.S]) return;
	vis[e.S] = 1;
	gec[tt++] = e.F;
	sec[sz++] = e.S;
	int v = e.F, pos;
	if (de){
		pos = lower_bound(adj[v].begin(), adj[v].end(), make_pair(u, -1)) - adj[v].begin();
		if (pos == adj[v].size() || adj[v][pos].F != u){
			pos = adj[v].size() - 1;
			go(u, adj[v][pos], 1);
		}
		else{
			sec[sz++] = adj[v][pos].S;
			vis[sec[sz - 1]] = 1;
			return;
		}
	}
	else{
		pos = adj[v].size() - 1;
		go(u, adj[v][pos], 1);
	}
}

bitset<MAXN> mark;
int sub[MAXN], ans[MAXN];

void init(int u, int p = -1){
	sub[u] = 1;
	for (int v : G[u])
		if (!mark[v] && p != v)
			init(v, u), sub[u] += sub[v];
}

void solve(int u, int c){
	init(u);
	
	int r = u; bool found = true;
	while(found){
		found = false;
		for (int v : G[r])
			if (sub[v] > sub[u] / 2 && sub[v] < sub[r]){
				r = v;
				found = true;
				break;
			}
	}

	mark[r] = true; ans[r] = c;
	for (int v : G[r]) if (!mark[v])
		solve(v, c + 1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		int a = i, b = i+1;
		if (b == n) b = 0;
		adj[a].push_back({b, i<<1});
	}
	for (int i = n; i < n+m; i++){
		int a, b;	cin >> a >> b, a--, b--;
		adj[a].push_back({b, i<<1}), adj[b].push_back({a, i<<1^1});
	}
	for (int i = 0; i < n; i++) sort(adj[i].begin(), adj[i].end());
	for (int i = 0; i < n; i++)
		for (auto e:adj[i])
			if (!vis[e.S]){
				sz = tt = 0;
				gec[tt++] = i;
				go(i, e);
				sort(gec, gec + tt);
				tt = unique(gec, gec + tt) - gec;
				reverse(gec, gec + tt);
				for (int j = 0; j < sz; j++)
					mx[sec[j]] = {{gec[0], gec[1]}, gec[2]};
				ord[ff++] = mx[sec[0]];
			}
	sort(ord, ord + ff);
	ff = unique(ord, ord+ff) - ord;
	for (int i = 0; i < MAXN; i++)
		comp[i] = (lower_bound(ord, ord + ff, mx[i]) - ord);
	for (int i = n; i < n+m; i++)
		G[comp[i<<1]].push_back(comp[i<<1^1])
			, G[comp[i<<1^1]].push_back(comp[i<<1]);

	solve(0, 1);

	for (int i = 0; i < ff; i++)
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}