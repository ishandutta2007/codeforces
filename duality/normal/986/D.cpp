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
vector<T> sq(vector<T> A) {
    assert(is_floating_point<FFT_T>());
    int i,n = 1;
    while (n < 2*A.size()-1) n <<= 1;
    vector<complex<FFT_T> > a(n,0);
    for (i = 0; i < A.size(); i++) a[i] = A[i];
    FFT(a,0);
    for (i = 0; i < n; i++) a[i] *= a[i];
    FFT(a,1);
    vector<T> ans(2*A.size()-1);
    for (i = 0; i < 2*A.size()-1; i++) {
        if (is_integral<T>()) ans[i] = a[i].real()+0.5;
        else ans[i] = a[i].real();
    }
    ans.pb(0);
    for (i = 0; i < ans.size()-1; i++) ans[i+1] += ans[i]/10000,ans[i] %= 10000;
    while (!ans.empty() && (ans.back() == 0)) ans.pop_back();
    if (ans.empty()) ans.pb(0);
    return ans;
}
vlli pow3(int e) {
    if (e == 0) {
        vlli r;
        r.pb(1);
        return r;
    }
    else if (e & 1) {
        int i;
        vlli r = pow3(e-1);
        r.pb(0);
        int c = 0;
        for (i = 0; i < r.size(); i++) {
            r[i] *= 3,r[i] += c;
            c = r[i]/10000,r[i] %= 10000;
        }
        while (!r.empty() && (r.back() == 0)) r.pop_back();
        if (r.empty()) r.pb(0);
        return r;
    }
    else {
        vlli r = pow3(e/2);
        return sq<double,LLI>(r);
    }
}

int main() {
    string n;
    cin >> n;

    int i;
    vlli v;
    reverse(n.begin(),n.end());
    for (i = 0; i < n.size(); i += 4) {
        int x = n[i]-'0';
        if ((i+1) < n.size()) x += 10*(n[i+1]-'0');
        if ((i+2) < n.size()) x += 100*(n[i+2]-'0');
        if ((i+3) < n.size()) x += 1000*(n[i+3]-'0');
        v.pb(x);
    }
    int two,ans = MAX_VAL;
    double x = 0;
    for (i = n.size()-1; i >= max((int) n.size()-10,0); i--) x *= 10,x += n[i]-'0';
    x = log10(x),x += max((int) n.size()-10,0) - log10(4),x /= log10(3);
    int es = max(x-1,0.0);
    vlli t = pow3(es);
    for (two = 0; two <= 2; two++) {
        vlli r = t;
        r.pb(0);
        int c = 0;
        for (i = 0; i < r.size(); i++) {
            r[i] *= (1 << two),r[i] += c;
            c = r[i]/10000,r[i] %= 10000;
        }
        while (!r.empty() && (r.back() == 0)) r.pop_back();
        if (r.empty()) r.pb(0);
        int e = es;
        while (1) {
            int f = 0;
            for (i = max(v.size(),r.size()); i >= 0; i--) {
                int p = (i < v.size()) ? v[i]:0;
                int q = (i < r.size()) ? r[i]:0;
                if (p == q) continue;
                if (p < q) f = -1;
                else f = 1;
                break;
            }
            if (f != 1) break;
            else {
                e++;
                r.pb(0);
                int c = 0;
                for (i = 0; i < r.size(); i++) {
                    r[i] *= 3,r[i] += c;
                    c = r[i]/10000,r[i] %= 10000;
                }
                while (!r.empty() && (r.back() == 0)) r.pop_back();
                if (r.empty()) r.pb(0);
            }
        }
        ans = min(ans,3*e+2*two);
    }
    printf("%d\n",max(ans,1));

    return 0;
}