/*{{{*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<limits.h>
#include<assert.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(LL &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const LL &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
const double PI = acos(-1.0);
 
template<typename T> struct TPoint2D {
    T X, Y;
    TPoint2D() : X(), Y() {}
    TPoint2D(const T& x, const T& y) : X(x), Y(y) {}
    TPoint2D(const TPoint2D<T>& p) : X(p.X), Y(p.Y) {}
    TPoint2D& operator=(const TPoint2D<T>& p) { X = p.X; Y = p.Y; return *this; }
    T operator&(const TPoint2D<T>& p) const { return X * p.X + Y * p.Y; }
    T operator^(const TPoint2D<T>& p) const { return X * p.Y - Y * p.X; }
    TPoint2D conj() const { return TPoint2D(X, -Y); }
    TPoint2D<T> operator*(const TPoint2D<T>& p) const { return TPoint2D<T>(*this & p.conj(), -*this ^ p.conj()); }
    TPoint2D<T> operator*(const T& p) const { return TPoint2D<T>(p * X, p * Y); }
    TPoint2D<T> operator-(void) const { return TPoint2D(-X, -Y); }
    TPoint2D<T> operator+(const TPoint2D<T>& p) const { return TPoint2D(X + p.X, Y + p.Y); }
    TPoint2D<T> operator-(const TPoint2D<T>& p) const { return *this + (-p); }
    T norm() const { return X * X + Y * Y; }
};
 
typedef TPoint2D<double> base;
 
void fft (vector<base>& a, bool invert) {
    int n = (int) a.size();
    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }
    for (int len=2; len<=n; len<<=1) {
        double ang = 2*PI/len * (invert ? -1 : 1);
        base wlen (cos(ang), sin(ang));
        for (int i=0; i<n; i+=len) {
            base w (1, 0);
            for (int j=0; j<len/2; ++j) {
                base u = a[i+j],  v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w = w*wlen;
            }
        }
    }
    if (invert)
        for (int i=0; i<n; ++i)
            a[i] = a[i] * (1.0 / n);
}
VL mul(const VL & a, const VL & b) {
    int n = 1;
    while (n < (int)a.size() + (int)b.size()) n *= 2;
    vector<base> x(n), y(n);
    for (int i = 0; i < a.size(); ++i) x[i] = base(a[i], 0);
    for (int i = 0; i < b.size(); ++i) y[i] = base(b[i], 0);
    fft(x, 0);
    fft(y, 0);
    for (int i = 0; i < x.size(); ++i) x[i] = x[i] * y[i];
    fft(x, 1);
    VL res(a.size()+b.size());
    for (int i = 0; i < res.size(); ++i) res[i] = (LL)round(x[i].X);
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}
int a[SIZE];

int main(){
    int n,x;
    R(n,x);
    FOR(i,1,n){
        int v; R(v);
        a[i]=a[i-1];
        if(v<x)a[i]++;
    }
    VL d(n+1),d2(n+1);
    REP(i,n+1)d[a[i]]++;
    REP(i,n+1)d2[n-a[i]]++;
    VL d3=mul(d,d2);
    VL an(n+1);
    REP(i,n+1){
        if(n-i<SZ(d3)){
            an[i]+=d3[n-i];
        }
    }
    an[0]-=n+1;
    an[0]/=2;
    W(an);
    return 0;
}