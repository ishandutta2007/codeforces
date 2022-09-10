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
char s[1000][10][12];
struct EDGE{
    int x,y,v;
    EDGE(int _x=0,int _y=0,int _v=0):x(_x),y(_y),v(_v){}
    bool operator<(const EDGE& b)const{return v<b.v;}
}e[1000000];
int d[1000],en;
int find(int x){
    if(x!=d[x])return d[x]=find(d[x]);
    return x;
}
bool uu(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return false;
    d[x]=y;
    return true;
}
vector<int>ee[1000];
bool used[1000];
void dfs(int x){
    used[x]=true;
    REP(i,SZ(ee[x])){
        int y=ee[x][i];
        if(!used[y]){
            printf("%d %d\n",y+1,x+1);
            dfs(y);
        }
    }
}
int main(){
    DRII(n,m);
    int sz=n*m;
    DRII(k,w);
    REP(i,k){
        REP(j,n)RS(s[i][j]);
    }
    REP(i,k)REPP(j,i+1,k){
        int cnt=0;
        REP(k1,n)REP(k2,m){
            cnt+=(s[i][k1][k2]!=s[j][k1][k2]);
        }
        if(cnt*w<sz)e[en++]=EDGE(i,j,cnt*w);
    }
    sort(e,e+en);
    LL an=0;
    int r=k;
    REP(i,k)d[i]=i;
    REP(i,en){
        if(uu(e[i].x,e[i].y)){r--;an+=e[i].v;ee[e[i].x].PB(e[i].y);ee[e[i].y].PB(e[i].x);}
        if(r==1)break;
    }
    an+=r*sz;
    cout<<an<<endl;
    REP(i,k){
        if(used[i]==0){
            printf("%d %d\n",i+1,0);
            dfs(i);
        }
    }
    return 0;
}