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

LLI a[100000];
int dp[60][100001];
int r;
bool comp(LLI a,LLI b) {
    return (a & ((1LL << r)-1)) > (b & ((1LL << r)-1));
}
int main() {
    int i;
    int n;
    LLI m = 0;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%I64d",&a[i]),m = max(m,a[i]);
    for (i = 0; i < n; i++) a[i] = m-a[i];

    int j;
    dp[0][0] = 0;
    for (i = 1; i <= n; i++) dp[0][i] = 1e9;
    for (i = 0; i < 59; i++) {
        r = i;
        sort(a,a+n,comp);
        for (j = 0; j <= n; j++) dp[i+1][j] = 1e9;
        int c = 0,b = 0;
        for (j = 0; j < n; j++) {
            if (a[j] & (1LL << i)) b++;
        }
        for (j = 0; j <= n; j++) {
            dp[i+1][c] = min(dp[i+1][c],dp[i][j]+b+j-2*c);
            dp[i+1][j+b-c] = min(dp[i+1][j+b-c],dp[i][j]+n-(b+j-2*c));
            if ((j < n) && (a[j] & (1LL << i))) c++;
        }
    }
    printf("%d\n",dp[59][0]);

    return 0;
}