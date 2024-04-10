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
typedef int64_t LL;
typedef uint64_t ULL;
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
LL get_cost(int x){
    int ll=0,rr=20000;
    while(ll<rr){
        int mm=(ll+rr+1)/2;
        if(mm*(mm+1)/2>x)rr=mm-1;
        else ll=mm;
    }
    return x*(LL)(ll+1)-(LL)ll*(ll+1)*(ll+2)/6;
}
struct SCC{
    int n,used[SIZE],order[SIZE],gg[SIZE];
    vector<int>e[SIZE],ae[SIZE],ge[SIZE],emp,ev[SIZE],aev[SIZE],gev[SIZE];
    LL oc[SIZE];
    int id,gn;
    LL dp[SIZE];
    LL dfs(int x){
        if(dp[x]!=-1)return dp[x];
        LL& res=dp[x];
        res=oc[x];
        LL nxt_v=0;
        REP(i,SZ(ge[x])){
            nxt_v=max(nxt_v,dfs(ge[x][i])+gev[x][i]);
        }
        res+=nxt_v;
        return res;
    }
    void init(int _n){
        n=_n;
        memset(used,0,sizeof(int)*n);
        REP(i,n){
            e[i]=ae[i]=ge[i]=emp;
        }
    }
    void add_edge(int x,int y,int v){
        e[x].PB(y);
        ev[x].PB(v);
        ae[y].PB(x);
        aev[y].PB(v);
    }
    void dfs1(int x){
        if(used[x]==1)return;
        used[x]=1;
        REP(i,SZ(e[x])){
            int y=e[x][i];
            dfs1(y);
        }
        order[--id]=x;
    }
    void dfs2(int x){
        if(used[x]==2)return;
        gg[x]=gn;
        used[x]=2;
        REP(i,SZ(ae[x])){
            int y=ae[x][i];
            if(used[y]==2){
                if(gg[y]!=gg[x]){
                    ge[gg[y]].PB(gg[x]);
                    gev[gg[y]].PB(aev[x][i]);
                }
                else{
                    oc[gn]+=get_cost(aev[x][i]);
                }
            }
            else{
                oc[gn]+=get_cost(aev[x][i]);
                dfs2(y);
            }
        }
    }
    void make_scc(){
        gn=0;
        id=n;
        REP(i,n)
            dfs1(i);
        REP(i,n){
            if(used[order[i]]!=2){
                oc[gn]=0;
                dfs2(order[i]);
                gn++;
            }
        }
    }
    void solve(){
        MS1(dp);
        int x;
        R(x);x--;
        x=gg[x];
        dfs(x);
        W(dp[x]);
    }
}scc;
int main(){
    int n,m;
    R(n,m);
    scc.init(n);
    REP(i,m){
        int x,y,v;
        R(x,y,v);x--;y--;
        scc.add_edge(x,y,v);
    }
    scc.make_scc();
    scc.solve();
    return 0;
}