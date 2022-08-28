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

namespace FFT {
    const double TAU = 2*acos(-1.0);
    int base;
    complex<double> w[1 << 20];
    int rev[1 << 20];
    int setBase(int nbase) {
        int i,j;
        base = nbase;
        for (i = 0; i < (1 << base); i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (base-1));
        w[0] = complex<double>(0,0),w[1] = complex<double>(1,0);
        for (i = 1; i < nbase; i++) {
            double a = TAU/((1 << (i+1)));
            for (j = (1 << (i-1)); j < (1 << i); j++) {
                w[j << 1] = w[j];
                double a2 = a*(((j << 1)|1)-(1 << i));
                w[(j << 1)|1] = complex<double>(cos(a2),sin(a2));
            }
        }
        return 0;
    }
    int FFT(vector<complex<double> > &a) {
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
                    complex<double> z = a[i+j+k]*w[j+k];
                    a[i+j+k] = a[i+j]-z,a[i+j] = a[i+j] + z;
                }
            }
        }
        return 0;
    }
    template<typename T>
    vector<T> multiply(vector<T> A,vector<T> B) {
        int i,n = 1;
        while (n < A.size()+B.size()-1) n <<= 1;
        vector<complex<double> > a(n,0);
        for (i = 0; i < n; i++) a[i] = complex<double>((i < A.size()) ? A[i]:0,(i < B.size()) ? B[i]:0);
        FFT(a);
        complex<double> r(0,-0.25/n);
        for (i = 0; i <= (n >> 1); i++) {
            int j = (n-i) & (n-1);
            complex<double> z = (a[j]*a[j] - conj(a[i]*a[i])) * r;
            if (i != j) a[j] = (a[i]*a[i] - conj(a[j]*a[j])) * r;
            a[i] = z;
        }
        FFT(a);
        vector<T> ans(A.size()+B.size()-1);
        for (i = 0; i < A.size()+B.size()-1; i++) ans[i] = a[i].real()+0.5;
        return ans;
    }
}
#define MOD 998244353

namespace NTT {
    int mbase,base,root;
    int w[1 << 20];
    int rev[1 << 20];
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
vlli A,B;
int main() {
    int i;
    int n,m,c,x;
    scanf("%d %d %d",&n,&m,&c);
    A.resize(490018),B.resize(490018);
    for (i = 0; i < n; i++) scanf("%d",&x),A[((LLI) i*i) % 490018] += x;
    for (i = 0; i < m; i++) scanf("%d",&x),B[((LLI) i*i*i) % 490018] += x;

    int invc = 1;
    int b = c,e = 490019-2;
    while (e > 0) {
        if (e & 1) invc = ((LLI) invc*b) % 490019;
        e >>= 1;
        b = ((LLI) b*b) % 490019;
    }
    for (i = 0; i < 490018; i++) {
        if (A[i] > 0) {
            A[i] %= 490019;
            int b = invc,e = ((LLI) i*(i-1)/2) % 490018;
            while (e > 0) {
                if (e & 1) A[i] = (A[i]*b) % 490019;
                e >>= 1;
                b = ((LLI) b*b) % 490019;
            }
        }
        if (B[i] > 0) {
            B[i] %= 490019;
            int b = invc,e = ((LLI) i*(i-1)/2) % 490018;
            while (e > 0) {
                if (e & 1) B[i] = (B[i]*b) % 490019;
                e >>= 1;
                b = ((LLI) b*b) % 490019;
            }
        }
    }
    int ans = 0;
    FFT::setBase(20);
    vlli C = FFT::multiply(A,B);
    vi A2,B2;
    for (i = 0; i < 490018; i++) A2.pb(A[i]),B2.pb(B[i]);
    NTT::setBase(20);
    vi C2 = NTT::multiply(A2,B2);
    for (i = 0; i < C.size(); i++) {
        int t = (C2[i]-(C[i] % MOD)+MOD) % MOD;
        if (t < MOD/2) C[i] += t;
        else C[i] += t-MOD;
        C[i] %= 490019;
        int b = c,e = ((LLI) i*(i-1)/2) % 490018;
        while (e > 0) {
            if (e & 1) C[i] = (C[i]*b) % 490019;
            e >>= 1;
            b = ((LLI) b*b) % 490019;
        }
        ans += C[i],ans %= 490019;
    }
    printf("%d\n",ans);

    return 0;
}