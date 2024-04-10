#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 3e5 + 10;
const int N = 1e7;

int n, m, from[MAXN], to[MAXN];
vector<int> adj[MAXN], _adj[MAXN];
int q[MAXN], lv[MAXN], par[MAXN];
int comp[MAXN], g;
bool vis[MAXN];
int ans[MAXN], cnt[N], cc[MAXN], pp[MAXN];

void dfs(int v){
	if (vis[v]) return;
	vis[v] = 1;
	comp[v] = g;
	for (int u:_adj[v])
		dfs(u);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> from[i] >> to[i], from[i]--, to[i]--, adj[from[i]].push_back(to[i]), adj[to[i]].push_back(from[i]);

	memset(lv, 63, sizeof(lv));
	memset(par, -1, sizeof(par));
	int h = 0, t = 0;
	lv[0] = 0, q[t++] = 0;
	while (t-h){
		int v = q[h++];
		for (int u:adj[v])
			if (lv[v]+1 < lv[u]){
				lv[u] = lv[v] + 1;
				pp[u] = v;
				if (lv[u] == 1)
					par[u] = u;
				else
					par[u] = par[v];
				q[t++] = u;
			}
	}

	int c = 0;
	for (int v = 0; v < n; v++)
		if (lv[v] == 1) c++;

	for (int v = 0; v < n; v++)
		for (int u:adj[v])
			if (lv[u] == 1)
				cc[v]++;

	int XX = 1e6;
	for (int i = 0; i < n; i++)
		if (lv[i] == 1 && cc[i] == c-1 && adj[i].size() == cc[i]+1){
			vis[i] = 1;
			ans[i] = XX;
		}
	for (int i = 0; i < m; i++)
		if (min(from[i], to[i]))
			_adj[par[from[i]]].push_back(par[to[i]])
				, _adj[par[to[i]]].push_back(par[from[i]]);

	for (int i = 1; i < n; i++)
		if (lv[i] == 1 && !vis[i])
			g++, dfs(i);

	ans[0] = XX;
	for (int v = 1; v < n; v++){
		if (ans[v] > 0) continue;
		if (comp[par[v]] == 1)
			ans[v] = XX+lv[v];
		else
			ans[v] = XX-lv[v];
	}
	for (int v = 0; v < n; v++) cnt[ans[v]]++;

	for (int i = 0; i < m; i++)
		if (abs(ans[from[i]] - ans[to[i]]) > 1){
			cout << "NO\n";
			return 0;
		}

	for (int i = 0; i < n; i++){
		int c = cnt[ans[i]] + cnt[ans[i]-1] + cnt[ans[i]+1] - 1;
		if (c != adj[i].size()){
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
	for (int v = 0; v < n; v++)
		cout << ans[v] << " ";
	cout << "\n";
	return 0;
}