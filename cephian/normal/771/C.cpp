#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 2e5+5;
int n,k,u,v;
ll dp[N][5];
ll ans = 0;
vvi T;

int dfs(int u, int v) {
	int subt_sz = 1;
	fill(dp[v],dp[v]+k,0);
	dp[v][0] = 1;
	for(int w : T[v]) {
		if(u == w) continue;
		subt_sz += dfs(v,w);
		for(int i = 0; i < k; ++i)
			for(int j = 0; j < k; ++j)
				ans += ((2*k-i-j-1)%k)*dp[v][i]*dp[w][j];
		for(int i = 0; i < k; ++i)
			dp[v][(i+1)%k] += dp[w][i];
	}
	ans += 1LL*subt_sz*(n-subt_sz);
	return subt_sz;
}

int main() {
	scanf("%d%d",&n,&k);
	T = vvi(n,vi());
	for(int i = 1; i < n; ++i) {
		scanf("%d%d",&u,&v);
		T[--u].push_back(--v);
		T[v].push_back(u);
	}
	dfs(-1,0);
	printf("%I64d\n",ans/k);
}