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
int mii[SIZE],ma[SIZE];
#define INF 1034567890
struct EDGE{
        int y,c,v;
        EDGE(int _y=0,int _c=0,int _v=0):y(_y),c(_c),v(_v){}
}es[1000000];
vector<int>e[10000];
int en;
int EE; // sink
void flow_clear(int _EE){
    EE=_EE;
    REP(i,EE+1)e[i].clear();
    en=0;
}
void add_edge(int x,int y,int c,int v){
        e[x].PB(en);
        es[en++]=EDGE(y,c,v);
        e[y].PB(en);
        es[en++]=EDGE(x,0,-v);
        
}
int mi[10000],lt[10000],bfs[1000000],used[10000];
int flow(){
        REP(i,EE+1)mi[i]=INF,used[i]=0;
        mi[EE]=INF;
        bfs[0]=0;
        mi[0]=0;
        int rr=1;
        for(int i=0;i<rr;i++){
                int x=bfs[i];
                used[x]=0;
                REP(j,SZ(e[x])){
                        int r=e[x][j];
                        if(es[r].c>0&&mi[x]+es[r].v<mi[es[r].y]){
                                mi[es[r].y]=mi[x]+es[r].v;
                                lt[es[r].y]=r;
                                if(!used[es[r].y]){
                                        used[es[r].y]=1;
                                        bfs[rr++]=es[r].y;
                                }
                        }
                }
        }
        if(mi[EE]==INF)return -1;
        int now=EE;
        while(now){
                int r=lt[now];
                es[r].c--;
                es[r^1].c++;
                now=es[r^1].y;
        }
        return mi[EE];
}
int solve(int nn){
        int v=0;
        REP(i,nn)v+=flow();
        return v;
}
int main(){
    DRII(n,q);
    EE=2*n+1;
    REPP(i,1,n+1){
        mii[i]=1;
        ma[i]=n;
    }
    REP(i,q){
        DRIII(ty,x,y);DRI(v);
        REPP(j,x,y+1){
            if(ty==1)mii[j]=max(mii[j],v);
            else ma[j]=min(ma[j],v);
        }
    }
    REPP(i,1,n+1)
        if(ma[i]<mii[i])return 0*puts("-1");
    REPP(i,1,n+1){
        add_edge(0,i,1,0);
        REPP(j,mii[i],ma[i]+1){
            add_edge(i,n+j,1,0);
        }
    }
    REPP(i,1,n+1){
        REPP(j,1,n+1){
            add_edge(n+i,n+n+1,1,j*2-1);
        }
    }
    printf("%d\n",solve(n));
    return 0;
}