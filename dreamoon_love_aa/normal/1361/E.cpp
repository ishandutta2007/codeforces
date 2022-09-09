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
const int AA = 100;
VI e[SIZE];
int u[SIZE],tt,in_queue[SIZE],back[SIZE];
bool dfs0(int x){
    back[x]=0;
    u[x]=tt;
    in_queue[x]=tt;
    for(int y:e[x]){
        if(u[y]==tt){
            if(in_queue[y]!=tt)return 0;
        }
        else{
            if(!dfs0(y))return 0;
        }
    }
    in_queue[x]=0;
    return 1;
}
struct BIT2{
    LL _d[SIZE];
    int _n;
    void init(int __n){
        _n=__n;
        memset(_d,0,sizeof(LL)*(_n+1));
    }
    void ins(int x,LL v){
        for(;x;x-=x&-x)_d[x]+=v;
    }
    void ins_range(int x,int y,LL v){
        ins(y,v);
        if(x>1)ins(x-1,-v);
    }
    LL qq(int x){
        LL res=0;
        if(x<=0||x>_n)return 0;
        for(;x<=_n;x+=x&-x)res+=_d[x];
        return res;
    }
}bit,bit2;
int dep[SIZE];
void dfs_back(int x,int lv){
    u[x]=tt;
    dep[x]=lv;
    for(int y:e[x]){
        if(u[y]==tt){
            bit.ins_range(dep[y]+1,lv,y);
            bit2.ins_range(dep[y]+1,lv,1);
        }
        else{
            dfs_back(y,lv+1);
        }
    }
    int y=bit.qq(lv);
    int num=bit2.qq(lv);
    if(num>1)back[x]=-1;
    else{
        back[x]=y;
    }
    bit.ins_range(lv,lv,-y);
    bit2.ins_range(lv,lv,-num);
}
bool test_root(int x){
    tt++;
    return dfs0(x);
}
int _p[SIZE];
LL my_rand(){
    return ((LL)rand()<<16)^rand();
}
int an[SIZE],an_cnt,visited[SIZE];
void dfs(int x,int rt){
    visited[x]=tt;
    if(x==rt){
        u[x]=tt;
        an[an_cnt++]=x;
    }
    else{
        if(back[x]!=-1&&u[back[x]]==tt){
            u[x]=tt;
            an[an_cnt++]=x;
        }
    }
    for(int y:e[x]){
        if(visited[y]!=tt)dfs(y,rt);
    }
}
bool solve(){
    int n,m;
    R(n,m);
    REP(i,n)_p[i]=i+1;
    REPP(i,1,n){
        int nxt=my_rand()%(i+1);
        if(nxt!=i)swap(_p[i],_p[nxt]);
    }
    FOR(i,1,n)e[i].clear();
    REP(i,m){
        int x,y;
        R(x,y);
        e[x].PB(y);
    }
    int rt=-1;
    REP(i,min(n,AA)){
        if(test_root(_p[i])){
            rt=_p[i];
            break;
        }
    }
    if(rt==-1)return 0;
    bit.init(n);
    bit2.init(n);
    tt++;
    dfs_back(rt,1);
    DEBUG(VI(back,back+n+1));
    an_cnt=0;
    tt++;
    dfs(rt,rt);
    if(an_cnt*5>=n){
        sort(an,an+an_cnt);
        W(VI(an,an+an_cnt));
        return 1;
    }
    return 0;
}
int main(){
    srand(514);
    CASET{
        if(!solve())W(-1);
    }
    return 0;
}