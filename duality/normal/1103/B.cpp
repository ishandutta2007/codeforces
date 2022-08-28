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


int main() {
    int i;
    string s;
    while (1) {
        cin >> s;
        if (s == "end") break;
        assert(s == "start");

        cout << "? 0 1" << endl;
        cin >> s;
        if (s == "x") {
            cout << "! 1" << endl;
            continue;
        }
        int l,r;
        i = 1;
        while (1) {
            cout << "? " << i << " " << 2*i << endl;
            cin >> s;
            if (s == "x") {
                l = i+1,r = 2*i;
                break;
            }
            else i *= 2;
        }
        while (l < r-2) {
            int m = (l+r) / 2;
            int b = m/2;
            cout << "? " << b << " " << 2*b << endl;
            cin >> s;
            if (s == "x") r = 2*b;
            else l = 2*b+1;
        }
        if (l < r) {
            cout << "? " << l << " " << l+1 << endl;
            cin >> s;
            if (s == "x") l++;
        }
        cout << "! " << l << endl;
    }

    return 0;
}