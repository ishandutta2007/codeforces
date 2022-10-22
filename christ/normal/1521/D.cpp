#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5+5;
vector<int> adj[MN];
int dp[MN][2];
array<int,2> from[MN][2];
void dfs (int cur, int p = -1) {
	int sum = 0; vector<array<int,2>> diffs;
	for (int i : adj[cur]) if (i != p) {
		dfs(i,cur);
		sum += dp[i][0];
		diffs.push_back({dp[i][1] - dp[i][0],i});
	}
	sort(diffs.begin(),diffs.end());
	auto get = [&] (int i) {return i < (int)diffs.size() ? diffs[i][0] : 1;};
	int i = cur;
	if (diffs.empty()) {
		dp[i][0] = dp[i][1] = 1;
	} else {
		dp[i][0] = min(sum + get(0) + get(1) - 1,sum+1);
		dp[i][1] = min(sum + get(0),sum+1);
		if (sum+1 == dp[i][0]);
		else if (sum + get(0) == dp[i][0]) {
			from[i][0] = {diffs[0][1],-1};
		} else {
			from[i][0] = {diffs[0][1],diffs[1][1]};
		}
		if (sum+1 == dp[i][1]);
		else from[i][1] = {diffs[0][1],-1};
	}
}
vector<int> at[MN];
vector<array<int,2>> rem,ed;
bool vis[MN];
void dfs2 (int cur, int top = 1, int t = 0) {
	int cnt = 0; vis[cur] = true;
	for (int i : from[cur][t]) if (i != -1) {
		++cnt;
		dfs2(i,top,1);
	}
	if (cnt == 0 || (cnt == 1 && t == 0)) {
		at[top].push_back(cur);
		if ((int)at[top].size() == 2) {
			ed.push_back({at[top][0],at[top][1]});
		}
	}
	for (int i : adj[cur]) if (!vis[i]) {
		rem.push_back({cur,i});
		dfs2(i,i,0);
	}
}
void solve () {
	int n; scanf ("%d",&n); ed.clear(); rem.clear();
	for (int i = 1; i <= n; i++) adj[i].clear(), at[i].clear(), dp[i][0] = dp[i][1] = 0, from[i][0] = from[i][1] = {-1,-1}, vis[i] = 0;
	for (int i = 1; i < n; i++) {
		int a,b; scanf ("%d %d",&a,&b);
		adj[a].push_back(b); adj[b].push_back(a);
	}
	dfs(1);
	printf ("%d\n",dp[1][0]-1);
	dfs2(1);
	for (int i = 1; i <= n; i++) if ((int)at[i].size() == 1) {
		ed.push_back({i,i});
	}
	for (int i = 0; i < (int)rem.size(); i++) {
		printf ("%d %d %d %d\n",rem[i][0],rem[i][1],ed[i][1],ed[i+1][0]);
	}
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}