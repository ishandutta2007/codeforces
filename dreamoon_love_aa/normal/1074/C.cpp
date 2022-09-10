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
PII p[SIZE];
VPII AA;
int an[SIZE];
int f(PII x,PII y,PII z){
    VPII gg{x,y,z};
    PII mi{MOD,MOD},ma{-MOD,-MOD};
    REP(i,3){
        mi.F=min(mi.F,gg[i].F);
        mi.S=min(mi.S,gg[i].S);
        ma.F=max(ma.F,gg[i].F);
        ma.S=max(ma.S,gg[i].S);
    }
    return (ma.F+ma.S-mi.F-mi.S)*2;
}
int main(){
    int n; R(n);
    PII mi{MOD,MOD},ma{-MOD,-MOD};
    REP(i,n){
        R(p[i].F,p[i].S);
        mi.F=min(mi.F,p[i].F);
        mi.S=min(mi.S,p[i].S);
        ma.F=max(ma.F,p[i].F);
        ma.S=max(ma.S,p[i].S);
    }
    FOR(i,4,n)an[i]=(ma.F+ma.S-mi.F-mi.S)*2;
    sort(p,p+n);
    for(int it=0;it<n&&p[it].F==p[0].F;it++)AA.PB(p[it]);
    for(int it=n-1;it>=0&&p[it].F==p[n-1].F;it--)AA.PB(p[it]);
    REP(i,n)swap(p[i].F,p[i].S);
    sort(p,p+n);
    for(int it=0;it<n&&p[it].F==p[0].F;it++)AA.PB({p[it].S,p[it].F});
    for(int it=n-1;it>=0&&p[it].F==p[n-1].F;it--)AA.PB({p[it].S,p[it].F});
    REP(i,n)swap(p[i].F,p[i].S);
    REP(i,n){
        REP(j,SZ(AA))REP(k,j){
            an[3]=max(an[3],f(p[i],AA[j],AA[k]));
        }
    }
    W(VI(an+3,an+n+1));
    return 0;
}