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

vi adjList[100000],adjList2[100000];
int deg[100000];
int up[100000],down[100000];
LLI ans = 0;
int main() {
    int i;
    int n,m,q,v;
    int a,b;
    LLI ans = 0;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) {
        scanf("%d %d",&a,&b);
        a--,b--;
        if (a < b) swap(a,b);
        adjList[a].pb(b);
        adjList2[b].pb(a);
        deg[a]++,deg[b]++;
        up[b]++,down[a]++;
    }
    for (i = 0; i < n; i++) ans += (LLI) up[i]*down[i];
    scanf("%d",&q);
    printf("%I64d\n",ans);
    for (i = 0; i < q; i++) {
        scanf("%d",&v),v--;

        ans -= (LLI) up[v]*down[v];
        down[v] = deg[v],up[v] = 0,ans += (LLI) up[v]*down[v];
        for (auto it = adjList2[v].begin(); it != adjList2[v].end(); it++) {
            int w = *it;
            ans -= (LLI) up[w]*down[w];
            up[w]++,down[w]--;
            ans += (LLI) up[w]*down[w];
            adjList2[w].pb(v);
        }
        adjList2[v].clear();
        printf("%I64d\n",ans);
    }

    return 0;
}