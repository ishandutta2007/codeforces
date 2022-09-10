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
const int INF = 1e9+7;
const int SIZE = 1e5+10;
typedef PII MYTYPE;
struct data{
    MYTYPE v;
    int id;
    data(MYTYPE _v,int _id):v(_v),id(_id){}
    bool operator<(const data& b)const{return v>b.v;}
};
struct Dijkstra{
    vector<pair<int,int> >e[SIZE];
    MYTYPE mi[SIZE];
    bool used[SIZE];
    int n,tt,lt[SIZE];
    void init(int _n){
        n=_n;
        REP(i,n+1)e[i].clear();
    }
    void add_edge(int x,int y,int v){
        e[x].PB(MP(y,v));
        e[y].PB(MP(x,v));
    }
    void dis(int st,int ed){
        priority_queue<data>qq;
        REP(i,n+1)mi[i]=MP(INF,INF),used[i]=0;
        mi[st]=MP(0,0);
        qq.push(data(MP(0,0),st));
        while(!qq.empty()){
            data now=qq.top();qq.pop();
            if(used[now.id])continue;
            if(now.id==ed)return;
            used[now.id]=1;
            REP(i,SZ(e[now.id])){
                int y=e[now.id][i].F;
                if(mi[y]>MP(now.v.F+1,now.v.S+1-e[now.id][i].S)){
                    mi[y]=MP(now.v.F+1,now.v.S+1-e[now.id][i].S);
                    lt[y]=now.id;
                    qq.push(data(mi[y],y));
                }
            }
        }
        return ;
    }
    void solve(){
        set<PII>use;
        int now=n;
        while(now!=1){
            use.insert(MP(min(lt[now],now),max(lt[now],now)));
            now=lt[now];
        }
        vector<int>an;
        REPP(i,1,n+1){
            REP(j,SZ(e[i]))
                if(e[i][j].F>i){
                    if(use.count(MP(i,e[i][j].F))){
                        if(e[i][j].S==0){
                            an.PB(i);
                            an.PB(e[i][j].F);
                            an.PB(1);
                        }
                    }
                    else{
                        if(e[i][j].S==1){
                            an.PB(i);
                            an.PB(e[i][j].F);
                            an.PB(0);
                        }
                    }
                }
        }
        printf("%d\n",SZ(an)/3);
        REP(i,SZ(an)){
            printf("%d%c",an[i],i%3==2?'\n':' ');
        }
    }
}dij;
int main(){
    DRII(n,m);
    dij.init(n);
    REP(i,m){
        DRIII(x,y,v);
        dij.add_edge(x,y,v);
    }
    dij.dis(1,n);
    dij.solve();
    return 0;
}