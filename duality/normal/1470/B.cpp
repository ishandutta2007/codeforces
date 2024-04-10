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

int f[1000001];
int a[300000],occ[1000001];
int main() {
    int i,j;
    for (i = 2; i <= 1000000; i++) {
        if (f[i] == 0) {
            for (j = 2*i; j <= 1000000; j += i) f[j] = i;
            f[i] = i;
        }
    }

    int t,n,q;
    LLI w;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (i = 0; i < n; i++) scanf("%d",&a[i]);

        for (i = 0; i < n; i++) {
            int x = a[i];
            int x2 = 1;
            while (x > 1) {
                if ((x2 % f[x]) == 0) x2 /= f[x];
                else x2 *= f[x];
                x /= f[x];
            }
            a[i] = x2,occ[x2]++;
        }
        int ans0 = 0,ans1 = 0;
        for (i = 0; i < n; i++) {
            ans0 = max(ans0,occ[a[i]]);
            if (!(occ[a[i]] & 1)) ans1 += occ[a[i]];
            else {
                if (a[i] == 1) ans1 += occ[a[i]];
            }
            occ[a[i]] = 0;
        }
        ans1 = max(ans1,ans0);

        scanf("%d",&q);
        for (i = 0; i < q; i++) {
            scanf("%I64d",&w);

            if (w == 0) printf("%d\n",ans0);
            else printf("%d\n",ans1);
        }
    }

    return 0;
}