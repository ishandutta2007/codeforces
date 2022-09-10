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
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
#define FN 2000010
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
int nxt[SIZE*2][26];
int nxt_ed;
char s[SIZE];
int used[SIZE*2],tt;
int main(){
    CASET{
        nxt_ed=1;
        DRI(n);
        VPII edge;
        tt++;
        MS0(nxt[0]);
        int node_cnt=0;
        REP(i,n){
            RS(s);
            int sn=LEN(s);
            int now1=0;
            int now2=0;
            REP(j,sn){
                int v=s[j]-'a';
                if(!nxt[now1][v]){
                    MS0(nxt[nxt_ed]);
                    nxt[now1][v]=nxt_ed++;
                }
                now1=nxt[now1][v];
                if(used[now1]!=tt){
                    used[now1]=tt;
                    node_cnt++;
                    if(j&1){
                        edge.PB(MP(0,now1));
                    }
                    else{
                        edge.PB(MP(now1,-1));
                    }
                }

                if(j){
                    if(!nxt[now2][v]){
                        MS0(nxt[nxt_ed]);
                        nxt[now2][v]=nxt_ed++;
                    }
                    now2=nxt[now2][v];
                    if(j&1){
                        edge.PB(MP(now1,now2));
                    }
                    else{
                        edge.PB(MP(now2,now1));
                    }
                }
            }
        }
        flow.init(nxt_ed+1);
        REP(i,SZ(edge)){
            int x=edge[i].F;
            int y=edge[i].S;
            if(y==-1)y=nxt_ed;
            flow.add_edge(x,y,1);
        }
        printf("%d\n",node_cnt-flow.maxflow());
    }
    return 0;
}