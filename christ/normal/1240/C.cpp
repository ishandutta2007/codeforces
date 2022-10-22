#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 5e5+3, MOD = 1e9+7;
vector<pii> adj[MN];
ll dp[MN][2]; int k;
void dfs (int cur, int p = -1) {
    vector<pll> poss;
    for (pii i : adj[cur]) if (i.first != p) {
        dfs(i.first,cur);
        poss.emplace_back(dp[i.first][0]+i.second,max(dp[i.first][1],dp[i.first][0]));
    }
    sort(all(poss),[](pll a, pll b){return a.first-a.second > b.first-b.second;});
    dp[cur][0] = dp[cur][1] = 0; int i;
    for (i = 0; i < min(k,(int)poss.size()); i++) {
        if (poss[i].first-poss[i].second < 0) break;
        dp[cur][1] += poss[i].first;
    }
    for (;i<poss.size();i++) dp[cur][1] += poss[i].second;
    for (i = 0; i < min(k-1,(int)poss.size()); i++) {
        if (poss[i].first-poss[i].second < 0) break;
        dp[cur][0] += poss[i].first;
    }
    for (;i<poss.size();i++) dp[cur][0] += poss[i].second;
}
void solve () {
    int n;
    scanf ("%d %d",&n,&k);
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 1; i < n; i++) {
        int a,b,c;
        scanf ("%d %d %d",&a,&b,&c);
        adj[a].emplace_back(b,c);
        adj[b].emplace_back(a,c);
    }
    dfs(1);
    printf ("%lld\n",max(dp[1][0],dp[1][1]));
}
int main() {
    int t;
    scanf ("%d",&t);
    while (t--) solve();
    return 0;
}