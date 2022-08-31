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

vi adjList[3000];
int sub[3000],parent[3000];
int doDFS(int u,int p) {
    int i;
    sub[u] = 1,parent[u] = p;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) sub[u] += doDFS(v,u);
    }
    return sub[u];
}
LLI dp[3000][3000];
int getSub(int u,int p) {
    if (p == parent[u]) return sub[u];
    else return sub[0]-sub[p];
}
LLI findAns(int u,int v,int pu,int pv) {
    if (dp[u][v] != -1) return dp[u][v];
    int i;
    LLI ans = 0;
    for (i = 0; i < adjList[u].size(); i++) {
        int w = adjList[u][i];
        if (w != pu) ans = max(ans,findAns(w,v,u,pv)+getSub(v,pv)*getSub(w,u));
    }
    for (i = 0; i < adjList[v].size(); i++) {
        int w = adjList[v][i];
        if (w != pv) ans = max(ans,findAns(u,w,pu,v)+getSub(u,pu)*getSub(w,v));
    }
    dp[u][v] = ans;
    return ans;
}
int main() {
    int i;
    int n,u,v;
    scanf("%d",&n);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    doDFS(0,-1);
    memset(dp,-1,sizeof(dp));
    LLI ans = 0;
    for (i = 1; i < n; i++) ans = max(ans,findAns(i,parent[i],parent[i],i)+getSub(i,parent[i])*getSub(parent[i],i));
    printf("%I64d\n",ans);

    return 0;
}