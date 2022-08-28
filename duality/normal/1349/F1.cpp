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

int fact[100001],A[5005][5005],C[5005][5005];
int main() {
    int n;
    cin >> n;

    int i,j;
    C[0][0] = 1;
    fact[0] = 1;
    for (i = 1; i <= n; i++) fact[i] = ((LLI) i*fact[i-1]) % MOD;
    for (i = 1; i <= n; i++) {
        A[i][0] = C[i][0] = 1;
        for (j = 1; j <= i; j++) {
            A[i][j] = ((LLI) (i-j)*A[i-1][j-1]+(LLI) (j+1)*A[i-1][j]) % MOD;
            C[i][j] = (C[i-1][j-1]+C[i-1][j]) % MOD;
        }
    }
    for (i = 1; i <= n; i++) {
        LLI ans = 0;
        for (j = 1; j <= n; j++) ans += ((((LLI) C[n][j]*fact[n-j]) % MOD)*A[j][i-1]) % MOD;
        printf("%I64d ",ans % MOD);
    }
    printf("\n");

    return 0;
}