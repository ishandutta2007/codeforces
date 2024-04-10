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

int w[200000];
vi adjList[200000];
queue<int> Q;
int deg[200000],visited[200000];
LLI val[200000];
int main() {
    int i;
    int n,m,s,u,v;
    LLI ans = 0;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) scanf("%d",&w[i]),ans += w[i];
    for (i = 0; i < m; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    scanf("%d",&s),s--;

    LLI mm = 0;
    for (i = 0; i < n; i++) {
        deg[i] = adjList[i].size();
        if ((i != s) && (adjList[i].size() == 1)) Q.push(i),val[i] = 0;
    }
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        val[u] += w[u],mm = max(mm,val[u]);
        ans -= w[u];

        for (i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i];
            deg[v]--,val[v] = max(val[v],val[u]);
            if ((v != s) && (deg[v] == 1)) Q.push(v);
        }
    }
    ans += mm;
    printf("%I64d\n",ans);

    return 0;
}