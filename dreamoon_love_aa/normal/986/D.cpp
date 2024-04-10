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
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
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
const int BB = 1000;
VI mul(const VI & a, const VI & b) {
    int n = 1;
    while (n < (int)a.size() + (int)b.size()) n *= 2;
    vector<base> x(n), y(n);
    for (int i = 0; i < (int)a.size(); ++i) x[i] = base(a[i], 0);
    for (int i = 0; i < (int)b.size(); ++i) y[i] = base(b[i], 0);
    fft(x, 0);
    fft(y, 0);
    for (int i = 0; i < (int)x.size(); ++i) x[i] = x[i] * y[i];
    fft(x, 1);
    VL res(a.size()+b.size());
    for (int i = 0; i < (int)res.size(); ++i) res[i] = (LL)round(x[i].X);
    REP(i,8)res.PB(0);
    REP(i,SZ(res)-1){
        res[i+1]+=res[i]/BB;
        res[i]%=BB;
    }
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    VI res2(SZ(res));
    REP(i,SZ(res))res2[i]=res[i];
    return res2;
}
VI in;
char input[1555555];
int now_three;
VI three{3},res{1};
bool valid(int ker){
    int base=ker%3;
    if(base<=1)base+=3;
    ker-=base;
    VI bb{base};
    ker/=3;
    if(!now_three){
        now_three=ker;
        while(ker){
            if(ker&1){
                res=mul(res,three);
            }
            three=mul(three,three);
            ker>>=1;
        }
    }
    else{
        for(;now_three<ker;now_three++){
            REP(i,SZ(res))res[i]*=3;
            res.PB(0);
            REP(i,SZ(res)-1){
                res[i+1]+=res[i]/BB;
                res[i]%=BB;
            }
            while(res.back()==0)res.pop_back();
        }
    }
    VI me=mul(res,bb);
    if(SZ(me)>SZ(in))return 1;
    if(SZ(me)<SZ(in))return 0;
    for(int i=SZ(me)-1;i>=0;i--){
        if(me[i]!=in[i])return me[i]>in[i];
    }
    return 1;
}
int main(){
    RS(input);
    int len=LEN(input);
    if(len==1){
        int v=atoi(input);
        if(v<=4)W(v);
        else if(v<=6)W(5);
        else W(6);
        return 0;
    }
    {
        int it=0;
        int ten=1;
        while(it<len){
            if(ten==1){
                in.PB(0);
            }
            in.back()+=ten*(input[len-1-it]-'0');
            ten*=10;
            if(ten>=BB){
                ten=1;
            }
            it++;
        }
    }
    int st=(len-1)*log(10)/log(3)*3-2;
    st=max(st,6);
    while(!valid(st))st++;
    W(st);
    return 0;
}