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

int a[1500],l[1500],r[1500],ll[1500],rr[1500];
pii sorted[1500];
int dp[1501][1501];
int poss[1500];
int main() {
    int i;
    int n,s,mm,kk;
    scanf("%d %d %d %d",&n,&s,&mm,&kk);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),sorted[i] = mp(a[i],i);
    for (i = 0; i < s; i++) scanf("%d %d",&l[i],&r[i]),l[i]--,r[i]--;
    sort(sorted,sorted+n);

    int j,k,l0 = kk-1,r0 = n;
    while (l0 < r0) {
        int m = (l0+r0) / 2;
        vi v;
        for (i = 0; i <= m; i++) v.pb(sorted[i].second);
        sort(v.begin(),v.end());
        printVar(m);
        printArr(v,v.size());
        for (i = 0; i < v.size(); i++) poss[i] = 1e9;
        for (i = 0; i < s; i++) {
            ll[i] = lower_bound(v.begin(),v.end(),l[i])-v.begin();
            rr[i] = upper_bound(v.begin(),v.end(),r[i])-v.begin()-1;
            if (ll[i] <= rr[i]) poss[rr[i]] = min(poss[rr[i]],ll[i]);
        }
        for (i = (int) v.size()-2; i >= 0; i--) poss[i] = min(poss[i],poss[i+1]);
        printArr(poss,v.size());
        memset(dp,0,sizeof(dp));
        for (i = 0; i < v.size(); i++) {
            for (j = 0; j <= mm; j++) {
                dp[i+1][j] = dp[i][j];
                if (poss[i] != 1e9) {
                    if (j > 0) dp[i+1][j] = max(dp[i+1][j],dp[poss[i]][j-1]+i-poss[i]+1);
                }
            }
        }
        int ans = 0;
        for (i = 0; i <= mm; i++) ans = max(ans,dp[v.size()][i]);
        if (ans >= kk) r0 = m;
        else l0 = m+1;
        v.clear();
    }
    printf("%d\n",(l0 == n) ? -1:sorted[l0].first);

    return 0;
}