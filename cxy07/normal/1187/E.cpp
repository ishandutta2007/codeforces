//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const int mod = 1e9 + 7;

int n,ans;
int siz[MAXN],dp[MAXN];
vector<int> G[MAXN];

void DFS1(int x,int fa) {
	siz[x] = 1;
	for(register int i = 0,to;i < G[x].size(); ++i) {
		to = G[x][i];
		if(to == fa) continue;
		DFS1(to,x);
		siz[x] += siz[to];
	}
	dp[1] += siz[x];
}

void DFS2(int x,int fa) {
	ans = max(ans,dp[x]);
	for(register int i = 0,to;i < G[x].size(); ++i) {
		to = G[x][i];
		if(to == fa) continue;
		dp[to] = dp[x] - siz[to] + n - siz[to];
		DFS2(to,x);
	}
}

signed main () {
	scanf("%lld",&n);
	for(register int i = 1,x,y;i < n; ++i) {
		scanf("%lld%lld",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	DFS1(1,0);
	DFS2(1,0);
	printf("%lld\n",ans);
	return 0;
}