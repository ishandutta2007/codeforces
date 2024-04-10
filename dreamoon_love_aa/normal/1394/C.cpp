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
#define PB emplace_back
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
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
void print(int x,int y){
    REP(i,x)putchar('B');
    REP(i,y)putchar('N');
}
int x[SIZE],y[SIZE];
void solve() {
    int n;
    R(n);
    REP(i,n){
        string s;
        R(s);
        REP(j,SZ(s)){
            if(s[j]=='B')x[i]++;
            else y[i]++;
        }
    }
    if(n==1){
        W(0);
        print(x[0],y[0]);
        return;
    }
    int ll=0,rr=500000;
    while(ll<rr){
        int mm=(ll+rr)/2;
        PII ma=MP(MOD,MOD),mi=MP(-MOD,-MOD);
        int ma_x_sub_y=MOD,mi_x_sub_y=-MOD;
        REP(i,n){
           mii(ma.F,x[i]+mm);
           mii(ma.S,y[i]+mm);
           maa(mi.F,x[i]-mm);
           maa(mi.S,y[i]-mm);
           mii(ma_x_sub_y,x[i]-y[i]+mm);
           maa(mi_x_sub_y,x[i]-y[i]-mm);
        }
        bool err=0;
        if(ma.F<mi.F||ma.S<mi.S||ma_x_sub_y<mi_x_sub_y)err=1;
        if(mi.F-ma.S>ma_x_sub_y)err=1;
        if(ma.F-mi.S<mi_x_sub_y)err=1;
        if(err)ll=mm+1;
        else rr=mm;
    }
    {
        W(ll);
        int mm=ll;
        PII ma=MP(MOD,MOD),mi=MP(-MOD,-MOD);
        int ma_x_sub_y=MOD,mi_x_sub_y=-MOD;
        REP(i,n){
           mii(ma.F,x[i]+mm);
           mii(ma.S,y[i]+mm);
           maa(mi.F,x[i]-mm);
           maa(mi.S,y[i]-mm);
           mii(ma_x_sub_y,x[i]-y[i]+mm);
           maa(mi_x_sub_y,x[i]-y[i]-mm);
        }
        if(ma.F-ma.S>=mi_x_sub_y&&ma.F-ma.S<=ma_x_sub_y){
            print(ma.F,ma.S);
        } else if (ma.F-ma.S<mi_x_sub_y){
            print(ma.F,ma.F-mi_x_sub_y);
        } else{
            print(ma.S+ma_x_sub_y,ma.S);
        }
    }
}
int main(){
#define MULTITEST 0
#if MULTITEST    
    CASET{
        solve();
    }
#else
    solve();
#endif
    return 0;
}