#define DEBUG 1

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

vi a,b;
int x[300000];
int main() {
    string s;
    cin >> s;

    int i,j;
    for (i = 0; i < s.size(); i++) {
        if (s[i] == '0') a.pb(i);
        else b.pb(i);
    }
    fill(x,x+s.size(),-1);
    for (i = 0; i < a.size(); i++) {
        int yes = 1;
        for (j = i-1; j >= 0; j--) {
            if ((2*a[i]-a[j] < s.size()) && (s[2*a[i]-a[j]] == '0')) break;
            else if (2*a[i]-a[j] >= s.size()) {
                yes = 0;
                break;
            }
        }
        if (yes && (j >= 0)) x[2*a[i]-a[j]] = max(x[2*a[i]-a[j]],a[j]);
    }
    for (i = 0; i < b.size(); i++) {
        int yes = 1;
        for (j = i-1; j >= 0; j--) {
            if ((2*b[i]-b[j] < s.size()) && (s[2*b[i]-b[j]] == '1')) break;
            else if (2*b[i]-b[j] >= s.size()) {
                yes = 0;
                break;
            }
        }
        if (yes && (j >= 0)) x[2*b[i]-b[j]] = max(x[2*b[i]-b[j]],b[j]);
    }
    LLI ans = 0;
    for (i = 0; i < s.size(); i++) {
        if (i > 0) x[i] = max(x[i],x[i-1]);
        ans += x[i]+1;
    }
    printf("%I64d\n",ans);

    return 0;
}