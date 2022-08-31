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
#define y1 Y1
#define y2 Y2

int x1[50],y1[50],x2[50],y2[50];
vi lx,ly;
vi adjList[200];
int adjMat[200][200];
int addEdge(int u,int v,int c) {
    adjMat[u][v] = c;
    adjList[u].pb(v),adjList[v].pb(u);
    return 0;
}
int dist[200];
queue<int> Q;
int doBFS(int n) {
    int i;
    fill(dist,dist+n,-1);
    dist[0] = 0,Q.push(0);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i];
            if ((adjMat[u][v] > 0) && (dist[v] == -1)) {
                dist[v] = dist[u]+1;
                Q.push(v);
            }
        }
    }
    return dist[1] != -1;
}
int work[200];
int doDFS(int u,int f) {
    if (u == 1) return f;
    int &i = work[u];
    for (; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if ((adjMat[u][v] > 0) && (dist[v] == dist[u]+1)) {
            int df = doDFS(v,min(f,adjMat[u][v]));
            if (df > 0) {
                adjMat[u][v] -= df,adjMat[v][u] += df;
                return df;
            }
        }
    }
    return 0;
}
int main() {
    int i;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);
        lx.pb(x1[i]),lx.pb(x2[i]+1);
        ly.pb(y1[i]),ly.pb(y2[i]+1);
    }
    sort(lx.begin(),lx.end());
    lx.resize(unique(lx.begin(),lx.end())-lx.begin());
    sort(ly.begin(),ly.end());
    ly.resize(unique(ly.begin(),ly.end())-ly.begin());
    if (m == 0) {
        printf("0\n");
        return 0;
    }

    int j,k;
    for (i = 0; i < lx.size()-1; i++) addEdge(0,i+2,lx[i+1]-lx[i]);
    for (i = 0; i < ly.size()-1; i++) addEdge(i+lx.size()+1,1,ly[i+1]-ly[i]);
    for (i = 0; i < m; i++) {
        x1[i] = lower_bound(lx.begin(),lx.end(),x1[i])-lx.begin();
        x2[i] = lower_bound(lx.begin(),lx.end(),x2[i]+1)-lx.begin();
        y1[i] = lower_bound(ly.begin(),ly.end(),y1[i])-ly.begin();
        y2[i] = lower_bound(ly.begin(),ly.end(),y2[i]+1)-ly.begin();
        for (j = x1[i]; j < x2[i]; j++) {
            for (k = y1[i]; k < y2[i]; k++) addEdge(j+2,k+lx.size()+1,1e9);
        }
    }
    for (i = 0; i < lx.size()+ly.size(); i++) {
        sort(adjList[i].begin(),adjList[i].end());
        adjList[i].resize(unique(adjList[i].begin(),adjList[i].end())-adjList[i].begin());
    }

    int mf = 0,f;
    while (doBFS(lx.size()+ly.size())) {
        fill(work,work+lx.size()+ly.size(),0);
        while ((f=doDFS(0,1e9)) > 0) mf += f;
        while (!Q.empty()) Q.pop();
    }
    printf("%d\n",mf);

    return 0;
}