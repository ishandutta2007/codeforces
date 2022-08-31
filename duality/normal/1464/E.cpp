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

vi adjList[100000];
int nim[100000],occ[512];
int doDFS(int u) {
    if (nim[u] != -1) return 0;
    int i;
    set<int> S;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        doDFS(v);
        S.insert(nim[v]);
    }
    nim[u] = 0;
    while (S.count(nim[u])) nim[u]++;
    return 0;
}
int mat[512][513];
int inv(LLI n) {
    LLI r = 1;
    int e = MOD-2;
    while (e > 0) {
        if (e & 1) r = (r*n) % MOD;
        e >>= 1;
        n = (n*n) % MOD;
    }
    return r;
}
int main() {
    int i;
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) {
        scanf("%d %d",&u,&v);
        adjList[u-1].pb(v-1);
    }

    int j,k;
    m = 0;
    fill(nim,nim+n,-1);
    for (i = 0; i < n; i++) {
        if (nim[i] == -1) doDFS(i);
        occ[nim[i]]++,m = max(m,nim[i]);
    }
    m = 512;
    for (i = 0; i < m; i++) {
        mat[i][i] = n+1;
        for (j = 0; j < m; j++) {
            mat[i][i^j] += MOD-occ[j];
            mat[i][i^j] %= MOD;
        }
        mat[i][m] = (i != m-1);
    }
    for (i = 0; i < m; i++) {
        for (j = i; j < m; j++) {
            if (mat[j][i] != 0) break;
        }
        int p = j;
        if (p != i) {
            for (k = 0; k <= m; k++) swap(mat[i][k],mat[p][k]);
        }
        for (j = i+1; j < m; j++) {
            LLI f = ((LLI) mat[j][i]*inv(mat[i][i])) % MOD;
            for (k = i; k <= m; k++) {
                mat[j][k] -= (mat[i][k]*f) % MOD;
                if (mat[j][k] < 0) mat[j][k] += MOD;
            }
        }
    }
    LLI ans = ((LLI) mat[m-1][m]*inv(mat[m-1][m-1])) % MOD;
    cout << ans << endl;

    return 0;
}