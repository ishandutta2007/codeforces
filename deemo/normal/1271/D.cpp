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

const int MAXN = 5e3 + 10;
const ll INF = 1e18;

int n, m, k, a[MAXN], b[MAXN], c[MAXN];
vector<int> adj[MAXN];
int mx[MAXN];
ll dp[2][MAXN];

void solve() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i];
	iota(mx, mx + n, 0);
	while (m--){
		int u, v; cin >> u >> v, u--, v--;
		mx[v] = max(mx[v], u);
	}
	for (int v = 0; v < n; v++)
		adj[mx[v]].push_back(v);
	for (int v = 0; v < n; v++)
		sort(adj[v].begin(), adj[v].end(), [](int u, int v){
				return c[u] > c[v];
			});

	memset(dp, -20, sizeof(dp));
	int cur = 0;
	dp[cur][k] = 0;
	for (int i = 0; i < n; i++, cur = !cur){
		memset(dp[!cur], -20, sizeof(dp[!cur]));
		for (int t = a[i]; t < MAXN; t++)
			if (dp[cur][t] >= 0) {
				int rem = t + b[i];
				dp[!cur][rem] = max(dp[!cur][rem], dp[cur][t]);
				ll sm = 0;
				for (int v: adj[i]) {
					sm += c[v];
					rem--;
					if (rem < 0) break;
					dp[!cur][rem] = max(dp[!cur][rem], dp[cur][t] + sm);
				}
			}
	}

	ll ans = -1;
	for (int i = 0; i < MAXN; i++)
		ans = max(ans, dp[cur][i]);
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