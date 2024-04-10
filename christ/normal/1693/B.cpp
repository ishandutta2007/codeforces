#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
vector<int> adj[MN];
long long L[MN], R[MN];
pair<long long,int> dfs (int cur) {
    long long sum = 0;
    int cnt = 0;
    for (int i : adj[cur]) {
        pair<long long,int> got = dfs(i);
        sum += got.first;
        cnt += got.second;
    }
    if (sum >= L[cur]) return{min(sum,R[cur]),cnt};
    else return {R[cur],cnt+1};
}
void solve () {
    int n; scanf ("%d",&n);
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        L[i] = R[i] = 0;
    }
    vector<int> p(n+1);
    for (int i = 2; i <= n; i++) {
        scanf ("%d",&p[i]);
        adj[p[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) scanf ("%lld %lld",&L[i],&R[i]);
    printf ("%d\n",dfs(1).second);
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}