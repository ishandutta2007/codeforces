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

vpii adjList[200000];
vpii adjList2[200000];
int colour[200000],no;
int doDFS(int u,int c) {
    if (colour[u] != -1) {
        if (colour[u] != c) no = 1;
        return 0;
    }

    colour[u] = c;
    for (auto [v,d]: adjList2[u]) doDFS(v,c^d);
    return 0;
}
int main() {
    int i;
    int t,n,m;
    int x,y,v;
    int a,b,p;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&m);
        for (i = 0; i < n-1; i++) {
            scanf("%d %d %d",&x,&y,&v);
            x--,y--;
            adjList[x].pb(mp(y,v));
            adjList[y].pb(mp(x,v));
            if (v != -1) {
                adjList2[x].pb(mp(y,__builtin_popcount(v) & 1));
                adjList2[y].pb(mp(x,__builtin_popcount(v) & 1));
            }
        }
        for (i = 0; i < m; i++) {
            scanf("%d %d %d",&a,&b,&p);
            a--,b--;
            adjList2[a].pb(mp(b,p));
            adjList2[b].pb(mp(a,p));
        }

        fill(colour,colour+n,-1),no = 0;
        for (i = 0; i < n; i++) {
            if (colour[i] == -1) doDFS(i,0);
        }
        if (no) printf("NO\n");
        else {
            printf("YES\n");
            for (i = 0; i < n; i++) {
                for (auto [v,d]: adjList[i]) {
                    if (i < v) {
                        if (d == -1) printf("%d %d %d\n",i+1,v+1,colour[i]^colour[v]);
                        else printf("%d %d %d\n",i+1,v+1,d);
                    }
                }
            }
        }

        for (i = 0; i < n; i++) adjList[i].clear(),adjList2[i].clear();
    }

    return 0;
}