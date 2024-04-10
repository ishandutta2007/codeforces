#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;	

const int nax = 3e5 + 111;

int n;
int cost[nax];
int a, b;
vector <int> v[nax];
ll dp[nax];
ll best = -1e18;

void dfs(int u, int p) {
	dp[u] = cost[u];
	for(auto it : v[u]) {
		if(it != p) {
			dfs(it, u);
			dp[u] += max(0ll, dp[it]);
		}
	}
	if(best < dp[u]) 
		best = dp[u];
}

ll h[nax];
int ile;
	
void solve(int u, int p) {
	h[u] = cost[u];
	for(auto it : v[u]) {
		if(it != p) {
			solve(it, u);
			h[u] += max(0ll, h[it]);
		}
	}
	if(h[u] == best) {
		h[u] = 0;
		ile++;
	}
}
			
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", cost + i);
	for(int i = 1; i < n; ++i) {
		scanf("%d %d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1, 0);
	solve(1, 0);	
	printf("%lld %d", best * ile, ile);
	
	return 0;
}