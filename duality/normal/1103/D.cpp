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

LLI gcd(LLI a,LLI b) {
    LLI t;
    while (a > 0) t = b % a,b = a,a = t;
    return b;
}
LLI a[1000000];
int e[1000000];
vlli factors;
map<LLI,vi> M;
LLI num[12];
LLI dp[12][1 << 11],dp2[12][1 << 11];
int main() {
    int i;
    int n;
    LLI K,g = 0;
    scanf("%d %I64d",&n,&K);
    for (i = 0; i < n; i++) scanf("%I64d",&a[i]),g = gcd(g,a[i]);
    for (i = 0; i < n; i++) scanf("%d",&e[i]);

    int j;
    for (i = 2; (LLI) i*i <= g; i++) {
        if ((g % i) == 0) {
            LLI x = 1;
            while ((g % i) == 0) x *= i,g /= i;
            factors.pb(x);
        }
    }
    if (g > 1) factors.pb(g);
    if (factors.empty()) {
        printf("0\n");
        return 0;
    }

    int k,l;
    LLI ans = 1e18;
    for (i = 0; i < n; i++) {
        LLI x = a[i],y = 1;
        for (j = 0; j < factors.size(); j++) {
            while ((x % factors[j]) == 0) x /= factors[j],y *= factors[j];
        }
        if (!M.count(y)) M[y] = vi(1,e[i]);
        else M[y].pb(e[i]);
    }
    for (i = 0; i <= factors.size(); i++) {
        for (j = 0; j < (1 << factors.size()); j++) dp[i][j] = 1e18;
    }
    dp[0][0] = 0;
    for (auto it = M.begin(); it != M.end(); it++) {
        LLI x = it->first;
        for (i = 0; i < factors.size(); i++) {
            num[i] = 1;
            while ((x % factors[i]) == 0) x /= factors[i],num[i] *= factors[i];
        }
        vi good;
        for (i = 0; i < (1 << factors.size()); i++) {
            LLI x = 1;
            for (j = 0; j < factors.size(); j++) {
                if (i & (1 << j)) x *= num[j];
            }
            if (x <= K) {
                for (j = 0; j < factors.size(); j++) {
                    if (!(i & (1 << j)) && (x*num[j] <= K)) break;
                }
                if (j == factors.size()) good.pb(i);
            }
        }
        vi &v = it->second;
        sort(v.begin(),v.end());
        v.resize(min(v.size(),factors.size()));
        for (i = 0; i < v.size(); i++) {
            for (j = factors.size()-1; j >= 0; j--) {
                for (k = 0; k < (1 << factors.size()); k++) {
                    for (l = 0; l < good.size(); l++) dp[j+1][k | good[l]] = min(dp[j+1][k | good[l]],dp[j][k]+v[i]);
                }
            }
        }
        for (i = 1; i <= factors.size(); i++) ans = min(ans,dp[i][(1 << factors.size())-1]*i);
    }
    if (ans == 1e18) printf("-1\n");
    else printf("%lld\n",ans);

    return 0;
}