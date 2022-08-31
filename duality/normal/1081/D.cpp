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

int x[100000];
struct edge { int u,v,w; };
bool comp(edge a,edge b) {
    return a.w < b.w;
}
edge edges[100000];
int parent[100000];
int find(int n) {
    if (parent[n] != n) parent[n] = find(parent[n]);
    return parent[n];
}
vpii adjList[100000];
int size[100000],pw[100000];
int doDFS(int u,int p) {
    int i;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i].first;
        if (v != p) pw[v] = adjList[u][i].second,size[u] += doDFS(v,u);
    }
    return size[u];
}
int main() {
    int i;
    int n,m,k;
    int u,v,w;
    scanf("%d %d %d",&n,&m,&k);
    for (i = 0; i < k; i++) scanf("%d",&x[i]),x[i]--;
    for (i = 0; i < m; i++) {
        scanf("%d %d %d",&u,&v,&w);
        u--,v--;
        edges[i] = (edge){u,v,w};
    }
    sort(edges,edges+m,comp);

    for (i = 0; i < n; i++) parent[i] = i;
    for (i = 0; i < m; i++) {
        if (find(edges[i].u) != find(edges[i].v)) {
            parent[find(edges[i].u)] = find(edges[i].v);
            adjList[edges[i].u].pb(mp(edges[i].v,edges[i].w));
            adjList[edges[i].v].pb(mp(edges[i].u,edges[i].w));
        }
    }
    for (i = 0; i < k; i++) size[x[i]]++;
    doDFS(0,-1);
    int ans = 0;
    for (i = 0; i < n; i++) {
        if ((size[i] < k) && (size[i] > 0)) ans = max(ans,pw[i]);
    }
    for (i = 0; i < k; i++) printf("%d ",ans);
    printf("\n");

    return 0;
}