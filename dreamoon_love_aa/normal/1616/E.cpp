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
    //  n  BIT
    BIT(int __n) {
        init(__n);
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
    //  k 
    long long k_th(int k){
        int now = 0;
        for(int i = bit_num - 1; i >= 0; i--) {
            if(_d[now + (1 << i)] < k) {
                k -= _d[now + (1 << i)];
                now += 1 << i;
            }
        }
        return now + 1;
    }
};
int n;
string s,t;
int dp[SIZE][26];
VI pos[26];
void solve() {
    string tmp=s;
    sort(ALL(tmp));
    if(t<=tmp){
        W(-1);
        return;
    }
    REP(i,26)pos[i].clear();
    REP(i,n){
        pos[s[i]-'a'].PB(i);
    }
    VI it(26);
    BIT bit(n);
    LL an=1e18;
    LL now=0;
    REP(i,n){
        int mi=n;
        REP(j,t[i]-'a'){
            if(it[j]<SZ(pos[j])){
                mi=min(mi,pos[j][it[j]]);
            }
        }
        if(mi!=n){
            an=min(an,now+mi-bit.qq(mi));
        }
        if(it[t[i]-'a']<SZ(pos[t[i]-'a'])){
            int p=pos[t[i]-'a'][it[t[i]-'a']];
            it[t[i]-'a']++;
            now+=p-bit.qq(p);
            bit.ins(p+1,1);
        }
        else break;
    }
    W(an);
}
void input() {
    R(n);
    R(s,t);
}
int main(){
    CASET {
        input();
        solve();
    }
    return 0;
}