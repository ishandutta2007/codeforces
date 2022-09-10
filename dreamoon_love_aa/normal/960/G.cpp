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
int MOD = 998244353;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 4e5+10;
LL fac[SIZE],inv[SIZE];
LL mypow(LL x,LL y){
    LL res=1;
    while(y){
        if(y&1)res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}
LL C(int x,int y){
    if(y<0||y>x)return 0;
    return fac[x]*inv[y]%MOD*inv[x-y]%MOD;
}
void build(){
    fac[0]=1;
    REPP(i,1,SIZE)fac[i]=fac[i-1]*i%MOD;
    inv[SIZE-1]=mypow(fac[SIZE-1],MOD-2);
    for(int i=SIZE-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%MOD;
}
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int mod = 998244353;

void add (int &a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}
void sub (int &a, int b)
{
    a -= b;
    if (a < 0)
        a += mod;
}
int mult (int a, int b)
{
    return (ll)a * b % mod;
}
int powmod (int a, int pw)
{
    int res = 1;
    while (pw)
    {
        if (pw & 1)
            res = mult(res, a);
        a = mult(a, a);
        pw >>= 1;
    }

    return res;
}

const int inv2 = (mod + 1) / 2;
#define forn(i, n) for (int i = 0; i < int(n); ++i)
namespace FFT {
    using ld = int;
    using T = int;

    const int MAXB = 21;
    const int MAXN = 1 << MAXB;

    int rev[MAXN];

    void fft(T* a, int K, bool inv) {
        const int n = 1 << K;

        rev[0] = 0;
        for (int i = 1; i < n; ++i) {
            rev[i] = (rev[i >> 1] >> 1) ^ ((i & 1) << (K - 1)); 
        }

        forn(i, n) {
            if (i < rev[i]) {
                swap(a[i], a[rev[i]]);
            }
        }

        for (int len = 1; len < n; len *= 2) {
            vector<T> roots(len);
            
            roots[0] = 1;
            if  (len > 1) {
                roots[1] = powmod(3, (mod - 1) / (2 * len));
            }
            
            for (int i = 2; i < len; ++i) {
                roots[i] = mult(roots[i >> 1], roots[(i + 1) >> 1]);
            }
            
            for (int i = 0; i < n; i += len * 2) {
                forn(j, len) {
                    const auto& w = roots[j];
                    const auto x = a[i + j];
                    const auto y = mult(a[i + len + j], w);
                    a[i + j] = x;
                    add(a[i + j], y);
                    a[i + len + j] = x;
                    sub(a[i + len + j], y);
                    if  (inv) {
                        a[i + j] = mult(a[i + j], inv2);
                        a[i + len + j] = mult(a[i + j + len], inv2);
                    }
                }
            }
        }

        if  (inv) {
            reverse(a + 1, a + n);
        }
    }

    vi mult(const vi& a, const vi& b) {
        int K = 0;
        while ((1 << K) < max(SZ(a), SZ(b))) {
            ++K;
        }
        ++K;

        vector<T> A(1 << K);
        vector<T> B(1 << K);

        forn(i, SZ(a)) {
            A[i] = a[i];
        }
        forn(i, SZ(b)) {
            B[i] = b[i];
        }

        fft(A.data(), K, false);
        fft(B.data(), K, false);
        forn(i, SZ(A)) {
            A[i] = ::mult(A[i], B[i]);
        }
        fft(A.data(), K, true);

        vi res(SZ(A));
        forn(i, SZ(A)) {
            res[i] = A[i];
        }
        
        return res;
    }

    vi brut_mult(const vi& a, const vi& b) {
        vi c(SZ(a) + SZ(b));
        forn(i, SZ(a)) {
            forn(j, SZ(b)) {
                add(c[i + j], ::mult(a[i], b[j]));
            }
        }
        return c;
    }
};

VI kerker[SIZE];
void get(int id,int ll,int rr){
    if(ll==rr){
        kerker[id]={ll,1};
        return;
    }
    int mm=(ll+rr)/2;
    get(id*2,ll,mm);
    get(id*2+1,mm+1,rr);
    kerker[id]=FFT::mult(kerker[id*2], kerker[id*2+1]);
    //W(id,":",kerker[id]);
}
int main(){
    int N,A,B; R(N,A,B);
    if(N==1){
        if(A==1&&B==1)W(1);
        else W(0);
    }
    else if(A==0||B==0)W(0);
    else if(A==1&&B==1)W(0);
    else{
        build();
        LL an=C(A+B-2,A-1);
        if(N==2){
            kerker[1]={1};
        }
        else{
            get(1,1,N-2);
        }
        an=an*kerker[1][A+B-3]%MOD;
        W(an);
    }
    return 0;
}