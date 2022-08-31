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

int l[100000],r[100000];
vi adjList[100000];
LLI dp[100000][2];
int doDFS(int u,int p) {
    int i;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) {
            doDFS(v,u);
            dp[u][0] += max(dp[v][0]+abs(l[v]-l[u]),dp[v][1]+abs(l[u]-r[v]));
            dp[u][1] += max(dp[v][0]+abs(l[v]-r[u]),dp[v][1]+abs(r[u]-r[v]));
        }
    }
    return 0;
}
int main() {
    int i;
    int t,n,u,v;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (i = 0; i < n; i++) scanf("%d %d",&l[i],&r[i]);
        for (i = 0; i < n-1; i++) {
            scanf("%d %d",&u,&v);
            u--,v--;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }
        doDFS(0,-1);
        printf("%I64d\n",max(dp[0][0],dp[0][1]));
        for (i = 0; i < n; i++) dp[i][0] = dp[i][1] = 0,adjList[i].clear();
    }

    return 0;
}