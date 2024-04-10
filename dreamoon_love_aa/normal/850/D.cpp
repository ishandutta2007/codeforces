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
int C2[100];
int dp[32][2000][62],a[31];
int rn;
PII rd[100000];
char an[65][65];
void go(int m,int ss,int nn){
    printf("%d\n",nn);
    VI d;
    while(m){
        int u=dp[m][ss][nn];
        m--;
        REP(i,u)d.PB(a[m]);
        ss-=u*a[m];
        nn-=u;
    }
    int n=SZ(d);
    int ed=1+C2[SZ(d)]+SZ(d);
    flow.init(ed+1);
    REP(i,n)REP(j,i){
        rn++;
        rd[rn]=MP(j,i);
        flow.add_edge(0,rn,1);
        flow.add_edge(rn,C2[SZ(d)]+i+1,1);
        flow.add_edge(rn,C2[SZ(d)]+j+1,1);
    }
    REP(i,SZ(d)){
        flow.add_edge(C2[SZ(d)]+i+1,ed,d[i]);
    }
    flow.maxflow();
    REP(i,SZ(d))REP(j,SZ(d))an[i][j]='0';
    for(int i=0;i<flow.m;i+=2){
        int x=es[i+1].k;
        int y=es[i].k;
        if(x<=C2[SZ(d)]&&y>C2[SZ(d)]&&!es[i].c){
            int from=y-C2[SZ(d)]-1;
            int to=rd[x].F+rd[x].S-from;
            an[y-C2[SZ(d)]-1][to]='1';
        }
    }
    REP(i,SZ(d))puts(an[i]);
}
int main(){
    REP(i,100)C2[i]=i*(i-1)/2;
    DRI(m);
    REP(i,m)RI(a[i]);
    sort(a,a+m);
    dp[0][0][0]=INF;
    REP(i,m){
        int r=m-i-1;
        REP(ss,2000)REP(nn,62){
            if(!dp[i][ss][nn])continue;
            int now_ss=ss;
            for(int k=1;k+nn+r<=61;k++){
                now_ss+=a[i];
                if(now_ss>=C2[k+nn]){
                    dp[i+1][now_ss][k+nn]=k;
                }
                else break;
            }
        }
    }
    for(int i=1;i<=61;i++){
        if(dp[m][C2[i]][i]){
            go(m,C2[i],i);
            return 0;
        }
    }
    return 0*puts("=(");
}