#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5+3, MOD = 1e9+7;
vector<int> adj[MN];
bool vis[MN];
int depth[MN];
int par[MN];
int need, leaves,mx,nxt; vector<int> gol;
void dfs (int cur, int p = -1) {
    vis[cur] = 1; bool leaf = 1;
    mx = max(mx,depth[cur]);
    for (int i : adj[cur]) if (i != p) {
        if (vis[i]) {
            if (depth[cur]-depth[i]+1 >= need) {
                vector<int> ret = {cur};
                int cc = cur;
                while (cc != i) ret.push_back(cc = par[cc]);
                printf ("2\n%d\n",ret.size());
                for (int i : ret) printf ("%d ",i);
                printf ("\n");
                exit(0);
            } else nxt = i;
        } else {
            leaf = 0;
            depth[i] = depth[cur] + 1;
            par[i] = cur;
            dfs(i,cur);
        }
    }
    if (leaf) gol.push_back(cur);
}
int main() {
    mt19937 rnd(time(NULL));
    int n,m;
    scanf ("%d %d",&n,&m);
    need = (int)ceil(sqrt(n));
    while (m--) {
        int a,b; scanf ("%d %d",&a,&b);
        adj[a].push_back(b); adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) shuffle(adj[i].begin(),adj[i].end(),rnd);
    while (1) {
        int r = uniform_int_distribution<int>(1,n)(rnd);
        memset(vis,0,sizeof vis); depth[r] = 0; gol.clear();
        dfs(r);
        set<int> has(all(gol));
        vector<int> cango;
        for (int i = 1; i <= n; i++) if (!has.count(i)) cango.push_back(i);
        sort(all(cango),[&](int a, int b) {return depth[a] > depth[b];});
        for (int i : cango) {
            for (int j : adj[i]) if (has.count(j)) goto fail;
            has.insert(i);
            fail:;
        }
        gol = vector<int>(all(has));
        if (gol.size() >= need) {
            printf ("1\n");
            for (int i = 0; i < need; i++) printf ("%d ",gol[i]);
            printf ("\n");
            return 0;
        }
        assert(0);
    }
    return 0;
}