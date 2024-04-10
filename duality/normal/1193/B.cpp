#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long int LLI;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int P[100000],D[100000],W[100000];
vi adjList[100000];
map<int,LLI> M[100000];
int doDFS(int u) {
    int i;
    M[u][0] = 0;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        doDFS(v);
        if (M[v].size() > M[u].size()) swap(M[u],M[v]);
        for (auto it = M[v].begin(); it != M[v].end(); it++) {
            if (M[u].count(it->first)) M[u][it->first] += it->second;
            else M[u][it->first] = it->second;
        }
    }
    if (M[u].count(D[u])) M[u][D[u]] += W[u];
    else M[u][D[u]] = W[u];
    auto it = M[u].upper_bound(D[u]);
    LLI s = 0;
    while ((it != M[u].end()) && (s+it->second <= W[u])) s += it->second,it = M[u].erase(it);
    if (it != M[u].end()) it->second += s-W[u];
    return 0;
}
int main() {
    int i;
    int n,m,k,v,d,w;
    scanf("%d %d %d",&n,&m,&k);
    for (i = 1; i < n; i++) scanf("%d",&P[i]),adjList[--P[i]].pb(i);
    for (i = 0; i < m; i++) scanf("%d %d %d",&v,&d,&w),v--,D[v] = d,W[v] = w;

    LLI ans = 0;
    doDFS(0);
    for (auto it = M[0].begin(); it != M[0].end(); it++) ans += it->second;
    printf("%lld\n",ans);

    return 0;
}