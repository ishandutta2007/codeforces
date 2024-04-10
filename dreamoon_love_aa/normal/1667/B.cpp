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
const int BIT_NUM = 20;
const LL INF = 1e18;
struct BIT{
    int _n;
    long long _d[1 << BIT_NUM];
    void init(int __n) {
        _n=__n;
        FOR(i,1,_n)_d[i]=-INF;
    }
    void ins(int x, long long v) {
        for(; x <= _n; x += x & -x) { _d[x] = max(_d[x], v); }
    }
    long long qq(int x) {
        if(x <= 0) {
            return -INF;
        }
        long long res = -INF;
        for(; x; x -= x & -x) { res = max(res, _d[x]);}
        return res;
    }
}bit_pre,bit_pro;
LL a[SIZE];
LL s[SIZE];
LL zeroes[SIZE];
int n;
void solve() {
    VL d(n+2);
    FOR(i,1,n){
        s[i]=a[i]+s[i-1];
        d[i]=s[i];
    }
    d[n+1]=-INF;
    SORT_UNIQUE(d);
    int m=SZ(d)-1;
    bit_pre.init(m);
    bit_pro.init(m);
    FOR(i,0,m)zeroes[i]=-INF;
    {
        int p=GET_POS(d,0);
        zeroes[p]=0;
        bit_pre.ins(p,0);
        bit_pro.ins(m+1-p,0);
    }
    LL an=0;
    FOR(i,1,n){
        int p=GET_POS(d,s[i]);
        LL v=max({zeroes[p],bit_pre.qq(p-1)+i,bit_pro.qq((m+1-p)-1)-i});
        an=v;
        zeroes[p]=max(zeroes[p],v);
        bit_pre.ins(p,v-i);
        bit_pro.ins(m+1-p,v+i);
    }
    W(an);
}
void input() {
    R(n);
    FOR(i,1,n)R(a[i]);
}
int main(){
    CASET {
        input();
        solve();
    }
    return 0;
}