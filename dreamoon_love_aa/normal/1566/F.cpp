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

const int SIZE = 1<<18;
const LL INF = 1e18;
int a[SIZE];
int n,m;
VPII pp;
VPII AA[SIZE];
LL dp[SIZE][2];
void upd(LL &x, LL v){
    if(x > v){
        x=v;
    }
}
void go(LL target[], LL source[], LL low, LL hi, LL a0, LL a1){
    upd(target[0],source[0]+a0+low-hi*2);
    upd(target[1],source[0]+a0+low-hi-a1);
    upd(target[0],source[1]+2*low-hi*2);
    upd(target[1],source[1]+2*low-hi-a1);
}
void solve() {
    sort(ALL(pp));
    int now=-MOD;
    sort(a+1,a+n+1);
    int it=1;
    REP(i,m){
        pp[i].S=-pp[i].S;
        if(pp[i].S>now){
            now=pp[i].S;
            while(it<=n&&pp[i].F>=a[it])it++;
            if(it==1||pp[i].S>a[it-1]){
                AA[it-1].PB(pp[i]);
            }
        }
    }
    if(SZ(AA[0])){
        dp[0][0]=-AA[0][0].F*2LL;
        dp[0][1]=-AA[0][0].F-a[1];
    }else{
        dp[0][0]=dp[0][1]=-a[1]*2LL;
    }
    FOR(i,1,n-1){
        REP(j,2)dp[i][j]=INF;
        LL low=a[i];
        LL hi;
        if(SZ(AA[i])){
            hi=AA[i][0].F;
        }else{
            hi=a[i+1];
        }
        go(dp[i],dp[i-1],low,hi,a[i],a[i+1]);
        REP(j,SZ(AA[i])){
            low=AA[i][j].S;
            if(j!=SZ(AA[i])-1)hi=AA[i][j+1].F;
            else hi=a[i+1];
            go(dp[i],dp[i-1],low,hi,a[i],a[i+1]);
        }
    }
    int me=a[n];
    if(SZ(AA[n]))me=AA[n].back().S;
    W(min(dp[n-1][0]+me+a[n],dp[n-1][1]+me*2LL));
}
void input() {
    R(n,m);
    FOR(i,1,n)R(a[i]);
    FOR(i,0,n)AA[i].clear();
    pp.resize(m);
    REP(i,m){
        R(pp[i].S,pp[i].F);
        pp[i].S=-pp[i].S;
    }
}
int main(){
    CASET {
        input();
        solve();
    }
    return 0;
}