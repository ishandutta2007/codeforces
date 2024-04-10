#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 5e5+3, MOD = 1e9+7;
mt19937_64 rnd = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());
struct Edge {
    int a,b,w;
    void read() {scanf ("%d %d %d",&a,&b,&w);}
};
vector<int> adj[MN];
int sz[MN];
int main() {
    int n;
    scanf ("%d",&n);
    vector<Edge> edges(n-1);
    for (auto &au : edges) au.read(), adj[au.a].push_back(au.b), adj[au.b].push_back(au.a);
    function<int(int,int)> dfs = [&] (int cur, int p) {
        for (int i : adj[cur]) if (i != p) sz[cur] += dfs(i,cur);
        return ++sz[cur];
    };
    dfs(1,-1);
    long double ret = 0;
    for (auto &e : edges) {
        if (sz[e.a] > sz[e.b]) swap(e.a,e.b);
        long double sz1 = sz[e.a], sz2 = n - sz1;
        ret += (sz1*(sz1-1)*sz2 + sz1*sz2*(sz2 - 1))/2 * e.w;
    }
    int q;
    scanf ("%d",&q);
    while (q--) {
        int ind, v;
        scanf ("%d %d",&ind,&v); --ind;
        long double sz1 = sz[edges[ind].a], sz2 = n-sz1;
        ret += (sz1*(sz1-1)*sz2+sz1*sz2*(sz2-1))/2 * (v - edges[ind].w);
        edges[ind].w = v;
        printf ("%.12Lf\n",2*ret/((long double)n * (n-1) * (n-2) / 6)); //its off by a factor of two so clearly i just need to multiply by 2
    }
    return 0;
}