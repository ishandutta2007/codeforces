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

int k[1000000];
int modPow(int b,int e) {
    int r = 1;
    while (e > 0) {
        if (e & 1) r = ((LLI) r*b) % MOD;
        e >>= 1;
        b = ((LLI) b*b) % MOD;
    }
    return r;
}
int main() {
    int i,j;
    int t,n,p;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&p);
        for (i = 0; i < n; i++) scanf("%d",&k[i]);
        if (p == 1) {
            printf("%d\n",n & 1);
            continue;
        }

        sort(k,k+n,greater<int>());
        LLI ans = modPow(p,k[0]),c = 1;
        for (i = 1; i < n; i++) {
            if (c != 0) {
                for (j = 0; j < k[i-1]-k[i]; j++) {
                    if (c > 1e9) break;
                    else c *= p;
                }
            }
            if (c > 0) c--,ans -= modPow(p,k[i]);
            else c = 1,ans += modPow(p,k[i]);
        }
        ans %= MOD;
        if (ans < 0) ans += MOD;
        printf("%I64d\n",ans);
    }

    return 0;
}