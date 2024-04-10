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
const long long INF = 1e18; //INF should be enough large.
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
        e[y].PB(MP(x, v));
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
const int MAX_N = 514;
int N,K,ed,tt;
int get(int x, int y){
    return x * (K + 1) + y;
}
int col[MAX_N][MAX_N];
int row[MAX_N][MAX_N];
void solve() {
    FOR(i,0,K){
        REP(j,K){
            dij.add_edge(get(i,j),get(i,j+1),row[i][j]+row[K-i][K-j-1]);
        }
    }
    FOR(j,0,K){
        REP(i,K){
            dij.add_edge(get(i,j),get(i+1,j),col[i][j]+col[K-i-1][K-j]);
        }
    }
    FOR(j,0,K){
        dij.add_edge(get(0,j),ed,0);
        dij.add_edge(get(j,0),ed,0);
        dij.add_edge(get(K,j),ed,0);
        dij.add_edge(get(j,K),ed,0);
    }
    W(N-dij.dis(get(K/2,K/2),ed));
}
void input() {
    tt++;
    R(N,K);
    FOR(i,0,K)FOR(j,0,K){
        row[i][j]=col[i][j]=0;
    }
    ed=(K+1)*(K+1)+1;
    dij.init(ed+1);
    REP(i,N){
        int x1,y1,x2,y2;
        R(x1,y1,x2,y2);
        if(x1==x2){
            if(y1>y2)swap(y1,y2);
            col[x1-1][y1]++;
        }else{
            if(x1>x2)swap(x1,x2);
            row[x1][y1-1]++;
        }
    }
}
int main(){
    CASET {
        input();
        solve();
    }
    return 0;
}