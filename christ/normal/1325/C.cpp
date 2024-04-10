#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5+3, MOD = 1e9+7;
vector<pii> adj[MN];
int what[MN];
int main() {
    int n;
    scanf ("%d",&n);
    for (int i = 1; i < n; i++) {
        int a,b;
        scanf ("%d %d",&a,&b);
        adj[a].emplace_back(b,i);
        adj[b].emplace_back(a,i);
    }
    memset(what,-1,sizeof what);
    int cur = -1;
    for (int i = 1; i <= n; i++) if (adj[i].size() >= 3) {
        what[adj[i][0].second] = 0;
        what[adj[i][1].second] = 1;
        what[adj[i][2].second] = 2;
        cur = 2;
        break;
    }
    for (int i = 1; i <= n; i++) {
        for (pii j : adj[i]) if (what[j.second] == -1) what[j.second] = ++cur;
    }
    for (int i = 1; i < n; i++) printf ("%d\n",what[i]);
    return 0;
}