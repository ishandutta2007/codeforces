#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 1e5+3, MOD = 1e9+7;
ll v[MN],sum;
map<ll,int> cnt[MN];
vector<int> adj[MN];
void dfs (int cur, int p = -1) {
    cnt[cur][v[cur]] = 1;
    if (~p) for (auto &au : cnt[p]) cnt[cur][__gcd(au.first,v[cur])] += au.second;
    for (auto &au : cnt[cur]) sum = (sum + au.first * au.second % MOD) % MOD;
    for (int i : adj[cur]) if (i^p) {
        dfs(i,cur);
    }
}
int main() {
    int n;
    scanf ("%d",&n);
    for (int i = 1; i <= n; i++) scanf ("%lld",&v[i]);
    for (int i = 1; i < n; i++) {
        int a,b;
        scanf ("%d %d",&a,&b);
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs(1);
    printf ("%lld\n",sum);
    return 0;
}