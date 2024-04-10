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
const int SIZE = 1510;
int a[SIZE],dp0[SIZE];
int n,s,m,k;
int stn[SIZE],stl[SIZE];
PII stk[SIZE][SIZE];
int dp2[SIZE][SIZE];
VI d[SIZE];
int r[SIZE];
int far[SIZE];
bool valid(int v){
    FOR(i,1,n){
        dp0[i]=dp0[i-1]+(a[i]<=v);
    }
    FOR(j,0,m)stn[j]=stl[j]=0;
    dp2[0][0]=0;
    FOR(j,1,m)dp2[0][j]=-10000000;
    FOR(i,1,n){
        far[i]=n+1;
        for(int x:d[i]){
            far[i]=min(far[i],x);
        }
    }
    int mi=n+1;
    for(int i=n;i>0;i--){
        if(far[i]>=mi)far[i]=n+1;
        else mi=far[i];
    }
    FOR(i,1,n){
        FOR(j,0,m)dp2[i][j]=dp2[i-1][j];
        if(far[i]<=n){
            FOR(j,1,m){
                dp2[i][j]=max(dp2[i][j],dp2[far[i]-1][j-1]+dp0[i]-dp0[far[i]-1]);
                while(stl[j]<stn[j]&&stk[j][stl[j]].S<far[i])stl[j]++;
                if(stl[j]<stn[j]){
                    dp2[i][j]=max(dp2[i][j],dp0[i]+stk[j][stl[j]].F);
                }
            }
        }
        FOR(j,1,m){
            int gg=dp2[i][j-1]-dp0[i];
            while(stn[j]>stl[j]&&stk[j][stn[j]-1].F<=gg)stn[j]--;
            stk[j][stn[j]++]={gg,i};
        }
    }
    int ma=-1;
    FOR(i,0,m)ma=max(ma,dp2[n][i]);
    return ma>=k;
}
int main(){
    R(n,s,m,k);
    FOR(i,1,n)R(a[i]);
    VI AA(a+1,a+n+1);
    SORT_UNIQUE(AA);
    REP(i,s){
        int x,y; R(x,y);
        d[y].PB(x);
    }
    int ll=0,rr=SZ(AA);
    while(ll<rr){
        int mm=(ll+rr)/2;
        if(valid(AA[mm]))rr=mm;
        else ll=mm+1;
    }
    if(ll==SZ(AA))W(-1);
    else W(AA[ll]);
    return 0;
}