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
const int N_SIZE = 200010;
const int M_SIZE = 3010;
int n,m;
int a[N_SIZE];
int np[2];
LL dp[M_SIZE][M_SIZE];
LL w[N_SIZE];
LL inv[2*M_SIZE];
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
LL dp_pos[M_SIZE],dp_neg[M_SIZE];
int main(){
    MOD=998244353;
    R(n,m);
    FOR(i,1,n)R(a[i]);
    FOR(i,1,n){
        R(w[i]);
        if(a[i])np[1]+=w[i];
        else np[0]+=w[i];
    }
    FOR(i,-M_SIZE,M_SIZE){
        if(np[1]+np[0]+i>=0){
            inv[i+M_SIZE]=mypow(np[0]+np[1]+i,MOD-2);
        }
    }
    dp[0][0]=1;
    REP(i,m){
        FOR(pos_cnt,0,i){
            int neg_cnt=i-pos_cnt;
            if(neg_cnt>np[0])continue;
            ADD(dp[i+1][pos_cnt+1],dp[i][pos_cnt]*(np[1]+pos_cnt)%MOD*inv[pos_cnt-neg_cnt+M_SIZE]);
            if(np[0]>neg_cnt)ADD(dp[i+1][pos_cnt],dp[i][pos_cnt]*(np[0]-neg_cnt)%MOD*inv[pos_cnt-neg_cnt+M_SIZE]);
        }
    }
    LL pos_cc=0,neg_cc=0;
    dp_pos[0]=1;
    REP(i,m){
        dp_pos[i+1]=(dp_pos[i]+dp_pos[i]*mypow(np[1]+i,MOD-2))%MOD;
    }
    FOR(pos_cnt,0,m){
        ADD(pos_cc,dp_pos[pos_cnt]*dp[m][pos_cnt]);
    }
    dp_neg[0]=1;
    REP(i,min(np[0],m)){
        dp_neg[i+1]=(dp_neg[i]-dp_neg[i]*mypow(np[0]-i,MOD-2))%MOD;
        if(dp_neg[i+1]<0)dp_neg[i+1]+=MOD;
    }
    FOR(neg_cnt,0,min(np[0],m)){
        ADD(neg_cc,dp_neg[neg_cnt]*dp[m][m-neg_cnt]);
    }
    FOR(i,1,n){
        if(a[i])W(pos_cc*w[i]%MOD);
        else W(neg_cc*w[i]%MOD);
    }
    return 0;
}