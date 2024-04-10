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
const int SIZE = 2e6+10;
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
LL inv(LL x){
    return mypow(x,MOD-2);
}
LL dp[SIZE];
int ID;
int d[SIZE];
VPII e[SIZE];
bool u[SIZE];
bool cmp(int x,int y){
    return d[x]<d[y];
}
int n,m;
int bfs[SIZE],ty[SIZE];
void solve(){
    u[1]=1;
    dp[1]=0;
    int rr=1;
    bfs[0]=1;
    int id2=0;
    for(int i=0,j;i<rr;i=j){
        VPII gg;
        for(j=i;j<rr&&ty[j]==ty[i];j++){
            int x=bfs[j];
            REP(k,SZ(e[x])){
                int y=e[x][k].S;
                if(u[y])continue;
                gg.PB({e[x][k].F,y});
            }
        }
        sort(ALL(gg));
        REP(k,SZ(gg)){
            if(!k||gg[k].F!=gg[k-1].F)id2++;
            int y=gg[k].S;
            if(!u[y]){
                u[y]=1;
                dp[y]=(dp[bfs[i]]*10+gg[k].F)%MOD;
                ty[rr]=id2;
                bfs[rr++]=y;
            }
        }
    }
}
int main(){
    R(n,m);
    ID=n+1;
    FOR(i,1,m){
        int x,y;
        R(x,y);
        char c[10];
        sprintf(c,"%d",i);
        int len=LEN(c);
        int tmp[10];
        tmp[0]=x;
        tmp[len]=y;
        FOR(j,1,len-1)tmp[j]=ID++;
        FOR(j,1,len){
            e[tmp[j-1]].PB({c[j-1]-'0',tmp[j]});
        }
        tmp[0]=y;
        tmp[len]=x;
        FOR(j,1,len-1)tmp[j]=ID++;
        FOR(j,1,len){
            e[tmp[j-1]].PB({c[j-1]-'0',tmp[j]});
        }
    }
    FOR(i,1,ID){
        sort(ALL(e[i]));
    }
    solve();
    FOR(i,2,n)W(dp[i]);
    return 0;
}