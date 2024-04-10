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
int dist[200000],stop[200000];
queue<int> Q;
int ds[200000];
int find(int n) {
    if (ds[n] != n) ds[n] = find(ds[n]);
    return ds[n];
}
int parent[200000][18],depth[200000];
int doDFS(int u,int p,int d) {
    int i;
    parent[u][0] = p,depth[u] = d;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) doDFS(v,u,d+1);
    }
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
int getNode(int u,int v,int d,int l,int logn) {
    if (d > depth[u]-depth[l]) return getNode(v,u,depth[u]+depth[v]-2*depth[l]-d,l,logn);
    int i;
    for (i = logn-1; i >= 0; i--) {
        if (d & (1 << i)) u = parent[u][i];
    }
    return u;
}
int main() {
    int i;
    int n,k,r,q;
    int u,v;
    scanf("%d %d %d",&n,&k,&r);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    fill(dist,dist+n,-1);
    for (i = 0; i < r; i++) scanf("%d",&u),u--,dist[u] = 0,stop[u] = i,Q.push(u);

    int j;
    doDFS(0,-1,0);
    for (i = 1; (1 << i) < n; i++) {
        for (j = 0; j < n; j++) {
            if (parent[j][i-1] != -1) parent[j][i] = parent[parent[j][i-1]][i-1];
            else parent[j][i] = -1;
        }
    }
    int logn = i;

    for (i = 0; i < n; i++) ds[i] = i;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i];
            if (dist[v] == -1) {
                dist[v] = dist[u]+1;
                stop[v] = stop[u];
                Q.push(v);
            }
            else if ((dist[u]+dist[v]+1 <= k) && (stop[u] != stop[v])) {
                int pa = find(stop[u]),pb = find(stop[v]);
                if (pa != pb) ds[pa] = pb;
            }
        }
    }

    scanf("%d",&q);
    for (i = 0; i < q; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        int l = lca(u,v,logn);
        if (depth[u]+depth[v]-2*depth[l] <= k) printf("YES\n");
        else {
            int a = getNode(u,v,(k+1)/2,l,logn);
            int b = getNode(v,u,(k+1)/2,l,logn);
            if ((dist[a] <= k/2) && (dist[b] <= k/2) && (find(stop[a]) == find(stop[b]))) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}