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

const int MAXN = 2e3 + 10;

int k, n[2], mp[2][MAXN];
vector<int> adj[2][MAXN];
int mn[2][MAXN];
int lca[2][MAXN][MAXN];
int depth[2][MAXN];

void plant(int v, int t, int de = 0){
	depth[t][v] = de;
	for (int u: adj[t][v]) {
		plant(u, t, de + 1);
		mn[t][v] = min(mn[t][v], mn[t][u]);
	}
	sort(adj[t][v].begin(), adj[t][v].end(), [t](int u, int v) {
			return mn[t][u] < mn[t][v];
			});
}

#define tm kljasdf

int st[2][MAXN], ft[2][MAXN], tm, sec[2][MAXN];

void dfs(int v, int t){
	sec[t][tm] = v;
	st[t][v] = tm++;
	for (int u: adj[t][v])
		dfs(u, t);
	ft[t][v] = tm;
}

void dfs2(int v, int t){
	for (int i = st[t][v]+1; i < ft[t][v]; i++)
		lca[t][v][sec[t][i]] = lca[t][sec[t][i]][v] = v;
	for (int i = 0; i < (int)adj[t][v].size(); i++)
		for (int j = i+1; j < (int)adj[t][v].size(); j++) {
			int u1 = adj[t][v][i];
			int u2 = adj[t][v][j];
			for (int ii = st[t][u1]; ii < ft[t][u1]; ii++)
				for (int jj = st[t][u2]; jj < ft[t][u2]; jj++) {
					int a = sec[t][ii];
					int b = sec[t][jj];
					lca[t][a][b] = lca[t][b][a] = v;
				}
		}
	for (int u: adj[t][v])
		dfs2(u, t);
}

int get(int t, int i, int j) {
	int u = mp[t][i];
	int v = mp[t][j];
	int p = lca[t][u][v];
	return depth[t][u] - depth[t][p];
}

int dp[2][MAXN][MAXN];
void solve() {
	cin >> k; k++;
	memset(mn, 63, sizeof(mn));
	for (int w = 0; w < 2; w++){
		cin >> n[w];
		for (int i = 1; i < n[w]; i++){
			int p; cin >> p, p--;
			adj[w][p].push_back(i);
		}
		for (int i = 1; i < k; i++) {
			cin >> mp[w][i], mp[w][i]--;
			mn[w][mp[w][i]] = i;
		}
	}
	mp[0][0] = mp[1][0] = 0;
	plant(0, 0);
	plant(0, 1);
	dfs(0, 0);
	tm = 0;
	dfs(0, 1);
	dfs2(0, 0);
	dfs2(0, 1);
	
	memset(dp, 63, sizeof(dp));
	dp[0][0][0] = 0;
	dp[1][0][0] = 0;
	dp[0][1][0] = get(0, 1, 0);
	dp[1][1][0] = get(1, 1, 0);
	for (int i = 1; i < k; i++)
		for (int j = 0; j <= i; j++)
			if (j < i-1) {
				dp[0][i][j] = dp[0][i-1][j] + get(0, i, i-1);
				dp[1][i][j] = dp[1][i-1][j] + get(1, i, i-1);
			}
			else if (j == i-1) {
				for (int w = 0; w < j; w++) {
					dp[0][i][j] = min(dp[0][i][j], dp[1][i-1][w] + get(0, i, w));
					dp[1][i][j] = min(dp[1][i][j], dp[0][i-1][w] + get(1, i, w));
				}
			}
			else {
				for (int w = 0; w < j; w++)
					if (w == i-1){
						dp[0][i][j] = min(dp[0][i][j], dp[0][i-1][i-1] + get(0, i, w));
						dp[1][i][j] = min(dp[1][i][j], dp[1][i-1][i-1] + get(1, i, w));
					}
					else{
						dp[0][i][j] = min(dp[0][i][j], dp[1][i-1][w] + get(0, i, w));
						dp[1][i][j] = min(dp[1][i][j], dp[0][i-1][w] + get(1, i, w));
					}
			}
	cout << (n[0] + n[1] - 2) - min({n[0]-1, n[1]-1, dp[0][k-1][k-1], dp[1][k-1][k-1]}) << "\n";
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