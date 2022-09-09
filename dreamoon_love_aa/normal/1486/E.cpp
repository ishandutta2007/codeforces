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
const LL INF = 1e18; //INF should be enough large.
typedef long long MYTYPE;
struct Data{
    MYTYPE v;
    int id;
    int ty;
    Data(MYTYPE _v,int _id, int _ty):v(_v),id(_id),ty(_ty){}
    bool operator<(const Data& b)const{return v>b.v;}
};
struct Dijkstra{
    vector<pair<int,MYTYPE> >e[SIZE];
    MYTYPE mi[SIZE][51];
    bool used[SIZE][51];
    int n,tt;
    void init(int _n){
        n=_n;
        REP(i,n+1)e[i].clear();
    }
    void add_edge(int x,int y,MYTYPE v){
        e[x].PB(MP(y,v));
        e[y].PB(MP(x,v));
    }
    MYTYPE dis(int st){
        priority_queue<Data>qq;
        REP(i,n+1){
            REP(j,51){
                mi[i][j]=INF;
                used[i][j]=0;
            }
        }
        mi[st][0]=0;
        qq.push(Data(0,st,0));
        while(!qq.empty()){
            Data now=qq.top();qq.pop();
            if(used[now.id][now.ty])continue;
            used[now.id][now.ty]=1;
            if(!now.ty){
                REP(i,SZ(e[now.id])){
                    int y=e[now.id][i].F;
                    int v=e[now.id][i].S;
                    if(mi[y][v]>now.v){
                        mi[y][v]=now.v;
                        qq.push(Data(mi[y][v],y,v));
                    }
                }
            }else{
                REP(i,SZ(e[now.id])){
                    int y=e[now.id][i].F;
                    int v=e[now.id][i].S;
                    LL nxt_v = now.v + (now.ty+v)*(now.ty+v);
                    if(mi[y][0]>nxt_v){
                        mi[y][0]=nxt_v;
                        qq.push(Data(nxt_v,y,0));
                    }
                }
            }
        }
        return -1;
    }
}dij;
int n,m;
void solve() {
    dij.dis(0);
    REP(i,n){
        if(dij.mi[i][0]!=INF)printf("%lld%c",dij.mi[i][0]," \n"[i==n-1]);
        else printf("%d%c",-1," \n"[i==n-1]);
    }
}
void input() {
    R(n,m);
    dij.init(n);
    REP(i,m){
        int x,y,v;
        R(x,y,v);
        x--;
        y--;
        dij.add_edge(x,y,v);
    }
}
int main(){
    input();
    solve();
    return 0;
}