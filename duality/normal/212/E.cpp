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

vi adjList[5000];
int size[5000];
int doDFS(int u,int p) {
    int i;
    size[u] = 1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) {
            doDFS(v,u);
            size[u] += size[v];
        }
    }
    return 0;
}
bitset<5001> dp;
int yes[5000];
vi ans;
int main() {
    int i;
    int n,x,y;
    scanf("%d",&n);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&x,&y);
        x--,y--;
        adjList[x].pb(y);
        adjList[y].pb(x);
    }

    int j;
    for (i = 0; i < n; i++) {
        doDFS(i,-1);
        dp.reset(),dp[0] = 1;
        for (j = 0; j < adjList[i].size(); j++) {
            int v = adjList[i][j];
            dp |= dp << size[v];
        }
        for (j = 0; j < n-1; j++) {
            if (dp[j]) yes[j] = 1;
        }
    }
    for (i = 1; i < n-1; i++) {
        if (yes[i]) ans.pb(i);
    }
    printf("%d\n",ans.size());
    for (i = 0; i < ans.size(); i++) printf("%d %d\n",ans[i],n-1-ans[i]);

    return 0;
}