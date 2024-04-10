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

int C[5000][5000];
LLI a[2025],b[2025];
int main() {
    int n,m;
    cin >> n >> m;

    int i,j;
    for (i = 0; i < 5000; i++) {
        C[i][0] = 1;
        for (j = 1; j <= i; j++) C[i][j] = (C[i-1][j-1]+C[i-1][j]) % MOD;
    }
    LLI ans = 0;
    for (i = 1; i < n; i++) {
        LLI s = 0;
        for (j = 0; j <= m; j++) {
            if (j > 0) a[j] = ((LLI) C[i+j-1][j-1]*C[m-j+i-1][i-1]) % MOD;
            else a[j] = 0;
            if (j < m) b[j] = ((LLI) C[n-i+m-j-1][m-j-1]*C[j+n-i-1][n-i-1]) % MOD;
            else b[j] = 0;
            s += a[j],s %= MOD;
            ans += 2*s*b[j],ans %= MOD;
        }
    }
    swap(n,m);
    for (i = 1; i < n; i++) {
        LLI s = 0;
        for (j = 0; j <= m; j++) {
            if (j > 0) a[j] = ((LLI) C[i+j-1][j-1]*C[m-j+i-1][i-1]) % MOD;
            else a[j] = 0;
            if (j < m) b[j] = ((LLI) C[n-i+m-j-1][m-j-1]*C[j+n-i-1][n-i-1]) % MOD;
            else b[j] = 0;
            ans += 2*s*b[j],ans %= MOD;
            s += a[j],s %= MOD;
        }
    }
    cout << ans << endl;

    return 0;
}