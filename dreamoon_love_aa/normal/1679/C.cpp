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
const int MAX_BIT_NUM = 20;
/*  n  a 
 * 
 * 1.  x  v
 * 2.  x 
 * 3.  x  y 
 * 4.  a_i  i  k ()
 * 
 */
struct BIT{
    int _n;
    int bit_num;
    vector<long long> _d;
    //  n  BIT 4  2^x x  2^x > n 
    void init(int __n) {
        _n=__n;
        bit_num = __lg(_n) + 1;
        _d.resize((1 << bit_num) + 1);
        memset(_d.data() + 1, 0, sizeof(long long) * (1 << bit_num));
    }
    //  x  v
    void ins(int x, long long v) {
        for(;!(x >> bit_num); x += x & -x) { _d[x] += v; }
    }
    //  x 
    long long qq(int x) {
        if(x <= 0) {
            return 0;
        }
        long long res = 0;
        for(; x; x -= x & -x) { res += _d[x]; }
        return res;
    }
    //  x  y 
    long long qq_range(int x, int y) {
        if(x > y) {
            return 0;
        }
        long long ret = qq(y);
        if(x)ret -= qq(x-1);
        return ret;
    }
}bit[2];
int n,q;
int cnt_x[SIZE],cnt_y[SIZE];
void solve() {
    REP(i,2)bit[i].init(n);
    while(q--){
        int t,x,y;
        R(t);
        if(t==1){
            R(x,y);
            cnt_x[x]++;
            cnt_y[y]++;
            if(cnt_x[x]==1){
                bit[0].ins(x,1);
            }
            if(cnt_y[y]==1){
                bit[1].ins(y,1);
            }
        }else if(t==2){
            R(x,y);
            cnt_x[x]--;
            cnt_y[y]--;
            if(cnt_x[x]==0){
                bit[0].ins(x,-1);
            }
            if(cnt_y[y]==0){
                bit[1].ins(y,-1);
            }
        }else{
            int x1,x2,y1,y2;
            R(x1,y1,x2,y2);
            W((bit[0].qq_range(x1,x2)==x2-x1+1||bit[1].qq_range(y1,y2)==y2-y1+1)?"Yes":"No");
        }
    }
}
void input() {
    R(n, q);
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    input();
    solve();
    return 0;
}