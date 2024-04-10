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
const int SIZE = 1e5+10;
vector<pair<int,LL> >e[SIZE];
LL dp[SIZE][2],far[SIZE];
void dfs1(int x,int lt){
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(y==lt)continue;
        dfs1(y,x);
        if(dp[y][0]+e[x][i].S>dp[x][0]){
            dp[x][1]=dp[x][0];
            dp[x][0]=dp[y][0]+e[x][i].S;
        }
        else if(dp[y][0]+e[x][i].S>dp[x][1]){
            dp[x][1]=dp[y][0]+e[x][i].S;
        }
    }
}
void dfs2(int x,int lt,LL v){
    far[x]=max(v,dp[x][0]);
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(y==lt)continue;
        if(dp[y][0]+e[x][i].S==dp[x][0])dfs2(y,x,max(v,dp[x][1])+e[x][i].S);
        else dfs2(y,x,max(v,dp[x][0])+e[x][i].S);
    }
}
void add(int x,int y,int v){
    e[x].PB(MP(y,v));
    e[y].PB(MP(x,v));
}
int father[SIZE];
void dfs(int x,int lt){
    father[x]=lt;
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(y==lt)continue;
        dfs(y,x);
    }
}
struct Union_Find{
    int d[SIZE],num[SIZE],v[SIZE];
    void init(int n){
        REP(i,n){
            d[i]=i;
            num[i]=1;
            v[i]=1;
        }
    }
    int find(int x){
        return (x!=d[x])?(d[x]=find(d[x])):x;
    }
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        if(num[x]<num[y]){
            num[y]+=num[x];
            v[y]+=v[x];
            d[x]=y;
        }
        else{
            num[x]+=num[y];
            v[x]+=v[y];
            d[y]=x;
        }
        return 1;
    }
}U;
int main(){
    DRI(n);
    REPP(i,1,n){
        DRIII(x,y,v);
        x--;y--;
        add(x,y,v);
    }
    dfs1(0,0);
    dfs2(0,0,0);
    int root;
    LL mi=1e18;
    LL ma=0;
    REP(i,n){
        if(far[i]<mi){
            mi=far[i];
            root=i;
        }
        ma=max(ma,far[i]);
    }
    fprintf(stderr,"[%I64d]\n",ma-mi);
    dfs(root,root);
    vector<pair<LL,int> >pp;
    REP(i,n){
        pp.PB(MP(far[i],i));
    }
    sort(ALL(pp));
    DRI(Q);
    while(Q--){
        LL L;
        scanf("%I64d",&L);
        int an=0;
        int it=SZ(pp)-1;
        U.init(n);
        for(int i=SZ(pp)-1;i>=0;i--){
            int me=pp[i].S;
            REP(j,SZ(e[me])){
                int y=e[me][j].F;
                if(y==father[me])continue;
                U.uu(me,y);
            }
            while(pp[it].F-pp[i].F>L){
                U.v[U.find(pp[it].S)]--;
                it--;
            }
            an=max(an,U.v[U.find(me)]);
        }
        printf("%d\n",an);
    }
    return 0;
}