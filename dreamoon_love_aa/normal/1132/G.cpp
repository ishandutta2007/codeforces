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
LL ma[1<<21],_tmp[1<<21];
void push(int id){
    if(_tmp[id]==0)return;
    _tmp[id*2]+=_tmp[id];
    ma[id*2]+=_tmp[id];
    _tmp[id*2+1]+=_tmp[id];
    ma[id*2+1]+=_tmp[id];
    _tmp[id]=0;
}
void pull(int id){
    ma[id]=max(ma[id*2],ma[id*2+1]);
}
void seg_init(int L,int R,int id){
    if(L==R){
        ma[id]=-MOD;
        return;
    }
    int mm=(L+R)/2;
    seg_init(L,mm,id*2);
    seg_init(mm+1,R,id*2+1);
    pull(id);
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
        ma[id]+=v;
        _tmp[id]+=v;
        return;
    }
    int mm=(L+R)/2;
    push(id);
    ins(L,mm,id*2,ll,rr,v);
    ins(mm+1,R,id*2+1,ll,rr,v);
    pull(id);
}
// 0-based
#define MAX_LV 19
int jump[MAX_LV+1][SIZE];
int AA[SIZE];
int N,K,stk[SIZE],sn;
int bb;
VI e[SIZE];
int get_far(int x){
    int res=1;
    for(int i=MAX_LV;i>=0;i--){
        if(jump[i][x]<=bb){
            res+=1<<i;
            x=jump[i][x];
        }
    }
    return res;
}
void build(){
    REPP(i,1,MAX_LV+1){
        FOR(x,1,N+1)
            jump[i][x]=jump[i-1][jump[i-1][x]];
    }
}
int ID,ll[SIZE],rr[SIZE];
void dfs(int x,int lt){
    ll[x]=rr[x]=ID++;
    for(int y:e[x]){
        if(y==lt)continue;
        dfs(y,x);
        rr[x]=rr[y];
    }
}
int main(){
    R(N,K);
    FOR(i,1,N)R(AA[i]);
    stk[sn++]=N+1;
    AA[N+1]=MOD;
    jump[0][N+1]=N+1;
    for(int i=N;i>0;i--){
        while(sn&&AA[stk[sn-1]]<=AA[i]){
            sn--;
        }
        e[stk[sn-1]].PB(i);
        jump[0][i]=stk[sn-1];
        stk[sn++]=i;
    }
    dfs(N+1,N+1);
    build();
    seg_init(1,N,1);
    bb=N;
    REP(i,K){
        int x=N-i;
        int len=get_far(x);
        ins(1,N,1,ll[x],ll[x],MOD+len);
    }
    VI an;
    an.PB(qq(1,N,1,1,N));
    for(int i=N-K;i>0;i--){
        int y=i+K;
        ins(1,N,1,ll[y],rr[y],-1);
        bb--;
        int len=get_far(i);
        LL v=qq(1,N,1,ll[i],rr[i]);
        ins(1,N,1,ll[i],rr[i],len-v);
        an.PB(qq(1,N,1,1,N));
    }
    reverse(ALL(an));
    W(an);
    return 0;
}