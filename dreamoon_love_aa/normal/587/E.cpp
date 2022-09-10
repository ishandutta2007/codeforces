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
const int SIZE = 200001;
int NOW = 1<<19;
int NXT = NOW + 1;
int AA[SIZE];
int r[(1<<19)+2][31], pushed_value[(1<<19)+2];
int get_highest_bit(unsigned x){
    if(!x) return 30;
    return 31-__builtin_clz(x);
}
void ins(int d[],int v){
    while(v){
        int bit=get_highest_bit(v);
        if(d[bit])v^=d[bit];
        else{
            d[bit]=v;
            break;
        }
    }
}
void merge(int id,int l_id,int r_id){
    MS0(r[id]);
    REP(i,30){
        if(r[r_id][i])r[id][i]=r[r_id][i];
        else r[id][i]=r[l_id][i];
    }
    REP(i,30){
        if(r[r_id][i]&&r[l_id][i])ins(r[id],r[r_id][i]^r[l_id][i]);
    }
    r[id][30]=r[r_id][30];
    ins(r[id],r[l_id][30]^r[r_id][30]);
}
void build(int L,int R,int id){
    if(L==R){
        r[id][30]=AA[L];
        return;
    }
    int mm=(L+R)/2;
    build(L,mm,id*2);
    build(mm+1,R,id*2+1);
    merge(id,2*id,2*id+1);
}
void push(int id){
    int v=pushed_value[id];
    if(v){
        r[id*2][30]^=v;
        r[id*2+1][30]^=v;
        pushed_value[id*2]^=v;
        pushed_value[id*2+1]^=v;
        pushed_value[id]=0;
    }
}
void change(int L,int R,int id, int ll,int rr,int v){
    if(L>=ll&&R<=rr){
        r[id][30]^=v;
        pushed_value[id]^=v;
        return;
    }
    push(id);
    int mm=(L+R)/2;
    if(ll<=mm)change(L,mm,id*2,ll,rr,v);
    if(rr>mm)change(mm+1,R,id*2+1,ll,rr,v);
    merge(id,2*id,2*id+1);
}
void qq(int L,int R,int id,int ll,int rr){
    if(L>=ll&&R<=rr){
        swap(NOW,NXT);
        merge(NOW,NXT,id);
        return;
    }
    push(id);
    int mm=(L+R)/2;
    if(ll<=mm)qq(L,mm,id*2,ll,rr);
    if(rr>mm)qq(mm+1,R,id*2+1,ll,rr);
    merge(id,2*id,2*id+1);
}
int main(){
    int n,m;
    R(n,m);
    FOR(i,1,n){
        int v;
        R(v);
        AA[i]=v;
    }
    build(1,n,1);
    while(m--){
        int op,ll,rr,v=0;
        R(op,ll,rr);
        if(op==1){
            R(v);
            change(1,n,1,ll,rr,v);
        }
        else{
            MS0(r[NOW]);
            qq(1,n,1,ll,rr);
            ins(r[NOW],r[NOW][30]);
            for(int i=29;i>=0;i--) v+=(r[NOW][i]!=0);
            W(1<<v);
        }
    }
    return 0;
}