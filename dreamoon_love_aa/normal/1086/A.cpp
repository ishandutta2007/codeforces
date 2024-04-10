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
const int SIZE = 1010;
int d[SIZE][SIZE][3];
int v[SIZE][SIZE][3];
int from[SIZE][SIZE][3];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
PII AA[3];
bool out(int x,int y){return x<0||y<0||x>1000||y>1000;}
PII bfs[SIZE*SIZE];
bool u[SIZE][SIZE];
void go(int id){
    MS0(u);
    bfs[0]=AA[id];
    u[bfs[0].F][bfs[0].S]=1;
    int rr=1;
    REP(i,rr){
        auto x=bfs[i];
        REP(j,4){
            PII nxt={x.F+dx[j],x.S+dy[j]};
            if(out(nxt.F,nxt.S))continue;
            if(u[nxt.F][nxt.S])continue;
            u[nxt.F][nxt.S]=1;
            bfs[rr++]=nxt;
            v[nxt.F][nxt.S][id]=v[x.F][x.S][id]+1;
            from[nxt.F][nxt.S][id]=j;
        }
    }
}
void print(PII x,int id){
    if(v[x.F][x.S][id]==0)return;
    int it=from[x.F][x.S][id];
    x.F-=dx[it];
    x.S-=dy[it];
    W(x);
    print(x,id);

}
int main(){
    REP(i,3){
        R(AA[i].F,AA[i].S);
    }
    REP(i,3){
        go(i);
    }
    int mi=2000000;
    PII O;
    FOR(i,0,1000)FOR(j,0,1000){
        int need=v[i][j][0]+v[i][j][1]+v[i][j][2]+1;
        if(need<mi){
            mi=need;
            O={i,j};
        }
    }
    W(mi);
    W(O);
    REP(i,3)print(O,i);
    return 0;
}