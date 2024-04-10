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

vpii pos1,pos2;
int main() {
    int n;
    cin >> n;

    int i,j,a;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if ((i+j) & 1) pos1.pb(mp(i,j));
            else pos2.pb(mp(i,j));
        }
    }
    for (i = 0; i < n*n; i++) {
        cin >> a;
        if (a == 1) {
            if (!pos2.empty()) {
                cout << 2 << " " << pos2.back().first << " " << pos2.back().second << endl;
                pos2.pop_back();
            }
            else {
                cout << 3 << " " << pos1.back().first << " " << pos1.back().second << endl;
                pos1.pop_back();
            }
        }
        else if (a == 2) {
            if (!pos1.empty()) {
                cout << 1 << " " << pos1.back().first << " " << pos1.back().second << endl;
                pos1.pop_back();
            }
            else {
                cout << 3 << " " << pos2.back().first << " " << pos2.back().second << endl;
                pos2.pop_back();
            }
        }
        else {
            if (!pos1.empty()) {
                cout << 1 << " " << pos1.back().first << " " << pos1.back().second << endl;
                pos1.pop_back();
            }
            else {
                cout << 2 << " " << pos2.back().first << " " << pos2.back().second << endl;
                pos2.pop_back();
            }
        }
    }

    return 0;
}