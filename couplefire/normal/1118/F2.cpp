#include <bits/stdc++.h>
#define int long long
using namespace std; 

const int N = 3e5 + 100, M = 998244353;
typedef pair <int, int> pii;
int a[N], pr[N], h[N], dp[N][4], n, k;
set <pii> st[N];
vector <int> v[N], g[N];

void dfs(int x) {
	h[x] = h[pr[x]] + 1;
	for(auto u : v[x]) {
		if(u == pr[x])
			continue;
		pr[u] = x;
		dfs(u);
	}
}

void get(int x) {
	dp[x][0] = 1;
	for(auto u : g[x]) {
		if(u == pr[x])
			continue;
		pr[u] = x;
		get(u);
		dp[x][1] = (dp[x][1] * (dp[u][0] + dp[u][1]) + dp[x][0] * dp[u][1]) % M;
		dp[x][0] = (dp[x][0] * (dp[u][0] + dp[u][1])) % M;
	}
	if(x <= k)
		dp[x][1] = dp[x][0], dp[x][0] = 0; 
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) 
    	cin >> a[i];
    for(int i = 1; i < n; i++) {
    	int x, y;
    	cin >> x >> y;
    	v[x].push_back(y);
    	v[y].push_back(x);
	}
	dfs(1);
	for(int i = 1; i <= n; i++) 
		if(a[i])
			st[a[i]].insert({-h[i], i});
	for(int i = 1; i <= k; i++) {
		while((int)st[i].size() > 1) {
			pii p = *st[i].begin();
			st[i].erase(p);
			if(a[pr[p.second]] == 0) {
				a[pr[p.second]] = a[p.second];
				st[i].insert({-h[pr[p.second]], pr[p.second]});
			}
			else if(a[pr[p.second]] != a[p.second])
				return cout << 0, 0;
		}
	}
	int h = k + 1;
	for(int i = 1; i <= n; i++) {
		if(!a[i])
			a[i] = h++;
	}
	for(int i = 1; i <= n; i++) {
		for(auto u : v[i]) {
			if(u == pr[i] || a[i] == a[u])
				continue;
			g[a[i]].push_back(a[u]);
			g[a[u]].push_back(a[i]);
		}
	}
	memset(pr, 0, sizeof(pr));
	get(1);
	cout << dp[1][1] << endl;
}