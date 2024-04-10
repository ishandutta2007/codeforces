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

int a[1000000];
LLI c1[1000000],c2[1000000];
LLI dp[1000000][3];
int main() {
    int i;
    int n,r1,r2,r3,d;
    scanf("%d %d %d %d %d",&n,&r1,&r2,&r3,&d);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);

    for (i = 0; i < n; i++) {
        c1[i] = (LLI) r1*a[i]+r3;
        c2[i] = min((LLI) r2,(LLI) r1*(a[i]+1))+r1;
        c2[i] = min(c2[i],c1[i]);
    }
    printArr(c1,n);
    printArr(c2,n);
    dp[0][0] = c1[0],dp[0][1] = c2[0],dp[0][2] = 1e18;
    for (i = 1; i < n; i++) {
        dp[i][0] = d+c1[i]+min(dp[i-1][0],dp[i-1][2]);
        dp[i][1] = d+c2[i]+min(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = 3LL*d+c2[i]+min(dp[i-1][1],dp[i-1][2]);
    }
    LLI s = c1[n-1],s2 = c2[n-1]+2LL*d,ans = min(min(dp[n-1][0],dp[n-1][2]),dp[n-1][1]+2*d);
    debug ans;
    for (i = n-2; i >= 0; i--) {
        s += c2[i]+2*d,s2 += c2[i]+2*d;
        printVar(s);
        printVar(s2);
        printVar(min(s,s2)+((i == 0) ? 0:dp[i-1][0]+d));
        ans = min(ans,min(s,s2)+((i == 0) ? 0:dp[i-1][0]+d));
    }
    printf("%I64d\n",ans);

    return 0;
}