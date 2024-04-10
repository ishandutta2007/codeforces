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

int n,m;
int scan(int r,int c) {
    int s;
    cout << "SCAN " << r << " " << c << endl;
    cin >> s;
    return s;
}
int dig(int r,int c) {
    int s;
    cout << "DIG " << r << " " << c << endl;
    cin >> s;
    return s;
}
int main() {
    int i;
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;

        int p = scan(1,1),q = scan(n,1);
        p += 4,q -= 2*(n-1);
        int pp = (p+q)/2,qq = (p-q)/2;
        int u = scan(1,pp/2),v = scan(qq/2,1);
        u -= qq-2,v -= pp-2;
        int x = (pp+u)/2,y = (qq+v)/2;
        if ((1 <= x) && (x <= m) && (1 <= y) && (y <= n) && dig(y,x)) {
            x = (pp-u)/2,y = (qq-v)/2;
            dig(y,x);
        }
        else {
            y = (qq-v)/2;
            dig(y,x);
            x = (pp-u)/2,y = (qq+v)/2;
            dig(y,x);
        }
    }

    return 0;
}