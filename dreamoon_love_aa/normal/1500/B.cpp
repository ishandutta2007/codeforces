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
// a * x + b * y = z
struct gcd_t { long long x, y, z; };
gcd_t gcd(long long a, long long b) {
    if(b == 0) { return (gcd_t){1, 0, a}; }
    gcd_t t = gcd(b, a % b);
    return (gcd_t){t.y, t.x - t.y * (a / b), t.z};
}
int n,m;
LL k;
PII AA[SIZE];
/* x = n x u + AA[i].F
 * x = m x v + AA[i].S
 * n x u - m x v = (AA[i].S - AA[i].F)
 */
void solve() {
    VL r;
    gcd_t gg = gcd(n,m); 
    LL lcm = (LL)n * m / gg.z;
    REPP(i,1,SIZE){
        if(AA[i].F&&AA[i].S){
            if(abs(AA[i].F-AA[i].S) % gg.z == 0) {
                LL tmp = (LL)n * gg.x * ((AA[i].S - AA[i].F) / gg.z) + AA[i].F;
                tmp%=lcm;
                if(tmp<=0)tmp+=lcm;
                r.PB(tmp);
            }
        }
    }
    SORT_UNIQUE(r);
    LL dif_num = lcm - SZ(r);
    LL round = (k - 1) / dif_num;
    LL target = k % dif_num;
    if(!target) target = dif_num;
    LL an = lcm * round;
    LL lt = 0;
    REP(i,SZ(r)){
        if(r[i] - lt - 1 >= target) {
            an += lt + target;
            target = 0;
            break;
        }
        target -= r[i] - lt - 1;
        lt = r[i];
    }
    if(target) {
        an += lt + target;
    }
    W(an);
}
void input() {
    R(n,m,k);
    FOR(i,1,n){
        int v;
        R(v);
        AA[v].F=i;
    }
    FOR(i,1,m){
        int v;
        R(v);
        AA[v].S=i;
    }
}
int main(){
    input();
    solve();
    return 0;
}