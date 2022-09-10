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
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
const LL INF = 1e18; //INF should be enough large.
typedef long long MYTYPE;
struct data{
    MYTYPE v;
    int id;
    data(MYTYPE _v,int _id):v(_v),id(_id){}
    bool operator<(const data& b)const{return v>b.v;}
};

struct Dijkstra{
    vector<pair<int,MYTYPE> >e[SIZE];
    MYTYPE mi[SIZE];
    bool used[SIZE];
    int n,tt;
    void init(int _n){
        n=_n;
        REP(i,n+1)e[i].clear();
    }
    void add_edge(int x,int y,MYTYPE v){
        e[x].PB(MP(y,v));
    }
    VL dis(int st){
        priority_queue<data>qq;
        REP(i,n+1)mi[i]=INF,used[i]=0;
        mi[st]=0;
        qq.push(data(0,st));
        while(!qq.empty()){
            data now=qq.top();qq.pop();
            if(used[now.id])continue;
            used[now.id]=1;
            REP(i,SZ(e[now.id])){
                int y=e[now.id][i].F;
                if(mi[y]>now.v+e[now.id][i].S){
                    mi[y]=now.v+e[now.id][i].S;
                    qq.push(data(mi[y],y));
                }
            }
        }
        return VL(mi,mi+n+1);
    }
}dij;
int N,M,s,t;
int ee[1001][1001];
int main(){
    R(N,M,s,t);
    dij.init(N);
    REP(i,M){
        int x,y; R(x, y);
        dij.add_edge(x,y,1);
        dij.add_edge(y,x,1);
        ee[x][y]=ee[y][x]=1;
    }
    VL v1=dij.dis(s);
    VL v2=dij.dis(t);
    int an=0;
    FOR(i,1,N)FOR(j,i+1,N){
        if(ee[i][j])continue;
        if(min(v1[i]+v2[j],v1[j]+v2[i])+1>=v1[t]){
            DEBUG("(%d,%d)=%lld:%lld",i,j,min(v1[i]+v2[j],v1[j]+v2[i])+1,v1[t]);
            an++;
        }
    }
    W(an);
    return 0;
}