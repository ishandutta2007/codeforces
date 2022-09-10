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

#define FN 500010
#define FM 4200010
#define INF 1034567890
struct E {
    int k,c;
    E(){}
    E( int _k, int _c ):k(_k),c(_c){}
} es[FM];

struct Flow {
    int n,m,ty[FN],dis[FN];
    int qq[FN],qr,ql;
    VI e[FN],e0[FN];
    void init( int _n ) {
        n=_n+2; m=0;
        for ( int i=0; i<n; i++ ) e[i]=vector<int>();
    }
    void add_edge(int a,int b){
        e0[a].PB(b);
        e0[b].PB(a);
    }
    void _add_edge( int a, int b) {
        e[a].PB(m); es[m]=E(b,1); m++;
        e[b].PB(m); es[m]=E(a,0); m++;
    }
    void DFS(int x,int v){
        if(ty[x]!=-1)return;
        ty[x]=v;
        if(!v)_add_edge(0,x);
        else _add_edge(x,n-1);
        REP(i,SZ(e0[x])){
            int y=e0[x][i];
            if(!v)_add_edge(x,y);
            DFS(y,v^1);
        }
    }
    void construct_flow_edge(){
        memset(ty,-1,n*sizeof(int));
        REPP(i,1,n-1){
            if(ty[i]==-1){
                DFS(i,0);
            }
        }
    }
    bool BFS() {
        memset(dis,-1,n*sizeof(int));
        ql=qr=0;
        qq[qr++]=0;
        dis[0]=0;
        while ( ql!=qr && dis[n-1]==-1 ) {
            int p=qq[ql++];
            for(auto& it: e[p]) {
                E ee=es[it];
                if ( ee.c==0 || dis[ee.k]!=-1 ) continue;
                dis[ee.k]=dis[p]+1;
                qq[qr++]=ee.k;
            }
        }
        return dis[n-1]!=-1;
    }
    LL go( int p, LL c ) {
        if ( p==n-1 ) return c;
        LL ret=0,tmp;
        for(auto& it: e[p]) {
            E &ee=es[it];
            if ( ee.c==0 || dis[p]+1!=dis[ee.k] ) continue;
            tmp=go(ee.k,min(c-ret,(LL)ee.c));
            ret+=tmp; ee.c-=tmp; es[it^1].c+=tmp;
            if ( ret==c ) break;
        }
        if ( ret==0 ) dis[p]=-1;
        return ret;
    }
    LL maxflow(){
        construct_flow_edge();
        LL ret=0;
        while ( BFS() ) ret+=go(0,1LL<<60);
        return ret;
    }
    VI maximum_clique(){
        construct_flow_edge();
        while ( BFS() ) go(0,1LL<<60);
        VI res;
        REPP(i,1,n-1){
            if(ty[i]^(dis[i]!=-1))res.PB(i);
        }
        return res;
    }
} flow;
void print(VI& res){
    W(SZ(res)/4);
    for(int i=0;i<SZ(res);i+=4){
        W(res[i],res[i+1],res[i+2],res[i+3]);
    }
}
const int SIZE = 1010;
int row[SIZE][SIZE],col[SIZE][SIZE],AA[SIZE][SIZE];
int x[SIZE],y[SIZE];
int main(){
    int n; R(n);
    VI xx,yy;
    FOR(i,1,n){
        R(x[i],y[i]);
        xx.PB(x[i]);
        yy.PB(y[i]);
    }
    SORT_UNIQUE(xx);
    SORT_UNIQUE(yy);
    FOR(i,1,n){
        x[i]=GET_POS(xx,x[i]);
        y[i]=GET_POS(yy,y[i]);
        AA[x[i]][y[i]]=1;
    }
    int xn=SZ(xx);
    int yn=SZ(yy);
    int h_id=1;
    int v_id=1001;
    int ed=2018;
    flow.init(ed);
    REP(i,yn){
        int lt=-1;
        REP(j,xn){
            if(AA[j][i]){
                if(lt!=-1){
                    REPP(k,lt,j){
                        row[k][i]=h_id;
                    }
                    h_id++;
                }
                lt=j;
            }
        }
    }
    REP(j,xn){
        int lt=-1;
        REP(i,yn){
            if(AA[j][i]){
                if(lt!=-1){
                    REPP(k,lt,i){
                        col[j][k]=v_id;
                    }
                    v_id++;
                }
                lt=i;
            }
        }
    }
    REPP(i,1,xn-1)REPP(j,1,yn-1){
        if(!AA[i][j]&&row[i-1][j]&&col[i][j-1])flow.add_edge(row[i-1][j],col[i][j-1]);
    }
    VI res=flow.maximum_clique();
    sort(ALL(res));
    VI an1,an2;
    REP(i,xn){
        VI lt;
        REP(j,yn){
            if(AA[i][j]){
                if(SZ(lt)&&j&&!binary_search(ALL(res),col[i][j-1])){
                    an1.PB(xx[i]);
                    an1.PB(yy[lt[0]]);
                    an1.PB(xx[i]);
                    an1.PB(yy[lt.back()]);
                    lt.clear();
                }
                lt.PB(j);
            }
        }
        if(SZ(lt)){
            an1.PB(xx[i]);
            an1.PB(yy[lt[0]]);
            an1.PB(xx[i]);
            an1.PB(yy[lt.back()]);
        }
    }
    REP(j,yn){
        VI lt;
        REP(i,xn){
            if(AA[i][j]){
                if(SZ(lt)&&i&&!binary_search(ALL(res),row[i-1][j])){
                    an2.PB(xx[lt[0]]);
                    an2.PB(yy[j]);
                    an2.PB(xx[lt.back()]);
                    an2.PB(yy[j]);
                    lt.clear();
                }
                lt.PB(i);
            }
        }
        if(SZ(lt)){
            an2.PB(xx[lt[0]]);
            an2.PB(yy[j]);
            an2.PB(xx[lt.back()]);
            an2.PB(yy[j]);
        }
    }
    print(an2);
    print(an1);
    return 0;
}