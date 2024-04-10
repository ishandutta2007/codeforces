#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MN = 3e5+5, MOD = 998244353;
vector<int> adj[MN]; int rsum[MN], bsum[MN], color[MN];
void dfs (int cur, int p = -1) {
	for (int i : adj[cur]) if (i != p) {
		dfs(i,cur);
		rsum[cur] += rsum[i];
		bsum[cur] += bsum[i];
	}
	rsum[cur] += color[cur] == 1;
	bsum[cur] += color[cur] == 2;
}
int main() {
	int n;
	scanf ("%d",&n);
	for (int i = 1; i <= n; i++) scanf ("%d",&color[i]);
	for (int i = 1; i < n; i++) {
		int a,b;
		scanf ("%d %d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	int ret = 0;
	for (int i = 2; i <= n; i++) ret += (rsum[i] == 0 || bsum[i] == 0) && (rsum[1]-rsum[i] == 0 || bsum[1]-bsum[i] == 0);
	printf ("%d\n",ret);
    return 0;
}