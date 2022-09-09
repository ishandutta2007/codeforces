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
int MOD = 1e9+7;/*}}}*/
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

const int SIZE = 1<<21;
pair<int, int> mi[SIZE];
int _tmp[SIZE];
void push(int id){
    if(_tmp[id] == 0) { return; }
    _tmp[id*2] += _tmp[id];
    mi[id*2].first += _tmp[id];
    _tmp[id*2+1] += _tmp[id];
    mi[id*2+1].first += _tmp[id];
    _tmp[id]=0;
}
void pull(int id) {
    if(mi[id * 2].first != mi[id * 2 + 1].first) {
        if(mi[id * 2].first < mi[id * 2 + 1].first) {
            mi[id] = mi[id * 2];
        } else {
            mi[id] = mi[id * 2 + 1];
        }
    } else {
        mi[id] = {mi[id * 2].first, mi[id * 2].second + mi[id * 2 + 1].second};
    }
}
void init(int L, int R, int id) {
    if(L == R) {
        mi[id] = {0, 1};
        return;
    }
    int mm = (L + R) >> 1;
    init(L, mm, id * 2);
    init(mm + 1, R, id * 2 + 1);
    pull(id);
}
void ins(int L, int R, int id, int ll, int rr, long long v) {
    if(R < ll || L > rr) { return; }
    if(L >= ll && R <= rr) {
        mi[id].first += v;
        _tmp[id] += v;
        return;
    }
    int mm = (L + R) / 2;
    push(id);
    ins(L, mm, id * 2, ll, rr, v);
    ins(mm + 1, R, id * 2 + 1, ll, rr, v);
    pull(id);
}
int n,m;
vector<VI>segs;
void solve() {
    sort(ALL(segs));
    init(1,n-1,1);
    int rr=0;
    int an=MOD;
    REP(i,m){
        while(rr<m&&!mi[1].F){
            ins(1,n-1,1,segs[rr][1],segs[rr][2]-1,1);
            rr++;
        }
        if(mi[1].F){
            an=min(an,segs[rr-1][0]-segs[i][0]);
        }
        ins(1,n-1,1,segs[i][1],segs[i][2]-1,-1);
    }
    W(an);
}
void input() {
    R(m,n);
    REP(i,m){
        VI d(3);
        REP(j,3)R(d[j]);
        segs.push_back({d[2],d[0],d[1]});
    }
}
int main(){
    input();
    solve();
    return 0;
}