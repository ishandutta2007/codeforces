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
#define UnionFindSIZE 3005
VI e[3005];
int ord[3005], ord_it;
int pos[3005];
int C2(int x){
    return x*(x-1)/2;
}
struct Union_Find{
    int d[UnionFindSIZE],num[UnionFindSIZE],rt[UnionFindSIZE],e_num[UnionFindSIZE];
    int ll[UnionFindSIZE],rr[UnionFindSIZE];
    int rt_id;
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1,rt[i]=i,e_num[i]=0,ll[i]=rr[i]=pos[i];
        rt_id=n;
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
        e[rt_id].PB(rt[x]);
        e[rt_id].PB(rt[y]);
        e_num[y]+=e_num[x];
        ll[y]=min(ll[y],ll[x]);
        rr[y]=max(rr[y],rr[x]);
        rt[y]=rt_id;
        rt_id++;
        return 1;
    }
}U;
void dfs(int x){
    if(!SZ(e[x])){
        pos[x]=ord_it;
        ord[ord_it++]=x;
        return;
    }
    for(int y:e[x])dfs(y);
}
PII d[1125000];
int a[1505][1505];
LL dp[1505][1505];
VI ker[1505];
void solve() {
    int n;
    R(n);
    REP(i,n)REP(j,n){
        R(a[i][j]);
        if(i<j)d[a[i][j]]=MP(i,j);
    }
    U.init(n);
    FOR(i,1,n*(n-1)/2){
        U.uu(d[i].F,d[i].S);
    }
    dfs(U.rt_id-1);
    U.init(n);
    REP(i,n)ker[i].PB(i);
    FOR(i,1,n*(n-1)/2){
        U.uu(d[i].F,d[i].S);
        int g_id=U.find(d[i].F);
        U.e_num[g_id]++;
        if(U.e_num[g_id]==C2(U.num[g_id])){
            ker[U.ll[g_id]].PB(U.rr[g_id]);
        }
    }
    dp[0][0]=1;
    MOD=998244353;
    REP(x,n){
        for(int y:ker[x]){
            REP(j,n){
                ADD(dp[y+1][j+1],dp[x][j]);
            }
        }
    }
    W(VI(dp[n]+1,dp[n]+n+1));
}
void input() {
    
}
int main(){
    input();
    solve();
    return 0;
}