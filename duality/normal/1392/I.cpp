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
    complex<double> w[1 << 19];
    int rev[1 << 19];
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

int a[100000],b[100000];
vlli v1,v2,e1,e2,f1,f2;
vlli sum(vlli a,vlli b) {
    int i;
    vlli c(a.size());
    for (i = 0; i < a.size(); i++) c[i] = a[i]+b[i];
    return c;
}
int main() {
    int i;
    int n,m,qq,x;
    scanf("%d %d %d",&n,&m,&qq);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);
    for (i = 0; i < m; i++) scanf("%d",&b[i]);

    FFT::setBase(18);
    vlli p(100001),q(100001);
    for (i = 0; i < n; i++) p[a[i]]++;
    for (i = 0; i < m; i++) q[b[i]]++;
    v1 = v2 = FFT::multiply(p,q);
    for (i = 0; i < n; i++) p[a[i]] = 0;
    for (i = 1; i < n; i++) p[min(a[i],a[i-1])]++;
    e1 = FFT::multiply(p,q);
    for (i = 1; i < n; i++) p[min(a[i],a[i-1])] = 0;
    for (i = 1; i < n; i++) p[max(a[i],a[i-1])]++;
    e2 = FFT::multiply(p,q);
    for (i = 1; i < n; i++) p[max(a[i],a[i-1])] = 0;
    for (i = 0; i < n; i++) p[a[i]]++;
    for (i = 0; i < m; i++) q[b[i]] = 0;
    for (i = 1; i < m; i++) q[min(b[i],b[i-1])]++;
    e1 = sum(e1,FFT::multiply(p,q));
    for (i = 1; i < m; i++) q[min(b[i],b[i-1])] = 0;
    for (i = 1; i < m; i++) q[max(b[i],b[i-1])]++;
    e2 = sum(e2,FFT::multiply(p,q));
    for (i = 0; i < n; i++) p[a[i]] = 0;
    for (i = 1; i < n; i++) p[max(a[i],a[i-1])]++;
    f2 = FFT::multiply(p,q);
    for (i = 1; i < n; i++) p[max(a[i],a[i-1])] = 0;
    for (i = 1; i < n; i++) p[min(a[i],a[i-1])]++;
    for (i = 1; i < m; i++) q[max(b[i],b[i-1])] = 0;
    for (i = 1; i < m; i++) q[min(b[i],b[i-1])]++;
    f1 = FFT::multiply(p,q);
    for (i = 199999; i >= 0; i--) v1[i] += v1[i+1],e1[i] += e1[i+1],f1[i] += f1[i+1];
    for (i = 1; i <= 200000; i++) v2[i] += v2[i-1],e2[i] += e2[i-1],f2[i] += f2[i-1];

    for (i = 0; i < qq; i++) {
        scanf("%d",&x);
        printf("%lld\n",v1[x]-e1[x]+f1[x]-v2[x-1]+e2[x-1]-f2[x-1]);
    }

    return 0;
}