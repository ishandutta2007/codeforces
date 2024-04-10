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

LLI a[1 << 9][1 << 9],a2[1 << 9][1 << 9];
int x[99],y[99];
int main() {
    int i,j;
    int k,t;
    scanf("%d",&k);
    for (i = 0; i < (1 << k); i++) {
        for (j = 0; j < (1 << k); j++) scanf("%I64d",&a[i][j]);
    }
    scanf("%d",&t);
    for (i = 0; i < t; i++) scanf("%d %d",&x[i],&y[i]),x[i]--,y[i]--;

    int p,q;
    for (i = 0; i < k; i++) {
        for (j = 0; j < t; j++) {
            for (p = 0; p < (1 << k); p++) {
                for (q = 0; q < (1 << k); q++) a2[(p+(x[j] << i)) & ((1 << k)-1)][(q+(y[j] << i)) & ((1 << k)-1)] ^= a[p][q];
            }
        }
        for (p = 0; p < (1 << k); p++) {
            for (q = 0; q < (1 << k); q++) a[p][q] = a2[p][q],a2[p][q] = 0;
        }
    }
    int ans = 0;
    for (i = 0; i < (1 << k); i++) {
        for (j = 0; j < (1 << k); j++) ans += (a[i][j] != 0);
    }
    printf("%d\n",ans);

    return 0;
}