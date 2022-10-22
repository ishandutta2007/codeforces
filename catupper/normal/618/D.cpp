#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long Int;
typedef pair<Int, Int> P;
typedef double Real;

set<Int> ins;
vector<Int> edge[216000];

Int n, x, y, u, v, dig[216000], digg[216000];
Int dist[216000];
Int dp[2][216000]  ;

#define INF (1 << 30)

void dfs(int x, int last = -1){
	dp[0][x] = 0;
	dp[1][x] = -INF;
	dp[2][x] = -INF;
	for(int i = 0;i < edge[x].size();i++){
		int to = edge[x][i];
		if(to == last)continue;
		dfs(to, x);
		dp[2][x] = max(dp[2][x] + max(max(dp[0][to], dp[1][to]), dp[2][to]), dp[1][x] + max(dp[0][to], dp[1][to]) + 1);
		dp[1][x] = max(dp[1][x] + max(max(dp[0][to], dp[1][to]), dp[2][to]), dp[0][x] + 1 + max(dp[0][to], dp[1][to]));
		dp[0][x] += max(max(dp[0][to], dp[1][to]), dp[2][to]);
	}
}
int main(){
	cin >> n >> x >> y;
	Int digmax = 0;
	for(Int i = 0;i < n - 1;i++){
		cin >> u >> v;  u--, v--;
		digg[u]++;
		digg[v]++;
		digmax = max(digg[u], digmax);
		digmax = max(digg[v], digmax);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	
	dfs(0);
    Int ycnt = max(max(dp[0][0], dp[1][0]), dp[2][0]);
	if(x < y){
		cout << (n-1-ycnt) * y + ycnt * x << endl;
	}
	else if(digmax == n - 1){
		cout << (n-2)*y+x << endl;
	}
	else cout << (n-1)*y << endl;
	return 0;
	
}