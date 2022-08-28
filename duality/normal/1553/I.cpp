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
#pragma GCC optimize("Ofast")

typedef int T;
T mult(T a,T b) {
    return ((LLI) a*b) % MOD;
}
T modPow(T b,T e) {
    T r = 1;
    while (e > 0) {
        if (e & 1) r = mult(r,b);
        e >>= 1;
        b = mult(b,b);
    }
    return r;
}
T inv(T b) {
    return modPow(b,MOD-2);
}
int mbase,base;
T root,w[1 << 19];
int revb[1 << 19];
int setBase(int nbase) {
    int i,j;
    mbase = 1;
    while (!(MOD & (1LL << mbase))) mbase++;
    root = 2;
    while ((modPow(root,1LL << mbase) != 1) || (modPow(root,1LL << (mbase-1)) == 1)) root++;
    base = nbase;
    for (i = 0; i < (1 << base); i++) revb[i] = (revb[i >> 1] >> 1) | ((i & 1) << (base-1));
    w[0] = 0,w[1] = 1;
    for (i = 1; i < nbase; i++) {
        T z = modPow(root,1LL << (mbase-i-1));
        for (j = (1 << (i-1)); j < (1 << i); j++) w[j << 1] = w[j],w[(j << 1)|1] = mult(w[j],z);
    }
    return 0;
}
int FFT(T *a,int n) {
    int i,j,k,l = 0;
    while ((1 << l) < n) l++;
    int s = base - l;
    for (i = 0; i < n; i++) {
        if (i < (revb[i] >> s)) swap(a[i],a[revb[i] >> s]);
    }
    for (k = 1; k < n; k <<= 1) {
        for (i = 0; i < n; i += (k << 1)) {
            for (j = 0; j < k; j++) {
                T z = mult(a[i+j+k],w[j+k]);
                a[i+j+k] = a[i+j]-z,a[i+j] += z;
                if (a[i+j+k] < 0) a[i+j+k] += MOD;
                if (a[i+j] >= MOD) a[i+j] -= MOD;
            }
        }
    }
    for (i = 0; i < n; i++) a[i] %= MOD;
    return 0;
}
int FFT(vector<T> &a) {
    return FFT(a.data(),a.size());
}
vector<T> res(const vector<T> &A,int n) {
    vector<T> B = A;
    B.resize(n);
    return B;
}
vector<T> mult(const vector<T> &A,const vector<T> &B) {
    if ((LLI) A.size()*B.size() <= 10000) {
        int i,j;
        vector<T> C(A.size()+B.size()-1,0);
        const T *a = A.data(),*b = B.data();
        T *c = C.data();
        for (i = 0; i < A.size(); i++) {
            for (j = 0; j < B.size(); j++) {
                c[i+j] += mult(a[i],b[j]);
                if (c[i+j] >= MOD) c[i+j] -= MOD;
            }
        }
        return C;
    }
    int i,n = 1,s = A.size()+B.size()-1;
    while (n < s) n <<= 1;
    vector<T> A2 = res(A,n),B2 = res(B,n);
    FFT(A2),FFT(B2);
    T x = inv(n);
    for (i = 0; i < n; i++) A2[i] = mult(mult(A2[i],B2[i]),x);
    reverse(A2.begin()+1,A2.end()),FFT(A2);
    return res(A2,s);
}
vi add(vi a,vi b) {
    int i;
    if (a.size() < b.size()) swap(a,b);
    for (i = 0; i < b.size(); i++) {
        a[i] += b[i];
        if (a[i] >= MOD) a[i] -= MOD;
    }
    return a;
}

int a[100000],b[100000];
int inv2[1000000],fact[1000000];
set<pii> S;
vi v;
struct info { vi p[2][2]; };
info seen0[100005],seen1[100005];
info getAns(int s,int e) {
    if (s == e) {
        int i,j;
        info f;
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                f.p[i][j] = vi(3,0);
                if (i == j) f.p[i][j][i] = 1;
            }
        }
        return f;
    }
    else if (s == e-1) {
        int i,j;
        info f;
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                f.p[i][j] = vi(3,0);
                f.p[i][j][i+j] = (v[s+1] && (i == 0) && (j == 0)) ? inv2[1]:1;
            }
        }
        return f;
    }
    
    int i,j,k;
    int mid = (s+e) / 2;
    int z = 0,o = 0;
    for (i = s+1; i <= e; i++) {
        if (v[i] == 0) z = 1;
        else o = 1;
    }
    if (!z) {
        if (!seen1[e-s].p[0][0].empty()) return seen1[e-s];
    }
    else if (!o) {
        if (!seen0[e-s].p[0][0].empty()) return seen0[e-s];
    }
    info L = getAns(s,mid),R = getAns(mid,e),f;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                vi P = mult(L.p[i][k],R.p[k][j]);
                if (k) P.erase(P.begin());
                f.p[i][j] = add(f.p[i][j],P);
            }
        }
    }
    if (!z) seen1[e-s] = f;
    else if (!o) seen0[e-s] = f;
    return f;
}
int pow2[1000000];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),S.insert(mp(a[i],-i));
    setBase(19);
    
    int j,k;
    fact[0] = pow2[0] = inv2[0] = 1;
    for (i = 1; i < 1000000; i++) {
        fact[i] = ((LLI) i*fact[i-1]) % MOD;
        pow2[i] = (2*pow2[i-1]) % MOD;
        inv2[i] = ((LLI) ((MOD+1)/2)*inv2[i-1]) % MOD;
    }
    while (!S.empty()) {
        pii u = *S.rbegin();
        for (i = -u.second; i < -u.second+u.first; i++) {
            if ((i >= n) || (a[i] != u.first) || !S.count(mp(a[i],-i))) {
                printf("0\n");
                return 0;
            }
            else {
                S.erase(mp(a[i],-i));
                if (i > -u.second) b[i-1] = 1;
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (!b[i]) v.pb(a[i] == 1);
    }
    if (v.size() == 1) {
        if (n == 1) printf("1\n");
        else printf("2\n");
        return 0;
    }
    info f = getAns(0,(int) v.size()-2);
    LLI ans = 0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < f.p[i][j].size(); k++) {
                if (v[0] && (i == 0)) f.p[i][j][k] = ((LLI) f.p[i][j][k]*inv2[1]) % MOD;
                if (v.back() && (j == 0)) f.p[i][j][k] = ((LLI) f.p[i][j][k]*inv2[1]) % MOD;
                if (v.size() >= k) {
                    if (k & 1) ans -= (((LLI) f.p[i][j][k]*fact[v.size()-k]) % MOD)*pow2[v.size()-k];
                    else ans += (((LLI) f.p[i][j][k]*fact[v.size()-k]) % MOD)*pow2[v.size()-k];
                    ans %= MOD;
                }
            }
        }
    }
    ans %= MOD;
    if (ans < 0) ans += MOD;
    printf("%I64d\n",ans);
    
    return 0;
}