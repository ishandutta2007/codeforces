/*{{{*/
#include <bits/stdc++.h>
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
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
const int AA = 100;
// 0-based
#define MAX_LV 19
VI e[SIZE];
int jump[MAX_LV+1][SIZE],lv[SIZE];
void __init(int x,int lt){
    jump[0][x]=lt;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y!=lt){
            lv[y]=lv[x]+1;
            __init(y,x);
        }
    }
}
int adv(int x,int v){
    for(int i=0;(1<<i)<=v;i++){
        if((v>>i)&1)x=jump[i][x];
    }
    return x;
}
int lca(int x,int y){
    if(lv[x]>lv[y])x=adv(x,lv[x]-lv[y]);
    else y=adv(y,lv[y]-lv[x]);
    if(x==y)return x;
    for(int i=MAX_LV;i>=0;i--)
        if(jump[i][x]!=jump[i][y]){x=jump[i][x];y=jump[i][y];}
    return jump[0][x];
}
int dis(int x,int y){
    int z=lca(x,y);
    return lv[x]+lv[y]-lv[z]*2;
}
void build(int root,int N){
    __init(root,root);
    REPP(i,1,MAX_LV+1){
        REP(x,N)
            jump[i][x]=jump[i-1][jump[i-1][x]];
    }
}
int dist[SIZE];
int bfs[SIZE],bfs_v[SIZE];
void update(VI& red){
    int rr=0;
    REP(i,SZ(red)){
        bfs_v[rr]=0;
        bfs[rr++]=red[i];
    }
    REP(i,rr){
        int x=bfs[i];
        dist[x]=min(dist[x],bfs_v[i]);
        for(int y:e[x]){
            if(bfs_v[i]+1<dist[y]){
                dist[y]=bfs_v[rr]=bfs_v[i]+1;
                bfs[rr++]=y;
            }
        }
    }
}
int main(){
    int n,m;
    R(n,m);
    REP(i,n)dist[i]=n;
    REPP(i,1,n){
        int x,y;
        R(x,y);
        x--;y--;
        e[x].PB(y);
        e[y].PB(x);
    }
    build(0,n);
    VI red{0};
    REP(i,m){
        int ty,v;
        R(ty,v);
        v--;
        if(ty==1){
            red.PB(v);
            if(SZ(red)==AA){
                update(red);
                red.clear();
            }
        }
        else{
            int an=dist[v];
            for(int x:red){
                an=min(an,dis(x,v));
            }
            W(an);
        }
    }
    return 0;
}