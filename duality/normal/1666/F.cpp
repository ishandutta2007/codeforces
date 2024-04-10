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

int a[5000],C[5001][5001],dp[5001][5001];
int main() {
    int i,j,k;
    int t,n;
    for (i = 0; i <= 5000; i++) {
        C[i][0] = 1;
        for (j = 1; j <= i; j++) C[i][j] = (C[i-1][j-1]+C[i-1][j]) % MOD;
    }
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (i = 0; i < n; i++) scanf("%d",&a[i]);

        if (a[n-1] > a[n-2]) {
            n--;
            vi v;
            for (i = 0; i < n; i++) {
                if ((i > 0) && (a[i-1] == a[i])) v.back()++;
                else v.pb(1);
            }
            for (i = 0; i <= v.size(); i++) {
                for (j = 0; j <= n; j++) dp[i][j] = 0;
            }
            int s = 0;
            dp[0][0] = 1;
            for (i = 0; i < v.size(); i++) {
                for (j = 0; j <= (n+1)/2; j++) {
                    if (dp[i][j] == 0) continue;
                    if (j == 0) {
                        dp[i+1][j] = (dp[i+1][j]+(LLI) C[s+v[i]][v[i]]*dp[i][j]) % MOD;
                        dp[i+1][j+1] = (dp[i+1][j+1]+(LLI) C[s+v[i]-1][v[i]-1]*dp[i][j]) % MOD;
                    }
                    else {
                        assert(2*j-1 <= s);
                        int x = s-(2*j-1);
                        dp[i+1][j] = (dp[i+1][j]+(LLI) C[x+v[i]][v[i]]*dp[i][j]) % MOD;
                        if (x > 0) dp[i+1][j+1] = (dp[i+1][j+1]+(LLI) C[x-1+v[i]-1][v[i]-1]*dp[i][j]) % MOD;
                    }
                }
                s += v[i];
            }
            printf("%d\n",dp[v.size()][(n+1)/2]);
        }
        else printf("0\n");
    }

    return 0;
}