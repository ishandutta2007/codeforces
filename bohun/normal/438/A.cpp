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

int n, m;
int a, b;
int deg[1001];
int cost[1001];
vector <int> v[1001];
int f[1001];
ll ans = 0;

int main() {	
	scanf("%d%d", &n, &m);
	FOR(i, 1, n) {
		scanf("%d", &cost[i]);
		f[i] = i;
	}
	FOR(i, 1, m) {
		scanf("%d%d", &a, &b);
		deg[a] += 1;
		deg[b] += 1;
		v[a].pb(b);
		v[b].pb(a);
	}
	FOR(i, 1, n) {
		for(auto it : v[i])
			ans += cost[it];
	}
	sort(f + 1, f + n + 1, [](int a, int b) {
		return cost[a] < cost[b];
	});
	for(int i = n; 1 <= i; --i) {
		ans -= deg[f[i]] * cost[f[i]];
		for(auto it : v[f[i]]) 
			deg[it] -= 1;
	}
	
	cout << ans;
		
	
	
	
	
	return 0;
}