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

string COPYR = "r10lt";
string COPYL = "l10rt";
string COPYU = "u10dt";
string COPYD = "d10ut";
string FLIPR = "r01lt";
string FLIPL = "l01rt";
string FLIPU = "u01dt";
string FLIPD = "d01ut";
string AND = "r10ltlur10ltd0ut";
string XOR = AND + FLIPR + "ll" + FLIPR + "ul" + FLIPR + "dr" + COPYR + "ll" + AND + FLIPU + "dr" + COPYL + AND + COPYL + COPYL + COPYL;
string ans;
int main() {
    int i;
    ans += "r0u0";
    for (i = 0; i < 35; i++) ans += "l";
    for (i = 0; i < 35; i++) ans += "0rt";
    ans += "0";
    for (i = 0; i < 35; i++) ans += "r";
    for (i = 0; i < 35; i++) ans += "lt";
    ans += "dl";
    for (i = 0; i < 35; i++) ans += "l";
    for (i = 0; i < 35; i++) ans += "0rt";
    ans += "0";
    for (i = 0; i < 35; i++) ans += "r";
    for (i = 0; i < 35; i++) ans += "lt";
    ans += "lld";
    for (i = 0; i < 35; i++) ans += "0l";
    for (i = 0; i < 35; i++) ans += "r";
    for (i = 0; i < 35; i++) {
        ans += "uu";
        ans += COPYR + COPYD + COPYD + COPYD + COPYL;
        ans += AND + "ul" + AND + "ul" + AND;
        ans += FLIPR + "dl" + FLIPR + "dl" + FLIPR;
        ans += AND + COPYU + COPYL + AND;
        ans += FLIPD + COPYL + COPYL + COPYL + COPYL + COPYU;
        ans += "ru";
        ans += XOR + "d" + XOR + COPYD + COPYD;
        ans += "luu";
    }
    ans += "ddr";
    cout << ans << endl;

    return 0;
}