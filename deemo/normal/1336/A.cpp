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

int n, k;
vector<int> adj[MAXN];

int depth[MAXN], sub[MAXN];
void dfs(int v, int p = -1, int de = 0) {
	depth[v] = de;
	sub[v] = 1;
	for (int u: adj[v])
		if (u^p)
			dfs(u, v, de + 1), sub[v] += sub[u];
}

int sec[MAXN];
void solve() {
	cin >> n >> k;
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0);
	iota(sec, sec + n, 0);
	sort(sec, sec + n, [](int u, int v) {
			return depth[u] - sub[u] > depth[v] - sub[v];
			});

	ll ans = 0;
	for (int i = 0; i < k; i++) {
		int u = sec[i];
		ans += depth[u] - sub[u] + 1;
	}
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