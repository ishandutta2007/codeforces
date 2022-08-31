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

namespace NTT {
    int mbase,base,root;
    int w[1 << 19];
    int rev[1 << 19];
    int modPow(int b,int e) {
        int r = 1;
        while (e > 0) {
            if (e & 1) r = ((LLI) r*b) % MOD;
            e >>= 1;
            b = ((LLI) b*b) % MOD;
        }
        return r;
    }
    int setBase(int nbase) {
        int i,j;
        mbase = 1;
        while (!(MOD & (1 << mbase))) mbase++;
        root = 2;
        while ((modPow(root,1 << mbase) != 1) || (modPow(root,1 << (mbase-1)) == 1)) root++;
        base = nbase;
        for (i = 0; i < (1 << base); i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (base-1));
        w[0] = 0,w[1] = 1;
        for (i = 1; i < nbase; i++) {
            int z = modPow(root,1 << (mbase-i-1));
            for (j = (1 << (i-1)); j < (1 << i); j++) w[j << 1] = w[j],w[(j << 1)|1] = ((LLI) w[j]*z) % MOD;
        }
        return 0;
    }
    int FFT(vector<int> &a,int inv) {
        int i,j,k;
        int l = 0;
        while ((1 << l) < a.size()) l++;
        int s = base - l;
        for (i = 0; i < a.size(); i++) {
            if (i < (rev[i] >> s)) swap(a[i],a[rev[i] >> s]);
        }
        for (k = 1; k < a.size(); k <<= 1) {
            for (i = 0; i < a.size(); i += (k << 1)) {
                for (j = 0; j < k; j++) {
                    int z = ((LLI) a[i+j+k]*w[j+k]) % MOD;
                    a[i+j+k] = a[i+j]-z,a[i+j] += z;
                    if (a[i+j+k] < 0) a[i+j+k] += MOD;
                    if (a[i+j] >= MOD) a[i+j] -= MOD;
                }
            }
        }
        return 0;
    }
    vector<int> multiply(vector<int> A,vector<int> B) {
        int i,n = 1;
        while (n < A.size()+B.size()-1) n <<= 1;
        vector<int> a(n,0),b(n,0);
        for (i = 0; i < A.size(); i++) a[i] = A[i];
        for (i = 0; i < B.size(); i++) b[i] = B[i];
        FFT(a,0),FFT(b,0);
        int x = modPow(n,MOD-2);
        for (i = 0; i < n; i++) a[i] = ((((LLI) a[i]*b[i]) % MOD)*x) % MOD;
        reverse(a.begin()+1,a.end()),FFT(a,1),a.resize(A.size()+B.size()-1);
        return a;
    }
}

char s[200000];
int inv(LLI n) {
    LLI r = 1;
    int e = MOD-2;
    while (e > 0) {
        if (e & 1) r = (r*n) % MOD;
        e >>= 1;
        n = (n*n) % MOD;
    }
    return r;
}
int fact[1000001],invfact[1000001];
int C(int n,int k) {
    return ((((LLI) fact[n]*invfact[k]) % MOD)*invfact[n-k]) % MOD;
}
vi poly1,poly2,poly;
int main() {
    int i;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) scanf(" %c",&s[i]);

    fact[0] = 1;
    for (i = 1; i < 1000001; i++) fact[i] = ((LLI) fact[i-1]*i) % MOD;
    invfact[1000000] = inv(fact[1000000]);
    for (i = 999999; i >= 0; i--) invfact[i] = ((LLI) invfact[i+1]*(i+1)) % MOD;
    int cb = 0,cq = 0;
    for (i = 0; i < n; i += 2) {
        if (s[i] == 'b') cb++;
        else if (s[i] == '?') cq++;
    }
    debug cb,cq;
    poly1.resize(n/2+1);
    for (i = 0; i <= cq; i++) poly1[i+cb] = C(cq,i);
    cb = cq = 0;
    for (i = 1; i < n; i += 2) {
        if (s[i] == 'w') cb++;
        else if (s[i] == '?') cq++;
    }
    poly2.resize(n/2+1);
    for (i = 0; i <= cq; i++) poly2[i+cb] = C(cq,i);
    NTT::setBase(19);
    poly = NTT::multiply(poly1,poly2);
    LLI sum = 0,ways = 0;
    for (i = 0; i <= n; i++) {
        if ((abs(2*i-n) % 4) == 0) {
            ways += poly[i];
            sum += (LLI) poly[i]*(abs(2*i-n)/2);
            ways %= MOD,sum %= MOD;
        }
    }
    sum *= inv(ways),sum %= MOD;
    sum *= inv(2),sum %= MOD;
    printf("%I64d\n",sum);

    return 0;
}