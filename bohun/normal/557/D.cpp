#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl

using namespace std;

int n, m;
int a, b;
vector <int> v[100001];
int odw[100001];
bool ok = 0;
int h[100001];
int maks = 0;
int siz[3];
int z = 0;

void dfs(int u) {
	z += 1;
	odw[u] = 1;
	for(auto it : v[u]) {
		if(odw[it] && h[u] % 2 == h[it] % 2)
			ok = 1;
		if(!odw[it]) {
			h[it] = h[u] + 1;
			dfs(it);
		}
	}
}

int d[2];
ll ans = 0;

void solve(int u) {
	odw[u] = 1;
	ans += d[h[u] % 2];
	d[h[u] % 2] += 1;
	for(auto it : v[u]) 
		if(!odw[it]) {
			h[it] = h[u] + 1;
			solve(it);
		}
}
	
	
 
int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		scanf("%d %d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	
	for(int i = 1; i <= n; ++i) 
		if(!odw[i]) {
			z = 0;
			dfs(i);
			maks = max(maks, z);
			if(z <= 2)
				siz[z] += 1;
		}
	if(ok) 
		return printf("0 1"), 0;
	if(m == 0) 
		return printf("3 %lld", 1ll * n * (n - 1) * (n - 2) / 6), 0;
	if(maks == 2) {
		ans = 1ll * siz[2] * (n - 2);
		return printf("2 %lld", ans), 0;
	}
	for(int i = 1; i <= n; ++i)
		odw[i] = h[i] = 0;
	for(int i = 1; i <= n; ++i)
		if(!odw[i]) {
			d[0] = d[1] = 0;
			solve(i);
		}
	printf("1 %lld", ans);
	
	
	
	return 0;
}