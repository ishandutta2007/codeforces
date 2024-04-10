#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ss(x) (int) x.size()
 
using namespace std;

const int nax = 3e5 + 111;

int n, T, a, b;
vector <int> v[nax];
int dp[nax];
int res;
	
void dfs(int u, int p) {
	int p1 = 0;
	int p2 = 0;
	for(auto it : v[u]) {
		if(it == p)
			continue;
		
		dfs(it, u);
		if(dp[it] + 1 > p2)
			p2 = dp[it] + 1;
		if(p1 < p2)
			swap(p1, p2);
	}
	int root = (u != 1);
	int dzieci = ss(v[u]) - root;
	dp[u] = max(0, p1 + dzieci - 1);
	res = max({res, root + max(p1 + dzieci - 1, p1 + p2 + dzieci - 2)});
}
 
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
			v[i].clear();
		for(int i = 1; i < n; ++i) {
			scanf("%d %d", &a, &b);
			v[a].pb(b);
			v[b].pb(a);
		}
		for(int i = 1; i <= n; ++i)
			dp[i] = 0;
		
		res = 0;
		
		dfs(1, 0);
		
		printf("%d\n", res + 1);
	}
		
	
 
	return 0;
}