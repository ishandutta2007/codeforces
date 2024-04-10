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
int d[2][SIZE];
VPII e[SIZE];
int u[SIZE],tt;
VI gg[2];
void f(int x,int lt,int st){
    u[x]=tt;
    if(x==st){
        if(e[x][0].F==e[x][1].F){
            u[e[x][0].F]=tt;
            REP(j,2){
                if(e[x][j].S>0)gg[j].PB(e[x][j].S);
                else gg[1^j].PB(-e[x][j].S);
            }
            return;
        }
    }
    for(auto &[y,id]:e[x]){
        if(y==lt)continue;
        if(id>0){
            gg[0].PB(id);
        } else{
            gg[1].PB(-id);
        }
        if(y==st)return;
        f(y,x,st);
        return;
    }
}
void solve() {
    tt++;
    int n;
    R(n);
    REP(i,2)
        FOR(j,1,n)R(d[i][j]);
    FOR(i,1,n)e[i].clear();
    FOR(i,1,n){
        e[d[0][i]].PB(MP(d[1][i],i));
        e[d[1][i]].PB(MP(d[0][i],-i));
    }
    FOR(i,1,n){
        if(SZ(e[i])!=2){
            W(-1);
            return;
        }
    }
    VI an;
    FOR(i,1,n){
        if(u[i]!=tt){
            REP(j,2)gg[j].clear();
            f(i,i,i);
            int tar=1;
            if(SZ(gg[0])<SZ(gg[1]))tar=0;
            for(int x:gg[tar])an.PB(x);
        }
    }
    W(SZ(an));
    W(an);
}
int main(){
#define MULTITEST 1
#if MULTITEST    
    CASET{
        solve();
    }
#else
    solve();
#endif
    return 0;
}