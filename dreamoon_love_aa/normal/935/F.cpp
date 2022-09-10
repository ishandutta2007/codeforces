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
const int SIZE = 1e6+10;
const LL INF = 1e15;
LL a[SIZE];
int n;
LL mi[SIZE],_tmp[SIZE];
LL cal(LL b[]){
    if(b[0]<=b[1]&&b[1]>=b[2])return INF;
    if(b[0]>b[1]&&b[2]>b[1])return INF;
    return max(b[0],b[2])-b[1];
}
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
void seg_init(int L,int R,int id){
    if(L==R){
        mi[id]=cal(a+L-1);
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
struct BIT{
    int _n;
    LL _d[SIZE];
    void init(int __n){
        _n=__n;
        memset(_d,0,sizeof(LL)*(_n+1));
    }
    void ins(int x,LL v){
        for(;x<=_n;x+=x&-x)_d[x]+=v;
    }
    LL qq(int x){
        LL res=0;
        for(;x;x-=x&-x)res+=_d[x];
        return res;
    }
    LL qq_range(int x,int y){
        LL ret=qq(y);
        if(x)ret-=qq(x-1);
        return ret;
    }
}bit[2];
void update(LL b1[],LL b2[],int id){
    if(id<=1||id>=n)return;
    int dif=(b2[1]>=b2[0]&&b2[1]>=b2[2])-(b1[1]>=b1[0]&&b1[1]>=b1[2]);
    if(dif)bit[0].ins(id,dif);
    dif=(b2[1]<b2[0]&&b2[1]<b2[2])-(b1[1]<b1[0]&&b1[1]<b1[2]);
    if(dif)bit[1].ins(id,dif*id);
    LL dif2=cal(b2)-cal(b1);
    if(dif2)ins(2,n-1,1,id,id,dif2);
}
struct BIT2{
    LL _d[SIZE];
    int _n;
    void init(int __n){
        _n=__n;
        memset(_d,0,sizeof(LL)*(_n+1));
    }
    void ins(int x,LL v){
        for(;x;x-=x&-x)_d[x]+=v;
    }
    void ins_range(int x,int y,LL v){
        ins(y,v);
        if(x>1)ins(x-1,-v);
    }
    LL qq(int x){
        LL res=0;
        if(!x)return 0;
        for(;x<=_n;x+=x&-x)res+=_d[x];
        return res;
    }
}bit2;
int main(){
    R(n);
    FOR(i,1,n)R(a[i]);
    seg_init(2,n-1,1);
    LL now=0;
    REP(i,2)bit[i].init(n);
    bit2.init(n);
    FOR(i,1,n){
        if(i>1)now+=abs(a[i]-a[i-1]);
        bit2.ins(i,a[i]-a[i+1]);
    }
    FOR(i,2,n-1){
        if(a[i]>=a[i-1]&&a[i]>=a[i+1])bit[0].ins(i,1);
        else if(a[i]<a[i-1]&&a[i]<a[i+1])bit[1].ins(i,i);
    }
    int Q; R(Q);
    REP(cs,Q){
        int ty,l,r,x; R(ty,l,r,x);
        if(ty==1){
            if(bit[0].qq_range(l,r)>0)W(now+2*x);
            else{
                int id=bit[1].qq_range(l,r);
                LL ma_v=-2.2e9;
                if(id){
                    LL v=0;
                    LL tmp[3];
                    REP(i,3){
                        tmp[i]=bit2.qq(id-1+i);
                    }
                    v+=abs(tmp[1]+x-tmp[0])-abs(tmp[1]-tmp[0]);
                    v+=abs(tmp[2]-tmp[1]-x)-abs(tmp[2]-tmp[1]);
                    ma_v=max(ma_v,v);
                }
                if(!id||r-l+1>1){
                    LL v=qq(2,n-1,1,l,r);
                    ma_v=max(ma_v,max(0LL,(x-v)*2));
                }
                W(now+ma_v);
            }
        }
        else{
            bit2.ins_range(l,r,x);
            if(l==r){
                LL tmp2[5],tmp1[5];
                REP(i,5){
                    tmp2[i]=bit2.qq(l-2+i);
                    tmp1[i]=tmp2[i];
                    if(i==2)tmp1[i]-=x;
                    if(i>=2&&i<=3){
                        now+=abs(tmp2[i]-tmp2[i-1])-abs(tmp1[i]-tmp1[i-1]);
                    }
                }
                FOR(i,1,3)update(tmp1+i-1,tmp2+i-1,l-2+i);
            }
            else{
                LL tmp2[4],tmp1[4];
                REP(i,4){
                    tmp2[i]=bit2.qq(l-2+i);
                    tmp1[i]=tmp2[i];
                    if(i>1)tmp1[i]-=x;
                    if(i==2){
                        now+=abs(tmp2[i]-tmp2[i-1])-abs(tmp1[i]-tmp1[i-1]);
                    }
                }
                FOR(i,1,2)update(tmp1+i-1,tmp2+i-1,l-2+i);
                REP(i,4){
                    tmp2[i]=bit2.qq(r-1+i);
                    tmp1[i]=tmp2[i];
                    if(i<=1)tmp1[i]-=x;
                    if(i==2){
                        now+=abs(tmp2[i]-tmp2[i-1])-abs(tmp1[i]-tmp1[i-1]);
                    }
                }
                FOR(i,1,2)update(tmp1+i-1,tmp2+i-1,r-1+i);
            }
        }
    }
    return 0;
}