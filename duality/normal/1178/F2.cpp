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

int c[1000002];
int dp[501][501];
int getAns(int n,int *c) {
    int i,j,k,l;
    for (i = 0; i < n; i++) dp[i][i] = 1;
    for (i = 2; i <= n; i++) {
        for (j = 0; j <= n-i; j++) {
            k = j+i-1;
            int mi = j;
            for (l = j; l <= k; l++) {
                if (c[l] < c[mi]) mi = l;
            }
            LLI a = 0,b = 0;
            for (l = j; l <= mi; l++) {
                LLI c = (l == j) ? 1:dp[j][l-1];
                LLI d = (l == mi) ? 1:dp[l][mi-1];
                a += (c*d) % MOD;
                if (a >= MOD) a -= MOD;
            }
            for (l = mi; l <= k; l++) {
                LLI c = (l == mi) ? 1:dp[mi+1][l];
                LLI d = (l == k) ? 1:dp[l+1][k];
                b += (c*d) % MOD;
                if (b >= MOD) b -= MOD;
            }
            dp[j][k] = (a*b) % MOD;
        }
    }
    return dp[0][n-1];
}
pii p[501];
int sparse[1000002][20];
pii nxt[1000005];
int visited[1000005];
int c2[501];
int main() {
    int i;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 1; i <= m; i++) scanf("%d",&c[i]);
    m += 2,n++;

    int j;
    for (i = 0; i < n; i++) p[i] = mp(-1,-1);
    for (i = 0; i < m; i++) {
        if (p[c[i]].first == -1) p[c[i]] = mp(i,i);
        else p[c[i]].second = i;
    }
    for (i = 0; i < m; i++) sparse[i][0] = c[i];
    for (i = 1; (1 << i) <= m; i++) {
        for (j = 0; j <= m-(1 << i); j++) sparse[j][i] = min(sparse[j][i-1],sparse[j+(1 << (i-1))][i-1]);
    }
    for (i = 0; i < n; i++) {
        int l = log2(p[i].second-p[i].first+1);
        if (min(sparse[p[i].first][l],sparse[p[i].second-(1 << l)+1][l]) < i) {
            printf("0\n");
            return 0;
        }
    }
    LLI ans = 1;
    for (i = 0; i <= m+1; i++) nxt[i] = mp(-1,-1);
    for (i = 0; i < n; i++) nxt[p[i].first] = mp(p[i].second+1,i);
    for (i = 0; i < m; i++) {
        if (!visited[i] && (nxt[i].first != -1)) {
            int x = 0,u = i;
            while (nxt[u].first != -1) visited[u] = 1,c2[x++] = nxt[u].second,u = nxt[u].first;
            visited[u] = 1;
            ans *= getAns(x,c2),ans %= MOD;
        }
    }
    printf("%I64d\n",ans);

    return 0;
}