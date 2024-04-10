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

vi adjList[500000];
int t[500000];
int order[500000];
bool comp(int a,int b) {
    return t[a] < t[b];
}
int seen[500005];
int done[500000];
int main() {
    int i;
    int n,m;
    int a,b;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) {
        scanf("%d %d",&a,&b);
        a--,b--;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }
    for (i = 0; i < n; i++) scanf("%d",&t[i]);

    int j;
    for (i = 0; i < n; i++) order[i] = i;
    sort(order,order+n,comp);
    for (i = 0; i < n; i++) {
        int u = order[i];
        for (j = 0; j < adjList[u].size(); j++) {
            int v = adjList[u][j];
            if (done[v]) seen[t[v]] = 1;
        }
        int c = 1;
        while (seen[c]) c++;
        if (t[u] != c) {
            printf("-1\n");
            return 0;
        }
        else done[u] = 1;
        for (j = 0; j < adjList[u].size(); j++) {
            int v = adjList[u][j];
            if (done[v]) seen[t[v]] = 0;
        }
    }
    for (i = 0; i < n; i++) printf("%d ",order[i]+1);
    printf("\n");

    return 0;
}