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
int MOD = 1e9+7;/*}}}*/
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

const int SIZE = 1<<15;
int n;
int a[20];
LL dp0[SIZE];
LL dp[SIZE];
LL p[20][20];
int get_bit(int x, int v) { return (x >> v) & 1; }
long long mypow(long long x,long long y, int mod = MOD) {
    x %= mod;
    long long res = 1 % mod;
    while(y){
        if(y & 1) { res = res * x % mod; }
        y >>= 1;
        x = x * x % mod;
    }
    return res;
}
void solve() {
    REP(i,n)REP(j,i){
        p[i][j]=a[i]*mypow(a[i]+a[j],MOD-2)%MOD;
        p[j][i]=1;
        ADD(p[j][i],-p[i][j]);
    }
    REPP(i,1,1<<n){
        dp0[i]=1;
        for(int j=(i-1)&i;j;j=(j-1)&i){
            LL now=1;
            REP(x,n)REP(y,n){
                if(get_bit(j,x)&&get_bit(i,y)&&!get_bit(j,y)){
                    now=now*p[x][y]%MOD;
                }
            }
            ADD(dp0[i],-dp0[j]*now);
        }
    }
    LL an=0;
    REPP(i,1,1<<n){
        dp[i]=1;
        REP(x,n){
            REP(y,n){
                if(get_bit(i,x)&&!get_bit(i,y)){
                    dp[i]=dp[i]*p[x][y]%MOD;
                }
            }
        }
        //DEBUG(dp[i],dp0[i]);
        ADD(an,__builtin_popcount(i)*dp[i]%MOD*dp0[i]);
    }
    W(an);
}
void input() {
    R(n);
    REP(i,n)R(a[i]);
}
void fake_input(){
    n=14;
    REP(i,n)a[i]=10000-i;
}
int main(){
    input();
    //fake_input();
    solve();
    return 0;
}