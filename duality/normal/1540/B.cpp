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
#define MOD 1000000007

int inv(int n) {
    int e = MOD-2,r = 1;
    while (e > 0) {
        if (e & 1) r = ((LLI) r*n) % MOD;
        e >>= 1;
        n = ((LLI) n*n) % MOD;
    }
    return r;
}
vi adjList[200];
vi path;
int doDFS(int u,int p,int e) {
    path.pb(u);
    if (u == e) return 1;
    for (int v: adjList[u]) {
        if (v != p) {
            if (doDFS(v,u,e)) return 1;
        }
    }
    path.pop_back();
    return 0;
}
int bad[200],s = 0;
int doDFS2(int u,int p) {
    s++;
    for (int v: adjList[u]) {
        if ((v != p) && !bad[v]) doDFS2(v,u);
    }
    return 0;
}
int dp[201][201];
int main() {
    int i;
    int n,u,v;
    scanf("%d",&n);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }

    int j,k;
    LLI ans = 0;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0) dp[i][j] = 1;
            else if (j == 0) dp[i][j] = 0;
            else dp[i][j] = ((LLI) (dp[i-1][j]+dp[i][j-1])*inv(2)) % MOD;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            doDFS(i,-1,j);
            for (int u: path) bad[u] = 1;
            for (k = 0; k < path.size(); k++) {
                s = 0,doDFS2(path[k],-1);
                if (k == 0) ans += (LLI) s*inv(n);
                else if (k < path.size()-1) {
                    LLI p = dp[k][path.size()-k-1];
                    p = (p*inv(n)) % MOD;
                    ans += s*p;
                }
                ans %= MOD;
            }
            path.clear(),memset(bad,0,sizeof(bad));
        }
    }
    printf("%I64d\n",ans);

    return 0;
}