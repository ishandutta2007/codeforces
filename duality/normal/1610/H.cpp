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

vi adjList[600000],adjList2[600000];
int parent[600000],disc[600000],fin[600000],num = 0;
int doDFS(int u,int p) {
    parent[u] = p,disc[u] = num++;
    for (int v: adjList[u]) {
        if (v != p) adjList2[u].pb(v),doDFS(v,u);
    }
    fin[u] = num;
    return 0;
}
int anc(int u,int v) {
    return ((disc[v] >= disc[u]) && (disc[v] < fin[u]));
}
int getNext(int u,int v) {
    assert(u != v);
    if (anc(u,v)) {
        int l = 0,r = adjList2[u].size()-1;
        while (l < r) {
            int m = (l+r+1) / 2;
            if (disc[v] >= disc[adjList2[u][m]]) l = m;
            else r = m-1;
        }
        return adjList2[u][l];
    }
    else return parent[u];
}
int u[300000],v[300000];
vi vv[600000];
int dp[600000];
int doDFS2(int u,int p) {
    for (int v: adjList[u]) {
        if (v != p) doDFS2(v,u);
    }
    unordered_map<int,int> M;
    for (int v: vv[u]) M[getNext(u,v)] = max(M[getNext(u,v)],dp[v]+1);
    for (int v: adjList[u]) {
        if (v != p) dp[u] += max(dp[v],M[v]);
    }
    return 0;
}
int main() {
    int i;
    int n,m,p,x,y;
    scanf("%d %d",&n,&m);
    for (i = 1; i < n; i++) {
        scanf("%d",&p),p--;
        adjList[p].pb(n+i-1);
        adjList[n+i-1].pb(p);
        adjList[i].pb(n+i-1);
        adjList[n+i-1].pb(i);
    }
    doDFS(0,-1);
    for (i = 0; i < m; i++) {
        scanf("%d %d",&x,&y);
        x--,y--;
        u[i] = getNext(x,y),v[i] = getNext(y,x);
        if (u[i] == v[i]) {
            printf("-1\n");
            return 0;
        }
        if (disc[u[i]] > disc[v[i]]) swap(u[i],v[i]);
    }

    for (i = 0; i < m; i++) {
        if (anc(u[i],v[i])) vv[u[i]].pb(v[i]);
    }
    doDFS2(0,-1);
    int ans = dp[0];
    for (i = 0; i < m; i++) {
        if (!anc(u[i],v[i])) ans = max(ans,dp[u[i]]+dp[v[i]]+1);
    }
    printf("%d\n",ans);

    return 0;
}