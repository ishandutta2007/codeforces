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

const int nax = 1e5 + 111;

int n, m, a, b;
vector <int> v[nax];
int cost[nax];
ld ans = 0;
int p[nax];
int ile[nax];
bool byl[nax];
int f[nax];

int find(int x) {
	if(x == p[x])
		return x;
	return p[x] = find(p[x]);
}

void unia(int x, int y) {
	x = find(x);
	y = find(y);
	if(x == y)
		return;
	p[x] = y;
	ile[y] += ile[x];
}

int main() {	
	scanf("%d%d", &n, &m);
	FOR(i, 1, n) {
		f[i] = i;
		scanf("%d", &cost[i]);
	}
	FOR(i, 1, m) {
		scanf("%d%d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	sort(f + 1, f + n + 1, [](int a, int b) {
		return cost[a] < cost[b];
	});
	FOR(i, 1, n) {
		p[i] = i;
		ile[i] = 1;
	}
	for(int i = n; 1 <= i; --i) {
		int u = f[i];
		for(auto it : v[u]) {
			if(!byl[it] || find(u) == find(it))
				continue;
			ans += (ll) ile[find(u)] * ile[find(it)] * cost[u];
			unia(u, it);
		}
		byl[u] = 1;
	}
	ans /= (ll) n * (n - 1);
	ans *= 2;
	printf("%.15Lf", ans);
	
	
	
	
	return 0;
}