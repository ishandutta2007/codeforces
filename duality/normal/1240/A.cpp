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

int p[200000];
LLI pre[200001];
int gcd(int a,int b) {
    int t;
    while (a > 0) t = b % a,b = a,a = t;
    return b;
}
int main() {
    int i;
    int q,n;
    int x,a,y,b;
    LLI k;
    scanf("%d",&q);
    while (q--) {
        scanf("%d",&n);
        for (i = 0; i < n; i++) scanf("%d",&p[i]);
        scanf("%d %d %d %d",&x,&a,&y,&b);
        scanf("%I64d",&k);

        sort(p,p+n,greater<int>());
        for (i = 0; i < n; i++) pre[i+1] = pre[i]+p[i];
        for (i = 1; i <= n; i++) {
            int aa = i/a,bb = i/b,ab = i/((LLI) (a/gcd(a,b))*b);
            aa -= ab,bb -= ab;
            LLI c = pre[ab]*(x+y);
            if (x > y) {
                c += (pre[aa+ab]-pre[ab])*x;
                c += (pre[aa+ab+bb]-pre[aa+ab])*y;
            }
            else {
                c += (pre[bb+ab]-pre[ab])*y;
                c += (pre[bb+ab+aa]-pre[bb+ab])*x;
            }
            if (c >= k*100) break;
        }
        if (i == n+1) printf("-1\n");
        else printf("%d\n",i);
    }

    return 0;
}