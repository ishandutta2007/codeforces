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

int lps[500001];
int main() {
    string s,t;
    cin >> s >> t;

    int i,j = -1;
    lps[0] = -1;
    for (i = 0; i < t.size(); i++) {
        while ((j >= 0) && (t[i] != t[j])) j = lps[j];
        lps[i+1] = ++j;
    }
    string ans = t;
    int c0 = 0,c1 = 0;
    for (i = 0; i < s.size(); i++) {
        if (s[i] == '0') c0++;
        else c1++;
    }
    for (i = 0; i < ans.size(); i++) {
        if (ans[i] == '0') c0--;
        else c1--;
    }
    if ((c0 < 0) || (c1 < 0)) {
        cout << s << endl;
        return 0;
    }
    int a0 = 0,a1 = 0;
    debug lps[t.size()];
    for (i = lps[t.size()]; i < t.size(); i++) {
        if (t[i] == '0') a0++;
        else a1++;
    }
    while ((c0 >= a0) && (c1 >= a1)) {
        c0 -= a0,c1 -= a1;
        for (i = lps[t.size()]; i < t.size(); i++) ans += t[i];
    }
    for (i = 0; i < c0; i++) ans += '0';
    for (i = 0; i < c1; i++) ans += '1';
    cout << ans << endl;

    return 0;
}