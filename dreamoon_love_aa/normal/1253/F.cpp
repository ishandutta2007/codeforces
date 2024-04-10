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
const LL INF = 1e18;
typedef long long MYTYPE;
int en;
struct EDGE{
    int x,y;
    LL v;
    EDGE(int x=0,int y=0,LL v=0):x(x),y(y),v(v){}
    bool operator<(const EDGE& b)const{return v<b.v;}
}ee[SIZE];
struct Data{
    MYTYPE v;
    int id;
    int _from;
    Data(MYTYPE _v,int _id,int _from):v(_v),id(_id),_from(_from){}
    bool operator<(const Data& b)const{return v>b.v;}
};
struct Dijkstra{
    vector<pair<int,MYTYPE> >e[SIZE];
    MYTYPE mi[SIZE];
    int from[SIZE];
    bool used[SIZE];
    int n,tt;
    void init(int _n){
        n=_n;
        REP(i,n+1)e[i].clear();
    }
    void add_edge(int x,int y,MYTYPE v){
        e[x].PB(MP(y,v));
    }
    MYTYPE solve(int k){
        priority_queue<Data>qq;
        REP(i,n)mi[i]=INF,used[i]=0;
        REP(i,k){
            mi[i]=0;
            qq.push(Data(0,i,i));
        }
        while(!qq.empty()){
            Data now=qq.top();qq.pop();
            if(used[now.id])continue;
            used[now.id]=1;
            from[now.id]=now._from;
            REP(i,SZ(e[now.id])){
                int y=e[now.id][i].F;
                LL ev=e[now.id][i].S;
                if(used[y]&&from[y]!=now._from){
                    ee[en++]=EDGE(now._from,from[y],now.v+ev+mi[y]);
                }
                if(mi[y]>now.v+ev){
                    mi[y]=now.v+ev;
                    qq.push(Data(mi[y],y,now._from));
                }
            }
        }
        return -1;
    }
}dij;
int nxt[SIZE],pre[SIZE];
VPII qq[SIZE];
LL an[SIZE];
struct Union_Find{
    int d[SIZE],num[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1;
    }
    int find(int x){return (x!=d[x])?(d[x]=find(d[x])):x;}
    bool is_root(int x){return d[x]==x;}
    void merge(int x1,int y1){
        int x2=nxt[x1];
        int y2=nxt[y1];
        swap(nxt[x1],nxt[y1]);
        swap(pre[x2],pre[y2]);
    }
    bool uu(int x,int y, LL v){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        if(num[x]>num[y])swap(x,y);
        num[y]+=num[x];
        d[x]=y;
        int now=x;
        do{
            int it=0;
            for(auto pp:qq[now]){
                if(an[pp.S]){
                    continue;
                }
                if(find(pp.F)==y){
                    an[pp.S]=v;
                }
                else qq[now][it++]=pp;
            }
            qq[now].resize(it);
            now=nxt[now];

        }while(now!=x);
        merge(x,y);
        return 1;
    }
}U;
int main(){
    int n,m,k,q;
    R(n,m,k,q);
    dij.init(n);
    REP(i,m){
        int x,y,v;
        R(x,y,v);
        x--;y--;
        dij.add_edge(x,y,v);
        dij.add_edge(y,x,v);
    }
    REP(i,n)nxt[i]=pre[i]=i;
    REP(i,q){
        int a,b;
        R(a,b);
        a--;b--;
        qq[a].PB({b,i});
        qq[b].PB({a,i});
    }
    dij.solve(k);
    sort(ee,ee+en);
    U.init(n);
    REP(i,en){
        U.uu(ee[i].x,ee[i].y,ee[i].v);
    }
    REP(i,q)W(an[i]);
    return 0;
}