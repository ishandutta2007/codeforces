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
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
const int MM = 9;
int dp[1<<MM][1<<(20-MM)];
int from[1<<MM][1<<(20-MM)];
const int MASK=(1<<(20-MM))-1;
char s[24];
int p[SIZE],q[SIZE],d[20];
int get_bit(int x,int v){return (x>>v)&1;}
bitset<SIZE>u;
bool maa(int &x,int v){
    if(x<v){
        x=v;
        return 1;
    }
    return 0;
}
void add(int x,int id){
    if(u[x])return;
    u[x]=1;
    int bb=1<<(20-MM);
    int *res=dp[x>>(20-MM)];
    int *target=from[x>>(20-MM)];
    int me=x&MASK;
    REP(i,bb){
        if(maa(res[i],__builtin_popcount(me^i))){
            target[i]=id;
        }
    }
}
PII qq(int x){
    int res=0;
    int pos=-1;
    int me=x&MASK;
    int head=x>>(20-MM);
    REP(i,1<<MM){
        int v=dp[i][me];
        if(v!=-1&&maa(res,v+__builtin_popcount(head^i))){
            pos=from[i][me];
        }
    }
    return MP(res,pos);
}
void solve() {
    MS1(dp);
    int m,n,k;
    R(n,m,k);
    RS(s);
    int st=0;
    int ed=0;
    REP(i,k){
        if(s[i]=='0')st|=1<<i;
    }
    RS(s);
    REP(i,k){
        if(s[i]=='1')ed|=1<<i;
    }
    REP(i,k)d[i]=i;
    p[0]=st;
    q[0]=ed;
    FOR(i,1,n){
        int x,y;
        R(x,y);
        x--;
        y--;
        swap(d[x],d[y]);
        REP(j,k){
            p[i]|=get_bit(st,j)<<d[j];
            q[i]|=get_bit(ed,j)<<d[j];
        }
    }
    int an=-1;
    PII pos;
    FOR(i,m,n){
        add(p[i-m],i-m+1);
        auto res=qq(q[i]);
        if(res.F>an){
            an=res.F;
            pos=MP(res.S,i);
        }
    }
    W(an);
    W(pos);
}
int main(){
#define MULTITEST 0
#if MULTITEST    
    CASET{
        solve();
    }
#else
    solve();
#endif
    return 0;
}