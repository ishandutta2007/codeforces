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
const int SIZE = 2e5+10;
struct Union_Find{
    int d[SIZE],num[SIZE];
    void init(int n){
        REP(i,n+1)d[i]=i,num[i]=1;
    }
    int find(int x){
        return (x!=d[x])?(d[x]=find(d[x])):x;
    }
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        if(num[x]<=num[y]){
            num[y]+=num[x];
            d[x]=y;
        }
        else{
            num[x]+=num[y];
            d[y]=x;
        }
        return 1;
    }
}U;
int w[SIZE],c[SIZE];
// 1-based
vector<int>e[SIZE],e_id[SIZE];
int jump[18][SIZE],lv[SIZE];
PII ma_w[18][SIZE];
void __init(int x,int lt){
    jump[0][x]=lt;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y!=lt){
            ma_w[0][y]=MP(w[e_id[x][i]],e_id[x][i]);
            lv[y]=lv[x]+1;
            __init(y,x);
        }
    }
}
void add_edge(int x,int y,int id){
    e[x].PB(y);
    e_id[x].PB(id);
    e[y].PB(x);
    e_id[y].PB(id);
}
int adv(int x,int v,PII& ret){
    for(int i=0;(1<<i)<=v;i++){
        if((v>>i)&1){
            ret=max(ret,ma_w[i][x]);
            x=jump[i][x];
        }
    }
    return x;
}
PII lca(int x,int y){
    PII ret=MP(-1,-1);
    if(lv[x]>lv[y])x=adv(x,lv[x]-lv[y],ret);
    else y=adv(y,lv[y]-lv[x],ret);
    if(x==y)return ret;
    for(int i=17;i>=0;i--){
        if(jump[i][x]!=jump[i][y]){
            ret=max(ret,ma_w[i][x]);
            ret=max(ret,ma_w[i][y]);
            x=jump[i][x];y=jump[i][y];
        }
    }
    ret=max(ret,ma_w[0][x]);
    ret=max(ret,ma_w[0][y]);
    return ret;
}
int N;
void build(int root){
    __init(root,root);
    REPP(i,1,18){
        REPP(x,1,N+1){
            jump[i][x]=jump[i-1][jump[i-1][x]];
            ma_w[i][x]=max(ma_w[i-1][x],ma_w[i-1][jump[i-1][x]]);
        }
    }
}
struct EDGE{
    int x,y,id;
    EDGE(int _x=0,int _y=0,int _id=0):x(_x),y(_y),id(_id){}
    bool operator<(const EDGE& b)const{return w[id]<w[b.id];}
}ee[SIZE];
bool in[SIZE];
int main(){
    DRII(n,m);
    N=n;
    REP(i,m)RI(w[i+1]);
    REP(i,m)RI(c[i+1]);
    REP(i,m){
        DRII(x,y);
        ee[i]=EDGE(x,y,i+1);
    }
    DRI(SS);
    sort(ee,ee+m);
    U.init(n);
    LL sum=0;
    REP(i,m){
        if(U.uu(ee[i].x,ee[i].y)){
            add_edge(ee[i].x,ee[i].y,ee[i].id);
            sum+=w[ee[i].id];
            in[i]=1;
        }
    }
    int an_id=-1,match_id=-1;
    LL mi=sum+10;
    build(1);
    REP(i,m){
        if(in[i]){
            if(sum-SS/c[ee[i].id]<mi){
                mi=sum-SS/c[ee[i].id];
                an_id=ee[i].id;
                match_id=-1;
            }
        }
        else{
            PII ret=lca(ee[i].x,ee[i].y);
            if(sum+w[ee[i].id]-ret.F-SS/c[ee[i].id]<mi){
                mi=sum+w[ee[i].id]-ret.F-SS/c[ee[i].id];
                an_id=ee[i].id;
                match_id=ret.S;
            }
        }
    }
    printf("%I64d\n",mi);
    REP(i,m){
        if((in[i]&&match_id!=ee[i].id)||ee[i].id==an_id){
            printf("%d ",ee[i].id);
            if(ee[i].id==an_id){
                printf("%d\n",w[ee[i].id]-SS/c[ee[i].id]);
            }
            else printf("%d\n",w[ee[i].id]);
        }
    }
    return 0;
}