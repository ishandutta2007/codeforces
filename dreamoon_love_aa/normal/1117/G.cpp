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
void _R(LL &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const LL &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
int l[SIZE],r[SIZE];
VPII from_r[SIZE];
int p[SIZE];
LL an[SIZE];
LL dp[SIZE];
int pos[SIZE];
struct BIT{
    int _n;
    LL _d[SIZE];
    void init(int __n){
        _n=__n;
        memset(_d,0,sizeof(LL)*(_n+1));
    }
    void ins(int x,LL v){
        x=_n+1-x;
        for(;x<=_n;x+=x&-x)_d[x]+=v;
    }
    LL qq(int x){
        x=_n+1-x;
        LL res=0;
        for(;x;x-=x&-x)res+=_d[x];
        return res;
    }
}bit;
int main(){
    int n,q; R(n,q);
    FOR(i,1,n)R(p[i]);
    REP(i,q)R(l[i]);
    REP(i,q){
        R(r[i]);
        an[i]+=r[i]-l[i]+1;
    }
    REP(i,q)from_r[r[i]].PB({l[i],i});
    LL now=0;
    int sn=1;
    bit.init(n);
    FOR(i,1,n){
        while(sn>1&&p[pos[sn-1]]<p[i]){
            bit.ins(pos[sn-1],dp[sn-1]-dp[sn-2]+now);
            sn--;   
        }
        now++;
        dp[sn]=dp[sn-1]-now;
        REP(j,SZ(from_r[i])){
            int ll=from_r[i][j].F;
            int id=from_r[i][j].S;
            int it=lower_bound(pos+1,pos+sn,ll)-pos;
            an[id]+=dp[sn]-dp[it-1]+now*(sn-it+1LL)+bit.qq(ll);
        }
        pos[sn++]=i;
    }

    bit.init(n);
    reverse(p+1,p+n+1);
    REP(i,q)tie(l[i],r[i])=MP(n+1-r[i],n+1-l[i]);
    FOR(i,1,n)from_r[i].clear();
    REP(i,q)from_r[r[i]].PB({l[i],i});
    now=0;
    sn=1;
    FOR(i,1,n){
        while(sn>1&&p[pos[sn-1]]<p[i]){
            bit.ins(pos[sn-1],dp[sn-1]-dp[sn-2]+now);
            sn--;
        }
        now++;
        dp[sn]=dp[sn-1]-now;
        REP(j,SZ(from_r[i])){
            int ll=from_r[i][j].F;
            int id=from_r[i][j].S;
            int it=lower_bound(pos+1,pos+sn,ll)-pos;
            an[id]+=dp[sn]-dp[it-1]+now*(sn-it+1LL)+bit.qq(ll);
        }
        pos[sn++]=i;
    }

    W(VL(an,an+q));
    return 0;
}