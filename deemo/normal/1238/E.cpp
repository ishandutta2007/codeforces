#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int C = 20;//XXX

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

const int MAXN = 1e5 + 10;

int n, cnt[C][C], dp[1<<C], cost[1<<C], m;
string s;

void solve() {
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i + 1 < n; i++)
		cnt[s[i]-'a'][s[i+1]-'a']++;

	for (int mask = 1; mask < 1<<m; mask++){
		int v = __builtin_ctz(mask&-mask);
		cost[mask] = cost[mask^1<<v];
		for (int u = 0; u < m; u++)
			if (u^v){
				if (mask>>u&1)
					cost[mask] -= cnt[v][u] + cnt[u][v];
				else
					cost[mask] += cnt[v][u] + cnt[u][v];
			}
	}

	for (int mask = 1; mask < 1<<m; mask++) {
		int mn = 1e9;
		for (int v = 0; v < m; v++)
			if (mask>>v&1)
				mn = min(mn, dp[mask^1<<v]);
		dp[mask] = mn + cost[mask];
	}
	cout << dp[(1<<m)-1] << "\n";
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