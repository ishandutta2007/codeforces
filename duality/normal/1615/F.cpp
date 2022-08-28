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
#define MOD 1000000007

char s[2000],t[2000];
pii dp[4001],dp2[4001];
int main() {
    int i,j;
    int T,n;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (i = 0; i < n; i++) {
            scanf(" %c",&s[i]);
            if (i & 1) {
                if (s[i] == '0') s[i] = '1';
                else if (s[i] == '1') s[i] = '0';
            }
        }
        for (i = 0; i < n; i++) {
            scanf(" %c",&t[i]);
            if (i & 1) {
                if (t[i] == '0') t[i] = '1';
                else if (t[i] == '1') t[i] = '0';
            }
        }

        for (i = -n; i <= n; i++) dp[i+n] = mp(0,0);
        dp[n] = mp(1,0);
        for (i = 0; i < n; i++) {
            vi a,b;
            if (s[i] == '0') a.pb(0);
            else if (s[i] == '1') a.pb(1);
            else a.pb(0),a.pb(1);
            if (t[i] == '0') b.pb(0);
            else if (t[i] == '1') b.pb(-1);
            else b.pb(0),b.pb(-1);
            for (j = -n; j <= n; j++) dp2[j+n] = mp(0,0);
            for (j = -n; j <= n; j++) {
                if (dp[j+n] != mp(0,0)) {
                    for (int x: a) {
                        for (int y: b) {
                            int u = j+x+y+n;
                            dp2[u].first += dp[j+n].first;
                            if (dp2[u].first >= MOD) dp2[u].first -= MOD;
                            dp2[u].second += (dp[j+n].second+(LLI) dp[j+n].first*abs(j)) % MOD;
                            if (dp2[u].second >= MOD) dp2[u].second -= MOD;
                        }
                    }
                }
            }
            for (j = -n; j <= n; j++) dp[j+n] = dp2[j+n];
        }
        printf("%d\n",dp[n].second);
    }

    return 0;
}