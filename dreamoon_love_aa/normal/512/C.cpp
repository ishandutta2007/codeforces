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
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
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
    void add( int a, int b, int c ) {
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
int p[SIZE];
void prime_init(){
    for(int i=2;i<SIZE;i++){
        if(!p[i]){
            for(int j=i+i;j<SIZE;j+=i){
                if(!p[j])p[j]=i;
            }
        }
    }
}
bool is_prime(int x){
    if(x==1)return 1;
    return p[x]==x;
}
int a[222],gn,used[222];
vector<int>gg[222];
void dfs(int x){
    if(used[x])return;
    gg[gn].PB(x);
    used[x]=1;
    REP(i,SZ(flow.e[x])){
        int eid=flow.e[x][i];
        if(es[eid].k&&es[eid].k!=flow.n-1){
            if(a[x-1]%2==0){
                if(es[eid].c==0)dfs(es[eid].k);
            }
            else{
                if(es[eid].c==1)dfs(es[eid].k);
            }
        }
    }
}
int main(){
    prime_init();
    DRI(n);
    REP(i,n){
        RI(a[i]);
    }
    flow.init(2+n);
    REP(i,n){
        if(a[i]%2==0)flow.add(0,i+1,2);
        else flow.add(i+1,n+1,2);
    }
    REP(i,n){
        REP(j,n){
            if(i==j)continue;
            if(!p[a[i]+a[j]]){
                if(a[i]%2==0)flow.add(i+1,j+1,1);
            }
        }
    }
    if(flow.maxflow()!=n)puts("Impossible");
    else{
        REP(i,n){
            if(!used[i+1]){
                dfs(i+1);
                gn++;
            }
        }
        printf("%d\n",gn);
        REP(i,gn){
            printf("%d",SZ(gg[i]));
            REP(j,SZ(gg[i]))printf(" %d",gg[i][j]);
            puts("");
        }
    }
    return 0;
}