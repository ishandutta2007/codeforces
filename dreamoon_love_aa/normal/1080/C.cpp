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
int main(){
    CASET{
        LL n,m;
        R(n,m);
        LL x1,y1,x2,y2;
        LL x3,y3,x4,y4;
        R(x1,y1,x2,y2);
        R(x3,y3,x4,y4);
        LL x5=max(x1,x3);
        LL x6=min(x2,x4);
        LL y5=max(y1,y3);
        LL y6=min(y2,y4);
        LL ww=(n*m+1)/2;
        LL bb=n*m/2;
        int r=1-(x1+y1)%2;
        ww+=((x2-x1+1LL)*(y2-y1+1LL)+1-r)/2;
        bb-=((x2-x1+1LL)*(y2-y1+1LL)+1-r)/2;
        int r2=1-(x3+y3)%2;
        LL ww2=((x4-x3+1LL)*(y4-y3+1LL)+r2)/2;
        LL bb2=((x4-x3+1LL)*(y4-y3+1LL)+1-r2)/2;
        if(x5<=x6&&y5<=y6){
            int r3=1-(x5+y5)%2;
            ww2-=((x6-x5+1LL)*(y6-y5+1LL)+r3)/2;
            bb2-=((x6-x5+1LL)*(y6-y5+1LL)+(1-r3))/2;
            ww-=(x6-x5+1LL)*(y6-y5+1LL);
            bb+=(x6-x5+1LL)*(y6-y5+1LL);
        }
        ww-=ww2;
        bb+=ww2;
        W(ww,bb);
    }
    return 0;
}