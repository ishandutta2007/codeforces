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
const int SIZE = 1<<11;
int x[SIZE],y[SIZE],v[SIZE];
int dp[SIZE][SIZE];
int ma_len[SIZE];
PII stk[SIZE];
int sn;
LL get_sum(LL _x,LL _y){
    return (_y-_x+1)*(_x+_y)/2%MOD;
}
void solve() {
    auto maa = [](auto& x,auto y){if(x<y)x=y;};
    int n,m,q;
    R(n,m,q);
    REP(i,m){
        R(x[i],y[i],v[i]);
        maa(ma_len[x[i]],v[i]);
        maa(ma_len[y[i]],v[i]);
    }
    MS1(dp);
    dp[0][1]=0;
    REP(i,n){
        REP(j,m){
            if(dp[i][x[j]]!=-1){
                maa(dp[i+1][y[j]],dp[i][x[j]]+v[j]);
            }
            if(dp[i][y[j]]!=-1){
                maa(dp[i+1][x[j]],dp[i][y[j]]+v[j]);
            }
        }
    }
    LL an=0;
    REPP(i,1,n){
        int ma=0;
        FOR(j,1,n){
            maa(ma,dp[i][j]);
        }
        DEBUG("ma",i,ma);
        ADD(an,ma);
    }
    VPII AA;
    FOR(i,1,n){
        int ma=0;
        REP(j,n){
            if(dp[j][i]!=-1){
                maa(ma,dp[j][i]+(n-1-j)*ma_len[i]);
            }
        }
        AA.PB(MP(ma_len[i],ma));
    }
    int r=q-(n-1);
    sort(ALL(AA));
    {
        DEBUG(AA);
        int it=0;
        REP(i,SZ(AA)){
            while(it&&AA[it-1].S<=AA[i].S)it--;
            AA[it++]=AA[i];
        }
        AA.resize(it);
        DEBUG(AA);
    }
    REP(i,SZ(AA)){
        if(i+1<SZ(AA)&&(AA[i].F<=AA[i+1].F&&AA[i].S<=AA[i+1].S))continue;
        if(!sn){
            stk[sn++]=AA[i];
        }
        else{
            while(sn>1){
                if(sn==1){
                    if(AA[i].S>=stk[sn-1].S)sn--;
                    break;
                }
                else{
                    LD val=(LD)(stk[sn-1].S-stk[sn-2].S)/(stk[sn-2].F-stk[sn-1].F);
                    if(AA[i].F*val+AA[i].S>=stk[sn-1].F*val+stk[sn-1].S)sn--;
                    else break;
                }
            }
            stk[sn++]=AA[i];
        }
    }
    int now=0;
    REP(i,sn){
        DEBUG("final",stk[i]);
        if(i==sn-1){
            ADD(an,(LL)(r-now)*stk[i].S+get_sum(now+1,r)*stk[i].F);
        }
        else{
            LL nxt=min((LL)floor((LD)(stk[i].S-stk[i+1].S)/(stk[i+1].F-stk[i].F)),(LL)r);
            ADD(an,(nxt-now)*stk[i].S+get_sum(now+1,nxt)*stk[i].F);
            now=nxt;
        }
    }
    W(an);
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