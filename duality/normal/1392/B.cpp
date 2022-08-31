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

int a[200000];
int main() {
    int i;
    int t,n;
    LLI k;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %I64d",&n,&k);
        for (i = 0; i < n; i++) scanf("%d",&a[i]);

        if (k < 5) {
            while (k--) {
                int m = a[0];
                for (i = 0; i < n; i++) m = max(m,a[i]);
                for (i = 0; i < n; i++) a[i] = m-a[i];
            }
        }
        else {
            int c = 0;
            while (c < 5) {
                int m = a[0];
                for (i = 0; i < n; i++) m = max(m,a[i]);
                for (i = 0; i < n; i++) a[i] = m-a[i];
                c++;
            }
            if ((k-5) & 1) {
                int m = a[0];
                for (i = 0; i < n; i++) m = max(m,a[i]);
                for (i = 0; i < n; i++) a[i] = m-a[i];
            }
        }
        for (i = 0; i < n; i++) printf("%d ",a[i]);
        printf("\n");
    }

    return 0;
}