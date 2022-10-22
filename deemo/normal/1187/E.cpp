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

const int MAXN = 2e5 + 10;

int n;
vector<int> adj[MAXN];
ll dn[MAXN], up[MAXN];
int sub[MAXN];

void dfsSub(int v, int p = -1){
	sub[v] = 1;
	for (int u: adj[v])
		if (u^p){
			dfsSub(u, v);
			sub[v] += sub[u];
		}
}

void dfsDown(int v, int p = -1) {
	dn[v] = sub[v];
	ll sm = 0;
	for (int u: adj[v])
		if (u^p){
			dfsDown(u, v);
			dn[v] += dn[u];
			up[u] += sm;
			sm += dn[u];
		}

	reverse(adj[v].begin(), adj[v].end());
	sm = 0;
	for (int u: adj[v])
		if (u^p){
			up[u] += sm;
			sm += dn[u];
			up[u] += n - sub[u];
		}
}

void dfsUp(int v, int p = -1){
	for (int u: adj[v])
		if (u^p){
			up[u] += up[v];
			dfsUp(u, v);
		}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfsSub(0);
	dfsDown(0);
	dfsUp(0);
	ll ans = 0;
	for (int v = 0; v < n; v++)
		ans = max(ans, dn[v] + up[v] + (n - sub[v]));
	cout << ans << "\n";
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