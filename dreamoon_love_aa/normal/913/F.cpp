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
typedef int64_t LL;
typedef uint64_t ULL;
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
template<class T, class... U> void DEBUG(const T &head, const U &... tail) { 
#ifdef HOME
    _W('#'); _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...);
#endif
}
int MOD = 998244353;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 2010;
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
LL dp[SIZE],p,dp0[SIZE][SIZE],inv_p,dp2[SIZE][SIZE];
LL win[SIZE],lose[SIZE];
int main(){
    int n;
    R(n);
    {
        int a,b;
        R(a,b);
        p=a*mypow(b,MOD-2)%MOD;
        inv_p=1;
        ADD(inv_p,-p);
        win[0]=lose[0]=1;
        FOR(i,1,n)win[i]=win[i-1]*p%MOD;
        FOR(i,1,n)lose[i]=lose[i-1]*inv_p%MOD;
    }
    dp[1]=0;
    dp0[1][1]=dp0[1][0]=1;
    dp2[1][1]=1;
    REPP(i,1,n){
        FOR(j,0,i){
            ADD(dp0[i+1][j+1],dp0[i][j]*lose[i-j]);
            ADD(dp0[i+1][j],dp0[i][j]*win[j]);
        }
        i++;
        dp2[i][1]=dp0[i][1];
        REPP(j,2,i){
            dp2[i][j]=dp0[i][j]*dp2[j][j]%MOD;
        }
        dp2[i][i]=1;
        REPP(j,1,i)ADD(dp2[i][i],-dp2[i][j]);
        LL ss=i*(i-1)/2;
        FOR(j,1,i)ADD(ss,dp2[i][j]*(dp[j]+dp[i-j]-(i-j)*(i-j-1)/2));
        dp[i]=ss*mypow(MOD+1-dp2[i][i],MOD-2)%MOD;
        i--;
    }
    W(dp[n]);
    return 0;
}