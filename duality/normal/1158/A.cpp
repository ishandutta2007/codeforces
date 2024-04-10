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

int b[100000],g[100000];
int main() {
    int i;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) scanf("%d",&b[i]);
    for (i = 0; i < m; i++) scanf("%d",&g[i]);
    sort(b,b+n);
    sort(g,g+m);

    if (b[n-1] > g[0]) {
        printf("-1\n");
        return 0;
    }
    else if (n == 1) {
        LLI ans = 0;
        if (b[0] != g[0]) {
            printf("-1\n");
            return 0;
        }
        for (i = 0; i < m; i++) ans += g[i];
        printf("%I64d\n",ans);
        return 0;
    }
    else if (m == 1) {
        LLI ans = 0;
        if (b[n-1] != g[0]) {
            printf("-1\n");
            return 0;
        }
        for (i = 0; i < n; i++) ans += b[i];
        printf("%I64d\n",ans);
        return 0;
    }
    LLI ans = 0;
    for (i = 0; i < n; i++) ans += (LLI) b[i]*m;
    for (i = 1; i < m; i++) ans += g[i]-b[n-1];
    if (b[n-1] == g[0]) ans += g[0]-b[n-1];
    else ans += g[0]-b[n-2];
    printf("%I64d\n",ans);

    return 0;
}