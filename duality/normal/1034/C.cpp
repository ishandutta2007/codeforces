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

int a[1000000];
int p[1000000];
vi adjList[1000000];
LLI size[1000000];
LLI gcd(LLI a,LLI b) {
    LLI t;
    while (a > 0) t = b % a,b = a,a = t;
    return b;
}
vplli f;
vlli factors;
vlli seen;
int getFactors(int c,LLI x) {
    if (c == f.size()) {
        factors.pb(x);
        return 0;
    }
    int i;
    for (i = 0; i <= f[c].second; i++) {
        getFactors(c+1,x);
        if (i < f[c].second) x *= f[c].first;
    }
    return 0;
}
vi num;
vlli poss,dp;
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);
    for (i = 1; i < n; i++) scanf("%d",&p[i]),adjList[--p[i]].pb(i);

    int j;
    for (i = n-1; i >= 0; i--) {
        size[i] += a[i];
        if (i > 0) size[p[i]] += size[i];
        seen.pb(size[i]);
    }
    sort(seen.begin(),seen.end());
    LLI x = size[0];
    for (i = 2; (LLI) i*i <= x; i++) {
        if ((x % i) == 0) {
            int c = 0;
            while ((x % i) == 0) x /= i,c++;
            f.pb(mp(i,c));
        }
    }
    if (x > 1) f.pb(mp(x,1));
    getFactors(0,1);
    sort(factors.begin(),factors.end()),num.resize(factors.size());
    for (i = 0; i < n; i++) {
        LLI g = gcd(size[0],size[i]);
        num[lower_bound(factors.begin(),factors.end(),g)-factors.begin()]++;
    }
    for (i = 0; i < factors.size(); i++) {
        if (size[0]/factors[i] > n) continue;
        if (binary_search(seen.begin(),seen.end(),factors[i])) {
            int c = 0;
            for (j = 0; j < factors.size(); j++) {
                if ((factors[j] % factors[i]) == 0) c += num[j];
            }
            if (c == size[0]/factors[i]) poss.pb(factors[i]);
        }
    }
    sort(poss.begin(),poss.end()),dp.resize(poss.size());
    for (i = 0; i < poss.size(); i++) {
        dp[i] = 1;
        for (j = 0; j < i; j++) {
            if ((poss[i] % poss[j]) == 0) {
                dp[i] += dp[j];
                if (dp[i] >= MOD) dp[i] -= MOD;
            }
        }
    }
    printf("%d\n",dp.back());

    return 0;
}