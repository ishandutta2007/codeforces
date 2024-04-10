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
 #define DEBUG(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;/*}}}*/
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

const int SIZE = 1<<20;
long long mypow(long long x,long long y, int mod = MOD) {
    x %= mod;
    long long res = 1 % mod;
    while(y){
        if(y & 1) { res = res * x % mod; }
        y >>= 1;
        x = x * x % mod;
    }
    return res;
}
LL inv(LL x){
    return mypow(x,MOD-2);
}
int n,m;
LL p;
PII r,d;
void solve() {
    VI xx,yy;
    int dd=1;
    REP(i,2*n-2){
        xx.PB(r.F);
        if(r.F+dd>n||r.F+dd<=0){
            dd=-dd;
        }
        r.F+=dd;
    }
    dd=1;
    REP(i,2*m-2){
        yy.PB(r.S);
        if(r.S+dd>m||r.S+dd<=0){
            dd=-dd;
        }
        r.S+=dd;
    }
    LL now=1;
    p=p*inv(100)%MOD;
    LL neg_p=1;
    ADD(neg_p,-p);
    LL base=0;
    REP(i,(2*n-2)*(2*m-2)){
        if(xx[i%(2*n-2)]==d.F||yy[i%(2*m-2)]==d.S){
            ADD(base,now*p%MOD*(i+1));
            now=now*neg_p%MOD;
        }
    }
    LL an=base;
    ADD(an,now*(2*n-2)*(2*m-2));
    now=1-now;
    ADD(now,0);
    an=an*inv(now)-1;
    ADD(an,0);
    W(an);
}
void input() {
    R(n,m,r.F,r.S,d.F,d.S,p);
}
int main(){
    CASET {
        input();
        solve();
    }
    return 0;
}