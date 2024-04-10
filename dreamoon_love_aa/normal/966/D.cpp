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
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 3e5+10;
VI ans;
void print(){
    W(SZ(ans)-1);
    W(ans);
    exit(0);
}
VI e[SIZE];
int n,m; 
int bfs[SIZE],u[SIZE],step[SIZE],lt[SIZE];
void go_bfs(){
    bfs[0]=1;
    u[1]=1;
    int rr=1;
    REP(i,rr){
        int x=bfs[i];
        for(int y:e[x]) {
            if(u[y])continue;
            u[y] = 1;
            bfs[rr++] = y;
            lt[y]=x;
            step[y]=step[x]+1;
        }
    }
    if(u[n] && step[n]<=4) {
        int now = n;
        ans.PB(now);
        while(now!=1) {
            now = lt[now];
            ans.PB(now);
        }
        reverse(ALL(ans));
        print();
    }
}
int connect_to_st[SIZE];
int tt,ker[SIZE];
void go(int x){
    if(u[x])return;
    bfs[0]=x;
    u[x]=1;
    int rr=1;
    REP(i,rr){
        x=bfs[i];
        tt++;
        for(int y:e[x]){
            if(y == 1)continue;
            ker[y]=tt;
            if(!u[y]) {
                lt[y]=x;
                bfs[rr++]=y;
                u[y]=1;
            }
        }
        REP(j,i) {
            if(ker[bfs[j]]!=tt){
                int y=bfs[j];
                int z=lt[x];
                ans={1,x,z,y,x,n};
                print();
            }
        }
    }
}
int main(){
    R(n,m);
    VI gg;
    REP(i,m) {
        int x, y;
        R(x, y);
        if(x > y) swap(x, y);
        if(MP(x,y) == MP(1,n)) {
            ans = {1,n};
            print();
        }
        if(x == 1) {
            connect_to_st[y] = 1;
            gg.PB(y);
        }
        e[x].PB(y);
        e[y].PB(x);
    }
    go_bfs();
    REPP(x,2,n) {
        for(int y:e[x]){
            if(y != 1 && y != n && connect_to_st[x] && !connect_to_st[y]) {
                ans={1,x,y,1,n};
                print();
            }
        }
    }
    FOR(i,1,n)sort(ALL(e[i]));
    MS0(u);
    for(int x: gg){
        go(x);
    }
    W(-1);
    return 0;
}