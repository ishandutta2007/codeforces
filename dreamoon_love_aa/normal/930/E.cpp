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
template<class T, class... U> void DEBUG(const T &head, const U &... tail) { 
#ifdef HOME
    _W('#'); _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...);
#endif
}
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 5e5+10;
LL mypow(LL x,LL y){
    x%=MOD;
    LL res=1%MOD;
    while(y){
        if(y&1)res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}
int ll[2][SIZE];
int d[SIZE],dn;
VPII seg[2];
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
int get_v(int x){
    return lower_bound(d,d+dn,x)-d;
}
int get_len(int x){
    return d[x]-d[x-1];
}
struct BIT{
    int _n;
    LL _d[SIZE];
    void init(int __n){
        _n=__n;
        memset(_d,0,sizeof(LL)*(_n+1));
    }
    void ins(int x,LL v){
        x++;
        for(;x<=_n;x+=x&-x)ADD(_d[x],v);
    }
    LL qq(int x){
        x++;
        LL res=0;
        for(;x;x-=x&-x)ADD(res,_d[x]);
        return res;
    }
    LL qq_range(int x,int y){
        LL ret=qq(y);
        if(x)ADD(ret,-qq(x-1));
        return ret;
    }
}bit[2];
int main(){
    int K,N,M; R(K,N,M);
    if(N+M==0){
        W(mypow(2,K));
        return 0;
    }
    d[dn++]=0;
    REP(i,N){
        int x,y; R(x,y);
        d[dn++]=x-1;
        d[dn++]=y;
        seg[0].PB(MP(x-1,y));
    }
    REP(i,M){
        int x,y; R(x,y);
        d[dn++]=x-1;
        d[dn++]=y;
        seg[1].PB(MP(x-1,y));
    }
    sort(d,d+dn);
    dn=unique(d,d+dn)-d;
    REP(j,2){
        REP(i,SZ(seg[j])){
            maa(ll[j][get_v(seg[j][i].S)],get_v(seg[j][i].F)+1);
        }
    }
    REP(i,2)bit[i].init(dn+2);
    bit[0].ins(1,mypow(2,get_len(1))-2);
    if(ll[0][1]==0){
        bit[1].ins(0,1);
    }
    if(ll[1][1]==0){
        bit[0].ins(0,1);
    }
    int bb[2]={};
    REPP(i,2,dn){
        LL both[2]={};
        int len=get_len(i);
        REP(j,2)ADD(both[j],bit[j].qq(i-1));
        while(bb[0]<ll[1][i]){
            LL v=bit[0].qq_range(bb[0],bb[0]);
            bit[0].ins(bb[0],-v);
            bb[0]++;
        }
        if(ll[1][i]!=i)bit[0].ins(i-1,both[1]);
        while(bb[1]<ll[0][i]){
            LL v=bit[1].qq_range(bb[1],bb[1]);
            bit[1].ins(bb[1],-v);
            bb[1]++;
        }
        if(ll[0][i]!=i)bit[1].ins(i-1,both[0]);
        bit[0].ins(i,(both[0]+both[1])*(mypow(2,len)-2)%MOD);
    }
    LL ans=0;
    REP(i,2)ADD(ans,bit[i].qq(dn));
    W(ans*mypow(2,(K-d[dn-1]))%MOD);
    return 0;
}