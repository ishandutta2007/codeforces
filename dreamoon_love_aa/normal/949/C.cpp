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
const int SIZE = 2e5+10;
struct SCC{
    int n,used[SIZE],order[SIZE],gg[SIZE],gg_cnt[SIZE];
    vector<int>e[SIZE],ae[SIZE],ge[SIZE],emp;
    int id,gn;
    void init(int _n){
        n=_n;
        memset(used,0,sizeof(int)*n);
        REP(i,n){
            e[i]=ae[i]=ge[i]=emp;
        }
    }
    void add_edge(int x,int y){
        e[x].PB(y);
        ae[y].PB(x);
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
        gg_cnt[gn]++;
        gg[x]=gn;
        used[x]=2;
        REP(i,SZ(ae[x])){
            int y=ae[x][i];
            if(used[y]==2){
                if(gg[y]!=gg[x])ge[gg[y]].PB(gg[x]);
            }
            else dfs2(y);
        }
    }
    void make_scc(){
        gn=0;
        id=n;
        REP(i,n)
            dfs1(i);
        REP(i,n){
            if(used[order[i]]!=2){
                dfs2(order[i]);
                gn++;
            }
        }
        int mi=n+1,gid;
        REP(i,gn){
            if(SZ(ge[i])==0){
                if(mi>gg_cnt[i]){
                    mi=gg_cnt[i];
                    gid=i;
                }
            }
        }
        VI ans;
        REP(i,n){
            if(gg[i]==gid)ans.PB(i+1);
        }
        W(SZ(ans));
        W(ans);
        /* unique new graph edge
        REP(i,gn){
            sort(ALL(ge[i]));
            ge[i].resize(unique(ALL(ge[i]))-ge[i].begin());
        }
        */
    }
}scc;
int u[SIZE];
int main(){
    int n,m,h;
    R(n,m,h);
    scc.init(n);
    REP(i,n) R(u[i]);
    REP(i,m){
        int x,y;
        R(x,y);
        x--;y--;
        if((u[x]+1)%h==u[y])scc.add_edge(x,y);
        if((u[y]+1)%h==u[x])scc.add_edge(y,x);
    }
    scc.make_scc();
    return 0;
}