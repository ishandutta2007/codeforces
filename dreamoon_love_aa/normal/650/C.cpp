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
VPII row[SIZE],col[SIZE];
int v[SIZE];
int n,m;
int getP(int x,int y){return x*m+y;}
struct Union_Find{
    int d[SIZE],num[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1;
    }
    int find(int x){
        return (x!=d[x])?(d[x]=find(d[x])):x;
    }
    int get(int x,int y){
        return find(getP(x,y));
    }
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        if(num[x]<=num[y]){
            num[y]+=num[x];
            d[x]=y;
        }
        else{
            num[x]+=num[y];
            d[y]=x;
        }
        return 1;
    }
}U;
int an[SIZE];
VI e[SIZE];
void dfs(int x){
    int ma=0;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(!v[y]){
            dfs(y);
        }
        ma=max(ma,v[y]);
    }
    v[x]=ma+1;
}
int main(){
    RII(n,m);
    REP(i,n)REP(j,m){
        DRI(x);
        row[i].PB(MP(x,j));
        col[j].PB(MP(x,i));
    }
    U.init(n*m);
    REP(i,n){
        sort(ALL(row[i]));
        REPP(j,1,m){
            if(row[i][j].F==row[i][j-1].F)U.uu(getP(i,row[i][j].S),getP(i,row[i][j-1].S));
        }
    }
    REP(i,m){
        sort(ALL(col[i]));
        REPP(j,1,n){
            if(col[i][j].F==col[i][j-1].F)U.uu(getP(col[i][j].S,i),getP(col[i][j-1].S,i));
        }
    }
    REP(i,n){
        REPP(j,1,m){
            if(row[i][j].F>row[i][j-1].F)e[U.get(i,row[i][j].S)].PB(U.get(i,row[i][j-1].S));
        }
    }
    REP(i,m){
        REPP(j,1,n){
            if(col[i][j].F>col[i][j-1].F)e[U.get(col[i][j].S,i)].PB(U.get(col[i][j-1].S,i));
        }
    }
    REP(i,n*m){
        if(i==U.d[i]){
            if(!v[i])dfs(i);
        }
    }
    {
        int it=0;
        REP(i,n){
            REP(j,m){
                if(j)printf(" ");
                printf("%d",v[U.find(i*m+j)]);
            }
            puts("");
        }
    }
    return 0;
}