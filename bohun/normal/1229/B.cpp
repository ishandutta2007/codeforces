#pragma GCC optimize("O3")
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

const int nax = 1e5 + 111, LOG = 16;
const int mod = 1e9 + 7;

int n, a, b;
vector <int> v[nax];
ll cost[nax];
int h[nax];
int jump[nax][LOG + 1];
ll g[nax][LOG + 1];

void dfs(int u, int p) {
	h[u] = h[p] + 1;
	jump[u][0] = p;
	g[u][0] = cost[u];
	for(auto it : v[u]) 
		if(it != p)
			dfs(it, u);
}

int main() {
	scanf("%d", &n);
	FOR(i, 1, n)
		scanf("%lld", &cost[i]);
	FOR(i, 1, n - 1) {
		scanf("%d%d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1, 0);
	ll res = 0;
	
	FOR(j, 1, LOG)
		FOR(i, 1, n) {
			jump[i][j] = jump[jump[i][j - 1]][j - 1];
			g[i][j] = __gcd(g[i][j - 1], g[jump[i][j - 1]][j - 1]);
		}
	
	FOR(i, 1, n) {
		ll val = cost[i];
		int ver = i;
		while(ver > 0) {
			int sum = 0;
			for(int j = LOG; 0 <= j; --j) {
				if(h[ver] >= (1 << j) && __gcd(val, g[ver][j]) == val) {
					sum += (1 << j);
					ver = jump[ver][j];
				}
			}	
		//	cout << ver << " " << sum << " " << val << endl;
			res += (ll) sum * (val % mod) % mod;
			res %= mod;
			val = __gcd(val, cost[ver]);
		}
		//return 0;
	}
	cout << res;
			
					
			
		
	
	
	
		
	
	
	
	return 0;
}