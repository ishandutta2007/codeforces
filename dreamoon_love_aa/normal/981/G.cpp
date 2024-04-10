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
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 998244353;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
#define LEFT second
#define RIGHT first
LL sum[SIZE];
int num[SIZE];
PLL span[SIZE];
PLL unit=MP(1,0);
void go(LL& me,PLL v,int id){
    me=(me*v.F+v.S*num[id])%MOD;
}
void go2(PLL& me,PLL v){
    me=MP(me.F*v.F%MOD,(me.S*v.F+v.S)%MOD);
}
void push(int id){
    if(span[id]==unit)return;
    go(sum[id*2],span[id],id*2);
    go(sum[id*2+1],span[id],id*2+1);
    go2(span[id*2],span[id]);
    go2(span[id*2+1],span[id]);
    span[id]=unit;
}
void pull(int id){
    sum[id]=sum[id*2]+sum[id*2+1];
    if(sum[id]>=MOD)sum[id]-=MOD;
}
void seg_init(int L,int R,int id){
    span[id]=unit;
    sum[id]=0;
    if(L==R){
        num[id]=1;
        return;
    }
    int mm=(L+R)/2;
    seg_init(L,mm,id*2);
    seg_init(mm+1,R,id*2+1);
    num[id]=num[id*2]+num[id*2+1];
}
LL qq(int L,int R,int id,int ll,int rr){
    if(R<ll||L>rr)return 0;
    if(L>=ll&&R<=rr)return sum[id];
    int mm=(L+R)/2;
    push(id);
    LL res=qq(L,mm,id*2,ll,rr)+qq(mm+1,R,id*2+1,ll,rr);
    if(res>=MOD)res-=MOD;
    return res;
}
void ins(int L,int R,int id,int ll,int rr,PLL v){
    if(R<ll||L>rr)return;
    if(L>=ll&&R<=rr){
        go(sum[id],v,id);
        go2(span[id],v);
        return;
    }
    int mm=(L+R)/2;
    push(id);
    ins(L,mm,id*2,ll,rr,v);
    ins(mm+1,R,id*2+1,ll,rr,v);
    pull(id);
}
set<PLL>ran[SIZE];
PII MUL_TWO = MP(2,0);
PII ADD_ONE = MP(1,1);
int main(){
    int n,q; R(n,q);
    seg_init(1,n,1);
    REP(i,q){
        int ty,l,r,x;
        R(ty,l,r);
        if(ty==1){
            R(x);
            set<PLL>&now=ran[x];
            auto it=now.lower_bound(MP(l,0));
            if(it==now.end() || r<it->LEFT){
                ins(1,n,1,l,r,ADD_ONE);
                now.insert(MP(r,l));
            }
            else{
                int new_r=r,new_l=l;
                int ll=l;
                auto it2=it;
                while(it2!=now.end()&&it2->LEFT<=r){
                    new_l=min(new_l,(int)(it2->LEFT));
                    new_r=max(new_r,(int)(it2->RIGHT));
                    if(ll<=min((int)(it2->LEFT)-1,r)){
                        ins(1,n,1,ll,min((int)(it2->LEFT)-1,r),ADD_ONE);
                        ll=min((int)(it2->LEFT)-1,r)+1;
                    }
                    if(ll<=min((int)(it2->RIGHT),r)){
                        ins(1,n,1,ll,min((int)(it2->RIGHT),r),MUL_TWO);
                        ll=min((int)(it2->RIGHT),r)+1;
                    }
                    it2++;
                }
                if(ll<=r){
                    ins(1,n,1,ll,r,ADD_ONE);
                }
                now.erase(it,it2);
                now.insert(MP(new_r,new_l));
            }
        }
        else{
            W(qq(1,n,1,l,r));
        }
    }
    return 0;
}