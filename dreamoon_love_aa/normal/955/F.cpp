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
const int SIZE = 3e5+10;
#define MA(I,X) ma[I][(X)-1]
#define CUL(I,X) cul[I][(X)-1]
VI ma[SIZE],cul[SIZE];
VI e[SIZE];
int de[SIZE];
LL an;
int n;
void update(int &x,int v){
    if(x<v)x=v;
}
vector<VI> g[SIZE];
void dfs(int x,int lt){
    de[x]=1;
    if(x!=lt&&SZ(e[x])==1){
        ma[x]=cul[x]={n};
        an+=n;
        return;
    }
    vector<VI>&gg=g[x];
    gg.resize(20);
    for(int y:e[x]){
        if(y==lt)continue;
        dfs(y,x);
        de[x]=max(de[x],de[y]+1);
        while(SZ(cul[y])>SZ(cul[x]))cul[x].PB(0);
        FOR(i,1,SZ(cul[y])){
            update(CUL(x,i),CUL(y,i));
        }
        FOR(i,1,SZ(ma[y])){
            gg[i].PB(MA(y,i));
        }
    }
    for(int i=19;i>0;i--){
        if(SZ(gg[i])==0)continue;
        sort(ALL(gg[i]));
        int v=0;
        REP(j,SZ(gg[i])){
            v=max(v,min(SZ(gg[i])-j,gg[i][j]));
        }
        if(v>1) ma[x].PB(v);
    }
    {
        vector<VI> tmp;
        gg.swap(tmp);
    }
    ma[x].PB(n);
    reverse(ALL(ma[x]));
    while(SZ(cul[x])<SZ(ma[x]))cul[x].PB(0);
    FOR(i,1,SZ(ma[x])){
        update(CUL(x,i),MA(x,i));
    }
    FOR(i,1,SZ(cul[x]))an+=CUL(x,i)-1;
    an+=de[x];
}
int main(){
    R(n);
    REPP(i,1,n){
        int x,y; R(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    dfs(1,1);
    W(an);
    return 0;
}