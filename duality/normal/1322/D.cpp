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

int l[2000],s[2000],c[4001];
int dp[2000][2001],mm[2000];
int best[2001][4001];
int main() {
    int i;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) scanf("%d",&l[i]);
    for (i = 0; i < n; i++) scanf("%d",&s[i]);
    for (i = 1; i <= n+m; i++) scanf("%d",&c[i]);

    int j,k,ans = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) dp[i][j] = -1e9;
    }
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n+m; j++) best[i][j] = -1e9;
    }
    for (i = n-1; i >= 0; i--) {
        dp[i][1] = c[l[i]]-s[i];
        for (j = i+1; j < n; j++) {
            if (l[j] < l[i]-13) dp[i][1] = max(dp[i][1],mm[j]+c[l[i]]-s[i]);
        }
        for (j = l[i]; j >= max(l[i]-13,0); j--) {
            for (k = 1; k < n-i; k++) {
                int x = 0,b = 0;
                int z = k >> (l[i]-j);
                while (z & (1 << b)) x += c[b+l[i]+1],b++;
                dp[i][z+1] = max(dp[i][z+1],best[j][k]+c[l[i]]-s[i]+x);
            }
        }
        mm[i] = -1e9;
        for (j = 1; j <= n-i; j++) {
            best[l[i]][j] = max(best[l[i]][j],dp[i][j]);
            mm[i] = max(mm[i],dp[i][j]);
        }
        ans = max(ans,mm[i]);
    }
    printf("%d\n",ans);

    return 0;
}