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
const int SIZE = 1<<20;
LL ma_l[SIZE],ma_r[SIZE],ma[SIZE],sum[SIZE];
int d[SIZE],c[SIZE];
void build(int L,int R,int id){
    int mm=(L+R)/2;
    if(L==R){
        sum[id]=c[L];
        ma_l[id]=ma_r[id]=ma[id]=max(c[L],0);
        return;
    }
    build(L,mm,id*2);
    build(mm+1,R,id*2+1);
    ma[id]=max({ma[id*2],ma[id*2+1],ma_r[id*2]+ma_l[id*2+1]});
    ma_l[id]=max(sum[id*2]+ma_l[id*2+1],ma_l[id*2]);
    ma_r[id]=max(ma_r[2*id]+sum[id*2+1],ma_r[2*id+1]);
    sum[id]=sum[id*2]+sum[id*2+1];
}
LL qq(int L,int R,int ll,int rr,int id,LL &ma_ll_,LL &ma_rr_,LL &sum_){
    if(L>=ll&&R<=rr){
        ma_ll_=ma_l[id];
        ma_rr_=ma_r[id];
        sum_=sum[id];
        return ma[id];
    }
    int mm=(L+R)/2;
    if(mm>=rr)return qq(L,mm,ll,rr,id*2,ma_ll_,ma_rr_,sum_);
    if(mm<ll) return qq(mm+1,R,ll,rr,id*2+1,ma_ll_,ma_rr_,sum_);
    LL tmp[2][3];
    LL res=max(qq(L,mm,ll,rr,id*2,tmp[0][0],tmp[0][1],tmp[0][2]),qq(mm+1,R,ll,rr,id*2+1,tmp[1][0],tmp[1][1],tmp[1][2]));
    ma_ll_=max(tmp[0][0],tmp[0][2]+tmp[1][0]);
    ma_rr_=max(tmp[1][1],tmp[0][1]+tmp[1][2]);
    sum_=tmp[1][2]+tmp[0][2];
    return max(res,tmp[0][1]+tmp[1][0]);
}
int main(){
    int n;
    LL add;
    LL an=0;
    R(n,add);
    FOR(i,1,n){
        R(d[i],c[i]);
        c[i]=add-c[i];
        an=max(an,(LL)c[i]);
    }
    build(1,n,1);
    VPII AA;
    REPP(i,1,n){
        AA.PB(MP(abs(d[i]-d[i+1]),i));
    }
    sort(ALL(AA),greater<PLL>());
    set<int>H{0,n};
    REP(i,SZ(AA)){
        auto it=H.lower_bound(AA[i].S);
        int ll=*prev(it)+1;
        int rr=*it;
        LL ma_ll_,ma_rr_,sum_;
        an=max(an,qq(1,n,ll,rr,1,ma_ll_,ma_rr_,sum_)-(LL)AA[i].F*AA[i].F);
        H.insert(AA[i].S);
    }
    W(an);
    return 0;
}