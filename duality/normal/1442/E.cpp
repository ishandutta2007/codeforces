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

int a[200000];
vi adjList[200000];
int M;
int dp[200000][2];
int doDFS(int u,int p) {
    int i;
    int w1 = 0,w2 = 0,b1 = 0,b2 = 0;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) {
            doDFS(v,u);
            int c = min(dp[v][0],dp[v][1]+1);
            if (c >= w1) w2 = w1,w1 = c;
            else if (c >= w2) w2 = c;
            c = min(dp[v][1],dp[v][0]+1);
            if (c >= b1) b2 = b1,b1 = c;
            else if (c >= b2) b2 = c;
        }
    }
    if (w1+w2 > M) dp[u][0] = 1e9;
    else dp[u][0] = w1;
    if (b1+b2 > M) dp[u][1] = 1e9;
    else dp[u][1] = b1;
    if (a[u] == 1) dp[u][1] = 1e9;
    else if (a[u] == 2) dp[u][0] = 1e9;
    return 0;
}
int main() {
    int i;
    int t,n,u,v;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (i = 0; i < n; i++) scanf("%d",&a[i]);
        for (i = 0; i < n-1; i++) {
            scanf("%d %d",&u,&v);
            u--,v--;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }

        int l = 0,r = n;
        while (l < r) {
            int m = (l+r) / 2;
            M = m;
            doDFS(0,-1);
            if (min(dp[0][0],dp[0][1]) <= M) r = m;
            else l = m+1;
        }
        printf("%d\n",(l+1)/2+1);
        for (i = 0; i < n; i++) adjList[i].clear();
    }

    return 0;
}