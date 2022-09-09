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
const int SIZE = 1000000;
int K;
int q;
int qq[SIZE];
LL ff[6];
LL dp[SIZE];
LL dp2[SIZE];
void update(LL &x, LL v){
    x=max(x,v);
}
PLL stk[SIZE];
void go(int base, LL v){
    int base3 = base * 3;
    memcpy(dp2,dp,sizeof(dp2));
    for(int i = 0; i < base3; i++) {
        int sn=0,sl=0;
        for(int j = 0; i + j * base3 < SIZE; j++) {
            int pos=i+j*base3;
            if(dp[pos]!=-1){
                LL me=dp[pos]-v*j;
                while(sn>sl&&stk[sn-1].F <= me){
                    sn--;
                }
                stk[sn++]=MP(me,j);
            }
            if(sl<sn&&j-stk[sl].S>(K-1)*3) {
                sl++;
            }
            if(sl < sn) {
                LL new_v=stk[sl].F+j*v;
                update(dp2[pos],new_v);
                if(pos+base<SIZE)update(dp2[pos+base],new_v);
                if(pos+base*2<SIZE)update(dp2[pos+base*2],new_v);
            }

        }
    }
    for(int i=SIZE-1;i>=0;i--){
        if(dp[i]==-1)continue;
        int bb=min(SIZE-1LL,i+base*9LL*K);
        LL added=3LL*v*(K-1);
        for(int j=min(bb+1LL,i+base*9LL*(K-1));j<=bb;j+=base){
            update(dp2[j],dp[i]+added);
        }
        for(int j=min(bb+1LL,i+base*9LL*(K-1));j<=bb;j+=base3,added+=v){
            update(dp2[j],dp[i]+added);
        }
    }
    memcpy(dp,dp2,sizeof(dp));
}
void solve() {
    MS1(dp);
    dp[0]=0;
    int ten=1;
    REP(i,6){
        go(ten,ff[i]);
        ten*=10;
    }
}
void input() {
    R(K);
    REP(i,6)R(ff[i]);
    R(q);
    REP(i,q)R(qq[i]);
}
int main(){
    input();
    solve();
    REP(i,q)W(dp[qq[i]]);
    return 0;
}