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
int n,q;
LL cnt[32],now[32];
LL solve(int x,LL k){
    LL base=0;
    LL max_v=0;
    LL others=0;
    FOR(i,0,x){
        base+=cnt[i];
        max_v+=cnt[i]<<i;
    }
    if(base>=k){return 0;}
    REPP(i,x+1,n){
        others+=cnt[i]<<i;
    }
    if(max_v+others<k){return -1;}
    LL h=1LL<<(x+1);
    LL need=0;
    if(k>max_v){need=(k-max_v+h-1)/h;}
    LL added=need;
    base+=need*2;
    MS0(now);
    LL tmp=need;
    REPP(i,x+1,n){
        if(tmp<=cnt[i]){
            now[i]=cnt[i]-tmp;
            tmp=0;
        }else{
            added+=(tmp-cnt[i]+1)/2;
            now[i]=(tmp-cnt[i])&1;
            tmp=(tmp-cnt[i]+1)/2;
        }
    }
    REPP(i,x+1,n){
        LL expected=(k-base)>>(i-x);
        base+=min(now[i],expected)<<(i-x);
        added+=(min(now[i],expected)<<(i-x))-min(now[i],expected);
    }
    return added+k-base;
}
void solve() {
    while(q--){
        int a,b;
        LL c;
        R(a,b,c);
        if(a==1)cnt[b]=c;
        else W(solve(b,c));
    }
}
void input() {
    R(n,q);
    REP(i,n)R(cnt[i]);
}
int main(){
    input();
    solve();
    return 0;
}