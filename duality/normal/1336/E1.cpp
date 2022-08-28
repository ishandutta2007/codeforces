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

// from https://codeforces.com/blog/entry/68953
int d = 53;
LLI basis[53]; // basis[i] keeps the mask of the vector whose f value is i

int sz = 0; // Current size of the basis

void insertVector(LLI mask) {
    for (int i = 0; i < d; i++) {
        if ((mask & 1LL << i) == 0) continue; // continue if i != f(mask)

        if (!basis[i]) { // If there is no basis vector with the i'th bit set, then insert this vector into the basis
            basis[i] = mask;
            ++sz;

            return;
        }

        mask ^= basis[i]; // Otherwise subtract the basis vector from this vector
    }
}
vlli bb;
int ans[60];
int dp[40][1 << 15],dp2[40][1 << 15];
int main() {
    int i;
    int n,m;
    LLI a;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) {
        scanf("%I64d",&a);
        insertVector(a);
    }
    debug "here";

    int j,p = 1;
    for (i = 0; i < n-sz; i++) p *= 2,p %= MOD;
    vi b2;
    for (i = 0; i < m; i++) {
        if (basis[i] != 0) bb.pb(basis[i]);
        else b2.pb(i);
    }
    printArr(basis,m);
    printArr(bb,bb.size());
    if (sz <= 20) {
        debug "sz <= 20";
        for (i = 0; i < (1 << sz); i++) {
            LLI x = 0;
            for (j = 0; j < sz; j++) {
                if (i & (1 << j)) x ^= bb[j];
            }
            int b = 0;
            for (j = 0; j < m; j++) {
                if (x & (1LL << j)) b++;
            }
            ans[b]++;
        }
        for (i = 0; i <= m; i++) printf("%I64d ",((LLI) ans[i]*p) % MOD);
        printf("\n");
    }
    else {
        int k;
        vlli vv;
        printArr(b2,b2.size());
        for (i = 0; i < m; i++) {
            if (basis[i] != 0) {
                for (j = i+1; j < m; j++) {
                    if ((basis[j] != 0) && (basis[i] & (1LL << j))) basis[i] ^= basis[j];
                }
                LLI c = 0;
                for (j = 0; j < b2.size(); j++) {
                    if (basis[i] & (1LL << b2[j])) c |= (1LL << j);
                }
                vv.pb(c);
            }
        }
        printArr(vv,vv.size());
        printVar(vv.size());
        printVar(b2.size());
        dp[0][0] = 1;
        for (i = 0; i < vv.size(); i++) {
            memset(dp2,0,sizeof(dp2));
            for (j = 0; j <= i; j++) {
                for (k = 0; k < (1 << b2.size()); k++) {
                    dp2[j][k] += dp[j][k];
                    if (dp2[j][k] >= MOD) dp2[j][k] -= MOD;
                    dp2[j+1][k^vv[i]] += dp[j][k];
                    if (dp2[j+1][k^vv[i]] >= MOD) dp2[j+1][k^vv[i]] -= MOD;
                }
            }
            for (j = 0; j <= i+1; j++) {
                for (k = 0; k < (1 << b2.size()); k++) dp[j][k] = dp2[j][k];
            }
        }
        for (i = 0; i <= vv.size(); i++) {
            for (j = 0; j < (1 << b2.size()); j++) {
                ans[i+__builtin_popcount(j)] += dp[i][j];
                if (ans[i+__builtin_popcount(j)] >= MOD) ans[i+__builtin_popcount(j)] -= MOD;
            }
        }
        for (i = 0; i <= m; i++) printf("%I64d ",((LLI) ans[i]*p) % MOD);
        printf("\n");
    }

    return 0;
}