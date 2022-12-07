#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N(444444);
int siz[N], dp[N], dp1[N], fa[N];
bool ans[N];
vector<int> adj[N];
int n;
void dfs1(int v) {
	siz[v] = 1;
	dp[v] = 1;
	for(auto y : adj[v]) {
		if(fa[y] == 0) {
			fa[y] = v;
			dfs1(y);
			siz[v] += siz[y];
			dp[v] = max(dp[v], dp[y]);
		}
	}
	if(siz[v] <= n / 2) {
		dp[v] = siz[v];
	}
}
void dfs2(int v) {
	int mx1(0), mx2(0);
	for(auto y : adj[v]) {
		if(fa[y] == v) {
			if(dp[y] > mx1) {
				mx2 = mx1;
				mx1 = dp[y];
			}else if(dp[y] > mx2) {
				mx2 = dp[y];
			}
		}
	}
	for(auto y : adj[v]) {
		if(fa[y] == v) {
			dp1[y] = max(dp1[v], max(n - siz[y] <= n / 2 ? n - siz[y] : 0, dp[y] == mx1 ? mx2 : mx1));
		}
	}
	bool flag(true);
	for(auto y : adj[v]) {
		if(fa[y] == v) {
			dfs2(y);
			if(siz[y] <= n / 2 || siz[y] - dp[y] <= n / 2) {
				
			}else {
				flag = false;
			}
		}
	}
	if(n - siz[v] <= n / 2 || n - siz[v] - dp1[v] <= n / 2) {
	}else {
		flag = false;
	}
	ans[v] = flag;
}
int main() {
	scanf("%d", &n);
	for(int i(0); i < n - 1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	fa[1] = -1;
	dfs1(1);
	dfs2(1);
	/*for(int i(1); i <= n; i++) {
		printf("siz[%d] = %d, dp[%d] = %d, dp1[%d] = %d\n", i, siz[i], i, dp[i], i, dp1[i]);
	}*/
	
	for(int i(1); i <= n; i++) {

		printf("%d%c", ans[i], i == n ? '\n' : ' ');
	}
}