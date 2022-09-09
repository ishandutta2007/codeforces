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
template<class T>
T rmqfunc(T a, T b) {
    return MP(min(a.F,b.F),max(a.S,b.S));
}
template <class T,T RmqFunc(T,T)>
class RMQ{
    public:
        vector<vector<T>> values;

        template<class IterType> void build(IterType begin, IterType end) {
            assert(begin != end);
            int n = end - begin;
            int h = __lg(n);
            values.resize(h + 1);
            auto it = begin;
            values[0].assign(begin, end);
            for(int i = 1, len = 1; i <= h; i++, len <<= 1) {
                values[i].resize(n);
                for(int j = 0; j + len * 2 <= n; j++) {
                    values[i][j] = RmqFunc(values[i-1][j], values[i-1][j + len]);
                }
            }
        }
        T query(int ll,int rr) {
            int lv = __lg(rr - ll);
            return RmqFunc(values[lv][ll], values[lv][rr - (1 << lv)]);
        }
};
int u[SIZE],tt;
int pos[SIZE];
void f(RMQ<PII,rmqfunc>& rmq,int ll, int rr){
    if(ll+1>=rr){
        u[ll]=u[rr]=tt;
        return;
    }
    PII ret=rmq.query(ll,rr+1);
    int x=pos[ret.F];
    int y=pos[ret.S];
    if(x>y)swap(x,y);
    f(rmq,ll,x);
    f(rmq,y,rr);
}
void solve() {
    tt++;
    int n;
    R(n);
    VPII AA(n);
    REP(i,n){
        R(AA[i].F);
        pos[AA[i].F]=i;
        AA[i].S=AA[i].F;
    }
    RMQ<PII,rmqfunc> rmq;
    rmq.build(ALL(AA));
    f(rmq,0,n-1);
    W(count(u,u+n,tt)-1);
}
void input() {    
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    CASET {
        input();
        solve();
    }
    return 0;
}