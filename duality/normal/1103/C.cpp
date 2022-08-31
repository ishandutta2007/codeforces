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

vi adjList[250000];
int visited[250000];
int parent[250000],depth[250000];
vi tree[250000];
int doDFS(int u,int p,int d) {
    int i;
    parent[u] = p,visited[u] = 1,depth[u] = d;
    if (p != -1) tree[p].pb(u);
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (!visited[v]) doDFS(v,u,d+1);
    }
    return 0;
}
int main() {
    int i;
    int n,m,k;
    int u,v;
    scanf("%d %d %d",&n,&m,&k);
    for (i = 0; i < m; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }

    doDFS(0,-1,1);
    for (i = 0; i < n; i++) {
        if ((LLI) k*depth[i] >= n) {
            printf("PATH\n%d\n",depth[i]);
            int u = i;
            while (u != -1) printf("%d ",u+1),u = parent[u];
            printf("\n");
            return 0;
        }
    }
    int c = 0;
    printf("CYCLES\n");
    for (i = 0; i < n; i++) {
        if (tree[i].empty()) {
            int x,y;
            if (((abs(depth[adjList[i][0]]-depth[adjList[i][1]])) % 3) != 1) x = adjList[i][0],y = adjList[i][1];
            else if (((abs(depth[adjList[i][0]]-depth[adjList[i][2]])) % 3) != 1) x = adjList[i][0],y = adjList[i][2];
            else if (((abs(depth[adjList[i][1]]-depth[adjList[i][2]])) % 3) != 1) x = adjList[i][1],y = adjList[i][2];
            if (depth[x] < depth[y]) swap(x,y);
            printf("%d\n",depth[x]-depth[y]+2);
            printf("%d",i+1);
            while (x != y) printf(" %d",x+1),x = parent[x];
            printf(" %d\n",y+1);
            c++;
        }
        if (c == k) break;
    }

    return 0;
}