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

vi adjList[300000];
int dp[300000],parent[300000];
int c = 0;
int doDFS(int u,int p) {
    parent[u] = p;
    for (int v: adjList[u]) {
        if (v != p) {
            doDFS(v,u);
            dp[u] ^= dp[v]+1;
        }
    }
    return 0;
}
int ds[300000];
int find(int n) {
    if (ds[n] != n) ds[n] = find(ds[n]);
    return ds[n];
}
int yes[300000];
int update(int u) {
    if ((u > 0) && (!yes[u] && yes[parent[u]])) c ^= dp[u]+1;
    for (int v: adjList[u]) {
        if (v != parent[u]) {
            if ((v > 0) && (!yes[v] && yes[parent[v]])) c ^= dp[v]+1;
        }
    }
    yes[u] = 1;
    if ((u > 0) && (!yes[u] && yes[parent[u]])) c ^= dp[u]+1;
    for (int v: adjList[u]) {
        if (v != parent[u]) {
            if ((v > 0) && (!yes[v] && yes[parent[v]])) c ^= dp[v]+1;
        }
    }
    return 0;
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
    for (i = 0; i < n; i++) ds[i] = i;
    update(0);
    for (i = 0; i < n; i++) {
        int u = i;
        while (find(u) != 0) {
            u = find(u);
            update(u);
            ds[u] = find(parent[u]),c ^= 1;
        }
        if (c == 0) printf("2");
        else printf("1");
    }
    printf("\n");

    return 0;
}