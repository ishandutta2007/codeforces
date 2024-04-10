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

template<class T>
int FFT(vector<complex<T> > &a,int inv) {
    int i,j,k;
    int l = 0;
    while ((1 << l) < a.size()) l++;
    const double TAU = 2*acos(-1.0);
    for (i = 0; i < a.size(); i++) {
        int r = 0;
        for (j = 0; j < l; j++) {
            if (i & (1 << j)) r |= (1 << (l-j-1));
        }
        if (i < r) swap(a[i],a[r]);
    }
    double aa = TAU/a.size();
    if (!inv) aa = -aa;
    vector<complex<T> > w(a.size());
    for (i = 0; i < a.size(); i++) w[i] = complex<T>(cos(aa*i),sin(aa*i));
    for (i = 2; i <= a.size(); i <<= 1) {
        for (k = 0; k < a.size(); k += i) {
            for (j = 0; j < (i >> 1); j++) {
                complex<T> e = a[k+j],o = a[k+j+(i >> 1)]*w[j*(a.size()/i)];
                a[k+j] = e+o,a[k+j+(i >> 1)] = e-o;
            }
        }
    }
    if (inv) {
        for (i = 0; i < a.size(); i++) a[i].real(a[i].real()/a.size());
    }
    return 0;
}
template<class FFT_T = double,class T>
vector<T> multiply(vector<T> A,vector<T> B) {
    assert(is_floating_point<FFT_T>());
    int i,n = 1;
    while (n < A.size()+B.size()-1) n <<= 1;
    vector<complex<FFT_T> > a(n,0),b(n,0);
    for (i = 0; i < A.size(); i++) a[i] = A[i];
    for (i = 0; i < B.size(); i++) b[i] = B[i];
    FFT(a,0),FFT(b,0);
    for (i = 0; i < n; i++) a[i] *= b[i];
    FFT(a,1);
    vector<T> ans(A.size()+B.size()-1);
    for (i = 0; i < A.size()+B.size()-1; i++) {
        if (is_integral<T>()) ans[i] = a[i].real()+0.5;
        else ans[i] = a[i].real();
    }
    return ans;
}

vlli A,B,C;
int main() {
    int i;
    int n,x,a,s = 0;
    scanf("%d %d",&n,&x);
    A.resize(n+1),A[0] = 1;
    for (i = 0; i < n; i++) scanf("%d",&a),s += (a < x),A[s]++;
    B = A;
    reverse(B.begin(),B.end());
    C = multiply(A,B);
    for (i = 0; i <= n; i++) printf("%I64d%c",(i == 0) ? (C[i+n]-n-1)/2:C[i+n],(i == n) ? '\n':' ');
    return 0;
}