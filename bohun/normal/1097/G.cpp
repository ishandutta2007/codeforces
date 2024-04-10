#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
  
using namespace std;				

const int nax = 1e5 + 11;
const int K = 211;
const int mod = 1e9 + 7;

int n, a, b, k;
vector <int> v[nax];
int siz[nax];
int dp[nax][K];
int dp2[K];
int ans[K];
int com[2][K];

void add(int &a, int b) {
	a += b;
	if(a >= mod)
		a -= mod;
}

void sub(int &a, int b) {
	a -= b;
	if(a < 0)
		a += mod;
}
	

void dfs(int u, int p) {
	siz[u] = 1;
	dp[u][0] = 2;
	for(auto it : v[u]) {
		if(it == p)
			continue;
		dfs(it, u);
		
		for(int ja = 0; ja <= min(k, siz[u]); ++ja) {
			dp2[ja] = dp[u][ja];
			dp[u][ja] = 0;
		}
		
		for(int ja = 0; ja <= min(k, siz[u]); ++ja)
			for(int on = 0; on <= siz[it] && on + ja <= k; ++on) 
				add(dp[u][ja + on], (ll) dp2[ja] * (dp[it][on] + (on > 0 ? dp[it][on - 1] : 0) - (on == 1)) % mod);
		
		siz[u] += siz[it];
	}
	
	for(int i = 1; i <= k; ++i) {
		int sum = dp[u][i];
		for(auto it : v[u]) {
			if(it == p)
				continue;
			sub(sum, (dp[it][i] + dp[it][i - 1] - (i == 1)) % mod);
		}
		add(ans[i], sum);
	}
}			
	
int res = 0;			

int main() {
	scanf("%d%d", &n, &k);
	FOR(i, 1, n - 1) {
		scanf("%d %d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1, 0);
	FOR(i, 1, k) {
		FOR(j, 0, 1)
			FOR(g, 0, k)
				com[j][g] = 0;
		com[0][0] = 1;
		FOR(j, 1, k) {
			a = (j & 1);
			b = !a;
			FOR(g, 0, i)
				com[a][g] = 0;
			FOR(g, 1, i)
				com[a][g] = ((ll) com[b][g] * g % mod + (ll) com[b][g - 1] * (i - g + 1) % mod) % mod;
		}
		add(res, (ll) ans[i] * com[(k & 1)][i] % mod);
	}
	printf("%d", res);
		
		
		
		
		
		
	return 0;
}