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
bool ban[SIZE];
VPII e[SIZE];
int fib[60];
void pre(){
    fib[0]=fib[1]=1;
    REPP(i,2,60){
        fib[i]=fib[i-1]+fib[i-2];
    }
}
int n;
int son[SIZE];
int now_fib_id;
PII cut[2];
int cut_id[2];
int cn;
#include<time.h>
const double TIME_LIMIT = 0.95;
clock_t time_start;
void time_cut_start(){time_start = clock();}
bool check_time_cut(){return 1. * (clock()-time_start) / CLOCKS_PER_SEC < TIME_LIMIT;}
int tt;
void dfs_build(int x, int lt){
    tt++;
    if(tt&4095) {
        if(!check_time_cut()) {
            W("NO");
            exit(0);
        }
    }
    son[x]=1;
    REP(i,SZ(e[x])){
        if(e[x][i].S==lt || ban[e[x][i].S]) { continue; }
        dfs_build(e[x][i].F, e[x][i].S);
        int v;
        son[x]+=v=son[e[x][i].F];
        if(v == fib[now_fib_id - 1]) {
            cut_id[cn] = e[x][i].S;
            cut[cn++] = MP(x, e[x][i].F);
        } else if(v == fib[now_fib_id - 2]){
            cut_id[cn] = e[x][i].S;
            cut[cn++] = MP(e[x][i].F, x);
        }
    }
}
bool go(int fib_id, int rt) {
    if(fib_id <= 3) {
        return true;
    }
    now_fib_id = fib_id;
    cn=0;
    dfs_build(rt, -1);
    PII x{-1, -1};
    PII y{-1, -1};
    int x_id, y_id;
    if(cn >= 1) {
        x = cut[0];
        x_id = cut_id[0];
    }
    if(cn >= 2) {
        y = cut[1];
        y_id = cut_id[1];
    }
    if(x.F != -1) {
        ban[x_id] = 1;
        if(go(fib_id - 1, x.S) && go(fib_id - 2, x.F)) {
            ban[x_id] = 0;
            return 1;
        }
        ban[x_id] = 0;
    }
    if(y.F != -1) {
        ban[y_id] = 1;
        if(go(fib_id - 1, y.S) && go(fib_id - 2, y.F)) {
            ban[y_id] = 0;
            return 1;
        }
        ban[y_id] = 0;
    }
    return 0;
}
void solve() {
    if(n<=3){
        W("YES");
        return;
    }
    int id=0;
    while(fib[id]<n)id++;
    if(fib[id]!=n){
        W("NO");
        return;
    }
    W(go(id,1)?"YES":"NO");
}
void input() {
    R(n);
    REPP(i,1,n){
        int u, v;
        R(u,v);
        e[u].PB(MP(v,i));
        e[v].PB(MP(u,i));
    }
}
int main(){
    time_cut_start();
    pre();
    input();
    solve();
    return 0;
}