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

int n,k;
vi arr[3000];
LLI sum[3000];
LLI ans = 0;
int findAns(vlli dp,int l,int r) {
    if (l == r) {
        int i;
        LLI s = 0;
        for (i = 0; i <= min(k,(int) arr[l].size()); i++) {
            ans = max(ans,dp[k-i]+s);
            if (i < arr[l].size()) s += arr[l][i];
        }
        return 0;
    }

    int i,j,m = (l+r) / 2;
    vlli dp2 = dp;
    for (i = l; i <= m; i++) {
        for (j = k; j >= arr[i].size(); j--) dp2[j] = max(dp2[j],dp2[j-arr[i].size()]+sum[i]);
    }
    findAns(dp2,m+1,r);
    dp2 = dp;
    for (i = m+1; i <= r; i++) {
        for (j = k; j >= arr[i].size(); j--) dp2[j] = max(dp2[j],dp2[j-arr[i].size()]+sum[i]);
    }
    findAns(dp2,l,m);
    return 0;
}
int main() {
    int i,j;
    int t;
    scanf("%d %d",&n,&k);
    for (i = 0; i < n; i++) {
        scanf("%d",&t);
        arr[i].resize(t);
        for (j = 0; j < t; j++) scanf("%d",&arr[i][j]),sum[i] += arr[i][j];
    }
    findAns(vlli(k+1,0),0,n-1);
    printf("%lld\n",ans);

    return 0;
}