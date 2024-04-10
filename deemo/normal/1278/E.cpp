#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int C = 26;//XXX

void add(int &x, int y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}

int fix(int x){
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}

int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}

const int MAXN = 1e6 + 10;

int n, sub[MAXN];
pii ans[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p = -1){
	sub[v] = 1;
	if (p != -1)
		adj[v].erase(find(adj[v].begin(), adj[v].end(), p));
	for (int u: adj[v]){
		dfs(u, v);
		sub[v] += sub[u];
	}
}

void go(int v, int childL, int childR, int subL, int subR, int p = -1){
	for (int u: adj[v]){
		if (u == p) continue;
		int req = sub[u]*2 - 1;
		ans[u].F = childL;
		ans[u].S = subR - req + (int)adj[u].size() + 1;
		go(u, ans[u].S - (int)adj[u].size(), ans[u].S-1, ans[u].S+1, subR, v);
		childL++;
		subR -= req;
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0);
	ans[0] = {1, 2 + adj[0].size()};
	go(0, ans[0].F+1, ans[0].S-1, ans[0].S+1, 2*n);

	for (int i = 0; i < n; i++)
		cout << ans[i].F << " " << ans[i].S << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}