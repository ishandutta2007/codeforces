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
VPLL AA;
int an[500];
LL g(LL x,int it){
    VI ker;
    while(x){
        ker.PB(x%10);
        x/=10;
    }
    reverse(ALL(ker));
    return ker[it];
}
LL f(LL n){
    if(n<=9)return n;
    n-=9;
    if(n<=90*2){
        return g(10+(n-1)/2,(n-1)%2);
    }
    n-=90*2LL;
    if(n<=900*3){
        return g(100+(n-1)/3,(n-1)%3);
    }
    n-=900*3LL;
    if(n<=9000*4LL){
        return g(1000+(n-1)/4,(n-1)%4);
    }
    n-=9000*4LL;
    if(n<=90000*5LL){
        return g(10000+(n-1)/5,(n-1)%5);
    }
    n-=90000*5LL;
    if(n<=900000*6LL){
        return g(100000+(n-1)/6,(n-1)%6);
    }
    n-=900000*6LL;
    if(n<=9000000*7LL){
        return g(1000000+(n-1)/7,(n-1)%7);
    }
    n-=9000000*7LL;
    if(n<=90000000*8LL){
        return g(10000000+(n-1)/8,(n-1)%8);
    }
    n-=90000000*8LL;
    if(n<=900000000*9LL){
        return g(100000000+(n-1)/9,(n-1)%9);
    }
    return -1;
}
int main(){
    int q;
    R(q);
    REP(i,q){
        LL x;
        R(x);
        AA.PB({x,i});
    }
    sort(ALL(AA));
    LL now=0;
    LL len=0;
    int it=0;
    FOR(i,1,9){
        len++;
        while(it<q&&now+len>=AA[it].F){
            an[AA[it].S]=f(AA[it].F-now);
            it++;
        }
        now+=len;
    }
    FOR(i,10,99){
        len+=2;
        while(it<q&&now+len>=AA[it].F){
            an[AA[it].S]=f(AA[it].F-now);
            it++;
        }
        now+=len;
    }
    FOR(i,100,999){
        len+=3;
        while(it<q&&now+len>=AA[it].F){
            an[AA[it].S]=f(AA[it].F-now);
            it++;
        }
        now+=len;
    }
    FOR(i,1000,9999){
        len+=4;
        while(it<q&&now+len>=AA[it].F){
            an[AA[it].S]=f(AA[it].F-now);
            it++;
        }
        now+=len;
    }
    FOR(i,10000,99999){
        len+=5;
        while(it<q&&now+len>=AA[it].F){
            an[AA[it].S]=f(AA[it].F-now);
            it++;
        }
        now+=len;
    }
    FOR(i,100000,999999){
        len+=6;
        while(it<q&&now+len>=AA[it].F){
            an[AA[it].S]=f(AA[it].F-now);
            it++;
        }
        now+=len;
    }
    FOR(i,1000000,9999999){
        len+=7;
        while(it<q&&now+len>=AA[it].F){
            an[AA[it].S]=f(AA[it].F-now);
            it++;
        }
        now+=len;
    }
    FOR(i,10000000,99999999){
        len+=8;
        while(it<q&&now+len>=AA[it].F){
            an[AA[it].S]=f(AA[it].F-now);
            it++;
        }
        now+=len;
    }
    FOR(i,100000000,482720320){
        len+=9;
        while(it<q&&now+len>=AA[it].F){
            an[AA[it].S]=f(AA[it].F-now);
            it++;
        }
        now+=len;
    }
    W(VI(an,an+q));
    return 0;
}