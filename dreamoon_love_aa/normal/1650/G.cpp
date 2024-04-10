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
#ifdef HOME
 #define DEBUG(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;/*}}}*/
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

const int SIZE = 1<<20;
int n,m,s,t;
LL dp[SIZE][2];
int dis[SIZE];
VI e[SIZE];
PII bfs[SIZE];
int u[SIZE][2],tt;
void solve() {
    FOR(i,1,n)REP(j,2)dp[i][j]=0;
    tt++;
    int bn=0;
    bfs[bn++]=MP(s,0);
    dp[s][0]=1;
    dis[s]=0;
    u[s][0]=tt;
    REP(i,bn){
        int x=bfs[i].F;
        int v=bfs[i].S;
        for(int y:e[x]){
            if(u[y][0]!=tt){
                u[y][0]=tt;
                ADD(dp[y][0],dp[x][0]);
                dis[y]=dis[x]+1;
                bfs[bn++]=MP(y,dis[y]);
            }else{
                if(v+1==dis[y]){
                    ADD(dp[y][0],dp[x][v-dis[x]]);
                }else if(v==dis[y]){
                    if(u[y][1]!=tt){
                        u[y][1]=tt;
                        bfs[bn++]=MP(y,dis[y]+1);
                    }
                    ADD(dp[y][1],dp[x][v-dis[x]]);
                }
            }
        }
    }
    W((dp[t][1]+dp[t][0])%MOD);
}
void input() {
    R(n,m);
    R(s,t);
    FOR(i,1,n)e[i].clear();
    REP(i,m){
        int x,y;
        R(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
}
int main(){
    CASET {
        input();
        solve();
    }
    return 0;
}