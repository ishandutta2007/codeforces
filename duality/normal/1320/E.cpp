#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
// basic debugging macros
int __i__,__j__;
#define printLine(l) for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl
#define printLine2(l,c) for(__i__=0;__i__<l;__i__++){cout<<c;}cout<<endl
#define printVar(n) cout<<#n<<": "<<n<<endl
#define printArr(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}
#define print2dArr2(a,r,c,l) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<setw(l)<<setfill(' ')<<a[__i__][__j__]<<" ";}cout<<endl;}

// advanced debugging class
// debug 1,2,'A',"test";
class _Debug {
    public:
        template<typename T>
        _Debug& operator,(T val) {
            cout << val << endl;
            return *this;
        }
};
#define debug _Debug(),
#else
#define printLine(l)
#define printLine2(l,c)
#define printVar(n)
#define printArr(a,l)
#define print2dArr(a,r,c)
#define print2dArr2(a,r,c,l)
#define debug
#endif

// define
#define MAX_VAL 999999999
#define MAX_VAL_2 999999999999999999LL
#define EPS 1e-6
#define mp make_pair
#define pb push_back

// typedef
typedef unsigned int UI;
typedef long long int LLI;
typedef unsigned long long int ULLI;
typedef unsigned short int US;
typedef pair<int,int> pii;
typedef pair<LLI,LLI> plli;
typedef vector<int> vi;
typedef vector<LLI> vlli;
typedef vector<pii> vpii;
typedef vector<plli> vplli;

// ---------- END OF TEMPLATE ----------

vi adjList[200000];
int parent[200000][19],depth[200000],disc[200000],fin[200000],num = 0;
int doDFS(int u,int p,int d) {
    int i;
    parent[u][0] = p,depth[u] = d,disc[u] = num++;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) doDFS(v,u,d+1);
    }
    fin[u] = num;
    return 0;
}
int lca(int u,int v,int logn) {
    int i;
    if (depth[u] < depth[v]) swap(u,v);
    for (i = logn-1; i >= 0; i--) {
        if ((parent[u][i] != -1) && (depth[parent[u][i]] >= depth[v])) u = parent[u][i];
    }
    if (u == v) return u;
    for (i = logn-1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) u = parent[u][i],v = parent[v][i];
    }
    return parent[u][0];
}
int v[200000],s[200000],u[200000];
vpii nodes;
vi S;
vpii adjList2[200000];
int dist[200000],virus[200000];
priority_queue<pair<pii,int> > H;
int main() {
    int i,j,l;
    int n,q,k,m;
    int x,y;
    scanf("%d",&n);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&x,&y);
        x--,y--;
        adjList[x].pb(y);
        adjList[y].pb(x);
    }
    doDFS(0,-1,0);
    for (i = 1; (1 << i) < n; i++) {
        for (j = 0; j < n; j++) {
            if (parent[j][i-1] != -1) parent[j][i] = parent[parent[j][i-1]][i-1];
            else parent[j][i] = -1;
        }
    }
    int logn = i;
    scanf("%d",&q);
    for (i = 0; i < q; i++) {
        scanf("%d %d",&k,&m);
        for (j = 0; j < k; j++) scanf("%d %d",&v[j],&s[j]),v[j]--,nodes.pb(mp(disc[v[j]],v[j]));
        for (j = 0; j < m; j++) scanf("%d",&u[j]),u[j]--,nodes.pb(mp(disc[u[j]],u[j]));
        sort(nodes.begin(),nodes.end());
        for (j = 1; j < k+m; j++) {
            int l = lca(nodes[j-1].second,nodes[j].second,logn);
            nodes.pb(mp(disc[l],l));
        }
        sort(nodes.begin(),nodes.end());
        nodes.resize(unique(nodes.begin(),nodes.end())-nodes.begin());
        for (j = nodes.size()-1; j >= 0; j--) {
            while (!S.empty() && (disc[S.back()] < fin[nodes[j].second])) {
                adjList2[S.back()].pb(mp(nodes[j].second,depth[S.back()]-depth[nodes[j].second]));
                adjList2[nodes[j].second].pb(mp(S.back(),depth[S.back()]-depth[nodes[j].second]));
                S.pop_back();
            }
            S.pb(nodes[j].second);
        }

        for (j = 0; j < nodes.size(); j++) dist[nodes[j].second] = virus[nodes[j].second] = -1;
        for (j = 0; j < k; j++) dist[v[j]] = 0,virus[v[j]] = j,H.push(mp(mp(0,-j),v[j]));
        while (!H.empty()) {
            int u = H.top().second;
            pii d = H.top().first;
            H.pop();

            if (d < mp(-((dist[u]+s[virus[u]]-1)/s[virus[u]]),-virus[u])) continue;
            for (l = 0; l < adjList2[u].size(); l++) {
                int v = adjList2[u][l].first;
                if (virus[u] == virus[v]) continue;
                int t = (dist[u]+adjList2[u][l].second+s[virus[u]]-1)/s[virus[u]];
                if ((dist[v] == -1) || (mp(t,virus[u]) < mp((dist[v]+s[virus[v]]-1)/s[virus[v]],virus[v]))) {
                    dist[v] = dist[u]+adjList2[u][l].second;
                    virus[v] = virus[u];
                    H.push(mp(mp(-t,-virus[v]),v));
                }
            }
        }
        for (j = 0; j < m; j++) printf("%d ",virus[u[j]]+1);
        printf("\n");

        for (j = 0; j < nodes.size(); j++) adjList2[nodes[j].second].clear();
        S.clear(),nodes.clear();
    }

    return 0;
}