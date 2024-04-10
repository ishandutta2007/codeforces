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
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
char s[SIZE];
PII dp[SIZE][2],dp2[SIZE][3];
PII better(PII x,PII y){
    if(MP(x.F,-x.S)>MP(y.F,-y.S))return x;
    return y;
}
PII add(PII x,PII y){
    return MP(x.F+y.F,x.S+y.S);
}
int main(){
    int n,m;
    R(n);
    RS(s+1);
    R(m);
    int an=0;
    if(m==1){
        FOR(i,1,n){
            if(s[i]=='?')an++;
        }
        W(an);
    }
    else{
        FOR(i,1,n){
            if(s[i]!='b'){
                dp[i][i&1]=dp[i-1][i&1];
                dp[i][i&1].F++;
                dp[i][i&1].S+=(s[i]=='?');
            }
            else{
                dp[i][i&1]=MP(0,0);
            }
            if(s[i]!='a'){
                dp[i][(i&1)^1]=dp[i-1][(i&1)^1];
                dp[i][(i&1)^1].F++;
                dp[i][(i&1)^1].S+=(s[i]=='?');
            }
            else{
                dp[i][(i&1)^1]=MP(0,0);
            }
        }
        dp2[0][0]=dp2[0][1]=MP(-MOD,0);
        FOR(i,1,n){
            int me=i&1;
            dp2[i][0]=MP(-MOD,0);
            dp2[i][1]=MP(-MOD,1);
            if(s[i]!='b'&&1==m%2){
                if(dp[i][me].F>=m){
                    dp2[i][me]=better(dp2[i][me],add(dp2[i-m][2],MP(1,dp[i][me].S-dp[i-m][me].S)));
                }
            }
            me=(i&1)^1;
            if(s[i]!='a'&&0==m%2){
                if(dp[i][me].F>=m){
                    dp2[i][me]=better(dp2[i][me],add(dp2[i-m][2],MP(1,dp[i][me].S-dp[i-m][me].S)));
                }
            }
            dp2[i][2]=better(better(dp2[i-1][2],dp2[i][0]),dp2[i][1]);
        }
        an=dp2[n][2].S;
        W(an);
    }
    return 0;
}