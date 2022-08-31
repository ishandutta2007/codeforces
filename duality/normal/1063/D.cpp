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

LLI solve(LLI a,LLI b,LLI c,LLI Mx,LLI My) {
    if (c < 0) return -2;
    LLI l = (c+a-1)/a,r = (My+c)/a;
    if (b != 0) l = max(l,(c-Mx+b-1)/b),r = min(r,c/b);
    else if (c > Mx) return -2;
    if (l <= r) return r;
    else return -2;
}
int main() {
    LLI n,l,r,k;
    cin >> n >> l >> r >> k;
    LLI d = ((r-l+n) % n)+1;

    if (n < pow(k,(double) 1/3)) {
        int i,j;
        int ans = -1;
        for (i = 0; i <= d; i++) {
            for (j = 0; j <= n-d; j++) {
                LLI x = k-d-i;
                if ((x >= 0) && ((x % (n+i+j)) == 0)) ans = max(ans,i+j);
                if (i > 0) {
                    x = k-d-i+1;
                    if ((x >= 0) && ((x % (n+i+j)) == 0)) ans = max(ans,i+j);
                }
            }
        }
        cout << ans << endl;
    }
    else {
        int i;
        LLI ans = -1;
        for (i = 0; i <= k/n; i++) {
            ans = max(ans,solve(i+1,i,k-i*n-d,d,n-d));
            if (d > 0) ans = max(ans,solve(i+1,i,k-i*n-d-i,d-1,n-d)+1);
        }
        cout << ans << endl;
    }

    return 0;
}