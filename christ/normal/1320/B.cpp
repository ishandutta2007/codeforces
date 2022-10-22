#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5+3, MOD = 1e9+7;
vector<int> adj[MN], jda[MN];
int dist[MN];
int main() {
    int n,m;
    scanf ("%d %d",&n,&m);
    while (m--) {
        int a,b; scanf ("%d %d",&a,&b);
        adj[b].push_back(a); jda[a].push_back(b);
    }
    int k; scanf ("%d",&k);
    vector<int> go(k);
    for (auto &au : go) scanf ("%d",&au);
    int ed = go[k-1];
    memset(dist,0x3f,sizeof dist);
    dist[ed] = 0;
    queue<int> q; q.push(ed);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i : adj[cur]) if (dist[cur] + 1 < dist[i]) {
            dist[i] = dist[cur] + 1;
            q.push(i);
        }
    }
    int need=0,can=0;
    for (int i = 0; i < k-1; i++) {
        int togo = dist[go[i]];
        int nxt = dist[go[i+1]];
        if (nxt+1>togo) ++need;
        else {
            assert(nxt+1==togo);
            for (int j : jda[go[i]]) if (j != go[i+1] && togo==dist[j]+1) {++can; break;}
        }
    }
    printf ("%d %d\n",need,need+can);
    return 0;
}