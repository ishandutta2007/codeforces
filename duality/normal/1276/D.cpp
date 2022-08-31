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
#define MOD 998244353

vpii adjList[200001];
LLI dp[200001][3];
bool comp(pii a,pii b) {
    return a.second < b.second;
}
int doDFS(int u,int p) {
    int i,f = 0;
    LLI a = 1,b = 0,a2,b2;
    sort(adjList[u].begin(),adjList[u].end(),comp);
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i].first;
        if (v != p) {
            doDFS(v,u);
            if (f) {
                dp[u][0] *= dp[v][2],dp[u][0] %= MOD;
                b2 = (((dp[v][2]*b2) % MOD)+((dp[v][1]*a2) % MOD)) % MOD;
                a2 = (dp[v][0]*a2) % MOD;
            }
            b = (((dp[v][2]*b) % MOD)+((dp[v][1]*a) % MOD)) % MOD;
            a = (dp[v][0]*a) % MOD;
        }
        else {
            dp[u][0] = (a+b) % MOD;
            a2 = a,b2 = 0;
            f = 1;
        }
    }
    dp[u][1] = (a2+b2) % MOD,dp[u][2] = (a+b) % MOD;
    return 0;
}
int main() {
    int i;
    int n,u,v;
    scanf("%d",&n);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        adjList[u].pb(mp(v,i));
        adjList[v].pb(mp(u,i));
    }
    adjList[0].pb(mp(1,n-1));
    adjList[1].pb(mp(0,n-1));
    doDFS(1,0);
    printf("%d\n",(int) dp[1][2]);

    return 0;
}