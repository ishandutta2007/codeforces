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
VI cc[301][301],cn[301];
int need_id,an[301],xx[301],yy[301];
PII need[1000001];
int to[301];
bool used[301];
bool match(PII X,PII Y){
    if(X.F!=Y.F&&Y.F!=-1)return 0;
    if(X.S!=Y.S&&Y.S!=-1)return 0;
    return 1;
}
void go(int ma_id,int ma_hi,int n){
    if(ma_id!=1&&SZ(cc[ma_id][0])==0)return;
    VPII qq;
    int oo=need_id;
    for(int i=ma_hi;i>=0;i--){
        if(SZ(cc[ma_id][i])==0){
            need[++need_id]=MP(ma_id,i);
            cc[ma_id][i].PB(-need_id);
            qq.PB(MP(ma_id,i));
        }
    }
    //REPP(i,1,need_id+1)printf("[%d,%d]\n",need[i].F,need[i].S);
    if(need_id>n){
        REP(i,SZ(qq))cc[qq[i].F][qq[i].S].pop_back();
        need_id=oo;
        return;
    }
    flow.init(need_id+n+2);
    REPP(i,1,n+1)flow.add_edge(need_id+i,need_id+n+1,1);
    REPP(i,1,need_id+1){
        flow.add_edge(0,i,1);
        REPP(j,1,n+1){
            if(used[j])continue;
            if(match(need[i],MP(yy[j],xx[j])))flow.add_edge(i,need_id+j,1);
        }
    }
    if(flow.maxflow()!=need_id){
        need_id=oo;
        return;
    }
    for(int i=0;i<flow.m;i+=2){
        if(es[i].k>need_id&&es[i+1].k<=need_id&&es[i].c==0){
            used[es[i].k-need_id]=1;
            to[es[i+1].k]=es[i].k-need_id;
        }
    }
    REPP(i,1,n+1){
        REP(j,n){
            REP(k,SZ(cc[i][j])){
                if(cc[i][j][k]<0)cc[i][j][k]=to[-cc[i][j][k]];
            }
        }
    }
    REPP(i,1,n+1){
        if(!used[i]){
            used[i]=1;
            if(xx[i]==-1&&yy[i]==-1)cc[1][0].PB(i);
            else if(yy[i]!=-1)cc[yy[i]][1].PB(i);
            else if(xx[i]!=-1){
                if(xx[i]==0)cc[1][0].PB(i);
                else cc[ma_id][xx[i]].PB(i);
            }
        }
    }
    REPP(i,1,n+1){
        REP(j,SZ(cc[i][0])){
            if(j%i==0)an[cc[i][0][j]]=cc[i][0][j+i-1];
            else an[cc[i][0][j]]=cc[i][0][j-1];
        }
        REPP(j,1,n){
            REP(k,SZ(cc[i][j]))an[cc[i][j][k]]=cc[i][j-1][0];
        }
    }
    REPP(i,1,n+1)printf("%d%c",an[i]," \n"[i==n]);
    exit(0);
}
int main(){
    DRI(n);
    int ma_hi=-1;
    REPP(i,1,n+1){
        char s1[20],s2[20];
        RS(s1);RS(s2);
        int x=-1,y=-1;
        if(s1[0]!='?')x=atoi(s1);
        if(s2[0]!='?')y=atoi(s2);
        if(x!=-1&&y!=-1){
            cc[y][x].PB(i);
            used[i]=1;
        }
        else if(y!=-1)cn[y].PB(i);
        xx[i]=x;
        yy[i]=y;
        ma_hi=max(ma_hi,x);
    }
    int mi=10000,ma_id=1;
    REPP(i,1,n+1){
        int hi=n-1;
        while(hi>=0&&SZ(cc[i][hi])==0)hi--;
        while(hi>=0){
            if(!SZ(cc[i][hi])){
                need[++need_id]=MP(i,hi);
                cc[i][hi].PB(-need_id);
            }
            hi--;
        }
        if(SZ(cn[i])&&SZ(cc[i][0])==0){
            need[++need_id]=MP(i,0);
            cc[i][0].PB(-need_id);
        }
        while(SZ(cc[i][0])%i){
            need[++need_id]=MP(i,0);
            cc[i][0].PB(-need_id);
        }
    }
    for(int ker=1;ker<=n;ker++){
        go(ker,ma_hi,n);
    }
    return 0*puts("-1");
}