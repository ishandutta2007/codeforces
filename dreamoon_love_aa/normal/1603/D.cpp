#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
const int SIZE = 1 << 18;
const int AA = 18;
const int MAX_N = 100000;
LL dp[AA][MAX_N+1];
LL mi[SIZE],_tmp[SIZE];
void push(int id){
    if(_tmp[id]==0)return;
    _tmp[id*2]+=_tmp[id];
    mi[id*2]+=_tmp[id];
    _tmp[id*2+1]+=_tmp[id];
    mi[id*2+1]+=_tmp[id];
    _tmp[id]=0;
}
void pull(int id){
    mi[id]=min(mi[id*2],mi[id*2+1]);
}
int NOW;
void seg_init(int L,int R,int id){
    _tmp[id]=0;
    if(L==R){
        mi[id] = dp[NOW-1][L];
        return;
    }
    int mm=(L+R)/2;
    seg_init(L,mm,id*2);
    seg_init(mm+1,R,id*2+1);
    pull(id);
}
LL qq(int L,int R,int id,int ll,int rr){
    if(R<ll||L>rr)return LLONG_MAX;
    if(L>=ll&&R<=rr)return mi[id];
    int mm=(L+R)/2;
    push(id);
    return min(qq(L,mm,id*2,ll,rr),qq(mm+1,R,id*2+1,ll,rr));
}
void ins(int L,int R,int id,int ll,int rr,LL v){
    if(R<ll||L>rr)return;
    if(L>=ll&&R<=rr){
        mi[id]+=v;
        _tmp[id]+=v;
        return;
    }
    int mm=(L+R)/2;
    push(id);
    ins(L,mm,id*2,ll,rr,v);
    ins(mm+1,R,id*2+1,ll,rr,v);
    pull(id);
}

int phi[MAX_N+1];
VI fac[SIZE];
void pre(){
    FOR(i,1,MAX_N)phi[i]=i;
    FOR(j,1,MAX_N){
        if(j!=1&&phi[j]==j){
            for(int k=j;k<=MAX_N;k+=j){
                phi[k]=phi[k]/j*(j-1);
            }
        }
        for(int k=j;k<=MAX_N;k+=j)fac[k].PB(j);
    }
    FOR(i,1,MAX_N){
        dp[1][i]=dp[1][i-1]+i;
    }
    REPP(k,2,AA){
        NOW=k;
        seg_init(k-1,MAX_N-1,1);
        FOR(i,k,MAX_N){
            for(int x:fac[i]){
                if(x>=k){
                    ins(k-1,MAX_N-1,1,k-1,x-1,phi[i/x]);
                }
            }
            dp[k][i]=qq(k-1,MAX_N-1,1,k-1,i-1);
        }
    }
}
namespace io {
    const int SIZE = 1e7 + 10;
    char inbuff[SIZE];
    char *l, *r;
    inline void init() {
        l = inbuff;
        r = inbuff + fread(inbuff, 1, SIZE, stdin);
    }
    inline char gc() {
        if (l == r) init();
        return (l != r) ? *(l++) : EOF;
    }
    void read(int &x) {
        x = 0; char ch = gc();
        while(!isdigit(ch) && ch !='-') ch = gc();
        bool neg = 0;
        if(ch == '-') { neg = 1; ch = gc(); }
        while(isdigit(ch)) x = x * 10 + ch - '0', ch = gc();
        if(neg) { x = -x; }
    }
} using io::read;
void solve() {
    int n,k;
    read(n);
    read(k);
    if(k<AA){
        W(dp[k][n]);
    }else W(n);
}
int main(){
    pre();
    int T;
    read(T);
    while(T--){
        solve();
    }
    return 0;
}