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
const int nax = 41;

int n, m;
int t[nax][nax];
int a, b;
vector <int> v[nax];
ll ans = 0;
bool odw[nax];
int col[nax];
bool ok = 1;
int maska[nax];
int dp[(1 << 20)];
int gr[nax];

void dfs(int u, int p) {
	col[u] = !col[p];
	odw[u] = 1;
	for(auto it : v[u]) {
		if(odw[it] == 0)
			dfs(it, u);
		if(col[u] == col[it])
			ok = 0;
	}
}
			

int main() {	
	scanf("%d %d", &n, &m);
	FOR(i, 1, m) {
		scanf("%d%d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	
	if(m == 0) 
		ans -= (1LL << n);
	int alone = 0;
	FOR(i, 1, n)
		alone += (ss(v[i]) == 0);
	ans += (1LL << (alone + 1));
	
	int com = 0;
	
	FOR(i, 1, n)
		if(!odw[i]) {
			com += 1;
			dfs(i, 0);
		}
	if(ok) {
		ans += (1LL << com);
	}
	
	ans += (1LL << n);
	ans -= (1LL << com);
	
	//printf("%lld\n", ans);
	
	int x = (n + 1) / 2;
	int y = n - x;
	
	FOR(i, 1, x) {
		for(auto it : v[i]) {
			if(it <= x) {
				int u = it - 1;
				maska[i] |= (1 << u);
			}
		}
	}
	
	FOR(i, x + 1, n) {
		for(auto it : v[i]) {
			if(it > x) {
				int u = it - x - 1;
				maska[i] |= (1 << u);
			}
		}
	}
	
	FOR(mas, 0, (1 << y) - 1) {
		int M = 0;
		FOR(i, 0, y - 1) {
			if((1 << i) & mas)
			M |= maska[i + x + 1];
		}
		if((M & mas) > 0)
			continue;
		dp[mas] += 1;
	}

	FOR(i, 0, 19) 
		FOR(mas, 0, (1 << y) - 1)
			if((1 << i) & mas)
				dp[mas] += dp[mas ^ (1 << i)];
				
	FOR(i, 1, x) {
		for(auto it : v[i]) {
			if(it > x) {
				int u = it - x - 1;
				gr[i] |= (1 << u);
			}
		}
	}
	
	FOR(mas, 0, (1 << x) - 1) {
		int M = 0;
		FOR(i, 0, x - 1)
			if((1 << i) & mas)
				M |= maska[i + 1];
		if((M & mas) > 0)
			continue;
		M = 0;
		FOR(i, 0, x - 1)
			if((1 << i) & mas)
				M |= gr[i + 1];
		int full = (1 << y) - 1;
		full ^= M;
		ans -= 2LL * dp[full];
	}
	
	printf("%lld", ans);
			
	
	
	
	
	
	return 0;
}