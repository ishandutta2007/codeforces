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
const int SIZE = 51;
int a[SIZE];
int b[SIZE];
LL dp[SIZE][5001][26];
void update(LL& x,LL v){
    if(x==-1||x>v)x=v;
}
int main(){
    int n; R(n);
    FOR(i,1,n)R(a[i]);
    FOR(i,1,n)R(b[i]);
    VPII pp;
    FOR(i,1,n)pp.PB(MP(a[i],-b[i]));
    sort(ALL(pp));
    REP(i,n)pp[i].S=-pp[i].S;
    MS1(dp);
    dp[0][0][0]=0;
    int now=0;
    for(int i=0,j;i<SZ(pp);i=j){
        LL sum=0;
        for(j=i;j<SZ(pp)&&pp[i].F==pp[j].F;j++);
        int m=j-i;
        int ss=0;
        FOR(k,0,m){
            FOR(x,0,now){
                FOR(y,0,n/2){
                    if(dp[i][x][y]==-1)continue;
                    int ny=max(0,y-k)+m-k;
                    if(ny*2>n)continue;
                    update(dp[j][x+ss][ny],dp[i][x][y]+sum);
                }
            }
            if(k<m){
                sum+=pp[i+k].F;
                ss+=pp[i+k].S;
            }
        }
        now+=ss;
    }
    LL an=1e18;
    FOR(i,1,5000){
        if(dp[n][i][0]!=-1){
            an=min(an,(dp[n][i][0]*1000+i-1)/i);
        }
    }
    W(an);
    return 0;
}