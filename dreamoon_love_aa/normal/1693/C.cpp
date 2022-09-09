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
#include<iomanip>
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
#define CASET int ___T; cin >> ___T; for(int cs=1;cs<=___T;cs++)
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
template<class T,class U> void _R(pair<T,U> &x) {cin >> x.F >> x.S;}
void R() {}
template<class T, class... U> void R(T &head, U &... tail) {_R(head); R(tail...);}
template<class T> void _W(const T &x) {cout << x;}
void _W(const double &x) {cout << fixed << setprecision(16) << x;}
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); cout << ' '; _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) cout << ' '; }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); cout << (sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {cout << "[DEBUG] "; W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
const long long INF = 1e18; //INF should be enough large.
typedef long long MYTYPE;
struct Dijkstra{
    vector<pair<int, MYTYPE> > e[SIZE];
    MYTYPE mi[SIZE];
    int deg[SIZE];
    bool used[SIZE];
    int n;
    void init(int _n) {
        n = _n;
        for(int i = 0; i <= n; i++) { e[i].clear(); deg[i]=0;}
    }
    void add_edge(int x, int y, MYTYPE v) {
        e[x].PB(MP(y, v));
        deg[y]++;
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
                deg[y]--;
                if(mi[y] > -v + v2+deg[y]) {
                    mi[y] =  -v + v2+deg[y];
                    qq.push({v - v2-deg[y], y});
                }
            }
        }
        return -1;
    }
}dij;
int n,m;
void solve() {
    W(dij.dis(n,1));
}
void input() {
    R(n,m);
    dij.init(n);
    REP(i,m){
        int x,y;
        R(x,y);
        dij.add_edge(y,x,1);
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    input();
    solve();
    return 0;
}