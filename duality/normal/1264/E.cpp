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

int u[1225],v[1225];
int seen[50][50];
int deg[50];
struct edge { int v,c,cost,r; };
vector<edge> adjList[1300];
int addEdge(int u,int v,int c,int cost) {
    adjList[u].pb((edge){v,c,cost,adjList[v].size()});
    adjList[v].pb((edge){u,0,-cost,adjList[u].size()-1});
    return 0;
}
vpii edges;
int dist[1300],parent[1300],pp[1300];
queue<pii> Q;
int findPath(int N) {
    int i;
    for (i = 0; i < N; i++) dist[i] = 1e9;
    dist[0] = 0,Q.push(mp(0,0));
    while (!Q.empty()) {
        int u = Q.front().first;
        int d = Q.front().second;
        Q.pop();

        if (d > dist[u]) continue;
        for (i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i].v;
            if ((adjList[u][i].c > 0) && (dist[u]+adjList[u][i].cost < dist[v])) {
                dist[v] = dist[u]+adjList[u][i].cost;
                parent[v] = u,pp[v] = i;
                Q.push(mp(v,dist[v]));
            }
        }
    }
    return dist[1] < 1e9;
}
int ans[50][50];
int main() {
    int i,j;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) {
        scanf("%d %d",&u[i],&v[i]);
        u[i]--,v[i]--;
        deg[u[i]]++;
        seen[u[i]][v[i]] = seen[v[i]][u[i]] = 1;
    }

    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (!seen[i][j]) edges.pb(mp(i,j));
        }
    }
    for (i = 0; i < edges.size(); i++) {
        addEdge(0,i+2,1,0);
        addEdge(i+2,edges[i].first+edges.size()+2,1,0);
        addEdge(i+2,edges[i].second+edges.size()+2,1,0);
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n-1; j++) addEdge(i+edges.size()+2,1,1,2*(j+deg[i])+1);
    }
    while (findPath(2+edges.size()+n)) {
        int u = 1;
        while (u != 0) {
            int p = parent[u];
            adjList[p][pp[u]].c--,adjList[u][adjList[p][pp[u]].r].c++;
            u = parent[u];
        }
    }
    for (i = 0; i < m; i++) ans[u[i]][v[i]] = 1;
    for (i = 0; i < edges.size(); i++) {
        for (j = 0; j < adjList[i+2].size(); j++) {
            int v = adjList[i+2][j].v;
            v -= edges.size()+2;
            if (adjList[i+2][j].c == 0) {
                if (v == edges[i].first) ans[edges[i].first][edges[i].second] = 1;
                else ans[edges[i].second][edges[i].first] = 1;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) printf("%d",ans[i][j]);
        printf("\n");
    }

    return 0;
}