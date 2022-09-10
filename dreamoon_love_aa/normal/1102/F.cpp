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
int d1[16][16],d2[16][16];
int AA[16][10000];
int dp[1<<16][16][16];
int main(){
    int n,m; R(n,m);
    REP(i,n)REP(j,m) R(AA[i][j]);
    REP(i,n)REP(j,i){
        int mi=MOD;
        REP(k,m){
            mi=min(mi,abs(AA[i][k]-AA[j][k]));
        }
        d1[i][j]=d1[j][i]=mi;
    }
    REP(i,n)REP(j,n){
        int mi=MOD;
        REPP(k,1,m){
            mi=min(mi,abs(AA[i][k]-AA[j][k-1]));
        }
        d2[i][j]=mi;
    }
    MS1(dp);
    auto maa = [](auto& x,auto y){if(x<y)x=y;};
    REPP(i,1,1<<n){
        if(!(i&(i-1))){
            int id=__builtin_ctz(i);
            dp[i][id][id]=MOD;
        }
        REP(j,n){
            if(!((i>>j)&1))continue;
            REP(k,n){
                if(dp[i][j][k]==-1)continue;
                REP(k2,n){
                    if((i>>k2)&1)continue;
                    maa(dp[i|(1<<k2)][j][k2],min(dp[i][j][k],d1[k][k2]));               
                }
            }
        }
        if(i==(1<<n)-1){
            int an=0;
            REP(j,n)REP(k,n){
                an=max(an,min(dp[i][j][k],d2[j][k]));
            }
            W(an);
        }
    }
    return 0;
}