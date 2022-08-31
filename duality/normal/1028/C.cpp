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

int x1[150000],y1[150000],x2[150000],y2[150000];
struct data {
    int m1,m2,mi;
    data() { m1 = m2 = mi = -2e9; }
    int insert(int i,int x) {
        if (x >= m1) m2 = m1,m1 = x,mi = i;
        else if (x >= m2) m2 = x;
        return 0;
    }
    int query(int i) {
        if (i == mi) return m2;
        else return m1;
    }
};
data a,b,c,d;
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);

    for (i = 0; i < n; i++) a.insert(i,x1[i]),b.insert(i,-x2[i]),c.insert(i,y1[i]),d.insert(i,-y2[i]);
    for (i = 0; i < n; i++) {
        int l = a.query(i);
        int r = -b.query(i);
        int dd = c.query(i);
        int u = -d.query(i);
        if ((l <= r) && (dd <= u)) {
            printf("%d %d\n",l,dd);
            return 0;
        }
    }

    return 0;
}