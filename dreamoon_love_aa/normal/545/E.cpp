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
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
// template end here

void print_array(vector<int>&arr){
    REP(i,SZ(arr)){
        if(i)printf(" ");
        printf("%d",arr[i]);
    }
    puts("");
}
const LL INF = 1e18;
typedef long long MYTYPE;
struct data{
    MYTYPE v;
    int id;
    data(MYTYPE _v,int _id):v(_v),id(_id){}
    bool operator<(const data& b)const{return v>b.v;}
};
struct Dijkstra{
    vector<pair<int,MYTYPE> >e[SIZE];
    vector<int>eid[SIZE];
    MYTYPE mi[SIZE];
    bool used[SIZE];
    int n,tt;
    void init(int _n){
        n=_n;
        REP(i,n+1)e[i].clear();
    }
    void add_edge(int x,int y,MYTYPE v,int _id){
        e[x].PB(MP(y,v));
        eid[x].PB(_id);
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
int main(){
    DRII(n,m);
    dij.init(n);
    REP(i,m){
        DRIII(x,y,v);
        dij.add_edge(x-1,y-1,v,i+1);
        dij.add_edge(y-1,x-1,v,i+1);
    }
    DRI(st);
    st--;
    dij.dis(st);
    LL res=0;
    vector<int>qq;
    REP(i,n){
        if(i==st)continue;
        LL mi=1e12;
        int id=-1;
        REP(j,SZ(dij.e[i])){
            int y=dij.e[i][j].F;
            if(dij.e[i][j].S+dij.mi[y]==dij.mi[i]){
                if(mi>dij.e[i][j].S){
                    mi=min(dij.e[i][j].S,mi);
                    id=dij.eid[i][j];
                }
            }
        }
        res+=mi;
        qq.PB(id);
    }
    cout<<res<<endl;
    print_array(qq);
    return 0;
}