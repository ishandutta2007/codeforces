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

const int MAXN = 3e5 + 10;

int n, dp[MAXN], ans;
vector<int> adj[MAXN];

void dfs(int v, int p = -1){
	dp[v] = (int)adj[v].size() - 1;
	vector<int> vec;
	for (int u: adj[v])
		if (u^p){
			dfs(u, v);
			dp[v] = max(dp[v], (int)adj[v].size() - 1 + dp[u]);
			vec.push_back(dp[u]);
		}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	ans = max(ans, dp[v] + 2);
	if (vec.size() >= 2) {
		ans = max(ans, vec[0] + vec[1] + (int)adj[v].size() - 1 + 2);	
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) adj[i].clear();
	for (int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ans = 0;
	dfs(0);
	cout << ans << "\n";
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