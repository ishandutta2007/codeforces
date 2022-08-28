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

int F[6];
LLI dp[7][1000000];
deque<pair<LLI,int> > Q[1000];
LLI add[1000];
int main() {
    int i;
    int k,q;
    scanf("%d",&k);
    for (i = 0; i <= 5; i++) scanf("%d",&F[i]);
    reverse(F,F+6);

    int j;
    for (i = 1; i < 1000000; i++) dp[0][i] = -1e18;
    for (i = 1; i <= 6; i++) {
        int p = 1;
        for (j = 0; j < 6-i; j++) p *= 10;
        for (j = 0; j < 1000000; j++) {
            dp[i][j] = -1e18;
            if ((j % p) == 0) {
                int t = (j % (3*p))/p;
                dp[i][j] = max(dp[i][j],dp[i-1][j]);
                while (!Q[t].empty() && (Q[t].front().second <= j-9LL*(k-2)*p)) Q[t].pop_front();
                if (!Q[t].empty()) dp[i][j] = max(dp[i][j],Q[t].front().first+add[t]);
                LLI x = dp[i-1][j]-add[t];
                while (!Q[t].empty() && (Q[t].back().first <= x)) Q[t].pop_back();
                add[t] += F[i-1];
                Q[t].pb(mp(x,j));
            }
        }
        for (j = 1000000-1; j >= 0; j--) {
            int c;
            for (c = 0; c < 3; c++) {
                if (j-c*p >= 0) dp[i][j] = max(dp[i][j],dp[i][j-c*p]);
            }
        }
        for (j = 0; j < 1000000; j++) {
            int l;
            for (l = max(9*(k-4)+1,0); l <= 9*k; l++) {
                if (j >= (LLI) l*p) {
                    int m = l/3;
                    if ((l >= 9*(k-1)+3) && ((l % 3) != 0)) m = 3*(k-1);
                    dp[i][j] = max(dp[i][j],dp[i-1][j-l*p]+(LLI) m*F[i-1]);
                }
            }
        }
        for (j = 0; j < 1000; j++) Q[j].clear(),add[j] = 0;
    }

    int n;
    scanf("%d",&q);
    for (i = 0; i < q; i++) {
        scanf("%d",&n);
        printf("%I64d\n",dp[6][n]);
    }

    return 0;
}