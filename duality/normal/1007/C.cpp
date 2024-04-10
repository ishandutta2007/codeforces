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

int query(LLI x,LLI y) {
    int r;
    cout << x << " " << y << endl;
    cin >> r;
    if (r == 0) exit(0);
    return r;
}
int solveRect(LLI l,LLI r,LLI d,LLI u) {
    LLI lx = l,rx = r,ly = d,ry = u;
    while ((lx <= rx) && (ly <= ry)) {
        LLI mx = (lx+rx) / 2;
        LLI my = (ly+ry) / 2;
        if ((long double) (rx-lx)*(u-ly) < (long double) (r-rx)*(ry-ly)) mx = rx;
        if ((long double) (ry-ly)*(r-lx) < (long double) (u-ry)*(rx-lx)) my = ry;
        int q = query(mx,my);
        if (q == 1) lx = mx+1;
        else if (q == 2) ly = my+1;
        else rx = mx-1,ry = my-1;
    }
    if (lx <= rx) solveRect(lx,rx,ry,u);
    else solveRect(rx,r,ly,ry);
    return 0;
}
int main() {
    LLI n;
    cin >> n;
    solveRect(1,n,1,n);
    return 0;
}