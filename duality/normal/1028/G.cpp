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

LLI dp[6][10001];
LLI findNum(int q,int b) {
    if (q == 0) return 0;
    else if (dp[q][b] != -1) return dp[q][b];
    int i;
    LLI x = b;
    for (i = 0; i <= b; i++) x += findNum(q-1,min(x,10000LL))+1;
    dp[q][b] = x-b-1;
    return x-b-1;
}
int query(int q,LLI b) {
    int i;
    LLI x = b,c;
    vlli v;
    for (i = 0; i <= min(b,10000LL); i++) x += findNum(q-1,min(x,10000LL))+1,v.pb(x-1);
    v.pop_back();
    cout << v.size();
    for (i = 0; i < v.size(); i++) cout << " " << v[i];
    cout << endl;
    cin >> c;
    if (c >= 0) {
        if (c == 0) query(q-1,b);
        else query(q-1,v[c-1]+1);
    }
    return 0;
}
int main() {
    memset(dp,-1,sizeof(dp));
    query(5,1);
    return 0;
}