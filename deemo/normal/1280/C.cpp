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

int n;
vector<pii> adj[MAXN];
int par[MAXN], sub[MAXN], parW[MAXN];

void dfs(int v, int p = -1, int pw = 0){
	par[v] = p;
	sub[v] = 1;
	parW[v] = pw;
	for (auto e: adj[v])
		if (e.F^p)
			dfs(e.F, v, e.S), sub[v] += sub[e.F];
}

void solve() {
	cin >> n; n *= 2;
	for (int i = 0; i < n; i++) adj[i].clear();
	for (int i = 0; i < n-1; i++){
		int a, b, c; cin >> a >> b >> c, a--, b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	dfs(0);
	ll mn = 0, mx = 0;
	for (int v = 0; v < n; v++)
		if (par[v] != -1){
			mn += (sub[v]&1) * parW[v];
			mx += 1ll*min(sub[v], n-sub[v]) * parW[v];
		}
	cout << mn << "  " << mx << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}