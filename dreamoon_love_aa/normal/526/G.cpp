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
vector<pair<int,int> >e[SIZE];
VPII res;
int len[SIZE],lv[SIZE];
int father[17][SIZE];
int de[SIZE],cs,used[SIZE],root;
int ord[SIZE];
int dfs0(int x){
    int ma=0;
    used[x]=cs;
    for(int i=0;i<e[x].size();i++){
        int y=e[x][i].F;
        if(used[y]!=cs){
            len[y]=e[x][i].S;
            lv[y]=lv[x]+len[y];
            father[0][y]=x;
            ma=max(ma,dfs0(y)+e[x][i].S);
        }
    }
    return de[x]=ma;
}
void dfs(int x,int base){
    used[x]=cs;
    bool flag=0;
    int i;
    if(x!=root&&e[x].size()==1){
        res.PB(MP(base,x));
        return;
    }
    for(i=0;i<e[x].size();i++){
        int y=e[x][i].F;
        if(used[y]==cs)continue;
        if(de[y]+e[x][i].S<de[x])dfs(y,e[x][i].S);
        else{
            if(!flag){
                dfs(y,base+e[x][i].S);
                flag=1;
            }
            else dfs(y,e[x][i].S);
        }
    }
}
int dp[SIZE][2],far[SIZE];
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
void dfs2(int x,int lt,int v=0){
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
int line[SIZE];
int main(){
    DRII(n,q);
    REPP(i,1,n){
        DRIII(x,y,v);
        add(x,y,v);
    }
    dfs1(1,0);
    dfs2(1,0);
    int root=1;
    REPP(i,2,n+1){
        if(far[i]<far[root])root=i;
    }

    cs++;
    dfs0(root);
    cs++;
    dfs(root,0);
    father[0][root]=root;
    REPP(i,1,17){
        REPP(j,1,n+1)father[i][j]=father[i-1][father[i-1][j]];
    }
    sort(ALL(res));
    reverse(ALL(res));
    ord[root]=1;
    int all=0;
    REP(i,SZ(res)){
        int now=res[i].S;
        line[i/2+1]+=res[i].F;
        all+=res[i].F;
        while(!ord[now]){
            ord[now]=i+1;
            now=father[0][now];
        }
    }
    REPP(i,1,SIZE)line[i]+=line[i-1];
    MS0(dp);
    dfs1(root,root);
    int ans=0;
    REP(cs,q){
        DRII(x,y);
        x=(x+ans-1)%n+1;
        y=(y+ans-1)%n+1;
        if(y*2>=SZ(res))ans=all;
        else{
            if(y*2>=ord[x])ans=line[y];
            else{
                int you=x;
                for(int i=16;i>=0;i--){
                    if(ord[father[i][you]]>2*y)you=father[i][you];
                }
                ans=line[y]+dp[x][0]+lv[x]-lv[you]+len[you];
                ans-=min(res[2*y-1].F,dp[father[0][you]][0]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}