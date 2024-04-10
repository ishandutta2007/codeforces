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
#define MOD 998244353

int grid[1000][500];
int vv[1000];
int seen[500][500];
vi all;
vi adjList[1000];
int visited[1000];
int doDFS(int u,int c) {
    visited[u] = 1;
    if (c) vv[u] = 1;
    for (int v: adjList[u]) {
        if (!visited[v]) doDFS(v,!c);
    }
    return 0;
}
int main() {
    int i,j;
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (i = 0; i < 2*n; i++) {
            for (j = 0; j < n; j++) scanf("%d",&grid[i][j]),grid[i][j]--;
        }

        int f = 1;
        for (i = 0; i < 2*n; i++) vv[i] = 0;
        while (f) {
            f = 0;
            for (i = 0; i < 2*n; i++) {
                if (vv[i] == 0) {
                    for (j = 0; j < n; j++) {
                        if (seen[j][grid[i][j]]) break;
                    }
                    if (j < n) {
                        vv[i] = -1;
                        f = 1;
                    }
                }
            }
            for (i = 0; i < n; i++) {
                vi occ(n);
                for (j = 0; j < 2*n; j++) {
                    if (vv[j] == 0) occ[grid[j][i]]++;
                }
                int p = -1;
                for (j = 0; j < n; j++) {
                    if (!seen[i][j] && (occ[j] == 1)) {
                        p = j;
                        break;
                    }
                }
                if (p != -1) {
                    for (j = 0; j < 2*n; j++) {
                        if ((vv[j] == 0) && (grid[j][i] == p)) break;
                    }
                    p = j;
                    vv[p] = 1,f = 1;
                    for (j = 0; j < n; j++) seen[j][grid[p][j]] = 1;
                }
            }
        }
        printArr(vv,2*n);
        for (i = 0; i < 2*n; i++) {
            if (vv[i] == 0) all.pb(i);
        }
        int k;
        for (i = 0; i < all.size(); i++) {
            for (j = i+1; j < all.size(); j++) {
                for (k = 0; k < n; k++) {
                    if (grid[all[i]][k] == grid[all[j]][k]) break;
                }
                if (k < n) {
                    adjList[all[i]].pb(all[j]);
                    adjList[all[j]].pb(all[i]);
                }
            }
        }
        int ans = 1;
        fill(visited,visited+2*n,0);
        for (i = 0; i < all.size(); i++) {
            if (!visited[all[i]]) doDFS(all[i],0),ans = (2*ans) % MOD;
        }
        printf("%d\n",ans);
        for (i = 0; i < 2*n; i++) {
            if (vv[i] == 1) printf("%d ",i+1);
        }
        printf("\n");

        memset(seen,0,sizeof(seen));
        all.clear();
        for (i = 0; i < 2*n; i++) adjList[i].clear();
    }

    return 0;
}