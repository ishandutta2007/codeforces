#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e3 + 10;
const int MOD = 1e9 + 7;

int d, n, a[MAXN], dp[MAXN];
vector<int>	adj[MAXN];

bool valid(int z, int u){
	return (a[z] < a[u] || a[z] == a[u] && z < u) && a[u] <= a[z] + d;
}

int get(int v, int p, int z){
	dp[v] = 1;
	for (int u:adj[v])
		if (u^p && valid(z, u))
			dp[v] = (1ll * dp[v] * (1 + get(u, v, z))) % MOD;
	return dp[v];
}

int main(){
	cin >> d >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = (ans + get(i, -1, i)) % MOD;
	cout << ans << endl;
	return 0;
}