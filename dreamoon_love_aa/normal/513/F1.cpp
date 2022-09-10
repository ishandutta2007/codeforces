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
const int SIZE = 1e3+10;
// template end here
#define FN 500010
#define FM 4200010
#define INF 1034567890
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
int n,m;
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
char s[24][24];
int id[24][24];
struct data{
    int x,y,t;
    void scan(){RIII(x,y,t);x--;y--;}
}males[300],females[300];
int tt,used[24][24];
LL dis[24][24];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool Out(int x,int y){
    return x<0||y<0||x>=n||y>=m;
}
void BFS(int x,int y,int me,int ty,LL bound,int v){
    queue<PII>bfs;
    used[x][y]=tt;
    dis[x][y]=0;
    bfs.push(MP(x,y));
    while(SZ(bfs)){
        x=bfs.front().F;
        y=bfs.front().S;
        if(ty){
            flow.add_edge(id[x][y]+1,me,1);
        }
        else{
            flow.add_edge(me,id[x][y],1);
        }
        bfs.pop();
        REP(k,4){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(Out(nx,ny))continue;
            if(s[nx][ny]=='#')continue;
            if(used[nx][ny]==tt)continue;
            used[nx][ny]=tt;
            dis[nx][ny]=dis[x][y]+v;
            if(dis[nx][ny]<=bound){
                bfs.push(MP(nx,ny));
            }
        }
    }
}
bool valid(LL v,int N,int flowN){
    flow.init(flowN);
    REPP(i,2*N+1,flowN-1){
        flow.add_edge(i,i+1,1);
        i++;
    }
    REP(i,N){
        flow.add_edge(0,i+1,1);
        flow.add_edge(i+1+N,flowN-1,1);
    }
    REP(i,N){
        tt++;
        BFS(males[i].x,males[i].y,i+1,0,v,males[i].t);
        tt++;
        BFS(females[i].x,females[i].y,i+N+1,1,v,females[i].t);
    }
    return flow.maxflow()==N;
}
int main(){
    RII(n,m);
    DRII(malesN,femalesN);
    if(abs(malesN-femalesN)!=1){
        puts("-1");
        return 0;
    }
    REP(i,n)RS(s[i]);
    if(malesN<femalesN)males[malesN].scan();
    else females[femalesN].scan();
    REP(i,malesN)
        males[i].scan();
    REP(i,femalesN)
        females[i].scan();
    int N=max(malesN,femalesN);
    int flowN;
    {
        int now=2*N+1;
        REP(i,n)REP(j,m){
            if(s[i][j]=='.'){
                id[i][j]=now;
                now+=2;
            }
        }
        flowN=now+1;
    }
    LL ll=0,rr=4e12;
    while(ll<rr){
        LL mm=(ll+rr)>>1;
        if(valid(mm,N,flowN))rr=mm;
        else ll=mm+1;
    }
    if(ll==(LL)(4e12))ll=-1;
    cout<<ll<<endl;
    return 0;
}