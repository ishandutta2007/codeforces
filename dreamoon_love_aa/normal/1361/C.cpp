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
#define UnionFindSIZE 1234567
struct Union_Find{
    int d[UnionFindSIZE],num[UnionFindSIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1;
    }
    int find(int x){
        int y = x, z = x;
        while(y != d[y]) y = d[y];
        while(x != y){
            x = d[x];
            d[z] = y;
            z = x;
        }
        return y;
    }
    bool is_root(int x){return d[x]==x;}
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        if(num[x]>num[y])swap(x,y);
        num[y]+=num[x];
        d[x]=y;
        return 1;
    }
}U;
int a[SIZE],an[SIZE],from[SIZE];
int st[SIZE],ed[SIZE],cnt[SIZE];
int nxt[SIZE];
PII d[SIZE];
int n;
bool valid(int mod){
    if(mod==1){
        REP(i,2*n)an[i]=i;
        return 1;
    }
    memset(cnt,0,sizeof(int)*mod);
    int mask=mod-1;
    REP(i,2*n)d[i]=MP(a[i]&mask,i);
    sort(d,d+2*n);
    int it=0;
    REP(i,mod){
        st[i]=it;
        while(it<2*n&&d[it].F==i){
            from[d[it].S]=i;
            it++;
        }
        ed[i]=it;
        cnt[i]=ed[i]-st[i];
        if((ed[i]-st[i])&1){
            return 0;
        }
    }
    U.init(mod);
    for(int i=0;i<2*n;i+=2)U.uu(from[i],from[i+1]);
    int rt=-1;
    REP(i,mod){
        if(!cnt[i])continue;
        if(rt==-1)rt=U.find(i);
        else if(U.find(i)!=rt){
            return 0;
        }
    }
    U.init(n);
    REP(i,n){
        U.uu(d[i*2].S>>1,d[i*2+1].S>>1);
        nxt[d[i*2].S]=d[i*2+1].S;
        nxt[d[i*2+1].S]=d[i*2].S;
    }
    for(int i=2;i<2*n;i+=2){
        if(d[i].F==d[i-1].F&&U.find(d[i].S>>1)!=U.find(d[i-1].S>>1)){
            int x=d[i].S;
            int y=d[i-1].S;
            int nx=nxt[x];
            int ny=nxt[y];
            nxt[x]=y;
            nxt[y]=x;
            nxt[nx]=ny;
            nxt[ny]=nx;
            U.uu(x>>1,y>>1);
        }
    }
    an[0]=0;
    an[1]=1;
    for(int i=2;i<2*n;i+=2){
        an[i]=nxt[an[i-1]];
        an[i+1]=an[i]^1;
    }
    return 1;
}
int main(){
    R(n);
    REP(i,n)R(a[2*i],a[2*i+1]);
    int ll=0,rr=20;
    while(ll<rr){
        int mm=(ll+rr+1)/2;
        if(valid(1<<mm))ll=mm;
        else rr=mm-1;
    }
    valid(1<<ll);
    W(ll);
    REP(i,2*n)an[i]++;
    W(VI(an,an+2*n));
    return 0;
}