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
int grid[SIZE][SIZE];
int dis[41][SIZE][SIZE];
VPII pos[81];
PII bfs[SIZE*SIZE];
bool u[SIZE][SIZE],col_u[81];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,m;
bool valid(int x,int y){
    return x>0&&y>0&&x<=n&&y<=m;
}
void get_dis(int id,int dd[SIZE][SIZE]){
    MS0(u);
    MS0(col_u);
    REP(i,SZ(pos[id])){
        bfs[i]=pos[id][i];
        u[bfs[i].F][bfs[i].S]=1;
        dd[bfs[i].F][bfs[i].S]=0;

    }
    col_u[id]=1;
    int rr=SZ(pos[id]);
    REP(i,rr){
        PII me=bfs[i];
        REP(j,4){
            PII nxt=MP(me.F+dx[j],me.S+dy[j]);
            if(nxt.F<=0||nxt.S<=0||nxt.F>n||nxt.S>m)continue;
            if(!u[nxt.F][nxt.S]){
                u[nxt.F][nxt.S]=1;
                bfs[rr++]=nxt;
                dd[nxt.F][nxt.S]=dd[me.F][me.S]+1;
            }
        }
        if(!col_u[grid[me.F][me.S]]){
            col_u[grid[me.F][me.S]]=1;
            for(auto x:pos[grid[me.F][me.S]]){
                if(!u[x.F][x.S]){
                    u[x.F][x.S]=1;
                    bfs[rr++]=x;
                    dd[x.F][x.S]=dd[me.F][me.S]+1;
                }
            }
        }
    }
}
int main(){
    int k;
    R(n,m,k);
    FOR(i,1,n)FOR(j,1,m){
        R(grid[i][j]);
        pos[grid[i][j]].PB(MP(i,j));
    }
    FOR(i,1,k){
        get_dis(i,dis[i]);
    }
    int q;
    R(q);
    REP(cs,q){
        int x1,y1,x2,y2;
        R(x1,y1,x2,y2);
        int an=abs(x1-x2)+abs(y1-y2);
        an=min(an,1+dis[grid[x1][y1]][x2][y2]);
        for(int i=1;i<an;i++){
            FOR(j,0,i){
                int x=x1+j;
                int y=y1+i-j;
                if(valid(x,y))
                an=min(an,i+1+dis[grid[x][y]][x2][y2]);
                x=x1+j;
                y=y1-i+j;
                if(valid(x,y))
                an=min(an,i+1+dis[grid[x][y]][x2][y2]);
                x=x1-j;
                y=y1+i-j;
                if(valid(x,y))
                an=min(an,i+1+dis[grid[x][y]][x2][y2]);
                x=x1-j;
                y=y1-i+j;
                if(valid(x,y))
                an=min(an,i+1+dis[grid[x][y]][x2][y2]);
            }
        }
        W(an);
    }
    return 0;
}