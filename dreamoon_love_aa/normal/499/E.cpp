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
const int SIZE = 1e5+10;
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
vector<int>pp;
void prime_init(){
    p[1]=1;
    for(int i=2;i<SIZE;i++){
        if(!p[i]){
            pp.PB(i);
            for(int j=i;j<SIZE;j+=i){
                if(!p[j])p[j]=i;
            }
        }
    }
}
map<PII,int>num;
int No,st[101];
vector<int>fac[101];
int main(){
    prime_init();
    DRII(n,m);
    REP(i,n){
        DRI(x);
        for(int j=0;pp[j]*pp[j]<=x;j++){
            if(x%pp[j]==0){
                fac[i].PB(pp[j]);
                int cnt=0;
                while(x%pp[j]==0){
                    cnt++;
                    x/=pp[j];
                }
                num[MP(i,pp[j])]=cnt;
            }
        }
        if(x!=1){
            fac[i].PB(x);
            num[MP(i,x)]=1;
        }
        if(i)st[i]=st[i-1]+SZ(fac[i-1]);
    }
    flow.init(st[n-1]+SZ(fac[n-1])+2);
    REP(i,n){
        if(i&1){
            REP(j,SZ(fac[i])){
                flow.add(0,st[i]+j+1,num[MP(i,fac[i][j])]);
            }
        }
        else{
            REP(j,SZ(fac[i])){
                flow.add(st[i]+j+1,flow.n-1,num[MP(i,fac[i][j])]);
            }
        }
    }
    while(m--){
        DRII(x,y);
        x--;y--;
        if(y&1)swap(x,y);
        int rr=0;
        REP(i,SZ(fac[x])){
            while(rr<SZ(fac[y])&&fac[y][rr]<fac[x][i])rr++;
            if(rr<SZ(fac[y])&&fac[x][i]==fac[y][rr]){
                flow.add(st[x]+i+1,st[y]+rr+1,INF);
            }
        }
    }
    printf("%d\n",flow.maxflow());
    return 0;
}