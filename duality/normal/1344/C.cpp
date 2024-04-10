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

vi adjList[200000],adjList2[200000];
int visited[200000],c = 0;
int dp1[200000],dp2[200000];
int doDFS(int u) {
    int i;
    visited[u] = 1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (visited[v] == 0) doDFS(v);
        else if (visited[v] == 1) c = 1;
        dp1[u] = min(dp1[u],dp1[v]);
    }
    visited[u] = 2;
    return 0;
}
int doDFS2(int u) {
    int i;
    visited[u] = 1;
    for (i = 0; i < adjList2[u].size(); i++) {
        int v = adjList2[u][i];
        if (visited[v] == 0) doDFS2(v);
        else if (visited[v] == 1) c = 1;
        dp2[u] = min(dp2[u],dp2[v]);
    }
    visited[u] = 2;
    return 0;
}
char ans[200000];
int main() {
    int i;
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) scanf("%d %d",&u,&v),adjList[u-1].pb(v-1),adjList2[v-1].pb(u-1);

    for (i = 0; i < n; i++) dp1[i] = dp2[i] = i;
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) doDFS(i);
    }
    if (c) {
        printf("-1\n");
        return 0;
    }
    fill(visited,visited+n,0);
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) doDFS2(i);
    }
    c = 0;
    printArr(dp1,n);
    printArr(dp2,n);
    for (i = 0; i < n; i++) {
        if (min(dp1[i],dp2[i]) >= i) ans[i] = 'A',c++;
        else ans[i] = 'E';
    }
    printf("%d\n",c);
    for (i = 0; i < n; i++) printf("%c",ans[i]);
    printf("\n");

    return 0;
}