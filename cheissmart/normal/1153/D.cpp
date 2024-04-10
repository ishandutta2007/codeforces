#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

bool m[300005];
vi G[300005];
int dp[300005],lf[300005];

void dfs(int u) {
	if(G[u].size() == 0) {
		lf[u]=1;
		return;
	}
	for(int v:G[u]) {
		dfs(v);
		lf[u]+=lf[v];
	}
	if(m[u]) {
		for(int v:G[u]) 
			dp[u] = max(dp[u], lf[u] - lf[v] + dp[v]);
	} else {
		for(int v:G[u]) 
			dp[u] += dp[v];
	}
}

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> m[i];
	for(int i=1;i<n;i++) {
		int p;
		cin >> p;
		p--;
		G[p].PB(i);
	}
	dfs(0);
	cout << dp[0] + 1 << endl;
}