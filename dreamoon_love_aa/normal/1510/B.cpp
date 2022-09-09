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
const int SIZE = 1<<10;
#define INF 1034567890
const int MAX_EDGE_NUM = 1000000;
const int MAX_NODE_NUM = 100000;
struct EDGE{
        int y,c,v;
        EDGE(int _y=0,int _c=0,int _v=0):y(_y),c(_c),v(_v){}
}es[MAX_EDGE_NUM];
vector<int>e[MAX_NODE_NUM];
int en;
int EE; // sink
void flow_clear(int _EE){
    EE=_EE;
    REP(i,EE+1)e[i].clear();
    en=0;
}
void add_edge(int x,int y,int c,int v){
        e[x].PB(en);
        es[en++]=EDGE(y,c,v);
        e[y].PB(en);
        es[en++]=EDGE(x,0,-v);
        
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
                es[r].c--;
                es[r^1].c++;
                now=es[r^1].y;
        }
        return mi[EE];
}
int to[SIZE];
bitset<10>s[SIZE];
void add(vector<char>&an, bitset<10>v){
    REP(i,10){
        if(v[i]){
            an.PB('0'+i);
        }
    }
}
void solve(int nn){
    int v=0;
    REP(i,nn)v+=flow();
    VI st;
    for(int i=0;i<en;i+=2){
        if(es[i].y>nn&&es[i^1].y<=nn&&!es[i].c){
            if(!es[i^1].y){
                st.PB(es[i].y-nn);
            }else{
                to[es[i^1].y]=es[i].y-nn;
            }
        }
    }
    vector<char>an;
    for(int x:st){
        if(SZ(an)){
            an.PB('R');
        }
        add(an,s[x]);
        int now=x;
        while(to[now]){
            add(an,s[now]^s[to[now]]);
            now=to[now];
        }
    }
    W(SZ(an));
    W(an);
}
int n;
void solve() {
    flow_clear(2*n+1);
    FOR(i,1,n){
        add_edge(0,n+i,1,s[i].count()+1);
        add_edge(0,i,1,0);
        add_edge(n+i,2*n+1,1,0);
        FOR(j,1,n){
            if(i==j){continue;}
            if((s[i]&s[j])==s[j]){
                add_edge(j,i+n,1,s[i].count()-s[j].count());
            }
        }
    }
    solve(n);
}
void input() {
    int d;
    R(d,n);
    FOR(i,1,n){
        string _s;
        R(_s);
        REP(j,d){
            if(_s[j]=='1')s[i][j]=1;
        }
    }
}
int main(){
    input();
    solve();
    return 0;
}