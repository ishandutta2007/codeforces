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

vector<int> adjList[2602];
int adjMat[2602][2602];
int dist[2602];
int work[2602];
queue<int> Q;
int addEdge(int u,int v,int c) {
    adjList[u].pb(v),adjList[v].pb(u);
    adjMat[u][v] = c;
    //cout << u << " " << v << ": " << c << endl;
    return 0;
}
int doBFS(int s,int t,int N) {
    int i,u;
    for (i = 0; i < N; i++) dist[i] = -1;
    dist[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();

        if (u == t) return 1;
        for (i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i];
            if ((adjMat[u][v] > 0) && (dist[v] == -1)) {
                dist[v] = dist[u]+1;
                Q.push(v);
            }
        }
    }

    return 0;
}
int doDFS(int u,int f,int t) {
    if (u == t) return f;

    int &i = work[u];
    for (; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if ((adjMat[u][v] > 0) && (dist[v] == (dist[u]+1))) {
            int df = doDFS(v,min(f,adjMat[u][v]),t);
            if (df > 0) {
                adjMat[u][v] -= df;
                adjMat[v][u] += df;
                return df;
            }
        }
    }

    return 0;
}
int maxFlow(int s,int t,int N) {
    int mf = 0,f;
    while (doBFS(s,t,N)) {
        fill(work,work+N,0);
        while ((f=doDFS(s,MAX_VAL,t)) > 0) mf += f;
        while (!Q.empty()) Q.pop();
    }

    return mf;
}


int main() {
    int i,j;
    int n,h,m;
    int l,r,x,c;
    scanf("%d %d %d",&n,&h,&m);
    for (i = 0; i < n*(h+1); i++) addEdge(0,i+2,max(2*(i % (h+1))-1,0));
    for (i = 0; i < n; i++) {
        for (j = 0; j < h; j++) addEdge(i*(h+1)+j+3,i*(h+1)+j+2,MAX_VAL);
    }
    for (i = 0; i < m; i++) {
        scanf("%d %d %d %d",&l,&r,&x,&c);
        l--,r--,x++;
        if (x <= h) {
            addEdge(n*(h+1)+i+2,1,c);
            for (j = l; j <= r; j++) addEdge(j*(h+1)+x+2,n*(h+1)+i+2,MAX_VAL);
        }
    }
    printf("%d\n",n*h*h-maxFlow(0,1,n*(h+1)+m+2));

    return 0;
}