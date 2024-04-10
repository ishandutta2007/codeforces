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
int sp_id;
VPII e[2][SIZE];
int iter[2][SIZE];
int deg[2][SIZE];
int u[SIZE], v[SIZE], w[SIZE],sw[SIZE];
bitset<SIZE>used,visited;
VPII sp[SIZE];
char an[SIZE];
void find_path(int st) {
    int now=st;
    do{
        while(used[e[0][now][iter[0][now]].S]){
            iter[0][now]++;
        }
        deg[0][now]--;
        deg[0][e[0][now][iter[0][now]].F]--;
        used[e[0][now][iter[0][now]].S]=1;
        sp[sp_id].PB(MP(e[0][now][iter[0][now]].S, now != u[e[0][now][iter[0][now]].S]));
        now=e[0][now][iter[0][now]].F;
    }while(deg[0][now]%2==1);
    u[m+sp_id]=st;
    v[m+sp_id]=now;
    e[1][st].PB(MP(now,m+sp_id));
    e[1][now].PB(MP(st,m+sp_id));
    sp_id++;
}
void fil(int x, int y, int eid){
    if(eid<m){
        if(x==u[eid])an[eid]='1';
        else an[eid]='2';
    }else{
        ;
        for(PII t: sp[eid-m]){
            an[t.F]=((u[eid]==x)^t.S)?'1':'2';
        }
    }
}
void dfs(int e_type,int x) {
    visited[x]=1;
    for(int &i = iter[e_type][x]; i < SZ(e[e_type][x]); i++) {
        if(!used[e[e_type][x][i].second]) {
            used[e[e_type][x][i].second] = 1;
            fil(x,e[e_type][x][i].first,e[e_type][x][i].second);
            dfs(e_type,e[e_type][x][i].first);
        }
    }
}
void solve() {
    sp_id=0;
    W(count(sw,sw+n,1));
    REP(i,2){
        REP(j,n)deg[i][j]=SZ(e[i][j]);
    }
    REP(i, n) {
        if(deg[0][i]&1){
            find_path(i);
        }
    }
    VI odds;
    REP(i,n){
        if(SZ(e[1][i])&1)odds.PB(i);
    }
    for(int i=0;i<SZ(odds);i+=2){
        int x=odds[i];
        int y=odds[i+1];
        e[1][x].PB(MP(y,m+sp_id));
        e[1][y].PB(MP(x,m+sp_id));
        u[m+sp_id]=x;
        v[m+sp_id]=y;
        sp_id++;
    }
    for(int k=1;k>=0;k--){
        visited.reset();
        REP(i,n){
            if(!visited[i]){
                dfs(k,i);
            }
        }
    }
    W(an);
}
void input() {
    R(n,m);
    REP(i,m){
        R(u[i], v[i], w[i]);
        u[i]--;
        v[i]--;
        sw[u[i]]^=w[i]&1;
        sw[v[i]]^=w[i]&1;
        e[w[i]&1][u[i]].PB(MP(v[i],i));
        e[w[i]&1][v[i]].PB(MP(u[i],i));
    }
}
int main(){
    input();
    solve();
    return 0;
}