#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast", "no-stack-protector")
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7;

int a[N];
ll ans[N];
vi G[N];

gp_hash_table<int, int> dfs(int u, int p = 0) {
	gp_hash_table<int, int> ret;
	ret[a[u]]++;
	ans[a[u]]++;
	for(int v:G[u]) if(v != p) {
		gp_hash_table<int, int> tmp = dfs(v, u);
		for(pi p:tmp) {
			for(pi pp:ret) {
				ans[__gcd(p.F, pp.F)] += (ll) p.S * pp.S;
			}
		}
		for(pi p:tmp) {
			ret[__gcd(p.F, a[u])] += p.S;
		}
	}
	return ret;
}

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=0;i<n-1;i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	mt19937 rng(time(0));
	for(int i=1;i<=n;i++) {
		shuffle(ALL(G[i]), rng);
	}
	dfs(1);
	for(int i=1;i<=200000;i++) {
		if(ans[i]) cout << i << " " <<ans[i] << endl;
	}
}