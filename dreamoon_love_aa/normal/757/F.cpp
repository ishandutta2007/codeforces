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
const LL INF = 1e18; //INF should be enough large.
typedef long long MYTYPE;
// 1-based
vector<int>e[SIZE];
int jump[18][SIZE],lv[SIZE];
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
    for(int i=17;i>=0;i--)
        if(jump[i][x]!=jump[i][y]){x=jump[i][x];y=jump[i][y];}
    return jump[0][x];
}
void build(int x){
    REPP(i,1,18)jump[i][x]=jump[i-1][jump[i-1][x]];
}
struct data{
    MYTYPE v;
    int id;
    data(MYTYPE _v,int _id):v(_v),id(_id){}
    bool operator<(const data& b)const{return v>b.v;}
};
int stop[SIZE];
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
    void dis(int st){
        int an=0;
        priority_queue<data>qq;
        REP(i,n+1)mi[i]=INF,used[i]=0;
        mi[st]=0;
        jump[0][st]=st;
        build(st);
        qq.push(data(0,st));
        while(!qq.empty()){
            data now=qq.top();qq.pop();
            if(used[now.id])continue;
            used[now.id]=1;
            REP(i,SZ(e[now.id])){
                int y=e[now.id][i].F;
                if(mi[y]>now.v+e[now.id][i].S){
                    mi[y]=now.v+e[now.id][i].S;
                    jump[0][y]=now.id;
                    qq.push(data(mi[y],y));
                }
                else if(mi[y]==now.v-e[now.id][i].S){
                    jump[0][now.id]=lca(jump[0][now.id],y);
                }
            }
            if(now.id!=st){
                lv[now.id]=lv[jump[0][now.id]]+1;
                build(now.id);
                int gogo=adv(now.id,lv[now.id]-1);
                stop[gogo]++;
                an=max(an,stop[gogo]);
            }
        }
        printf("%d\n",an);
    }
}dij;
int main(){
    DRIII(n,m,s);
    dij.init(n);
    REP(i,m){
        DRIII(x,y,v);
        dij.add_edge(x,y,v);
    }
    dij.dis(s);
    return 0;
}