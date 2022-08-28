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

int a[500000],b[500000];
vpii adjList[500000];
int visited[500000],parent[500000],pp[500000];
int other[500000];
int doDFS(int u,int p) {
    int i;
    visited[u] = 1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i].first;
        if (visited[v] == 0) parent[v] = u,pp[v] = adjList[u][i].second,doDFS(v,u);
        else if ((v != p) && (visited[v] == 1)) {
            vi edges;
            edges.pb(adjList[u][i].second);
            int w = u;
            while (w != v) edges.pb(pp[w]),w = parent[w];
            int x = min_element(edges.begin(),edges.end())-edges.begin();
            int y = max_element(edges.begin(),edges.end())-edges.begin();
            w = x;
            while (w != y) {
                if (edges[w] > edges[(w+1) % edges.size()]) break;
                else w = (w+1) % edges.size();
            }
            if (w == y) {
                w = x;
                while (w != y) {
                    if (edges[w] > edges[(w+edges.size()-1) % edges.size()]) break;
                    else w = (w+edges.size()-1) % edges.size();
                }
                if (w == y) other[edges[x]] = edges[y];
            }
        }
    }
    visited[u] = 2;
    return 0;
}
int dp[500000],num[500000];
int main() {
    int i;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) {
        scanf("%d %d",&a[i],&b[i]);
        a[i]--,b[i]--,other[i] = -1;
        adjList[a[i]].pb(mp(b[i],i));
        adjList[b[i]].pb(mp(a[i],i));
    }
    doDFS(0,-1);
    for (i = 0; i < n; i++) dp[i] = 1;
    for (i = m-1; i >= 0; i--) {
        num[i] = dp[a[i]]+dp[b[i]];
        if (other[i] != -1) num[i] -= num[other[i]];
        dp[a[i]] = dp[b[i]] = num[i];
    }
    for (i = 0; i < n; i++) printf("%d ",dp[i]-1);
    printf("\n");
    return 0;
}