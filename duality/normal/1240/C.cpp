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

int k;
vpii adjList[500000];
LLI dp[500000][2];
int doDFS(int u,int p) {
    int i;
    vlli vv;
    dp[u][0] = dp[u][1] = 0;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i].first;
        if (v != p) {
            doDFS(v,u);
            LLI use = dp[v][0]+adjList[u][i].second;
            LLI notuse = max(dp[v][0],dp[v][1]);
            dp[u][0] += notuse,vv.pb(use-notuse);
        }
    }
    sort(vv.begin(),vv.end(),greater<LLI>());
    for (i = 0; i < min(k-1,(int) vv.size()); i++) dp[u][0] += max(vv[i],0LL);
    dp[u][1] = dp[u][0];
    for (i = k-1; i < min(k,(int) vv.size()); i++) dp[u][1] += max(vv[i],0LL);
    //cout<<u+1<<": "<<dp[u][0]<<","<<dp[u][1]<<endl;
    return 0;
}
int main() {
    int i;
    int q,n;
    int u,v,w;
    scanf("%d",&q);
    while (q--) {
        scanf("%d %d",&n,&k);
        for (i = 0; i < n-1; i++) {
            scanf("%d %d %d",&u,&v,&w);
            u--,v--;
            adjList[u].pb(mp(v,w));
            adjList[v].pb(mp(u,w));
        }
        doDFS(0,-1);
        printf("%I64d\n",max(dp[0][0],dp[0][1]));
        for (i = 0; i < n; i++) adjList[i].clear();
    }

    return 0;
}