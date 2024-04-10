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
struct EDGE{
    int x,y,v;
    EDGE(int _x=0,int _y=0,int _v=0):x(_x),y(_y),v(_v){}
    bool operator<(const EDGE& b)const{return v<b.v;}
}d[2000000];
int to[2111],dis[2111];
vector<pair<int,int> >e[2111];
int find(int x){
    if(x!=to[x])return to[x]=find(to[x]);
    return x;
}
bool uu(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y){
        to[x]=y;
        return 1;
    }
    return 0;
}
int a[2111][2111],ST;
void dfs(int x,int v,int lt){
    if(a[ST][x]!=v){
        puts("NO");
        exit(0);
    }
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(y==lt)continue;
        dfs(y,v+e[x][i].S,x);
    }
}
int main(){
    DRI(n);
    REP(i,n)to[i]=i;
    int dn=0;
    REP(i,n)REP(j,n){
        DRI(x);
        a[i][j]=x;
        if(i<j)d[dn++]=EDGE(i,j,x);
    }
    REP(i,n)REPP(j,i+1,n){
        if(a[i][j]!=a[j][i]||!a[i][j]){
            puts("NO");
            return 0;
        }
    }
    sort(d,d+dn);
    REP(i,dn){
        int x=d[i].x;
        int y=d[i].y;
        if(uu(x,y)){
            e[x].PB(MP(y,d[i].v));
            e[y].PB(MP(x,d[i].v));
        }
    }
    REP(i,n){
        ST=i;
        dfs(i,0,-1);
    }
    puts("YES");
    return 0;
}