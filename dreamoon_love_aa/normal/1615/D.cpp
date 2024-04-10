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
 #define DEBUG(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;/*}}}*/
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

const int SIZE = 1<<18;

#define UnionFindSIZE 1234567
struct Union_Find {
    int d[UnionFindSIZE], num[UnionFindSIZE],dif[UnionFindSIZE];
    void init(int n){
        for(int i = 0; i < n; i++) {
            d[i] = i;
            num[i] = 1;
            dif[i] = 0;
        }
    }
    bool is_root(int x) { return d[x] == x; }
    int get_val(int x){
        int v=0;
        while(x!=d[x]){
            v^=dif[x];
            x=d[x];
        }
        return v;
    }
    bool uu(int x,int y, int v) {
        while(x!=d[x]){
            v^=dif[x];
            x=d[x];
        }
        while(y!=d[y]){
            v^=dif[y];
            y=d[y];
        }
        if(x == y) { return !v; }
        if(num[x] > num[y]) { swap(x,y); }
        num[y] += num[x];
        dif[x]=v;
        d[x] = y;
        return 1;
    }
}U;
int n,m;
VPII e[SIZE];
int val[SIZE],par[SIZE];
void dfs(int x,int lt){
    for(auto &[y,v]:e[x]){
        if(y==lt)continue;
        val[y]=v;
        par[y]=x;
        if(v!=-1)U.uu(x,y,__builtin_popcount(v)%2);
        dfs(y,x);
    }
}
int a[SIZE],b[SIZE],p[SIZE];
void solve() {
    U.init(n+1);
    dfs(1,1);
    REP(i,m){
        if(!U.uu(a[i],b[i],__builtin_popcount(p[i])%2)){
            W("NO");
            return;
        }
    }
    W("YES");
    FOR(i,2,n){
        if(val[i]!=-1)W(i,par[i],val[i]);
        else{
            int v=U.get_val(i)^U.get_val(par[i]);
            W(i,par[i],v);
        }
    }
}
void input() {
    R(n,m);
    FOR(i,1,n)e[i].clear();
    REPP(i,1,n){
        int x,y,v;
        R(x,y,v);
        e[x].PB({y,v});
        e[y].PB({x,v});
    }
    REP(i,m){
        R(a[i],b[i],p[i]);
    }
}
int main(){
    CASET {
        input();
        solve();
    }
    return 0;
}