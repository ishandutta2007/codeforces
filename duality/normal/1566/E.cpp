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
int leaves = 0;
int no[200000];
int doDFS(int u,int p) {
    int c = 0,y = 0;
    for (int v: adjList[u]) {
        if (v != p) {
            c++,adjList2[u].pb(v);
            doDFS(v,u);
            y |= no[v];
        }
    }
    if (c == 0) leaves++,no[u] = 1;
    else no[u] = !y;
    return 0;
}
int main() {
    int i;
    int t,n,u,v;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (i = 0; i < n-1; i++) {
            scanf("%d %d",&u,&v);
            u--,v--;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }
        leaves = 0;
        doDFS(0,-1);

        int x = 0;
        for (i = 1; i < n; i++) {
            if (!no[i]) x++;
        }
        int f = 0;
        for (i = 0; i < n; i++) {
            if (!adjList2[i].empty()) {
                int a = 0;
                for (int u: adjList2[i]) {
                    if (no[u]) a = 1;
                }
                f += !a;
            }
        }
        printf("%d\n",max(leaves-x+f,1));
        for (i = 0; i < n; i++) adjList[i].clear(),adjList2[i].clear();
    }

    return 0;
}