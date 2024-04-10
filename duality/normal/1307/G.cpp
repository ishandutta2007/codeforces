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

struct edge { int v,r,c,cost; };
vector<edge> adjList[50];
int addEdge(int u,int v,int c,int cost) {
    adjList[u].pb((edge){v,adjList[v].size(),c,cost});
    adjList[v].pb((edge){u,adjList[u].size()-1,0,-cost});
    return 0;
}
int dist[50],parent[50],pp[50];
queue<pii> Q;
int findPath(int n) {
    int i;
    for (i = 0; i < n; i++) dist[i] = -1;
    dist[0] = 0,Q.push(mp(0,0));
    while (!Q.empty()) {
        int u = Q.front().first;
        int d = Q.front().second;
        Q.pop();

        if (d > dist[u]) continue;
        for (i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i].v;
            if ((adjList[u][i].c > 0) && ((dist[v] == -1) || (dist[u]+adjList[u][i].cost < dist[v]))) {
                dist[v] = dist[u]+adjList[u][i].cost,parent[v] = u,pp[v] = i;
                Q.push(mp(v,dist[v]));
            }
        }
    }
    return (dist[n-1] != -1);
}
vpii ans;
int maxFlow(int n) {
    int mf = 0,cost = 0;
    while (findPath(n)) {
        int u = n-1;
        while (u != 0) {
            int p = parent[u];
            adjList[p][pp[u]].c--,adjList[u][adjList[p][pp[u]].r].c++,cost += adjList[p][pp[u]].cost;
            u = p;
        }
        mf++;
        ans.pb(mp(mf,cost));
    }
    return 0;
}
int main() {
    int i,j;
    int n,m,q;
    int u,v,w,x;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d",&u,&v,&w);
        u--,v--;
        addEdge(u,v,1,w);
    }
    maxFlow(n);
    scanf("%d",&q);
    for (i = 0; i < q; i++) {
        scanf("%d",&x);
        double a = 1e99;
        for (j = 0; j < ans.size(); j++) a = min(a,(double) (ans[j].second+x)/ans[j].first);
        printf("%.10lf\n",a);
    }

    return 0;
}