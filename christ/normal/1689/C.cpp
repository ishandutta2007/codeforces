#include<bits/stdc++.h>
using namespace std;
const int MN = 3e5+5;
vector<int> adj[MN];
int dp[MN], sz[MN];
void getsz (int cur, int p = -1) {
    sz[cur] = 1;
    for (int i : adj[cur]) if (i != p) {
        getsz(i,cur);
        sz[cur] += sz[i];
    }
}
void dfs (int cur, int p = -1) {
    //I got infected
    //delete one of my children
    vector<int> ch;
    for (int i : adj[cur]) if (i != p) {
        dfs(i,cur);
        ch.push_back(i);
    }
    if ((int)ch.size() == 0) dp[cur] = 0;
    else if ((int)ch.size() == 1) dp[cur] = sz[ch[0]] - 1;
    else dp[cur] = max(sz[ch[0]] - 1 + dp[ch[1]], sz[ch[1]] - 1 + dp[ch[0]]);
}
void solve () {
    int n; scanf ("%d",&n);
    for (int i = 0; i <= n; i++) dp[i] = sz[i] = 0;
    for (int i = 0; i <= n; i++) adj[i].clear();
    for (int i = 1; i < n; i++) {
        int a,b; scanf ("%d %d",&a,&b);
        adj[a].push_back(b); adj[b].push_back(a);
    }
    getsz(1);
    dfs(1);
    printf ("%d\n",dp[1]);
}
int main () {
    int _t; scanf ("%d",&_t);
    while (_t--) solve();
    return 0;
}