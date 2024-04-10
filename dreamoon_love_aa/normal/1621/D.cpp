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

const long long INF = 1e18; //INF should be enough large.
const int SIZE = 1 << 20;
typedef long long MYTYPE;
struct Dijkstra{
    vector<pair<int, MYTYPE> > e[SIZE];
    MYTYPE mi[SIZE];
    bool used[SIZE];
    int n;
    void init(int _n) {
        n = _n;
        for(int i = 0; i <= n; i++) { e[i].clear(); }
    }
    void add_edge(int x, int y, MYTYPE v) {
        e[x].PB(MP(y, v));
    }
    MYTYPE dis(int st, int ed) {
        priority_queue<pair<long long, int>> qq;
        for(int i = 0; i <= n; i++) { mi[i] = INF; used[i] = 0; }
        mi[st] = 0;
        qq.push({0, st});
        while(qq.size()){
            auto [v, x] = qq.top();
            qq.pop();
            if(used[x]) { continue; }
            if(x == ed) { return mi[ed]; }
            used[x] = 1;
            for(auto &[y, v2]: e[x]){
                if(mi[y] > -v + v2) {
                    mi[y] = -v + v2;
                    qq.push({v - v2, y});
                }
            }
        }
        return -1;
    }
}dij;
const int N_SIZE = 1<<9;
int a[N_SIZE][N_SIZE];
int n;
int get(int x, int y){
    if(x<0)x+=2*n;
    if(x>=2*n)x-=2*n;
    if(y<0)y+=2*n;
    if(y>=2*n)y-=2*n;
    return x*(2*n)+y+1;
}
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int to(int x){
    if(x<0)return x+2*n;
    if(x>=2*n)return x-2*n;
    return x;
}
void solve() {
    LL an=0;
    REP(i,n){
        REP(j,n){
            an+=a[n+i][n+j];
            a[n+i][n+j]=0;
        }
    }
    W(an+min({a[n][0],a[2*n-1][0],a[2*n-1][n-1],a[n][n-1],a[0][n],a[0][2*n-1],a[n-1][n],a[n-1][2*n-1]}));
    return;
    int ed=4*n*n+1;
    dij.init(4*n*n+2);
    REP(i,2*n)REP(j,2*n){
        REP(k,4){
            int nx=i+dx[k];
            int ny=j+dy[k];
            dij.add_edge(get(i,j),get(nx,ny),a[to(nx)][to(ny)]);
        }
    }
    REP(i,n)REP(j,n){
        dij.add_edge(0,get(i,j),0);
        dij.add_edge(get(i+n,j+n),ed,0);
    }
    W(dij.dis(0,ed)+an);
}
void input() {
    R(n);
    REP(i,2*n)REP(j,2*n){
        R(a[i][j]);
    }
}
int main(){
    CASET {
        input();
        solve();
    }
    return 0;
}