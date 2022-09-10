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
const int SIZE = 1.6e6+10;
int N,MM,rr[400010];
int inv(int x){
    return 2*x+1;
}
int pos(int x){
    return 2*x;
}
int v[400010];
struct SCC{
    int n,used[SIZE],order[SIZE],gg[SIZE];
    vector<int>e[SIZE],ae[SIZE],ge[SIZE],emp,be[SIZE];
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
        gg[x]=gn;
        be[gn].PB(x);
        used[x]=2;
        REP(i,SZ(ae[x])){
            int y=ae[x][i];
            if(used[y]==2){
                if(gg[y]!=gg[x])ge[gg[y]].PB(gg[x]);
            }
            else dfs2(y);
        }
    }
    bool make_scc(){
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
        REP(i,N){
            if(gg[pos(i)]==gg[inv(i)])return 0;
        }
        REP(i,gn){
            sort(ALL(ge[i]));
            ge[i].resize(unique(ALL(ge[i]))-ge[i].begin());
        }
        int ma=MM-1;
        VI res;
        for(int i=gn-1;i>=0;i--){
            bool stop=0;
            for(int x: be[i]){
                if(x<2*N){
                    if(v[x>>1]){
                        stop=1;
                        break;
                    }
                }
            }
            if(!stop){
                for(int x: be[i]){
                    if(x<2*N){
                        if(!v[x>>1]){
                            if(x&1)v[x>>1]=-1;
                            else {
                                v[x>>1]=1;
                                res.PB((x>>1)+1);
                                ma=min(ma,rr[x>>1]);
                            }
                        }
                    }
                }
            }
        }
        SORT_UNIQUE(res);
        W(SZ(res),ma+1);
        W(res);
        return 1;
    }
}scc;
int main(){
    int n,p,M,m;
    R(n,p,M,m);
    MM=M;
    N=p;
    scc.init(2*p+2*M);
    REP(i,n){
        int x,y;
        R(x,y);
        x--;y--;
        scc.add_edge(inv(x),pos(y));
        scc.add_edge(inv(y),pos(x));
    }
    REPP(i,1,M){
        scc.add_edge(2*p+i-1,2*p+i);
    }
    REPP(i,1,M){
        scc.add_edge(2*p+M+i,2*p+M+i-1);
    }
    REP(i,p){
        int x,y; R(x,y);
        x--;y--;
        rr[i]=y;
        scc.add_edge(2*p+x,inv(i));
        scc.add_edge(2*p+M+y,inv(i));
        if(y+1<M)scc.add_edge(pos(i),2*p+y+1);
        if(x>0)scc.add_edge(pos(i),2*p+M+x-1);
    }
    REP(i,m){
        int x,y; R(x,y);
        x--;y--;
        scc.add_edge(pos(x),inv(y));
        scc.add_edge(pos(y),inv(x));
    }
    if(!scc.make_scc())W(-1);
    return 0;
}