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
const int SIZE = 1e5+10;
struct Union_Find{
    int d[SIZE],num[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1;
    }
    int find(int x){
        return (x!=d[x])?(d[x]=find(d[x])):x;
    }
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        if(num[x]>num[y])swap(x,y);
        num[y]+=num[x];
        d[x]=y;
        return 1;
    }
}pU,sU;
VI e[SIZE];
VI root;
// 1-based
int jump[20][SIZE],lv[SIZE];
void __init(int x,int lt){
    jump[0][x]=lt;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y!=lt){
            lv[y]=lv[x]+1;
            __init(y,x);
        }
    }
}
int adv(int x,int v){
    for(int i=0;(1<<i)<=v;i++){
        if((v>>i)&1)x=jump[i][x];
    }
    return x;
}
int lca(int x,int y){
    if(lv[x]>lv[y])x=adv(x,lv[x]-lv[y]);
    else y=adv(y,lv[y]-lv[x]);
    if(x==y)return x;
    for(int i=19;i>=0;i--)
        if(jump[i][x]!=jump[i][y]){x=jump[i][x];y=jump[i][y];}
    return jump[0][x];
}
void build(int N){
    REP(i,SZ(root)){
        __init(root[i],root[i]);
    }
    REPP(i,1,20){
        REPP(x,1,N+1)
            jump[i][x]=jump[i-1][jump[i-1][x]];
    }
}
VPII qq[SIZE];
VI qid[SIZE];
int an[SIZE];
int in_queue[SIZE],group_in_queue[SIZE];
/*
void dfs(int x,int lt){
    in_queue[x]++;
    group_in_queue[U.find(x)]++;
    REP(i,SZ(qq[x])){
        int ty=qq[x][i].S;
        int y=qq[x][i].F;
        if(ty==1){
            if(in_queue[y]&&U.find(x)==U.find(y))an[qid[x][i]]=1;
        }
        else{
            if(group_in_queue[U.find(y)]&&U.find(x)!=U.find(y))an[qid[x][i]]=1;
        }
    }
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y==lt)continue;
        dfs(y,x);
    }
    in_queue[x]--;
    group_in_queue[U.find(x)]--;
}
*/
int main(){
    DRI(n);
    sU.init(n+1);
    pU.init(n+1);
    REPP(i,1,n+1){
        DRII(p,ty);
        if(p==-1)root.PB(i);
        else{
            e[p].PB(i);
            if(ty==0)sU.uu(p,i);
            else pU.uu(p,i);
        }
    }
    build(n);
    DRI(q);
    REP(i,q){
        DRIII(ty,u,v);
        if(u==v)continue;
        int z=lca(u,v);
        if(ty==1){
            if(z==u&&sU.find(u)==sU.find(v))an[i]=1;
        }
        else{
            if(pU.find(z)==pU.find(v)&&sU.find(z)==sU.find(u)&&z!=v)an[i]=1;
        }
    }
    //REP(i,SZ(root))dfs(root[i],root[i]);
    REP(i,q)puts(an[i]?"YES":"NO");
    return 0;
}