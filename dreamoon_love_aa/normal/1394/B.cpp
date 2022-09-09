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
const int SIZE = 1<<18;
VPII e[SIZE];
bool ban2[10][10];
int ban[10][10][10];
int AA[SIZE][10];
int get_bit(int x,int v){return (x>>v)&1;}
int an;
int now[10];
void dfs(int x,int K){
    if(x>K){
        an++;
        return;
    }
    REP(i,x){
        if(ban2[x][i])continue;
        now[x]=i;
        bool err=0;
        FOR(j,1,x-1){
            if(get_bit(ban[x][i][j],now[j])){
                err=1;
                break;
            }
        }
        if(!err){
            dfs(x+1,K);
        }
    }
}
void solve() {
    int n,m,K;
    R(n,m,K);
    REP(i,m){
        int u,v,w;
        R(u,v,w);
        e[u].PB(MP(w,v));
    }
    FOR(i,1,n){
        if(SZ(e[i])==0){
            W(0);
            return;
        }
        sort(ALL(e[i]));
        REP(j,SZ(e[i])){
            if(get_bit(AA[e[i][j].S][SZ(e[i])],j)){
                ban2[SZ(e[i])][j]=1;
            }
            AA[e[i][j].S][SZ(e[i])]|=1<<j;
        }
    }
    FOR(i,1,n){
        FOR(j,2,K){
            REP(k,j){
                if(!get_bit(AA[i][j],k))continue;
                REPP(l,1,j){
                    ban[j][k][l]|=AA[i][l];
                }
            }
        }
    }
    dfs(1,K);
    W(an);
}
int main(){
#define MULTITEST 0
#if MULTITEST    
    CASET{
        solve();
    }
#else
    solve();
#endif
    return 0;
}