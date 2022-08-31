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

int x[1000],y[1000],w[1000];
struct edge {
    int v;
    LLI c;
    int r;
};
vector<edge> adjList[2002];
int addEdge(int u,int v,LLI c) {
    adjList[u].pb((edge){v,c,adjList[v].size()});
    adjList[v].pb((edge){u,0,adjList[u].size()-1});
    return 0;
}
int dist[2002],work[2002];
queue<int> Q;
int doBFS(int N) {
    int i,u;
    for (i = 0; i < N; i++) dist[i] = -1;
    dist[0] = 0,Q.push(0);
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();

        for (i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i].v;
            if ((adjList[u][i].c > 0) && (dist[v] == -1)) {
                dist[v] = dist[u]+1;
                Q.push(v);
            }
        }
    }
    return (dist[1] != -1);
}
LLI doDFS(int u,LLI f) {
    if (u == 1) return f;
    int &i = work[u];
    for (; i < adjList[u].size(); i++) {
        int v = adjList[u][i].v;
        if ((adjList[u][i].c > 0) && (dist[v] == dist[u]+1)) {
            LLI df = doDFS(v,min(f,adjList[u][i].c));
            if (df > 0) {
                adjList[u][i].c -= df;
                adjList[v][adjList[u][i].r].c += df;
                return df;
            }
        }
    }
    return 0;
}
int main() {
    int i;
    int n;
    LLI sum = 0;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d %d %d",&x[i],&y[i],&w[i]),sum += w[i];

    int j;
    for (i = 0; i < n; i++) {
        addEdge(2*i+2,2*i+3,w[i]);
        if ((x[i] & 1) && !(y[i] & 1)) addEdge(0,2*i+2,1e18);
        else if ((x[i] & 1) && (y[i] & 1)) addEdge(2*i+3,1,1e18);
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) {
                if (abs(x[i]-x[j])+abs(y[i]-y[j]) != 1) continue;
                if ((x[i] & 1) && !(y[i] & 1) && !(x[j] & 1) && !(y[j] & 1)) addEdge(2*i+3,2*j+2,1e18);
                if (!(x[i] & 1) && !(y[i] & 1) && !(x[j] & 1) && (y[j] & 1)) addEdge(2*i+3,2*j+2,1e18);
                if (!(x[i] & 1) && (y[i] & 1) && (x[j] & 1) && (y[j] & 1)) addEdge(2*i+3,2*j+2,1e18);
            }
        }
    }
    LLI mf = 0,f;
    while (doBFS(2*n+2)) {
        fill(work,work+2*n+2,0);
        while ((f=doDFS(0,1e18)) > 0) mf += f;
        while (!Q.empty()) Q.pop();
    }
    cout << sum-mf << endl;

    return 0;
}