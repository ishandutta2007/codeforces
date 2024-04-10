#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

ll n, m, from[MAXN], to[MAXN], w[MAXN], sum[MAXN];
vector<int> adj[MAXN];
int col[MAXN];
int root = -1;
int sec[MAXN], sz;
int tv = -1;

void dfs(int v, int c = 1, int p = -1){
	if (col[v]) {
		if (col[v] != c){
			root = v;
			sec[sz++] = p;
			tv = v;
		}
		return;
	}
	col[v] = c;

	for (int e:adj[v]){
		int u = from[e]^to[e]^v;
		dfs(u, 3-c, e);
		if (root != -1) {
			if (v == tv)
				tv = -1;
			if (tv != -1)
				sec[sz++] = p;
			return;
		}
	}
}

int par[MAXN], q[MAXN], h, t, cnt[MAXN];
void dfs2(int v, int p = -1){
	col[v] = 1;
	par[v] = p;

	for (int e:adj[v])
		if (e^p){
			int u = from[e]^to[e]^v;
			if (!col[u]) {
				dfs2(u, e);
				cnt[v]++;
			}
		}

	if (!cnt[v])
		q[t++] = v;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> sum[i];
	for (int i = 0; i < m; i++){
		cin >> from[i] >> to[i], from[i]--, to[i]--;
		adj[from[i]].push_back(i);
		adj[to[i]].push_back(i);
		w[i] = 1;
		sum[from[i]] -= 1;
		sum[to[i]] -= 1;
	}
	dfs(0);
	if (root == -1)
		root = 0;

	memset(col, 0, sizeof(col));
	dfs2(root);
	while (t-h){
		int v = q[h++];
		if (v == root) break;

		w[par[v]] += sum[v];
		int p = from[par[v]]^to[par[v]]^v;
		sum[p] -= sum[v];
		sum[v] = 0;

		cnt[p]--;
		if (cnt[p] == 0)
			q[t++] = p;
	}

	if (sum[root] == 0){
		cout << "YES\n";
		for (int i = 0; i < m; i++)
			cout << w[i] << "\n";
	}
	else{
		if (sz == 0)
			cout << "NO\n";
		else{
			assert((sum[root]&1) == 0);
			for (int i = 0; i < sz; i++)
				w[sec[i]] += (i&1?-sum[root]/2:sum[root]/2);
			cout << "YES\n";
			for (int i = 0; i < m; i++)
				cout << w[i] << "\n";
		}
	}
	return 0;
}