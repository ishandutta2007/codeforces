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
const LL INF = 1e18; //INF should be enough large.
typedef long long MYTYPE;
struct Data{
    MYTYPE v;
    int id;
    Data(MYTYPE _v,int _id):v(_v),id(_id){}
    bool operator<(const Data& b)const{return v>b.v;}
};
struct Dijkstra{
    vector<pair<int,MYTYPE> >e[SIZE];
    vector<int>eid[SIZE];
    MYTYPE mi[SIZE];
    int from[SIZE],from_id[SIZE];
    bool used[SIZE];
    int n,tt;
    void init(int _n){
        n=_n;
        REP(i,n+1)e[i].clear();
    }
    void add_edge(int x,int y,MYTYPE v,int id=0){
        e[x].PB(MP(y,v));
        eid[x].PB(id);
    }
    MYTYPE dis(int st,int ed){
        priority_queue<Data>qq;
        REP(i,n+1)mi[i]=INF,used[i]=0;
        mi[st]=0;
        qq.push(Data(0,st));
        while(!qq.empty()){
            Data now=qq.top();qq.pop();
            if(used[now.id])continue;
            if(now.id==ed)break;
            used[now.id]=1;
            REP(i,SZ(e[now.id])){
                int y=e[now.id][i].F;
                if(mi[y]>now.v+e[now.id][i].S){
                    from[y]=now.id;
                    from_id[y]=eid[now.id][i];
                    mi[y]=now.v+e[now.id][i].S;
                    qq.push(Data(mi[y],y));
                }
            }
        }
        W(mi[ed]);
        int now=ed;
        VI res;
        while(now!=st){
            if(from_id[now])res.PB(from_id[now]);
            now=from[now];
        }
        reverse(ALL(res));
        W(SZ(res));
        W(res);
        return -1;
    }
}dij;
int in[SIZE][3];
int main(){
    int n,L;
    R(n,L);
    VI pos{0,L};
    FOR(i,1,n){
        int x,d,t,p;
        R(x,d,t,p);
        if(x-p>=0){
            in[i][0]=x-p;
            in[i][1]=x+d;
            in[i][2]=t+p;
            pos.PB(in[i][0]);
            pos.PB(in[i][1]);
        }
        else in[i][0]=-1;
    }
    SORT_UNIQUE(pos);
    dij.init(SZ(pos));
    FOR(i,1,n){
        if(in[i][0]!=-1){
            dij.add_edge(GET_POS(pos,in[i][0]),GET_POS(pos,in[i][1]),in[i][2],i);
        }
    }
    REPP(i,1,SZ(pos)){
        dij.add_edge(i-1,i,pos[i]-pos[i-1]);
        dij.add_edge(i,i-1,pos[i]-pos[i-1]);
    }
    dij.dis(0,SZ(pos)-1);
    return 0;
}