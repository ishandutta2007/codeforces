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

LLI h[1000000],a[1000000],hh[1000000];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        scanf("%I64d",&h[i]);
        //h[i]=((i==0)?0:h[i-1])+(((i>=n/4)&&(i<=3*n/4))?2:0);
        //h[i]=rand() % 10;
        //if(i>0)h[i]+=h[i-1];
    }

    for (i = 0; i < n-1; i++) a[i] = h[i+1]-h[i];
    while (1) {
        int f = 0,f2 = 0;
        for (i = 0; i < n-1; i++) {
            if (a[i] == 0) f2++;
        }
        if (f2 <= 1) break;
        for (i = 0; i < n-1; i++) {
            LLI c = a[i]/2;
            if (c > 0) f = 1;
            a[i] -= 2*c;
            if (i > 0) a[i-1] += c;
            if (i < n-2) a[i+1] += c;
        }
        if (!f) break;
        printArr(a,n-1);
    }
    int f2 = 0;
    for (i = 0; i < n-1; i++) {
        if (a[i] == 0) f2++;
    }
    if (f2 <= 1) {
        LLI s = 0;
        for (i = 0; i < n-1; i++) s += (LLI) (i+1)*a[i],s %= n;
        LLI s2 = 0;
        for (i = 0; i < n-1; i++) s2 += i+1,s2 %= n;
        s = (s2-s+n) % n;
        for (i = 0; i < n-1; i++) a[i] = (i+1 == s) ? 0:1;
    }
    printArr(a,n-1);
    LLI sum = 0,sum2 = 0;
    for (i = 0; i < n; i++) sum += h[i];
    for (i = 0; i < n-1; i++) {
        if (a[i] == 1) sum2 += n-1-i;
    }
    sum -= sum2,sum /= n;
    hh[0] = sum;
    for (i = 1; i < n; i++) hh[i] = hh[i-1]+a[i-1];
    for (i = 0; i < n; i++) printf("%lld ",hh[i]);
    printf("\n");

    return 0;
}