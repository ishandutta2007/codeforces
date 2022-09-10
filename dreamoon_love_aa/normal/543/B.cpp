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
const int SIZE = 1e6+10;
// template end here
typedef int MYTYPE;
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
    void add_edge(int x,int y,MYTYPE v=1){
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
int dd[3001][3001];
int main(){
    DRII(n,m);
    dij.init(n);
    REP(i,m){
        DRII(x,y);
        x--;y--;
        dij.add_edge(x,y);
    }
    DRIII(st1,ed1,L1);
    st1--;ed1--;
    DRIII(st2,ed2,L2);
    st2--;ed2--;
    REP(i,n){
        dij.dis(i);
        REP(j,n)dd[i][j]=dij.mi[j];
    }
    if(dd[st1][ed1]>L1||dd[st2][ed2]>L2)puts("-1");
    else{
        int res=dd[st1][ed1]+dd[st2][ed2];
        REP(i,n)REP(j,n){
            int now=dd[i][j];
            if(now>=INF)continue;
            int v1=min(dd[st1][i]+dd[j][ed1],dd[st1][j]+dd[i][ed1]);
            if(v1+now>L1)continue;
            int v2=min(dd[st2][i]+dd[j][ed2],dd[st2][j]+dd[i][ed2]);
            if(v2+now>L2)continue;
            res=min(res,now+v1+v2);
        }
        printf("%d\n",m-res);
    }
    return 0;
}