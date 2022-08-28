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

int h[200000];
vi adjList[200000];
LLI dp[200000],mm[200000];
int doDFS(int u,int p) {
    LLI m = -1e9;
    mm[u] = h[u],dp[u] = 0;
    for (int v: adjList[u]) {
        if (v != p) {
            doDFS(v,u);
            mm[u] = max(mm[u],mm[v]),m = max(m,mm[v]);
            dp[u] += dp[v];
        }
    }
    if (mm[u] == h[u]) {
        if (m < 0) dp[u] = h[u];
        else dp[u] += h[u]-m;
    }
    return 0;
}
int main() {
    int i;
    int n,u,v;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&h[i]);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }

    int m = max_element(h,h+n)-h;
    doDFS(m,-1);
    if (adjList[m].size() == 1) printf("%lld\n",dp[m]+h[m]);
    else {
        LLI sum = 0;
        vlli vv;
        for (int v: adjList[m]) sum += dp[v],vv.pb(mm[v]);
        sort(vv.begin(),vv.end(),greater<LLI>());
        sum += h[m]-vv[0];
        sum += h[m]-vv[1];
        printf("%lld\n",sum);
    }

    return 0;
}