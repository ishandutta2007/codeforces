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
int MOD = 1e9+7;/*}}}*/
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

// 0-based
#define MAX_LV 8
const int SIZE = 1 << MAX_LV;
vector<int> e[SIZE];
int jump[MAX_LV+1][SIZE], lv[SIZE];
void __init(int x,int lt) {
    jump[0][x] = lt;
    for(int y: e[x]) {
        if(y != lt) {
            lv[y] = lv[x] + 1;
            __init(y, x);
        }
    }
}
int adv(int x,int v){
    for(int i = 0; v >> i; i++) {
        if((v >> i) & 1) { 
            x = jump[i][x];
        }
    }
    return x;
}
int lca(int x, int y) {
    if(lv[x] > lv[y]) { x = adv(x,lv[x] - lv[y]); }
    else { y = adv(y, lv[y] - lv[x]); }
    if(x == y) { return x; }
    for(int i = MAX_LV; i >= 0; i--) {
        if(jump[i][x] != jump[i][y]) {
            x = jump[i][x];
            y = jump[i][y];
        }
    }
    return jump[0][x];
}
int dis(int x, int y) {
    int z = lca(x, y);
    return lv[x] + lv[y] - lv[z] * 2;
}
void build(int root,int N) {
    __init(root, root);
    for(int i = 1; i <= MAX_LV; i++) {
        for(int x = 0; x < N; x++) {
            jump[i][x] = jump[i - 1][jump[i - 1][x]];
        }
    }
}
int n;
long long mypow(long long x,long long y, int mod = MOD) {
    x %= mod;
    long long res = 1 % mod;
    while(y){
        if(y & 1) { res = res * x % mod; }
        y >>= 1;
        x = x * x % mod;
    }
    return res;
}
LL dp[SIZE][SIZE];
bool u[SIZE][SIZE];
LL f(int v1, int v2){
    if(!v1){return 1;}
    if(!v2){return 0;}
    if(u[v1][v2])return dp[v1][v2];
    u[v1][v2]=1;
    dp[v1][v2]=(f(v1-1,v2)+f(v1,v2-1))*mypow(2,MOD-2)%MOD;
    return dp[v1][v2];
}
void solve() {
    LL an=0;
    REP(i,n){
        build(i,n);
        REP(j,n)REP(k,j){
            int z=lca(j,k);
            an+=f(lv[j]-lv[z],lv[k]-lv[z]);
            if(an>=MOD)an-=MOD;
        }
    }
    W(an*mypow(n,MOD-2)%MOD);
}
void input() {
    R(n);
    REPP(i,1,n){
        int x,y;
        R(x,y);
        x--;
        y--;
        e[x].PB(y);
        e[y].PB(x);
    }
}
int main(){
    input();
    solve();
    return 0;
}