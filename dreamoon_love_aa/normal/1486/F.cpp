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
int ll[SIZE],rr[SIZE];
int node_id;
const int BIT_NUM = 20;
struct BIT{
    int _n;
    long long _d[1 << BIT_NUM];
    void init(int __n) {
        _n=__n;
        memset(_d, 0, sizeof(long long) * (_n+1));
    }
    void ins(int x, long long v) {
        for(; x <= _n; x += x & -x) { _d[x] += v; }
    }
    long long qq(int x) {
        if(x <= 0) {
            return 0;
        }
        long long res = 0;
        for(; x; x -= x & -x) { res += _d[x];}
        return res;
    }
    long long qq_range(int x, int y) {
        if(x > y) {
            return 0;
        }
        long long ret = qq(y);
        if(x)ret -= qq(x-1);
        return ret;
    }
    long long k_th(int k){
        int now = 0;
        for(int i = BIT_NUM - 1; i >= 0; i--) {
            if(_d[now + (1 << i)] < k) {
                k -= _d[now + (1 << i)];
                now += 1 << i;
            }
        }
        return now + 1;
    }
}bit;
#define UnionFindSIZE 1234567
struct Union_Find {
    int d[UnionFindSIZE];
    void init(int n){
        for(int i = 0; i < n; i++) {
            d[i]=i;
        }
    }
    int find(int x){
        int y = x, z = x;
        while(y != d[y]) { y = d[y]; }
        while(x != y) {
            x = d[x];
            d[z] = y;
            z = x;
        }
        return y;
    }
    bool is_root(int x) { return d[x] == x; }
    bool uu(int x,int y) {
        x=find(x);
        y=find(y);
        if(x == y) { return 0; }
        d[x] = y;
        return 1;
    }
}U;
int single[SIZE];
map<int,int> AA[SIZE];
map<int,int> *ptr[SIZE];
VI e[SIZE];
VI path_id[SIZE];
int n,m;
int merge(int x, int y, VPII &pp){
    if(ptr[x]->size() > ptr[y]->size()){
        swap(x,y);
    }
    for(auto it=ptr[x]->begin();it!=ptr[x]->end();it++){
        int my_id = U.find(it->S);
        auto it2=ptr[y]->find(it->F);
        if(it2 != ptr[y]->end()){
            bit.ins(ll[it->S],-1);
            bit.ins(ll[it2->S],-1);
            int your_id=U.find(it2->S);
            if(my_id>your_id){
                swap(my_id,your_id);
            }
            pp.PB(MP(my_id,your_id));
        }else{
            (*ptr[y])[it->F]=it->S;
        }
    }
    return y;
}
LL an=0;
int tmp[SIZE];
int tn;
LL C2(LL x){
    return x*(x-1)/2;
}
LL calc(VPII& pp, int rt){
    tn=0;
    LL ret=C2(SZ(pp))+(single[rt]+SZ(pp))*bit.qq_range(ll[rt],rr[rt])+C2(single[rt])+(LL)single[rt]*SZ(pp);
    //DEBUG(SZ(pp),single[rt],bit.qq_range(ll[rt],rr[rt]));
    REP(i,SZ(pp)){
        if(pp[i].F!=rt)ret-=bit.qq_range(ll[pp[i].F],rr[pp[i].F]);
        if(pp[i].S!=rt)ret-=bit.qq_range(ll[pp[i].S],rr[pp[i].S]);
        tmp[tn++]=pp[i].F;
        tmp[tn++]=pp[i].S;
    }
    sort(tmp,tmp+tn);
    for(int i=0,j;i<tn;i=j){
        for(j=i+1;j<tn&&tmp[j]==tmp[i];j++);
        if(tmp[i]!=rt)ret-=C2(j-i);
    }
    sort(ALL(pp));
    for(int i=0,j;i<SZ(pp);i=j){
        for(j=i+1;j<SZ(pp)&&pp[i]==pp[j];j++);
        if(pp[i].F!=rt&&pp[i].S!=rt){
            ret+=C2(j-i);
        }
    }
    return ret;
}
void dfs(int x,int lt){
    ptr[x]=&AA[x];
    int me=-1;
    VPII pp;
    for(int y: e[x]) {
        if(y==lt)continue;
        dfs(y,x);
        if(me==-1){
            me=y;
        }
        else{
            me=merge(me,y,pp);
        }
    }
    bit.ins(ll[x],SZ(path_id[x]));
    for(int id:path_id[x]){
        AA[x][id]=x;
    }
    if(me==-1){
        me=x;
    }else{
        me=merge(me,x,pp);
    }
    if(me!=x)swap(ptr[x],ptr[me]);
    an+=calc(pp, x);
    for(int y: e[x]){
        if(y==lt)continue;
        U.uu(y,x);
    }
}
void dfs0(int x,int lt){
    ll[x]=rr[x]=++node_id;
    for(int y:e[x]){
        if(y==lt)continue;
        dfs0(y,x);
        rr[x]=rr[y];
    }
}
void solve() {
    U.init(n+1);
    dfs0(1,1);
    bit.init(n);
    dfs(1,1);
    W(an);
}
void input() {
    R(n);
    REPP(i,1,n){
        int x,y;
        R(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    R(m);
    REP(i,m){
        int u,v;
        R(u,v);
        if(u==v){
            single[u]++;
        }else{
            path_id[u].PB(i);
            path_id[v].PB(i);
        }
    }
}
int main(){
    input();
    solve();
    return 0;
}