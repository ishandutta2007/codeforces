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
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int inv(int n) {
    int e = MOD-2,r = 1;
    while (e > 0) {
        if (e & 1) r = ((LLI) r*n) % MOD;
        e >>= 1;
        n = ((LLI) n*n) % MOD;
    }
    return r;
}
int a[3000];
int dp[3001][1 << 10],dp2[3001][3001],pow2[3001],diff[3001],num[3000],ans[3001];
int main() {
    int i;
    int n,c;
    scanf("%d %d",&n,&c);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),a[i]--;

    int j,k;
    if (c <= 10) {
        dp[0][0] = 1;
        for (i = 0; i < n; i++) {
            for (j = n/c; j >= 0; j--) {
                for (k = (1 << c)-1; k >= 0; k--) {
                    dp[j][k|(1 << a[i])] += dp[j][k];
                    if (dp[j][k|(1 << a[i])] >= MOD) dp[j][k|(1 << a[i])] -= MOD;
                }
                if (j < n/c) {
                    dp[j+1][0] += dp[j][(1 << c)-1],dp[j][(1 << c)-1] = 0;
                    if (dp[j+1][0] >= MOD) dp[j+1][0] -= MOD;
                }
            }
        }
        for (i = 0; i <= n; i++) {
            if (i <= n/c) {
                int ans = (i == 0) ? MOD-1:0;
                for (j = 0; j < (1 << c); j++) {
                    ans += dp[i][j];
                    if (ans >= MOD) ans -= MOD;
                }
                printf("%d ",ans);
            }
            else printf("0 ");
        }
        printf("\n");
    }
    else {
        pow2[0] = 1;
        for (i = 1; i <= n; i++) {
            pow2[i] = (2*pow2[i-1]) % MOD;
            if (i == 1) diff[i] = 1;
            else diff[i] = ((LLI) (pow2[i]-1)*inv(pow2[i-1]-1)) % MOD;
        }
        dp2[0][0] = 1;
        for (i = 0; i < n; i++) {
            int x = 0;
            LLI w = 0;
            memset(num,0,sizeof(num));
            for (j = i-1; j >= 0; j--) {
                if (a[j] != a[i]) {
                    x += num[a[j]] == 0;
                    num[a[j]]++;
                    if (x == c-1) {
                        w = 1;
                        for (k = 0; k < c; k++) {
                            if (k != a[i]) w = (w*(pow2[num[k]]-1)) % MOD;
                        }
                        x = c;
                    }
                    else if (x == c) w = (w*diff[num[a[j]]]) % MOD;
                }
                if (w > 0) {
                    int B = min(n/c,j/c+1);
                    for (k = 1; k <= B; k++) dp2[i+1][k] = (dp2[i+1][k]+w*dp2[j][k-1]) % MOD;
                }
            }
        }
        int x = 0;
        LLI w = 0;
        memset(num,0,sizeof(num));
        ans[0] = MOD-1;
        for (i = n; i >= 0; i--) {
            for (j = 0; j <= n/c; j++) {
                ans[j] += ((LLI) dp2[i][j]*(pow2[n-i]+MOD-w)) % MOD;
                if (ans[j] >= MOD) ans[j] -= MOD;
            }
            if (i > 0) {
                x += num[a[i-1]] == 0;
                num[a[i-1]]++;
                if (x == c) {
                    w = 1;
                    for (j = 0; j < c; j++) {
                        if (j != a[i-1]) w = (w*(pow2[num[j]]-1)) % MOD;
                    }
                    x = c+1;
                }
                else if (x == c+1) w = (w*diff[num[a[i-1]]]) % MOD;
            }
        }
        for (i = 0; i <= n; i++) printf("%d ",ans[i]);
        printf("\n");
    }

    return 0;
}