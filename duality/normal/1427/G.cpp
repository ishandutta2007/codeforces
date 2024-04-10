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

int a[200][200];
vi v;
struct edge { int v,c,r; };
vector<edge> adjList[40000];
int addEdge(int u,int v,int c,int c2) {
    adjList[u].pb((edge){v,c,adjList[v].size()});
    adjList[v].pb((edge){u,c2,adjList[u].size()-1});
    return 0;
}
int dist[40000],parent[40000],pp[40000];
queue<int> Q;
int findPath(int s,int e,int n) {
    int i;
    for (i = 0; i < n; i++) dist[i] = -1;
    dist[s] = 0,Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i].v;
            if ((adjList[u][i].c > 0) && (dist[v] == -1)) {
                dist[v] = dist[u]+1;
                parent[v] = u,pp[v] = i;
                Q.push(v);
            }
        }
    }
    return (dist[e] != -1);
}
int findPath2(int s,int e,int n) {
    int i;
    for (i = 0; i < n; i++) dist[i] = -1;
    dist[s] = 0,Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i].v;
            if ((adjList[u][i].c == 0) && (dist[v] == -1)) {
                dist[v] = dist[u]+1;
                parent[v] = u,pp[v] = i;
                Q.push(v);
            }
        }
    }
    return (dist[e] != -1);
}
int flow = 0;
int change(int u,int n) {
    int i;
    for (i = 0; i < adjList[u].size(); i++) {
        if (adjList[u][i].v == n*n-1) {
            if (adjList[u][i].c == 0) {
                findPath2(0,u,n*n);
                int v = u;
                while (v != 0) {
                    adjList[parent[v]][pp[v]].c++;
                    adjList[v][adjList[parent[v]][pp[v]].r].c--;
                    v = parent[v];
                }
                flow--;
            }
            adjList[u][i].c = 0;
            adjList[n*n-1][adjList[u][i].r].c = 0;
            break;
        }
    }
    addEdge(0,u,1,0);
    return 0;
}
int main() {
    int i,j;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d",&a[i][j]);
            if (a[i][j] > 0) v.pb(a[i][j]);
        }
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());

    for (i = 1; i < n-1; i++) {
        for (j = 1; j < n; j++) {
            if ((a[i][j] != -1) && (a[i][j-1] != -1)) addEdge(i*n+j,i*n+j-1,1,1);
        }
        addEdge(i*n,n*n-1,1,0),addEdge(i*n+n-1,n*n-1,1,0);
        addEdge(i,n*n-1,1,0),addEdge((n-1)*n+i,n*n-1,1,0);
    }
    for (i = 1; i < n; i++) {
        for (j = 1; j < n-1; j++) {
            if ((a[i][j] != -1) && (a[i-1][j] != -1)) addEdge(i*n+j,(i-1)*n+j,1,1);
        }
    }
    LLI ans = 0;
    for (i = 1; i < n; i++) {
        ans += abs(a[0][i]-a[0][i-1]);
        ans += abs(a[n-1][i]-a[n-1][i-1]);
        ans += abs(a[i][0]-a[i-1][0]);
        ans += abs(a[i][n-1]-a[i-1][n-1]);
    }
    for (i = 0; i < v.size()-1; i++) {
        for (j = 1; j < n-1; j++) {
            if (a[0][j] == v[i]) change(j,n);
            if (a[n-1][j] == v[i]) change((n-1)*n+j,n);
            if (a[j][0] == v[i]) change(j*n,n);
            if (a[j][n-1] == v[i]) change(j*n+n-1,n);
        }
        while (findPath(0,n*n-1,n*n)) {
            int u = n*n-1;
            while (u != 0) {
                adjList[parent[u]][pp[u]].c--;
                adjList[u][adjList[parent[u]][pp[u]].r].c++;
                u = parent[u];
            }
            flow++;
        }
        ans += (LLI) flow*(v[i+1]-v[i]);
    }
    printf("%I64d\n",ans);

    return 0;
}