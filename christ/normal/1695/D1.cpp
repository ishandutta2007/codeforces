#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
vector<int> adj[MN];
int dp[MN][2];
void dfs (int cur, int p = -1) {
    int best = 0;
    for (int i : adj[cur]) if (i != p) {
        dfs(i,cur);
        dp[cur][0] += dp[i][1];
        best = min(best,dp[i][0] - dp[i][1]);
    }
    dp[cur][0] += best;
    dp[cur][1] = max(1,dp[cur][0]);
}
void solve () {
    int n; scanf ("%d",&n);
    for (int i = 1; i <= n; i++) adj[i].clear(), dp[i][0] = dp[i][1] = 0;
    for (int i = 1; i < n; i++) {
        int a,b; scanf ("%d %d",&a,&b);
        adj[a].push_back(b); adj[b].push_back(a);
    }
    if (n <= 2) {
        printf ("%d\n",n-1);
        return;
    }
    int rt = -1;
    for (int i = 1; i <= n; i++) if ((int)adj[i].size() > 2) rt = i;
    if (!~rt) {
        printf ("1\n");
        return;
    }
    assert(~rt);
    dfs(rt);
    printf ("%d\n",dp[rt][1]);
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}