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
const int SIZE = 2e5+10;
int AA[SIZE],BB[SIZE];
VI pos[SIZE];
PII dp[SIZE+1][2];
int from[SIZE+1][2]; // 0: left, 1:right
bool update(PII &x,PII y){
    if(y.F==MOD)return 0;
    if(x.F==MOD){
        x=y;
        return 1;
    }
    if(x.F>=y.F&&x.S<=y.S){
        x=y;
        return 1;
    }
    return 0;
}
int an[SIZE];
int n;
void print(int x,int id){
    while(x){
        if(SZ(pos[x-1])==0)x--;
        else{
            for(int y:pos[x-1]){
                if(y==dp[x][id].F)an[y]=0;
                else an[y]=1;
            }
            id=from[x][id];
            x--;
        }
    }
    W("YES");
    W(VI(an,an+n));
}
int main(){
    R(n);
    REP(i,SIZE+1)REP(j,2)dp[i][j]={MOD,-MOD};
    REP(i,n){
        R(AA[i]);
        pos[AA[i]].PB(i);
    }
    REP(i,SIZE){
        if(SZ(pos[i])>2){
            W("NO");
            return 0;
        }
    }
    dp[0][0]=dp[0][1]={-1,n};
    REP(i,SIZE){
        if(!SZ(pos[i])){
            REP(j,2)dp[i+1][j]=dp[i][j];
        }
        else if(SZ(pos[i])==1){
            REP(j,2){
                if(pos[i][0]>dp[i][j].F){
                    if(update(dp[i+1][0],{pos[i][0],dp[i][j].S}))from[i+1][0]=j;
                }
                if(pos[i][0]<dp[i][j].S){
                    if(update(dp[i+1][1],{dp[i][j].F,pos[i][0]}))from[i+1][1]=j;
                }
            }
        }
        else{
            REP(j,2){
                if(pos[i][0]>dp[i][j].F&&pos[i][1]<dp[i][j].S){
                    if(update(dp[i+1][0],{pos[i][0],pos[i][1]}))from[i+1][0]=j;
                }
                if(pos[i][1]>dp[i][j].F&&pos[i][0]<dp[i][j].S){
                    if(update(dp[i+1][1],{pos[i][1],pos[i][0]}))from[i+1][1]=j;
                }
            }
        }
    }
    if(dp[SIZE][0].F!=MOD)print(SIZE,0);
    else if(dp[SIZE][1].F!=MOD)print(SIZE,1);
    else W("NO");
    return 0;
}