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

const int MAXN = 3e3 + 10;
const ll INF = 1e18;

int n, k, sm[MAXN];
vector<int> adj[MAXN];
pair<int, ll> dp[2][MAXN][MAXN];

int getReal(pair<int, ll> p){
	return p.S > 0? p.F: p.F-1;
}

void smax(pair<int, ll> &a, pair<int, ll> b){a = max(a, b);}

int sub[MAXN];
pair<int, ll> sec[2][MAXN];
void dfs(int v, int p = -1){
	for (int i = 0; i <= k; i++)
		dp[0][v][i] = {0, -INF}, dp[1][v][i] = {1, -INF};
	dp[0][v][1] = {0, sm[v]};
	dp[1][v][1] = {1, sm[v]};
	sub[v] = 1;
	for (int u: adj[v])
		if (u^p){
			dfs(u, v);
			for (int i = 0; i <= sub[u] + sub[v] && i <= k; i++)
				sec[0][i] = {0, -INF}, sec[1][i] = {1, -INF};

			for (int a = 1; a <= sub[v]; a++)
				for (int b = 1; b <= sub[u] && a+b-1 <=k; b++)
					for (int aa = 0; aa < 2; aa++)
						for (int bb = 0; bb < 2; bb++){
							//0
							smax(sec[aa][a+b], {dp[aa][v][a].F + (bb? getReal(dp[bb][u][b]): dp[bb][u][b].F), dp[aa][v][a].S});
							//1
							smax(sec[aa][a+b-1], {dp[aa][v][a].F + (dp[bb][u][b].F - bb), dp[aa][v][a].S + dp[bb][u][b].S});
						}

			sub[v] += sub[u];
			for (int i = 0; i <= sub[v] && i <= k; i++)
				dp[0][v][i] = sec[0][i], dp[1][v][i] = sec[1][i];
		}
	//if (v == 0)
	//	cout << dp[1][v][3].F << "   " << dp[1][v][3].S << endl;
}

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> sm[i], sm[i] *= -1;
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		sm[i] += x;
	}
	for (int i = 0; i < n; i++) adj[i].clear();
	for (int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0);
	cout << max(dp[0][0][k].F, getReal(dp[1][0][k])) << "\n";
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