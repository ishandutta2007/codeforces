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

int a[500000],pre[1000001];
int best[1000002];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),pre[a[i]]++;
    for (i = 1; i <= 1000000; i++) {
        if (pre[i] > 0) best[i+1] = i;
        else best[i+1] = best[i];
        pre[i] += pre[i-1];
    }

    int j;
    LLI ans = 0;
    sort(a,a+n);
    int x = max(a[n-1]/2,a[max(n-2,0)]);
    for (i = 2; i <= 500000; i++) {
        LLI c = 0;
        for (j = 1; j <= 500000/i; j++) c += (LLI) j*(pre[(j+1)*i-1]-pre[j*i-1]);
        x = min((LLI) x,c);
        while (c-2*(x/i) < x) x--;
        while (x >= 2) {
            LLI lose0 = 1e18,lose1 = 1e18,lose2 = 1e18;
            for (j = x/i; j <= 500000/i; j++) {
                int p = best[(j+1)*i-1];
                if (pre[(j+1)*i-1] > pre[(j+1)*i-2]) p = (j+1)*i-1;
                if (p >= j*i) {
                    if (p >= 2*x) lose0 = min(lose0,(LLI) p/i-(p-2*x)/i);
                    if (p >= x) {
                        int l = p/i-(p-x)/i;
                        if (l <= lose1) lose2 = lose1,lose1 = l;
                        else if (l <= lose2) lose2 = l;
                        if (pre[p] <= pre[p-1]+1) p = best[p];
                        if ((p >= j*i) && (p >= x)) {
                            l = p/i-(p-x)/i;
                            if (l <= lose1) lose2 = lose1,lose1 = l;
                            else if (l <= lose2) lose2 = l;
                        }
                    }
                }
            }
            if (c-min(lose0,lose1+lose2) >= x) break;
            else x--;
        }
        if (x >= 2) ans = max(ans,(LLI) x*i);
    }
    printf("%I64d\n",ans);

    return 0;
}