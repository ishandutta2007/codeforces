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
char s[SIZE];
int d[SIZE];
const int MAX_BIT_NUM = 20;
struct BIT{
    int _n;
    int bit_num;
    long long _d[1 << MAX_BIT_NUM];
    void init(int __n) {
        _n=__n;
        bit_num = 0;
        while(_n >> bit_num) { bit_num++; }
        memset(_d, 0, sizeof(long long) << bit_num);
    }
    void ins(int x, long long v) {
        for(;!(x >> bit_num); x += x & -x) { _d[x] += v; }
    }
    long long qq(int x) {
        if(x <= 0) {
            return 0;
        }
        long long res = 0;
        for(; x; x -= x & -x) { res += _d[x]; }
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
}bit;
char answer[4];
void solve() {
    int n=LEN(s);
    int cnt[128]={};
    REP(i,n){cnt[s[i]]++;}
    char p[]="ANOT";
    sort(p,p+4);
    int now[128];
    LL ma=-1;
    do{
        int v=0;
        REP(i,4){
            now[p[i]]=v;
            v+=cnt[p[i]];
        }
        REP(i,n){
            d[i]=++now[s[i]];
        }
        //DEBUG(string(p,p+4),VI(d,d+n));
        bit.init(n);
        LL res=0;
        for(int i=n-1;i>=0;i--){
            res+=bit.qq(d[i]-1);
            bit.ins(d[i],1);
        }
        if(res>ma){
            ma=res;
            REP(i,4)answer[i]=p[i];
        }
    }while(next_permutation(p,p+4));
    REP(i,4){
        REP(j,cnt[answer[i]])putchar(answer[i]);
    }
    W("");
}
void input() {
    RS(s);
}
int main(){
    CASET {
        input();
        solve();
    }
    return 0;
}
//DDAAAADD
//AADDDDAA