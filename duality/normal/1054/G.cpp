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

bitset<2000> bs[2000];
vector<pair<int,pii> > edges;
int parent[2000];
int find(int n) {
    if (parent[n] != n) parent[n] = find(parent[n]);
    return parent[n];
}
vi adjList[2000];
int doDFS(int u,int p) {
    int i;
    parent[u] = p;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) doDFS(v,u);
    }
    return 0;
}
int main() {
    int i,j;
    int t,n,m;
    char c;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&m);
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) scanf(" %c",&c),bs[j][i] = (c == '1');
        }

        for (i = 0; i < n; i++) {
            for (j = i+1; j < n; j++) edges.pb(mp((bs[i] & bs[j]).count(),mp(i,j)));
        }
        sort(edges.begin(),edges.end());
        for (i = 0; i < n; i++) parent[i] = i;
        for (i = edges.size()-1; i >= 0; i--) {
            int u = edges[i].second.first,v = edges[i].second.second;
            if (find(u) != find(v)) {
                parent[find(u)] = find(v);
                adjList[u].pb(v),adjList[v].pb(u);
            }
        }
        doDFS(0,-1);
        for (i = 0; i < m; i++) {
            int c = 0;
            for (j = 0; j < n; j++) {
                if (bs[j][i] && ((j == 0) || !bs[parent[j]][i])) c++;
            }
            if (c > 1) break;
        }
        if (i < m) printf("NO\n");
        else {
            printf("YES\n");
            for (i = 1; i < n; i++) printf("%d %d\n",parent[i]+1,i+1);
        }

        for (i = 0; i < n; i++) adjList[i].clear(),bs[i].reset();
        edges.clear();
    }

    return 0;
}