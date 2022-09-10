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
const int SIZE = 100010;
PLL _p[SIZE],p[SIZE];
int pn;
int n;
int point_ty(const PII &x){
    if(x.S>=0){
        if(x.F<0)return 3;
        return 2;
    }
    else{
        if(x.F>=0)return 1;
        return 0;
    }
}
bool cmp(const PII &x,const PII &y){
    int x_ty=point_ty(x);
    int y_ty=point_ty(y);
    if(x_ty!=y_ty)return x_ty<y_ty;
    else return (LL)x.F*y.S-(LL)y.F*x.S>0;
}
LL calc(int id){
    pn=0;
    REP(i,n){
        if(i==id)continue;
        p[pn++]=MP(_p[i].F-_p[id].F,_p[i].S-_p[id].S);
    }
    sort(p,p+pn,cmp);
    REP(i,pn){
        p[pn+i]=p[i];
    }
    int ll=0;
    LL cnt3=(LL)pn*(pn-1)*(pn-2)/6;
    //LL cnt4=(LL)pn*(pn-1)*(pn-2)*(pn-3)/24;
    REPP(i,1,pn*2){
        while(ll+pn<=i||(LL)p[ll].F*p[i].S-(LL)p[i].F*p[ll].S<0)ll++;
        int num=i-ll;
        if(i>=pn){
            //cnt4-=(LL)num*(num-1)*(num-2)/6;
            cnt3-=num*(num-1)/2;
        }
    }
    return cnt3*(pn-3);
    //return cnt4+(cnt3*(pn-3)-cnt4);
}
int main(){
    R(n);
    REP(i,n)R(_p[i].F,_p[i].S);
    LL an=0;
    REP(i,n){
        an+=calc(i);
    }
    W(an/2);
    return 0;
}