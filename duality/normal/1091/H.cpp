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
#pragma GCC optimize("Ofast")

vi v;
int dp[200005];
bitset<200005> bs[60],m;
int main() {
    int i;
    int n,f,b,w,r;
    scanf("%d %d",&n,&f);
    for (i = 0; i < n; i++) scanf("%d %d %d",&b,&w,&r),v.pb(w-b-1),v.pb(r-w-1);

    int j;
    for (i = 2; i < 200005; i++) {
        int t = i,c = 0;
        for (j = 2; j*j <= t; j++) {
            if ((t % j) == 0) {
                while ((t % j) == 0) t /= j,c++;
            }
        }
        if (t > 1) c++;
        if ((i != f) && (c <= 2)) m[i] = 1;
    }

    for (i = 0; i < 200005; i++) {
        for (j = 0; j < 60; j++) {
            if (!bs[j][i]) break;
        }
        dp[i] = j;
        bs[j] |= (m << i);
    }
    int x = 0;
    for (i = 0; i < v.size(); i++) x ^= dp[v[i]];
    if (x == 0) printf("Bob\nAlice\n");
    else printf("Alice\nBob\n");

    return 0;
}