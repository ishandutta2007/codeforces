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
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<21;
LL ma[SIZE],_tmp[SIZE];
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
void push(int id){
    if(_tmp[id]==0)return;
    maa(_tmp[id*2],_tmp[id]);
    maa(ma[id*2],_tmp[id]);
    maa(_tmp[id*2+1],_tmp[id]);
    maa(ma[id*2+1],_tmp[id]);
    _tmp[id]=0;
}
void pull(int id){
    ma[id]=max(ma[id*2],ma[id*2+1]);
}
LL qq(int L,int R,int id,int ll,int rr){
    if(R<ll||L>rr)return LLONG_MIN;
    if(L>=ll&&R<=rr)return ma[id];
    int mm=(L+R)/2;
    push(id);
    return max(qq(L,mm,id*2,ll,rr),qq(mm+1,R,id*2+1,ll,rr));
}
void ins(int L,int R,int id,int ll,int rr,LL v){
    if(R<ll||L>rr)return;
    if(L>=ll&&R<=rr){
        maa(ma[id],v);
        maa(_tmp[id],v);
        return;
    }
    int mm=(L+R)/2;
    push(id);
    ins(L,mm,id*2,ll,rr,v);
    ins(mm+1,R,id*2+1,ll,rr,v);
    pull(id);
}
int  N,K;
VI e[SIZE];
int p[SIZE],lv[SIZE],pid,ll[SIZE],rr[SIZE];
void dfs(int x,int lt){
    ll[x]=rr[x]=pid++;
    for(int y:e[x]){
        if(y==lt)continue;
        p[y]=x;
        lv[y]=lv[x]+1;
        dfs(y,x);
        rr[x]=rr[y];
    }
}
bool ker[SIZE];
int main(){
    R(N,K);
    REPP(i,1,N){
        int x,y; R(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    dfs(N,N);
    ker[N]=1;
    int r=N-K-1;
    for(int i=N-1;i>0;i--){
        if(ker[i])continue;
        int dd=lv[i]-qq(0,N,1,ll[i],ll[i]);
        if(dd<=r){
            r-=dd;
            int now=i;
            while(!ker[now]){
                ker[now]=1;
                ins(0,N,1,ll[now],rr[now],lv[now]);
                now=p[now];
            }
            if(!r)break;
        }
    }
    VI an;
    FOR(i,1,N)
        if(!ker[i])an.PB(i);
    W(an);
    return 0;
}