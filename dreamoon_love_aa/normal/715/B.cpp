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
const int INF = 1e9+7;
const int SIZE = 1e4+10;
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
        e[x].PB(MP(y,max(1LL,v)));
        e[y].PB(MP(x,max(1LL,v)));
    }
    MYTYPE dis(int st,int ed){
        priority_queue<data>qq;
        REP(i,n+1)mi[i]=(LL)INF*INF,used[i]=0;
        mi[st]=0;
        qq.push(data(0,st));
        while(!qq.empty()){
            data now=qq.top();qq.pop();
            if(used[now.id])continue;
            if(now.id==ed)return mi[ed];
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
int input[SIZE][3];
void pt(int x,int y,int v){
    printf("%d %d %d\n",x,y,v);
}
int main(){
    DRIII(n,m,L);
    DRII(s,t);
    dij.init(n);
    REP(i,m){
        REP(j,3)RI(input[i][j]);
        dij.add_edge(input[i][0],input[i][1],input[i][2]);
    }
    if(dij.dis(s,t)>L){
        puts("NO");
        return 0;
    }
    LL ll=0,rr=(LL)m*INF;
    while(ll<=rr){
        LL mm=(ll+rr)/2;
        int id=mm/INF,v=mm%INF+1;
        dij.init(n);
        REP(i,m){
            if(!input[i][2]){
                if(i<id)dij.add_edge(input[i][0],input[i][1],INF);
                else if(i>id)dij.add_edge(input[i][0],input[i][1],1);
                else dij.add_edge(input[i][0],input[i][1],v);
            }
            else{
                dij.add_edge(input[i][0],input[i][1],input[i][2]);
            }
        }
        LL res=dij.dis(s,t);
        if(res==L){
            puts("YES");
            REP(i,m){
                if(!input[i][2]){
                    if(i<id)pt(input[i][0],input[i][1],INF);
                    else if(i>id)pt(input[i][0],input[i][1],1);
                    else pt(input[i][0],input[i][1],v);
                }
                else{
                    pt(input[i][0],input[i][1],input[i][2]);
                }
            }
            return 0;
        }
        if(res>L)rr=mm-1;
        else ll=mm+1;
    }
    puts("NO");
    return 0;
}