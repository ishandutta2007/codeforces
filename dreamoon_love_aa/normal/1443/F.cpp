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
const int SIZE = 1<<20;
int n, k;
int p[SIZE];
int b[SIZE];
struct BIT{
    int _n;
    long long _d[SIZE];
    void init(int __n) {
        _n=__n;
        memset(_d, 0, sizeof(long long) * (_n+1));
    }
    void ins(int x, long long v) {
        for(; x <= _n; x += x & -x) { _d[x] += v; }
    }
    long long qq(int x) {
        if(x <= 0) {
            return 0;
        }
        long long res = 0;
        for(; x; x -= x & -x) { res += _d[x];}
        return res;
    }
    long long qq_range(int x, int y) {
        if(x > y) {
            return 0;
        }
        long long ret = qq(y);
        if(x)ret -= qq(x-1);
        return ret;
    }
}bit;
void solve() {
    set<int> AA {0, n + 1};
    LL an=1;
    for(int i = k; i > 0; i--) {
        auto it_r = AA.lower_bound(b[i]);
        auto it_l = prev(it_r);
        int l_num = bit.qq_range(*it_l, b[i] - 1);
        int r_num = bit.qq_range(b[i] + 1, *it_r);
        if((l_num && l_num >= b[i] - *it_l - 1)
        || (r_num && r_num >= *it_r - b[i] - 1)) {
            W(0);
            return;
        }
        AA.insert(b[i]);
        bit.ins(b[i], -1);
        int v = 0;
        if(*it_l + 1 != b[i]) {
            v++;
        }
        if(b[i] + 1 != *it_r) {
            v++;
        }
        an = an * v % MOD;
    }
    W(an);
}
void input() {
    R(n,k);
    bit.init(n+1);
    FOR(i,1,n){
        int x;
        R(x);
        p[x]=i;
    }
    FOR(i,1,k){
        int x;
        R(x);
        b[i]=p[x];
        bit.ins(b[i],1);
    }
}
int main(){
    MOD=998244353;
    CASET {
        input();
        solve();
    }
    return 0;
}