#define DEBUG 1

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

vi adjList[100000];
int dist[100000],parent[100000];
int doDFS(int u,int p,int d) {
    int i;
    dist[u] = d,parent[u] = p;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) doDFS(v,u,d+1);
    }
    return 0;
}
int main() {
    int i;
    int n,k,u,v;
    scanf("%d %d",&n,&k);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    if (n < 4) {
        printf("No\n");
        return 0;
    }

    vi leaf;
    for (i = 0; i < n; i++) {
        if (adjList[i].size() == 1) leaf.pb(i);
    }
    doDFS(leaf[0],-1,0);
    for (i = 0; i < n; i++) {
        if (dist[i] == 2*k) break;
    }
    if (i == n) {
        printf("No\n");
        return 0;
    }
    int r = i;
    for (i = 0; i < k; i++) r = parent[r];
    doDFS(r,-1,0);
    for (i = 0; i < n; i++) {
        if ((adjList[i].size() == 1) && (dist[i] != k)) {
            printf("No\n");
            return 0;
        }
    }
    for (i = 0; i < n; i++) {
        if (i == r) {
            if (adjList[i].size() < 3) {
                printf("No\n");
                return 0;
            }
            continue;
        }
        if ((adjList[i].size() != 1) && (adjList[i].size() < 4)) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");

    return 0;
}