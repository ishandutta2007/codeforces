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
#define MOD 998244353

int inv(int n) {
    int e = MOD-2,r = 1;
    while (e > 0) {
        if (e & 1) r = ((LLI) r*n) % MOD;
        e >>= 1;
        n = ((LLI) n*n) % MOD;
    }
    return r;
}
int fact[100005],invfact[100005];
int C(int n,int k) {
    if ((k < 0) || (k > n)) return 0;
    else return ((((LLI) fact[n]*invfact[k]) % MOD)*invfact[n-k]) % MOD;
}
int a[100000];
vlli pre,suff;
map<LLI,int> M1,M2;
int main() {
    int i;
    fact[0] = 1;
    for (i = 1; i < 100005; i++) fact[i] = ((LLI) i*fact[i-1]) % MOD;
    for (i = 0; i < 100005; i++) invfact[i] = inv(fact[i]);

    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (i = 0; i < n; i++) scanf("%d",&a[i]);

        LLI s = 0;
        for (i = 0; i < n; i++) s += a[i],pre.pb(s);
        s = 0;
        for (i = n-1; i >= 0; i--) s += a[i],suff.pb(s);
        while (!pre.empty() && (2*pre.back() > s)) pre.pop_back();
        while (!suff.empty() && (2*suff.back() > s)) suff.pop_back();
        LLI ans = 1;
        for (LLI x: pre) M1[x]++;
        for (LLI x: suff) M2[x]++;
        for (auto [x,_]: M1) {
            if (M2.count(x)) {
                if (2*x == s) {
                    assert(M1[x] == M2[x]);
                    for (i = 0; i < M1[x]; i++) ans = (2*ans) % MOD;
                }
                else {
                    LLI w = 0;
                    for (i = 0; i <= M1[x]; i++) w += (LLI) C(M1[x],i)*C(M2[x],i),w %= MOD;
                    ans = (ans*w) % MOD;
                }
            }
        }
        if (s == 0) ans = (ans*inv(2)) % MOD;
        printf("%lld\n",ans);

        M1.clear(),M2.clear();
        pre.clear(),suff.clear();
    }
    
    return 0;
}