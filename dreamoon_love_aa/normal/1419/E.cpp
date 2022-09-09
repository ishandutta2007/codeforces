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
const int SIZE = 1<<17;
bitset<SIZE>p;
VI pp;
int n;
VPII fac;
LL mypow(LL x,LL y){
    x%=MOD;
    LL res=1%MOD;
    while(y){
        if(y&1)res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}
VI AA[20];
VI BB[20];
VI CC[20];
int get_bit(int x,int v){return (x>>v)&1;}
void dfs(int id,int v,int mask){
    if(id==SZ(fac)){
        if(v==1)return;
        if(!(mask&(mask-1)))AA[__builtin_ctz(mask)].PB(v);
        else{
            for(int i=0;i+1<SZ(fac);i++){
                if(get_bit(mask,i)&&get_bit(mask,i+1)){
                    BB[__builtin_ctz(mask)].PB(v);
                    return;
                }
            }
            if(get_bit(mask,0)&&get_bit(mask,SZ(fac)-1)){
                BB[SZ(fac)-1].PB(v);
                return;
            }
            CC[__builtin_ctz(mask)].PB(v);
        }
        return;
    }
    dfs(id+1,v,mask);
    REP(i,fac[id].S){
        v*=fac[id].F;
        dfs(id+1,v,mask|(1<<id));
    }
}
void solve() {
    fac.clear();
    int _n=n;
    for(int x:pp){
        if(_n%x==0){
            int cnt=0;
            while(_n%x==0){
                cnt++;
                _n/=x;
            }
            fac.PB(MP(x,cnt));
        }
    }
    if(_n>1)fac.PB(MP(_n,1));
    if(SZ(fac)==1){
        LL v=1;
        VI res;
        FOR(i,1,fac[0].S){
            v*=fac[0].F;
            res.PB(v);
        }
        W(res);
        W(0);
    }
    else if(SZ(fac)==2){
        VI d[2];
        FOR(i,1,fac[0].S)FOR(j,1,fac[1].S){
            if(SZ(d[0]))d[1].PB(mypow(fac[0].F,i)*mypow(fac[1].F,j));
            else d[0].PB(mypow(fac[0].F,i)*mypow(fac[1].F,j));
        }
        VI res;
        FOR(i,1,fac[0].S)res.PB(mypow(fac[0].F,i));
        for(int x:d[0])res.PB(x);
        FOR(i,1,fac[1].S)res.PB(mypow(fac[1].F,i));
        for(int x:d[1])res.PB(x);
        W(res);
        W(1-(SZ(d[1])!=0));
    }
    else{
        REP(i,SZ(fac)){
            AA[i].clear();
            BB[i].clear();
            CC[i].clear();
        }
        dfs(0,1,0);
        VI res;
        REP(i,SZ(fac)){
            for(int x:AA[i])res.PB(x);
            for(int x:CC[i])res.PB(x);
            for(int x:BB[i])res.PB(x);
        }
        W(res);
        W(0);
    }
}
void input() {
    R(n);
    for(int i=2;i*i<=1000000000;i++){
        if(!p[i])
        {
            pp.PB(i);
            for(int j=i+i;j<SIZE;j+=i)p[j]=1;
        }
    }
}
void pre(){
}
int main(){
    pre();
#define MULTITEST 1
#if MULTITEST    
    CASET
#endif
    {
        input();
        solve();
    }
    return 0;
}