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
int parent[500000];
int find(int n) {
    if (parent[n] != n) parent[n] = find(parent[n]);
    return parent[n];
}
int u[500000],v[500000],w[500000];
int pp[500000],depth[500000],bound[500000];
int doDFS(int u,int p,int d) {
    int i;
    pp[u] = p,depth[u] = d;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) doDFS(v,u,d+1);
    }
    return 0;
}
int main() {
    int i;
    int n,k,m;
    int a,b;
    LLI s = 0;
    scanf("%d %d %d",&n,&k,&m);
    for (i = 0; i < n; i++) parent[i] = i;
    for (i = 0; i < k; i++) {
        scanf("%d %d",&a,&b);
        a--,b--;
        adjList[a].pb(b);
        adjList[b].pb(a);
        parent[find(a)] = find(b);
    }
    for (i = 0; i < m; i++) {
        scanf("%d %d %d",&u[i],&v[i],&w[i]);
        u[i]--,v[i]--;
        if (find(u[i]) != find(v[i])) {
            s += w[i];
            adjList[u[i]].pb(v[i]);
            adjList[v[i]].pb(u[i]);
            parent[find(u[i])] = find(v[i]);
        }
    }

    for (i = 0; i < n; i++) parent[i] = i,bound[i] = 2e9;
    doDFS(0,-1,0);
    for (i = 0; i < m; i++) {
        a = u[i],b = v[i];
        while (find(a) != find(b)) {
            a = find(a),b = find(b);
            if (depth[a] < depth[b]) swap(a,b);
            bound[a] = w[i],parent[a] = find(pp[a]);
        }
    }
    LLI ans = 0;
    for (i = 1; i < n; i++) {
        if (bound[i] == 2e9) {
            printf("-1\n");
            return 0;
        }
        ans += bound[i];
    }
    printf("%lld\n",ans-s);

    return 0;
}