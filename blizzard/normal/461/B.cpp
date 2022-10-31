#include <bits/stdc++.h> //sugoma 2

using namespace std;
#define ll long long
struct p {
    ll r, h, rh;
    ll i;
};
ll n2;
ll nt;
const long double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148;

vector<int> x;
const int MAXN = 1e5+7;
const int MOD = 1e9+7;
vector<int> e[MAXN];
long long dp[MAXN][2];
long long pref[MAXN];
long long suf[MAXN];

void dfs(int v) {
	int n = e[v].size();
	dp[v][0] = (x[v] == 0);
	dp[v][1] = 1 - dp[v][0];
	if (x[v] == 0) {
		for (int u : e[v]) {
			dfs(u);
			dp[v][1] = (dp[v][1] * (dp[u][0] + dp[u][1])) % MOD;
			dp[v][1] = (dp[v][1] + (dp[v][0] * dp[u][1])) % MOD;
			
			
			dp[v][0] = (dp[v][0] * (dp[u][0] + dp[u][1])) % MOD;
		}
	}
	if (x[v] == 1) {
		dp[v][0] = 0;
		dp[v][1] = 1;
		for (int u : e[v]) {
			dfs(u);
			dp[v][1] = (dp[v][1] * (dp[u][0] + dp[u][1])) % MOD;
		}
	}
	
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;

	for (int i = 1; i < n; i++) {
		int x; cin >> x;
		e[x].emplace_back(i);
	}
	x.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	
	dfs(0);
	cout << dp[0][1] << endl;
	/*for (int i = 0; i < n; i++) {
		cerr << i << ": " << dp[i][0] << " " << dp[i][1] << endl;
	}*/
}