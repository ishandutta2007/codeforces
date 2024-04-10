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
int get_bit(LL x,int v){return (x>>v)&1;}
int main(){
    int n; R(n);
    VL AA(n);
    REP(i,n){
        R(AA[i]);
    }
    LL ma=*max_element(ALL(AA));
    REP(i,n){
        AA[i]=ma-AA[i];
    }
    sort(ALL(AA));
    //W("AA",AA);
    LL mask=0;
    LL two=1;
    VPLL dp{{0LL,0LL}};
    REP(bit,60){
        two<<=1;
        mask|=1LL<<bit;
        VPLL qq;
        REP(i,n){
            if(get_bit(AA[i],bit)){
                qq.PB({0LL,1LL});
                if(bit!=59){
                    qq.PB({two-(mask&AA[i]),-1});
                    if(two-(mask&AA[i])+(two>>1)<two)qq.PB({two-(mask&AA[i])+(two>>1),1});
                }
                else{
                    if(two-(mask&AA[i])+(two>>1)<two)qq.PB({two-(mask&AA[i])+(two>>1),1});
                }
            }
            else{
                if(bit!=59){
                    qq.PB({two/2-(mask&AA[i]),1});
                    if(mask&AA[i])qq.PB({two-(mask&AA[i]),-1});
                }
                else{
                    qq.PB({two/2-(mask&AA[i]),1});
                }
            }
        }
        qq.PB({0LL,0LL});
        sort(ALL(qq));
        LL now=0;
        VPLL qq2;
        for(int i=0,j;i<SZ(qq);i=j){
            for(j=i;j<SZ(qq)&&qq[i].F==qq[j].F;j++){
                now+=qq[j].S;
            }
            qq2.PB({qq[i].F,now});
        }
        int m=SZ(dp);
        REP(i,m)
            if(dp[i].F+(two/2)<two)dp.PB({dp[i].F+two/2,dp[i].S});
        dp.PB({two,0});
        //W(bit);
        //W(qq2);
        //W(dp);
        int it=0;
        REP(i,SZ(qq2)){
            LL mi=1e18;
            while(dp[it+1].F<=qq2[i].F)it++;
            LL nxt_v=two;
            if(i+1<SZ(qq2))nxt_v=qq2[i+1].F;
            while(dp[it+1].F<nxt_v){
                mi=min(mi,dp[it].S);
                it++;
            }
            mi=min(mi,dp[it].S);
            qq2[i].S+=mi;
        }
        dp=qq2;
    }
    LL an=1e9;
    REP(i,SZ(dp)){
        an=min(an,dp[i].S);
    }
    W(an);
    return 0;
}