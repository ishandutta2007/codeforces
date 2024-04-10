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
int l[SIZE],r[SIZE];
int dp[SIZE],dp2[SIZE];
void solve(){
    int n;
    R(n);
    VI d;
    REP(i,n){
        R(l[i],r[i]);
        d.PB(l[i]*2);
        d.PB(l[i]*2-1);
        d.PB(r[i]*2);
        d.PB(r[i]*2+1);
    }
    SORT_UNIQUE(d);
    int m=SZ(d);
    memset(dp,0,sizeof(int)*(m+1));
    memset(dp2,0,sizeof(int)*(m+1));
    REP(i,n){
        l[i]=GET_POS(d,l[i]*2);
        r[i]=GET_POS(d,r[i]*2);
        dp[l[i]]++;
        dp[r[i]+1]--;
    }
    REP(i,m+1){
        dp[i+1]+=dp[i];
    }
    VPII pp;
    int an=0;
    bool multi=0;
    for(int i=0,j;i<m;i=j){
        if(!dp[i]){
            j=i+1;
            continue;
        }
        for(j=i;j<m&&dp[j];j++){
           if(dp[j]>1)multi=1;
        };
        an++;
    }
    if(!multi){
        W(an-1);
        return;
    }
    for(int i=0,j;i<m;i=j){
        if(!dp[i]){
            j=i+1;
            continue;
        }
        for(j=i+1;j<m&&dp[j]==dp[i];j++);
        if(dp[i]==1&&dp[i-1]&&dp[j]){
            dp2[i]=1;
        }
    }
    REPP(i,1,m)dp2[i]+=dp2[i-1];
    int ma=0;
    REP(i,n){
        ma=max(ma,dp2[r[i]]-dp2[l[i]-1]);
    }
    W(an+ma);
}
int main(){
    CASET{
        solve();
    }
    return 0;
}