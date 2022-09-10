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
#define INF 1034567890
const int MAX_EDGE_NUM = 1000000;
const int MAX_NODE_NUM = 100000;
struct EDGE{
        int y,c,v,ty;
        EDGE(int _y=0,int _c=0,int _v=0,int ty=0):y(_y),c(_c),v(_v),ty(ty){}
}es[MAX_EDGE_NUM];
vector<int>e[MAX_NODE_NUM];
int C,d;
int en;
int EE; // sink
void flow_clear(int _EE){
    EE=_EE;
    REP(i,EE+1)e[i].clear();
    en=0;
}
void add_edge(int x,int y,int c,int v,int _ty){
        e[x].PB(en);
        es[en++]=EDGE(y,c,v,_ty);
        e[y].PB(en);
        if(_ty==1){
            es[en++]=EDGE(x,0,-C+d,_ty);
        }
        else{
            es[en++]=EDGE(x,0,-v,_ty);
        }
        
}
int mi[MAX_NODE_NUM],lt[MAX_NODE_NUM],bfs[10000000],used[MAX_NODE_NUM];
int flow(){
        REP(i,EE+1)mi[i]=INF,used[i]=0;
        mi[EE]=INF;
        bfs[0]=0;
        mi[0]=0;
        int rr=1;
        for(int i=0;i<rr;i++){
                int x=bfs[i];
                used[x]=0;
                REP(j,SZ(e[x])){
                        int r=e[x][j];
                        if(es[r].c>0&&mi[x]+es[r].v<mi[es[r].y]){
                                mi[es[r].y]=mi[x]+es[r].v;
                                lt[es[r].y]=r;
                                if(!used[es[r].y]){
                                        used[es[r].y]=1;
                                        bfs[rr++]=es[r].y;
                                }
                        }
                }
        }
        if(mi[EE]==INF)return -1;
        int now=EE;
        while(now){
                int r=lt[now];
                if(es[r].ty==1){
                    if((r&1)==1){
                        es[r].v+=2*d;
                        es[r^1].v-=2*d;
                    }
                    else{
                        es[r].v+=2*d;
                        es[r^1].v-=2*d;
                    }
                }
                es[r].c--;
                es[r^1].c++;
                now=es[r^1].y;
        }
        return mi[EE];
}
int solve(int nn){
        int v=0;
        REP(i,nn)v+=flow();
        return v;
}
int main(){
    int n,m,k;
    R(n,m,k,C,d);
    flow_clear(n*100+1);
    FOR(i,1,k){
        int x;
        R(x);
        add_edge(0,x,1,0,0);
    }
    FOR(i,1,99){
        add_edge(1+i*n,100*n+1,INF,0,0);
    }
    FOR(i,1,n){
        FOR(j,1,99){
            add_edge(i+(j-1)*n,i+j*n,INF,C,0);
        }
    }
    FOR(i,1,m){
        int x,y; R(x,y);
        FOR(j,1,99){
            add_edge(x+(j-1)*n,y+j*n,INF,C+d,1);
            add_edge(y+(j-1)*n,x+j*n,INF,C+d,1);
        }
    }
    W(solve(k));
    return 0;
}