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

int sum0 = 0,sum1 = 0;
int a[200000];
int w[200000];
int dp[55][55][55],I,M;
int inv(int n) {
    n %= MOD;
    int e = MOD-2,r = 1;
    while (e > 0) {
        if (e & 1) r = ((LLI) r*n) % MOD;
        e >>= 1;
        n = ((LLI) n*n) % MOD;
    }
    return r;
}
int findAns(int m,int c,int c0) {
    if (dp[m][c][c0] != -1) return dp[m][c][c0];
    if (c0 > sum0) return 0;
    if ((a[I] == 0) && (c > w[I])) return 0;
    if (m == 0) {
        if (a[I] == 0) return w[I]-c;
        else return w[I]+c;
    }

    LLI ans = 0;
    if (a[I] == 0) {
        // I is w[I]-c
        // 0: sum0-c0
        // 1: sum1+(M-m-c0)
        int sum = sum0-c0+sum1+M-m-c0;
        ans += ((LLI) (sum0-c0-(w[I]-c))*inv(sum) % MOD)*findAns(m-1,c,c0+1),ans %= MOD;
        ans += ((LLI) (w[I]-c)*inv(sum) % MOD)*findAns(m-1,c+1,c0+1),ans %= MOD;
        ans += ((LLI) (sum1+M-m-c0)*inv(sum) % MOD)*findAns(m-1,c,c0),ans %= MOD;
    }
    else {
        int sum = sum0-c0+sum1+M-m-c0;
        ans += ((LLI) (sum0-c0)*inv(sum) % MOD)*findAns(m-1,c,c0+1),ans %= MOD;
        ans += ((LLI) (sum1+M-m-c0-(w[I]+c))*inv(sum) % MOD)*findAns(m-1,c,c0),ans %= MOD;
        ans += ((LLI) (w[I]+c)*inv(sum) % MOD)*findAns(m-1,c+1,c0),ans %= MOD;
    }
    dp[m][c][c0] = ans;
    return ans;
}
int main() {
    int i;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);
    for (i = 0; i < n; i++) scanf("%d",&w[i]);

    int j,k,l;
    for (i = 0; i < n; i++) {
        if (a[i] == 0) sum0 += w[i];
        else sum1 += w[i];
    }
    M = m;
    for (i = 0; i < n; i++) {
        memset(dp,-1,sizeof(dp));
        I = i;
        printf("%d\n",findAns(m,0,0));
    }

    return 0;
}