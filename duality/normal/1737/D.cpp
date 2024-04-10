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

vpii adjList[500];
int dist[500][500];
int main() {
    int i,j,k;
    int t,n,m;
    int u,v,w;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&m);
        for (i = 0; i < m; i++) {
            scanf("%d %d %d",&u,&v,&w);
            u--,v--;
            adjList[u].pb(mp(v,w));
            adjList[v].pb(mp(u,w));
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) dist[i][j] = 1e9;
            dist[i][i] = 0;
        }
        for (i = 0; i < n; i++) {
            for (auto [v,w]: adjList[i]) dist[i][v] = 1;
        }
        for (k = 0; k < n; k++) {
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
        LLI ans = 1e18;
        for (i = 0; i < n; i++) {
            for (auto [v,w]: adjList[i]) {
                ans = min(ans,(LLI) (dist[0][i]+dist[n-1][v]+1)*w);
                for (j = 0; j < n; j++) ans = min(ans,(LLI) (dist[0][j]+dist[j][n-1]+min(dist[j][i],dist[j][v])+2)*w);
            }
        }
        printf("%lld\n",ans);

        for (i = 0; i < n; i++) adjList[i].clear();
    }
    
    return 0;
}