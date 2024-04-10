#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e6 + 10;

int n, k, m;
int from[MAXN], to[MAXN], w[MAXN], sec[MAXN], par[MAXN];
vector<int> vec[MAXN], adj[MAXN];
set<pii> st[MAXN];
ll ans = 0;

bool cmp(int u, int v){return w[u] < w[v];}
int getPar(int v){return par[v]==v? v: par[v] = getPar(par[v]);}

void dfs(int v, int p = -1){
	int mx = -1;
	for (int e:adj[v])
		if (e^p){
			int u = from[e]^to[e]^v;
			dfs(u, e);
			mx = max(mx, (int)st[u].size());
		}
	for (int e:adj[v])
		if (e^p){
			int u = from[e]^to[e]^v;
			if ((int)st[u].size() == mx){
				st[v].swap(st[u]);
				mx = u;
				break;
			}
		}

	for (int e:adj[v])
		if (e^p){
			int u = from[e]^to[e]^v;
			if (u == mx) continue;

			for (auto x:st[u]){
				if (st[v].count(x))
					st[v].erase(x);
				else
					st[v].insert(x);
			}
			st[u].clear();
		}

	for (int e:vec[v]){
		pii x(w[e], e);
		if (st[v].count(x))
			st[v].erase(x);
		else
			st[v].insert(x);
	}

	if (p != -1 && p < k){
		if (st[v].empty()){
			cout << "-1\n";
			exit(0);
		}
		ans += st[v].begin()->F;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> m;
	m += k;
	for (int i = 0; i < k; i++)
		cin >> from[i] >> to[i], from[i]--, to[i]--;
	for (int i = k; i < m; i++)
		cin >> from[i] >> to[i] >> w[i], from[i]--, to[i]--;
	iota(sec, sec + m, 0);
	sort(sec + k, sec + m, cmp);
	iota(par, par + n, 0);
	for (int i = 0; i < m; i++){
		int e = sec[i];
		int u = getPar(from[e]), v = getPar(to[e]);
		if (u == v) {
			vec[from[e]].push_back(e);
			vec[to[e]].push_back(e);
			continue;
		}

		par[u] = v;
		adj[from[e]].push_back(e);
		adj[to[e]].push_back(e);
	}
	dfs(0);

	cout << ans << "\n";
	return 0;
}