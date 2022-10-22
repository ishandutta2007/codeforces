#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cout << #x << " = " << x << endl
 
using namespace std;

const int nax = 2e5 + 111;

int n, a, b;
vector <int> v[nax];
int siz[nax];


ll best = 0;
ll sum = 0;
 
void dfs(int u, int p, int odl = 1) {
	siz[u] = 1;
	sum += odl;
	for(auto it : v[u]) {
		if(it != p) {
			dfs(it, u, odl + 1);
			siz[u] += siz[it];
		}
	}
} 

void solve(int u, int p, ll dis) {
	best = max(best, dis);
	for(auto it : v[u]) {
		if(it == p)
			continue;
		ll disx = dis + (n - siz[it]) - siz[it];
		solve(it, u, disx);
	}
}
 
int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		scanf("%d %d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1, 0);
	solve(1, 0, sum);
	printf("%lld\n", best);
	
	
	
 
	return 0;
}