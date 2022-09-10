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
const int SIZE = 5e5+10;
const int MAX_V = 100000;
VPII p[2];
int dp[2][SIZE][2];
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
LL solve(VPII& d){
    REP(i,2)REP(j,SIZE){
        dp[i][j][0]=SIZE;
        dp[i][j][1]=0;
    }
    REP(i,SZ(d)){
        REP(j,2){
            maa(dp[j][d[i].F][1],d[i].S);
            mii(dp[j][d[i].F][0],d[i].S);
        }
    }
    REPP(i,1,SIZE){
        maa(dp[0][i][1],dp[0][i-1][1]);
        mii(dp[0][i][0],dp[0][i-1][0]);
    }
    for(int i=SIZE-2;i>=0;i--){
        maa(dp[1][i][1],dp[1][i+1][1]);
        mii(dp[1][i][0],dp[1][i+1][0]);
    }
    LL res=0;
    FOR(i,0,SIZE-2){
        res+=max(0,min(dp[0][i][1],dp[1][i+1][1])-max(dp[0][i][0],dp[1][i+1][0]));
    }
    return res;
}
int main(){
    LL an=0;
    int n; R(n);
    REP(i,n){
        int x,y;
        R(x,y);
        if((x+y)%2==0){
            p[0].PB(MP((x+y)/2+MAX_V,(x-y)/2+MAX_V));
        }
        else{
            p[1].PB(MP((x+y+1)/2+MAX_V,(x-y+1)/2+MAX_V));
        }
    }
    REP(i,2)an+=solve(p[i]);
    W(an);
    return 0;
}