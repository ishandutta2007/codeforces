#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int SIZE = 1e6+10;

#define FN 500010
#define FM 4200010
#define INF 2034567890
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
struct E {
    int k;
    LL c;
    E(){}
    E( int _k, LL _c ):k(_k),c(_c){}
} es[FM];

struct Flow {
    int n,m;
    int dis[FN];
    int qq[FN],qr,ql;
    vector<int> e[FN];
    void init( int _n ) {
        n=_n; m=0;
        for ( int i=0; i<n; i++ ) e[i]=vector<int>();
    }
    void add_edge( int a, int b, LL c) {
        e[a].push_back(m); es[m]=E(b,c); m++;
        e[b].push_back(m); es[m]=E(a,0); m++;
    }
    bool BFS() {
        memset(dis,-1,n*sizeof(int));
        ql=qr=0;
        qq[qr++]=0;
        dis[0]=0;
        while ( ql!=qr && dis[n-1]==-1 ) {
            int p=qq[ql++];
            FOR(it,e[p]) {
                E ee=es[*it];
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
        FOR(it,e[p]) {
            E &ee=es[*it];
            if ( ee.c==0 || dis[p]+1!=dis[ee.k] ) continue;
            tmp=go(ee.k,min(c-ret,ee.c));
            ret+=tmp; ee.c-=tmp; es[(*it)^1].c+=tmp;
            if ( ret==c ) break;
        }
        if ( ret==0 ) dis[p]=-1;
        return ret;
    }
    LL maxflow() {
        LL ret=0;
        while ( BFS() ) ret+=go(0,1LL<<60);
        return ret;
    }
} flow;
VPII e[1111];
int ev[31111];
VI an;
int mi;
int s,t;
int bk[1111],id,me[1111];
int xx[31111],yy[31111],v[31111];
int dfs(int x,int lt){
    bk[x]=me[x]=++id;
    int ret=(x==t);
    REP(i,SZ(e[x])){
        if(e[x][i].S==lt)continue;
        int y=e[x][i].F;
        if(me[y]){
            bk[x]=min(bk[x],me[y]);
        }
        else{
            int gg=dfs(y,e[x][i].S);
            ret|=gg;
            if(bk[y]>me[x]&&gg){
                if(v[e[x][i].S]<mi){
                    mi=v[e[x][i].S];
                    an.clear();
                    an.PB(e[x][i].S);
                }
                v[e[x][i].S]=-1;
            }
            bk[x]=min(bk[x],bk[y]);
        }
    }
    return ret;
}
int main(){
    mi=INF;
    DRII(n,m);
    RII(s,t);
    REPP(i,1,m+1){
        RIII(xx[i],yy[i],v[i]);
        e[xx[i]].PB(MP(yy[i],i));
        e[yy[i]].PB(MP(xx[i],i));
    }
    if(!dfs(s,0)){
        puts("0\n0");
        return 0;
    }
    flow.init(n+2);
    flow.add_edge(0,s,(LL)(1e12));
    flow.add_edge(t,n+1,(LL)(1e12));
    REPP(i,1,m+1){
        if(v[i]!=-1){
            flow.add_edge(xx[i],yy[i],(LL)(1e10)+v[i]);
            flow.add_edge(yy[i],xx[i],(LL)(1e10)+v[i]);
        }
        else{
            flow.add_edge(yy[i],xx[i],(LL)(1e12));
            flow.add_edge(xx[i],yy[i],(LL)(1e12));
        }
    }
    LL res=flow.maxflow();
    if(res-((LL)(1e10))*2<mi){
        mi=res-((LL)(1e10))*2;
        an.clear();
        REPP(i,1,m+1){
            if((flow.dis[xx[i]]==-1)^(flow.dis[yy[i]]==-1))an.PB(i);
        }
    }
    if(mi==INF)puts("-1");
    else{
        printf("%d\n",mi);
        printf("%d\n",SZ(an));
        REP(i,SZ(an)){
            if(i)printf(" ");
            printf("%d",an[i]);
        }
        puts("");
    }
    return 0;
}