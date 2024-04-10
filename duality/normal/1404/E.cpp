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

char grid[200][200];
struct edge { int v,c,r; };
vector<edge> adjList[40002];
int addEdge(int u,int v,int c,int cr) {
    adjList[u].pb((edge){v,c,adjList[v].size()});
    adjList[v].pb((edge){u,cr,adjList[u].size()-1});
    return 0;
}
int dist[40002];
queue<int> Q;
int doBFS(int N) {
    int i;
    for (i = 0; i < N; i++) dist[i] = -1;
    dist[0] = 0,Q.push(0);
    while (!Q.empty()) {
        int u = Q.front();
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
int work[40002];
int doDFS(int u,int f) {
    if (u == 1) return f;
    int &i = work[u];
    for (; i < adjList[u].size(); i++) {
        int v = adjList[u][i].v;
        if ((adjList[u][i].c > 0) && (dist[v] == dist[u]+1)) {
            int df = doDFS(v,min(f,adjList[u][i].c));
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
    int i,j;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) scanf(" %c",&grid[i][j]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                if ((j == 0) || (grid[i][j-1] == '.')) addEdge(0,i*m+j+2,1,0);
                else addEdge(i*m+j+2,i*m+j-1+2,1,1);
                if ((j == m-1) || (grid[i][j+1] == '.')) addEdge(0,i*m+j+2,1,0);
                if ((i == 0) || (grid[i-1][j] == '.')) addEdge(i*m+j+2,1,1,0);
                else addEdge(i*m+j+2,(i-1)*m+j+2,1,1);
                if ((i == n-1) || (grid[i+1][j] == '.')) addEdge(i*m+j+2,1,1,0);
            }
        }
    }
    int mf = 0,f;
    while (doBFS(n*m+2)) {
        while (!Q.empty()) Q.pop();
        while ((f=doDFS(0,1e9)) > 0) mf += f;
        fill(work,work+n*m+2,0);
    }
    printf("%d\n",mf/2);

    return 0;
}