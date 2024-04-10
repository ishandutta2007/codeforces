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

vi adjList[200];
struct edge { int u,v,b; };
edge edges[2000];
int visited[200],colour[200],bad = 0;
int doDFS(int u,int c) {
    if (visited[u]) {
        if (colour[u] != c) bad = 1;
        return 0;
    }
    int i;
    visited[u] = 1,colour[u] = c;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        doDFS(v,!c);
    }
    return 0;
}
vpii adjList2[200];
int dist[200],a[200],ans[200];
int main() {
    int i;
    int n,m,u,v,b;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d",&u,&v,&b);
        u--,v--;
        edges[i] = (edge){u,v,b};
        adjList[u].pb(v);
        adjList[v].pb(u);
    }

    doDFS(0,0);
    if (bad) {
        printf("NO\n");
        return 0;
    }
    for (i = 0; i < m; i++) {
        u = edges[i].u,v = edges[i].v;
        if (edges[i].b == 0) {
            adjList2[u].pb(mp(v,1));
            adjList2[v].pb(mp(u,1));
        }
        else {
            adjList2[u].pb(mp(v,1));
            adjList2[v].pb(mp(u,-1));
        }
        /*if (edges[i].b == 0) {
            if (colour[u] == 1) {
                adjList2[u].pb(mp(v,0));
                adjList2[v].pb(mp(u,1));
            }
            else {
                adjList2[u].pb(mp(v,1));
                adjList2[v].pb(mp(u,0));
            }
        }
        else {
            if (colour[u] == 1) {
                adjList2[u].pb(mp(v,0));
                adjList2[v].pb(mp(u,0));
            }
            else {
                adjList2[u].pb(mp(v,-1));
                adjList2[v].pb(mp(u,1));
            }
        }*/
    }
    int j,k,l;
    int best = 0;
    for (l = 0; l < n; l++) {
        for (i = 0; i < n; i++) dist[i] = 100000;
        dist[l] = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                for (k = 0; k < adjList2[j].size(); k++) {
                    int v = adjList2[j][k].first;
                    dist[v] = min(dist[v],dist[j]+adjList2[j][k].second);
                }
            }
        }
        for (j = 0; j < n; j++) {
            for (k = 0; k < adjList2[j].size(); k++) {
                int v = adjList2[j][k].first;
                if (dist[j]+adjList2[j][k].second < dist[v]) {
                    printf("NO\n");
                    return 0;
                }
            }
        }
        for (i = 0; i < n; i++) a[i] = dist[i];
        int d = *min_element(a,a+n);
        for (i = 0; i < n; i++) a[i] -= d;
        int x = *max_element(a,a+n)-*min_element(a,a+n);
        if (x > best) {
            best = x;
            for (i = 0; i < n; i++) ans[i] = a[i];
        }
    }
    printf("YES\n");
    printf("%d\n",best);
    for (i = 0; i < n; i++) printf("%d ",ans[i]);
    printf("\n");

    return 0;
}