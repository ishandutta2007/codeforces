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
#define MOD 31607

int inv(int n) {
    int e = MOD-2,r = 1;
    while (e > 0) {
        if (e & 1) r = ((LLI) r*n) % MOD;
        e >>= 1;
        n = ((LLI) n*n) % MOD;
    }
    return r;
}
int a[21][21],ii[21][21],o[21][21];
int pp[21];
int f(int c,int n) {
    if (c == n) {
        int i,p = 1;
        for (i = 0; i < n; i++) p = (p*(1-pp[i])) % MOD;
        return p;
    }

    int i,p = 1;
    for (i = 0; i < n; i++) {
        pp[i] *= a[c][i],pp[i] %= MOD;
        p *= a[c][i],p %= MOD;
    }
    int ans = f(c+1,n);
    for (i = 0; i < n; i++) pp[i] *= ii[c][i],pp[i] %= MOD;
    ans -= p*f(c+1,n),ans %= MOD;
    return ans;
}
int notWin(int n) {
    int i,j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) ii[i][j] = inv(a[i][j]);
        pp[i] = 1;
    }
    return f(0,n);
}
int main() {
    int i,j;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) scanf("%d",&a[i][j]),o[i][j] = a[i][j] = (a[i][j]*inv(10000)) % MOD;
    }

    int ans = notWin(n);
    int p = 1;
    for (i = 0; i < n; i++) p *= a[i][i],p %= MOD,a[i][i] = 1;
    ans -= p*notWin(n),ans %= MOD;
    for (i = 0; i < n; i++) a[i][i] = o[i][i];
    p = 1;
    for (i = 0; i < n; i++) p *= a[i][n-i-1],p %= MOD,a[i][n-i-1] = 1;
    ans -= p*notWin(n),ans %= MOD;
    for (i = 0; i < n; i++) p *= a[i][i],p %= MOD,a[i][i] = 1;
    ans += p*notWin(n),ans %= MOD;
    ans = 1-ans,ans %= MOD;
    if (ans < 0) ans += MOD;
    printf("%d\n",ans);

    return 0;
}