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
int a[SIZE],b[SIZE],c[SIZE],d[SIZE];
VPII e[SIZE];
int n;
map<PLL,int> AA;
int gid;
bitset<SIZE>u,in;
VPII an;
void add(int &x,int y){
    if(x==-1){
        x=y;
    }else{
        if(y!=-1){
            an.PB(x,y);
            x=-1;
        }
    }
}
int dfs(int x,int lt){
    u[x]=1;
    in[x]=1;
    int tmp=-1;
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(u[y]){
            if(e[x][i].S==lt||!in[y]){continue;}
            add(tmp,e[x][i].S);
        }else{
            int ret=dfs(y,e[x][i].S);
            add(tmp,ret);
        }
    }
    add(tmp,lt);
    in[x]=0;
    return tmp;
}
void solve() {
    REP(i,n){
        LL aa=(LL)(a[i]+b[i])*d[i];
        LL bb=(LL)b[i]*c[i];
        LL gg=__gcd(aa,bb);
        aa/=gg;
        bb/=gg;
        auto &x=AA[{aa,bb}];
        if(!x){
            x=++gid;
        }
        aa=(LL)a[i]*d[i];
        bb=(LL)b[i]*(c[i]+d[i]);
        gg=__gcd(aa,bb);
        aa/=gg;
        bb/=gg;
        auto &y=AA[{aa,bb}];
        if(!y){
            y=++gid;
        }
        e[x].PB(MP(y,i+1));
        e[y].PB(MP(x,i+1));
    }
    FOR(i,1,gid){
        if(!u[i]){
            dfs(i,-1);
        }
    }
    W(SZ(an));
    REP(i,SZ(an))W(an[i]);
}
void input() {
    R(n);
    REP(i,n)R(a[i],b[i],c[i],d[i]);
}
int main(){
    input();
    solve();
    return 0;
}