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
LLI l[52],r[52],c[51];
LLI dp[52][52][51][2][2][2][2];
LLI findAns(int s,int e,int b,int st,int et,int sd,int ed) {
    if (b > k) return (s > e) ? 0:1e18;
    else if (dp[s][e][b][st][et][sd][ed] != -1) return dp[s][e][b][st][et][sd][ed];
    int i;
    LLI ans = findAns(s,e,b+1,st,et,0,0);
    if ((s > 1) && (e < n) && (((st ? r[s-1]:l[s-1])^(et ? r[e+1]:l[e+1]) \
        ^((LLI) sd << b)^((LLI) ed << b)) & (1LL << b))) ans += c[b];
    for (i = s; i <= e; i++) {
        if (!(l[i] & (1LL << b)) && (((l[i] >> b) << b)+(1LL << (b+1))-1 < r[i]))
            ans = min(ans,findAns(s,i-1,b,st,0,sd,1)+findAns(i+1,e,b,0,et,1,ed));
        if ((r[i] & (1LL << b)) && (((r[i] >> b) << b)-(1LL << b) > l[i]))
            ans = min(ans,findAns(s,i-1,b,st,1,sd,1)+findAns(i+1,e,b,1,et,1,ed));
    }
    dp[s][e][b][st][et][sd][ed] = ans;
    return ans;
}
int main() {
    int i;
    scanf("%d %d",&n,&k);
    for (i = 1; i <= n; i++) scanf("%I64d %I64d",&l[i],&r[i]),l[i]--,r[i]++,l[i] += (1LL << k),r[i] += (1LL << k);
    for (i = 0; i < k; i++) scanf("%I64d",&c[i]);
    memset(dp,-1,sizeof(dp));
    printf("%I64d\n",findAns(1,n,0,0,0,0,0));
    return 0;
}