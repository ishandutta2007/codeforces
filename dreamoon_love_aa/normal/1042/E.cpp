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
int MOD = 998244353;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
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
vector<pair<LL,PLL>>AA;
LL dp[SIZE];
LL inv(LL x){
    return mypow(x,MOD-2);
}
LL sqr(LL x){
    return x*x%MOD;
}
int main(){
    int n,m; R(n,m);
    FOR(i,1,n)FOR(j,1,m){
        int v;
        R(v);
        AA.PB(MP(v,MP(i,j)));
    }
    sort(ALL(AA));
    LL r,c; R(r,c);
    int ed=-1;
    REP(i,SZ(AA)){
        if(AA[i].S==MP(r,c)){
            ed=i;
            break;
        }
    }
    while(ed>0&&AA[ed].F==AA[ed-1].F){
        swap(AA[ed],AA[ed-1]);
        ed--;
    }
    if(!ed)W(0);
    else{
        LL an=0;
        LL now=inv(ed);
        dp[ed]=1;
        for(int i=ed-1,j;i>=0;i=j){
            LL nxt=now;
            for(j=i;j>=0&&AA[j].F==AA[i].F;j--)dp[j]=now;
            LL v=inv(j+1);
            for(int k=i;k>j;k--){
                ADD(nxt,now*v);
            }
            now=nxt;
        }
        LL sqr_sum[2]={},sum[2]={};
        for(int i=0,j;i<=ed;i=j){
            for(j=i;j<=ed&&AA[j].F==AA[i].F;j++){
                if(!i)continue;
                LL tmp=(sqr(AA[j].S.F)*i-2*AA[j].S.F*sum[0]+sqr_sum[0])%MOD;
                ADD(tmp,sqr(AA[j].S.S)*i-2*AA[j].S.S*sum[1]+sqr_sum[1]);
                tmp=tmp*inv(i)%MOD*dp[j]%MOD;
                ADD(an,tmp);
            }
            for(j=i;j<=ed&&AA[j].F==AA[i].F;j++){
                ADD(sqr_sum[0],sqr(AA[j].S.F));
                ADD(sqr_sum[1],sqr(AA[j].S.S));
                ADD(sum[0],AA[j].S.F);
                ADD(sum[1],AA[j].S.S);
            }
        }
        W(an);
    }
    return 0;
}