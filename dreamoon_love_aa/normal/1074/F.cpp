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
int n;
VI e[SIZE];
// 0-based
#define MAX_LV 17
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
        FOR(x,1,N)
            jump[i][x]=jump[i-1][jump[i-1][x]];
    }
}
int ll[SIZE],rr[SIZE],id;
void dfs0(int x,int lt){
    ll[x]=rr[x]=id++;
    for(int y:e[x]){
        if(y==lt)continue;
        dfs0(y,x);
        rr[x]=rr[y];
    }
}
map<PII,int>last_occur;
PII NOW;
int HELP;
VPII edges[SIZE*4];
VI help[SIZE*4];
void ins(int L,int R,int x,int l,int r){
    if(R<l||L>r)return;
    if(L>=l&&R<=r){
        edges[x].PB(NOW);
        help[x].PB(HELP);
        return;
    }
    int mm=(L+R)/2;
    ins(L,mm,x*2,l,r);
    ins(mm+1,R,x*2+1,l,r);
}
int an[SIZE];
int calc(VPII& now){
    int ret=0;
    REP(i,SZ(now))ret+=now[i].S-now[i].F+1;
    return ret;
}
void get(VPII &me,int x,int y,int hh){
    PII xx={ll[x],rr[x]};
    PII yy={ll[y],rr[y]};
    if(ll[x]>rr[y])me={{ll[y],rr[y]},{ll[x],rr[x]}};
    else if(ll[y]>rr[x])me={{ll[x],rr[x]},{ll[y],rr[y]}};
    else {
        if(ll[x]>ll[y]){
            swap(x,y);
        }
        //ll[x]<ll[y]
        me={{0,ll[hh]-1},{ll[y],rr[y]}};
        if(rr[hh]<n-1)me.PB({rr[hh]+1,n-1});
    }
}
void merge_to(VPII& me,VPII& you){
    VPII ret;
    int it=0;
    for(auto pp:me){
        while(it<SZ(you)&&you[it].S<pp.F){
            it++;
        }
        while(it<SZ(you)&&you[it].F<=pp.S){
            ret.PB({max(you[it].F,pp.F),min(you[it].S,pp.S)});
            it++;
        }
        if(it)it--;
    }
    me=ret;
}
void dfs(int L,int R,int x,VPII now){
    if(now.empty())return;
    REP(i,SZ(edges[x])){
        VPII me;
        get(me,edges[x][i].F,edges[x][i].S,help[x][i]);
        merge_to(now,me);
    }
    if(L==R){
        an[L]=calc(now);
        return;
    }
    int mm=(L+R)/2;
    dfs(L,mm,x*2,now);
    dfs(mm+1,R,x*2+1,now);
}
int main(){
    int q; R(n,q);
    REPP(i,1,n){
        int x,y; R(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    build(1,n);
    dfs0(1,1);
    FOR(i,1,q){
        int x,y; R(x,y);
        if(x>y)swap(x,y);
        auto it=last_occur.find({x,y});
        if(it!=last_occur.end()){
            NOW={x,y};
            int z=lca(x,y);
            if(z==x)HELP=adv(y,lv[y]-lv[x]-1);
            else if(z==y)HELP=adv(x,lv[x]-lv[y]-1);
            ins(1,q,1,it->S,i-1);
            last_occur.erase(it);
        }
        else{
            last_occur[{x,y}]=i;
        }
    }
    for(auto pp:last_occur){
        NOW=pp.F;
        int x=pp.F.F,y=pp.F.S;
        int z=lca(x,y);
        if(z==x)HELP=adv(y,lv[y]-lv[x]-1);
        else if(z==y)HELP=adv(x,lv[x]-lv[y]-1);
        ins(1,q,1,pp.S,q);
    }
    dfs(1,q,1,{{0,n-1}});
    FOR(i,1,q)W(an[i]);
    return 0;
}