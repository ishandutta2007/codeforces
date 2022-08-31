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

LLI pos(LLI b,int k) {
    if (b == 0) return (LLI) k*(k+1)/2;
    LLI p = pos(b/k,k),m = b % k;
    if (m < (p-1)/k) return (LLI) k*(k+1)/2-m;
    else return (LLI) k*(k+1)/2-m+min(k*(m+1)-p+1,(LLI) k);
}
int main() {
    int t,k;
    LLI n;
    scanf("%d",&t);
    while (t--) {
        scanf("%I64d %d",&n,&k);
        LLI p = pos(n/((LLI) k*k+1),k);
        if (p == (n % ((LLI) k*k+1))) printf("%I64d\n",(k+1)*(n/((LLI) k*k+1)+1));
        else {
            LLI c = (n-1)/((LLI) k*k+1) + (p <= ((n-1) % ((LLI) k*k+1)));
            printf("%I64d\n",(n-c)+(n-c-1)/k);
        }
    }

    return 0;
}