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

pii p[1125000];
int parent[1500],size[1500],e[1500],dp[1500][1501],temp[1501];
int find(int n) {
    if (parent[n] != n) parent[n] = find(parent[n]);
    return parent[n];
}
int main() {
    int i,j;
    int n,a;
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) scanf("%d",&a),p[a] = mp(i,j);
    }

    int k;
    for (i = 0; i < n; i++) parent[i] = i,size[i] = 1,dp[i][1] = 1;
    for (i = 1; i <= n*(n-1)/2; i++) {
        int u = find(p[i].first),v = find(p[i].second);
        if (u == v) {
            e[u]++;
            if (e[u] == size[u]*(size[u]-1)/2) dp[u][1]++;
        }
        else {
            for (j = 0; j <= size[u]; j++) {
                for (k = 0; k <= size[v]; k++) temp[j+k] = (temp[j+k]+(LLI) dp[u][j]*dp[v][k]) % MOD;
            }
            for (j = 0; j <= size[u]+size[v]; j++) dp[u][j] = temp[j],temp[j] = 0;
            parent[v] = u,size[u] += size[v],e[u] += e[v]+1;
            if (e[u] == size[u]*(size[u]-1)/2) dp[u][1]++;
        }
    }
    for (i = 1; i <= n; i++) printf("%d ",dp[find(0)][i] % MOD);
    printf("\n");

    return 0;
}