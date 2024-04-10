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
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
#define FN 500010
#define FM 4200010
#define INF 1034567890
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
struct E {
    int k,c;
    E(){}
    E( int _k, int _c ):k(_k),c(_c){}
} es[FM];

struct Flow {
    int n,m,dis[FN];
    int qq[FN],qr,ql;
    vector<int> e[FN];
    void init( int _n ) {
        n=_n; m=0;
        for ( int i=0; i<n; i++ ) e[i]=vector<int>();
    }
    void add_edge( int a, int b, int c ) {
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
            tmp=go(ee.k,min(c-ret,(LL)ee.c));
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
VPII e[SIZE];
int cc[SIZE];
int lat[SIZE],id[SIZE];
bool in[SIZE],used[SIZE],edge_used[SIZE];
int M;
void dfs(int x,int lt){
    in[x]=1;
    used[x]=1;
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(y==lt)continue;
        if(in[y]){
            int me=x,cnt=0;
            flow.add_edge(M+e[x][i].S,M*2+e[x][i].S,1);
            edge_used[e[x][i].S]=1;
            do{
                cnt++;
                flow.add_edge(M+id[me],M*2+e[x][i].S,1);
                edge_used[id[me]]=1;
                me=lat[me];
            }while(me!=y);
            flow.add_edge(M*2+e[x][i].S,M*3+1,cnt);
        }
        else if(!used[y]){
            id[y]=e[x][i].S;
            lat[y]=x;
            dfs(y,x);
        }
    }
    in[x]=0;
}
int main(){
    DRII(n,m);
    M=m;
    flow.init(m+m+m+2);
    REPP(i,1,m+1){
        DRIII(x,y,v);
        cc[i]=v;
        e[x].PB(MP(y,i));
        e[y].PB(MP(x,i));
        flow.add_edge(0,i,1);
        flow.add_edge(v,m+i,1);
    }
    dfs(1,1);
    REPP(i,1,m+1){
        if(!edge_used[i]){
            flow.add_edge(m+i,3*m+1,1);
        }
    }
    printf("%d\n",flow.maxflow());
    return 0;
}