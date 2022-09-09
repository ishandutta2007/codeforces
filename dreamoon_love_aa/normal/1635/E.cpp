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

const int SIZE = 1<<20;
int n,m;
int ty[SIZE],x[SIZE],y[SIZE];
int dir[SIZE];
int pos[SIZE];
int NOW;
VPII e[SIZE];
VI e2[SIZE];
VI nodes;
void dfs(int x, int v) {
    dir[x]=v;
    nodes.PB(x);
    for(auto &[y, e_type]: e[x]) {
        if(dir[y]==dir[x]){
            W("NO");
            exit(0);
        }
        if(dir[x]==1&&e_type==2||dir[x]==-1&&e_type==1)e2[x].PB(y);
        else e2[y].PB(x);
        if(!dir[y]){
            dfs(y,-v);
        }
    }
}
bitset<SIZE>in,u;
void dfs2(int x){
    in[x]=1;
    u[x]=1;
    for(int y:e2[x]) {
        if(in[y]){
            W("NO");
            exit(0);
        }
        if(!u[y]){
            dfs2(y);
        }
    }
    in[x]=0;
    pos[x]=NOW--;
}
void solve() {
    FOR(i,1,n){
        if(!dir[i]){
            nodes.clear();
            dfs(i,1);
            for(int x:nodes){
                if(!u[x])dfs2(x);
            }
        }
    }
    W("YES");
    FOR(i,1,n){
        W(dir[i]==1?'R':'L',pos[i]);
    }
}
void input() {
    R(n,m);
    REP(i,m){
        R(ty[i],x[i],y[i]);
        e[x[i]].PB(MP(y[i],ty[i]));
        e[y[i]].PB(MP(x[i],ty[i]));
    }
}
int main(){
    input();
    solve();
    return 0;
}