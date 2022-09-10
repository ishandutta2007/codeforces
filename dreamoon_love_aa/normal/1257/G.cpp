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
/*}}}*/
const int SIZE = 1e6+10;
int p[SIZE];
VI d;
const int MOD = 998244353;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
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
    assert(MOD>=SIZE);
    fac[0]=1;
    REPP(i,1,SIZE)fac[i]=fac[i-1]*i%MOD;
    inv[SIZE-1]=mypow(fac[SIZE-1],MOD-2);
    for(int i=SIZE-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%MOD;
}
void add (int &a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}
void sub (int &a, int b) {
    a -= b;
    if (a < 0)
        a += MOD;
}
int mult (int a, int b) {
    return (LL)a * b % MOD;
}

const int inv2 = (MOD + 1) / 2;
namespace NTT {
    using T = int;

    const int MAXB = 21;
    const int MAXN = 1 << MAXB;

    int rev[MAXN];

    void ntt(T* a, int K, bool inv) {
        const int n = 1 << K;

        rev[0] = 0;
        REPP(i, 1, n) {
            rev[i] = (rev[i >> 1] >> 1) ^ ((i & 1) << (K - 1)); 
        }

        REP(i, n) {
            if (i < rev[i]) {
                swap(a[i], a[rev[i]]);
            }
        }

        for (int len = 1; len < n; len *= 2) {
            vector<T> roots(len);
            
            roots[0] = 1;
            if  (len > 1) {
                roots[1] = mypow(3, (MOD - 1) / (2 * len));
            }
            
            REPP(i, 2, len) {
                roots[i] = mult(roots[i >> 1], roots[(i + 1) >> 1]);
            }
            
            for (int i = 0; i < n; i += len * 2) {
                REP(j, len) {
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

    VI brut_mult(const VI& a, const VI& b) {
        VI c(SZ(a) + SZ(b));
        REP(i, SZ(a)) {
            REP(j, SZ(b)) {
                add(c[i + j], ::mult(a[i], b[j]));
            }
        }
        return c;
    }
    VI powr(const VI& a, int m){
        if(!m) return {1};
        int K = 0;
        while ((1 << K) < SZ(a)*m) {
            ++K;
        }
        ++K;

        vector<T> A(1 << K);

        REP(i, SZ(a)) {
            A[i] = a[i];
        }
        ntt(A.data(), K, false);
        REP(i, SZ(A)) {
            A[i] = mypow(A[i], m);
        }
        ntt(A.data(), K, true);

        VI res(SZ(A));
        REP(i, SZ(res)) {
            res[i] = A[i];
        }
        int len=SZ(res);
        while(len>1&&res[len-1]==0)len--;
        res.resize(len);
        return res;
    }
    VI mult(const VI& a, const VI& b) {
        int K = 0;
        while ((1 << K) < max(SZ(a), SZ(b))) {
            ++K;
        }
        ++K;

        vector<T> A(1 << K);
        vector<T> B(1 << K);

        REP(i, SZ(a)) {
            A[i] = a[i];
        }
        REP(i, SZ(b)) {
            B[i] = b[i];
        }

        ntt(A.data(), K, false);
        ntt(B.data(), K, false);
        REP(i, SZ(A)) {
            A[i] = ::mult(A[i], B[i]);
        }
        ntt(A.data(), K, true);

        VI res(SZ(A));
        REP(i, SZ(A)) {
            res[i] = A[i];
        }
        int len=SZ(res);
        while(len>1&&res[len-1]==0)len--;
        res.resize(len);
        return res;
    }
};
VI qq[1<<19];
LL get(int v){
    if(v<0)return 0;
    int m=SZ(d)-1;
    LL ret=0;
    REP(i,SZ(qq[1])){
        if(i>v)break;
        if(qq[1][i]){
            ADD(ret,C(m+v-i,m)*qq[1][i]);
        }
    }
    return ret;
}
void f(int L,int R,int id){
    if(L==R){
        qq[id]=VI(d[L]+2);
        qq[id][0]=1;
        qq[id].back()=-1;
        return;
    }
    int mm=(L+R)/2;
    f(L,mm,id*2);
    f(mm+1,R,id*2+1);
    qq[id]=NTT::mult(qq[id*2+1],qq[id*2]);
}
void solve(){
    if(SZ(d)==1){
        W(1);
        return;
    }
    int sum=0;
    for(int i=0;i+1<SZ(d);i++){
        sum+=d[i];
    }
    if(sum<=d.back()){
        LL res=1;
        REP(i,SZ(d)-1){
            res=res*(d[i]+1)%MOD;
        }
        W(res);
        return;
    }
    f(0,SZ(d)-2,1);
    //W(qq[1]);
    build();
    for(int i=0;i<=sum;i++){
        if(abs(i-(sum-(i+d.back())))<=1){
            LL res=get(i+d.back());
            ADD(res,-get(i-1));
            W(res);
            return;
        }
    }
}
int main(){
    int n; R(n);
    REP(i,n)R(p[i]);
    sort(p,p+n);
    for(int i=0,j;i<n;i=j){
        for(j=i+1;j<n&&p[j]==p[i];j++);
        d.PB(j-i);
    }
    sort(ALL(d));
    solve();
    return 0;
}