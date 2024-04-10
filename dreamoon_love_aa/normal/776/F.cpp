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
const int SIZE = 4e5+10;
// template end here
VI e[SIZE],emp;
int N,L,R,res[SIZE];
int d[SIZE],dn;
int bfs[SIZE],sons[SIZE];
int used[SIZE],tt,tt2,father[SIZE];
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
void build(int st,int given_v){
    bfs[0]=st;
    tt2--;
    used[st]=tt2;
    int i=0,j=1;
    for(;i<j;i++){
        int x=bfs[i];
        sons[x]=1;
        REP(k,SZ(e[x])){
            int y=e[x][k];
            if(used[y]==tt||used[y]==tt2)continue;
            father[y]=x;
            used[y]=tt2;
            bfs[j++]=y;
        }
    }
    int num=j;
    for(i=j-1;i>=0;i--){
        int x=bfs[i];
        if(sons[x]*2>=num){
            res[x]=given_v;
            used[x]=tt;
            REP(k,SZ(e[x])){
                int y=e[x][k];
                if(used[y]!=tt)build(y,given_v+1);
            }
            return;
        }
        sons[father[x]]+=sons[x];
    }
}
void init(){
    tt++;
    build(0,1);
}
VI edge[SIZE];
VPII edge_id;
int another[SIZE];
int polygon_id[SIZE];
int get_edge_id(int x,int y){
    return lower_bound(ALL(edge_id),MP(x,y))-edge_id.begin();
}
int edge_used[SIZE];
VI point_vector[SIZE];
int inc;
void get_polygon(int x,int y){
    int my_id=get_edge_id(x,y);
    if(edge_used[my_id]>=0){
        return;
    }
    int your_id=another[my_id];
    if(edge_used[your_id]!=-1){
        e[edge_used[your_id]].PB(inc);
        e[inc].PB(edge_used[your_id]);
    }
    edge_used[my_id]=inc;
    point_vector[inc].PB(x);
    int it=lower_bound(ALL(edge[y]),x)-edge[y].begin();
    it--;
    if(it<0)it=SZ(edge[y])-1;
    get_polygon(y,edge[y][it]);
}
bool compare(int x,int y){
    int it=0;
    while(it<SZ(point_vector[x])&&it<SZ(point_vector[y])){
        if(point_vector[x][it]!=point_vector[y][it])return point_vector[x][it]<point_vector[y][it];
        it++;
    }
    return 0;
}
int main(){
    DRII(n,m);
    if(!m){
        return 0*puts("1");
    }
    tt++;
    MS1(edge_used);
    REP(i,m){
        DRII(x,y);x--;y--;
        edge_id.PB(MP(x,y));
        edge_id.PB(MP(y,x));
        edge[x].PB(y);
        edge[y].PB(x);
    }
    REP(i,n){
        int x=i;
        int y=(i+1)%n;
        edge_id.PB(MP(x,y));
        edge_id.PB(MP(y,x));
        edge[x].PB(y);
        edge[y].PB(x);
    }
    sort(ALL(edge_id));
    REP(i,SZ(edge_id)){
        another[i]=get_edge_id(edge_id[i].S,edge_id[i].F);
    }
    REP(i,n){
        sort(ALL(edge[i]));
    }
    REP(i,n){
        REP(j,SZ(edge[i])){
            if((edge[i][j]+n-i)%n==n-1)continue;
            if(edge_used[get_edge_id(i,edge[i][j])]>=0)continue;
            get_polygon(i,edge[i][j]);
            sort(ALL(point_vector[inc]));
            reverse(ALL(point_vector[inc]));
            inc++;
        }
    }
    init();
    VI ker;
    REP(i,m+1)ker.PB(i);
    sort(ALL(ker),compare);
    REP(i,m+1)printf("%d ",res[ker[i]]);
    return 0;
}