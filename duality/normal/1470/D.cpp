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

vi adjList[300000];
int visited[300000];
vi order,ans;
int doDFS(int u) {
    int i;
    visited[u] = 1,order.pb(u);
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (!visited[v]) doDFS(v);
    }
    return 0;
}
int main() {
    int i,j;
    int t,n,m,u,v;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&m);
        for (i = 0; i < m; i++) {
            scanf("%d %d",&u,&v);
            u--,v--;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }

        doDFS(0);
        for (i = 0; i < n; i++) {
            if (!visited[i]) break;
        }
        if (i < n) printf("NO\n");
        else {
            fill(visited,visited+n,0);
            for (i = 0; i < n; i++) {
                u = order[i];
                if (!visited[u]) {
                    visited[u] = 1,ans.pb(u);
                    for (j = 0; j < adjList[u].size(); j++) visited[adjList[u][j]] = 1;
                }
            }
            printf("YES\n%d\n",ans.size());
            for (i = 0; i < ans.size(); i++) printf("%d ",ans[i]+1);
            printf("\n");
        }

        for (i = 0; i < n; i++) adjList[i].clear(),visited[i] = 0;
        order.clear(),ans.clear();
    }

    return 0;
}