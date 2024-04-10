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

vi adjList[1000000];
int visited[1000000];
int disc[1000000],low[1000000],inStack[1000000];
int num = 0,scc = 0;
vi S,ans,ans2;
int doDFS(int u) {
    int i;
    disc[u] = low[u] = num++;
    S.pb(u),inStack[u] = 1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (disc[v] == -1) doDFS(v),low[u] = min(low[u],low[v]);
        else if (inStack[v]) low[u] = min(low[u],disc[v]);
    }
    if (disc[u] == low[u]) {
        while (1) {
            int v = S.back();
            S.pop_back(),inStack[v] = 0;
            if (scc == 0) ans.pb(v);
            else ans2.pb(v);
            if (u == v) break;
        }
        scc++;
    }
    return 0;
}
int main() {
    int i;
    int t,n,m,a,b;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&m);
        for (i = 0; i < m; i++) {
            scanf("%d %d",&a,&b);
            a--,b--;
            adjList[a].pb(b);
        }

        for (i = 0; i < n; i++) disc[i] = low[i] = -1,inStack[i] = 0;
        num = scc = 0;
        for (i = 0; i < n; i++) {
            if (disc[i] == -1) doDFS(i);
        }
        if (scc == 1) printf("No\n");
        else {
            printf("Yes\n");
            printf("%d %d\n",ans.size(),ans2.size());
            for (i = 0; i < ans.size(); i++) printf("%d ",ans[i]+1);
            printf("\n");
            for (i = 0; i < ans2.size(); i++) printf("%d ",ans2[i]+1);
            printf("\n");
        }

        for (i = 0; i < n; i++) adjList[i].clear();
        ans.clear(),ans2.clear();
    }

    return 0;
}