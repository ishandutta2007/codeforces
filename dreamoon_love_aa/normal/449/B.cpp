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
#define F first
#define S second
typedef long long LL;
using namespace std;
const int SIZE = 1e5+5;
struct data{
    int x;
    LL v;
    data(int _x=0,LL _v=0):x(_x),v(_v){}
    bool operator<(const data& b)const{return v>b.v;}
};
vector<pair<int,int> >e[SIZE];
int deg[SIZE],mi[SIZE],dp[SIZE],have[SIZE],num[SIZE];
LL v[SIZE];
int main(){
    int an=0;
    DRIII(N,M,K);
    REPP(i,1,N+1)have[i]=1e9+5;
    REP(i,M){
        DRIII(x,y,v);
        if(x==1)have[y]=min(have[y],v);
        if(y==1)have[x]=min(have[x],v);
        e[x].PB(MP(y,v));
        e[y].PB(MP(x,v));
    }
    REPP(i,1,N+1)mi[i]=1e9+5;
    REP(i,K){
        DRII(y,v);
        e[1].PB(MP(y,v));
        deg[y]++;
        if(mi[y]>v){
            mi[y]=v;
            num[y]=1;
        }
        else if(mi[y]==v)num[y]++;
    }
    priority_queue<data>qq;
    qq.push(data(1,0));
    MS1(v);
    v[1]=0;
    while(!qq.empty()){
        data now=qq.top();qq.pop();
        if(now.v>v[now.x]){
            continue;
        }
        REP(i,SZ(e[now.x])){
            int y=e[now.x][i].F;
            LL nv=e[now.x][i].S;
            if(v[y]==-1||v[y]>nv+now.v){
                dp[y]=1;
                v[y]=nv+now.v;
                qq.push(data(y,nv+now.v));
            }
            else if(v[y]==nv+now.v){
                dp[y]++;
            }
        }
    }
    REPP(i,2,N+1){
        if(deg[i]>0){
            if(v[i]==mi[i]&&dp[i]==num[i])an+=deg[i]-1;
            else an+=deg[i];
        }
    }
    cout<<an<<endl;
    return 0;
}