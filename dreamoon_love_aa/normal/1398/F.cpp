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
const int SIZE = 1<<20;
char s[SIZE];
int dp[2][SIZE],d[SIZE];
struct BIT{
    int _n;
    int _d[SIZE];
    void init(int __n){
        _n=__n;
        memset(_d,0,sizeof(int)*(_n+1));
    }
    void ins(int x,int v){
        for(;x<=_n;x+=x&-x)_d[x]=max(_d[x],v);
    }
    int qq(int x){
        int res=0;
        for(;x;x-=x&-x)res=max(res,_d[x]);
        return res;
    }
}bit;
PII AA[SIZE];
int an[SIZE];
void solve() {
    int n;
    R(n);
    RS(s+1);
    bit.init(n);
    FOR(i,1,n){
        if(s[i]=='?'||s[i]=='1')dp[1][i]=dp[1][i-1]+1;
        else dp[1][i]=0;
        if(s[i]=='?'||s[i]=='0')dp[0][i]=dp[0][i-1]+1;
        else dp[0][i]=0;
        AA[i-1]=MP(max(dp[0][i],dp[1][i]),i);
    }
    sort(AA,AA+n,greater<PII>());
    int it=0;
    for(int i=n;i>1;i--){
        int now=n;
        int v=0;
        while(it<n&&AA[it].F==i){
            bit.ins(AA[it].S,AA[it].S);
            it++;
        }
        while(now>=1){
            int ret=bit.qq(now);
            if(!ret)break;
            int step=max(dp[0][ret],dp[1][ret])/i;
            v+=step;
            now=ret-step*i;
        }
        an[i]=v;
    }
    an[1]=n;
    W(VI(an+1,an+1+n));
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