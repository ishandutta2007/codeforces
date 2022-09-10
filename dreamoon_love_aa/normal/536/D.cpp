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
const LL INF = 1e15;
const int SIZE = 2e3+10;
typedef long long MYTYPE;
struct data{
    MYTYPE v;
    int id;
    data(MYTYPE _v,int _id):v(_v),id(_id){}
    bool operator<(const data& b)const{return v>b.v;}
};
struct Dijkstra{
    vector<pair<int,MYTYPE> >e[SIZE];
    MYTYPE mi[SIZE];
    bool used[SIZE];
    int n,tt;
    void init(int _n){
        n=_n;
        REP(i,n+1)e[i].clear();
    }
    void add_edge(int x,int y,MYTYPE v){
        e[x].PB(MP(y,v));
        e[y].PB(MP(x,v));
    }
    MYTYPE dis(int st){
        priority_queue<data>qq;
        REP(i,n+1)mi[i]=INF,used[i]=0;
        mi[st]=0;
        qq.push(data(0,st));
        while(!qq.empty()){
            data now=qq.top();qq.pop();
            if(used[now.id])continue;
            used[now.id]=1;
            REP(i,SZ(e[now.id])){
                int y=e[now.id][i].F;
                if(mi[y]>now.v+e[now.id][i].S){
                    mi[y]=now.v+e[now.id][i].S;
                    qq.push(data(mi[y],y));
                }
            }
        }
        return -1;
    }
}dij;
int v[SIZE];
pair<LL,LL> pp[SIZE];
LL xx[SIZE],yy[SIZE];
int xxn,yyn;
LL dp[SIZE][SIZE][2];
bool have[SIZE][SIZE];
bool rr[SIZE][SIZE];
bool uu[SIZE][SIZE];
bool ru[SIZE][SIZE];
LL r_sum[SIZE][SIZE];
LL u_sum[SIZE][SIZE];
LL score[SIZE][SIZE];
int main(){
    DRII(n,m);
    DRII(st,ed);
    REP(i,n)RI(v[i+1]);
    dij.init(n);
    REP(i,m){
        DRIII(x,y,v);
        dij.add_edge(x,y,v);
    }
    dij.dis(st);
    REP(i,n)pp[i+1].F=dij.mi[i+1];
    dij.dis(ed);
    REP(i,n)pp[i+1].S=dij.mi[i+1];
    REPP(i,1,n+1){
        xx[xxn++]=pp[i].F;
        yy[yyn++]=pp[i].S;
    }
    sort(xx,xx+xxn);
    xxn=unique(xx,xx+xxn)-xx;
    REPP(i,1,n+1)pp[i].F=lower_bound(xx,xx+xxn,pp[i].F)-xx+1;
    
    sort(yy,yy+yyn);
    yyn=unique(yy,yy+yyn)-yy;
    REPP(i,1,n+1)pp[i].S=lower_bound(yy,yy+yyn,pp[i].S)-yy+1;
    REPP(i,1,n+1){
        have[pp[i].F][pp[i].S]=1;
        score[pp[i].F][pp[i].S]+=v[i];
    }
    /*REP(i,xxn+1)REP(j,yyn+1){
        if(have[i][j])printf("[%d,%d]=%d\n",i,j,score[i][j]);
    }*/
    REPP(i,1,xxn+1){
        for(int j=yyn;j>0;j--){
            if(rr[i][j+1]||have[i][j])rr[i][j]=1;
            r_sum[i][j]=score[i][j]+r_sum[i][j+1];
        }
    }
    REPP(j,1,yyn+1){
        for(int i=xxn;i>0;i--){
            if(uu[i+1][j]||have[i][j])uu[i][j]=1;
            u_sum[i][j]=score[i][j]+u_sum[i+1][j];
        }
    }
    for(int i=xxn;i>0;i--)for(int j=yyn;j>0;j--){
        if(ru[i+1][j]||rr[i][j])ru[i][j]=1;
    }
    REP(i,yyn+2)REP(k,2)dp[xxn+1][i][k]=INF;
    REP(i,xxn+2)REP(k,2)dp[i][yyn+1][k]=INF;
    for(int i=xxn;i>=1;i--){
        for(int j=yyn;j>=1;j--){
            if(!ru[i][j]){
                REP(k,2)dp[i][j][k]=0;
            }
            else{
                if(!rr[i][j])dp[i][j][0]=dp[i+1][j][0];
                else{
                    if(i==xxn)
                        dp[i][j][0]=r_sum[i][j];
                    else
                        dp[i][j][0]=max(dp[i+1][j][0]+r_sum[i][j],r_sum[i][j]-dp[i+1][j][1]);
                }
                if(!uu[i][j])dp[i][j][1]=dp[i][j+1][1];
                else{
                    if(j==yyn)
                        dp[i][j][1]=u_sum[i][j];
                    else
                        dp[i][j][1]=max(dp[i][j+1][1]+u_sum[i][j],u_sum[i][j]-dp[i][j+1][0]);
                }
            }
            //printf("(%I64d %I64d)   ",dp[i][j][0],dp[i][j][1]);
        }
        //puts("");
    }
    if(dp[1][1][0]>0)puts("Break a heart");
    else if(dp[1][1][0]==0)puts("Flowers");
    else puts("Cry");
    return 0;
}