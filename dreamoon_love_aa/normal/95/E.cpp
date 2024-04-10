#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define SIZE 100001
using namespace std;
vector<int>e[SIZE],d;
int an;
bool used[SIZE],perfect[SIZE];
void dfs(int x,int y){
    if(y>=SIZE)return;
    perfect[y]=1;
    dfs(x+1,y*10+4);
    dfs(x+1,y*10+7);
}
int Go(int x){
    static int bfs[SIZE];
    int i,j,k;
    bfs[0]=x;
    used[x]=1;
    for(i=0,j=1;i<j;i++){
        int now=bfs[i];
        for(k=0;k<e[now].size();k++){
            if(!used[e[now][k]]){
                bfs[j++]=e[now][k];
                used[e[now][k]]=1;
            }
        }
    }
    return i;
}
int dp[SIZE],up;
void pack(int x,int n){
    int i,j,two=1,sum=0;
    do{
        for(i=up;i>=0;i--){
            if(dp[i]<0)continue;
            if(dp[i+x*two]==-1||dp[i+x*two]>dp[i]+two){
                dp[i+x*two]=dp[i]+two;
                if(perfect[i+x*two]){
                    if(an==-1||an>dp[i+x*two])an=dp[i+x*two];
                }
            }
        }
        up+=two*x;
        sum+=two;
        if(sum==n)return;
        two<<=1;
        if(sum+two>n)
            two=n-sum;
    }while(1);
}
int main(){
    int n,m,i,j,x,y;
    an=-1;
    dfs(0,0);
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for(i=1;i<=n;i++){
        if(!used[i]){
            d.push_back(Go(i));
        }
    }
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    up=0;
    sort(d.begin(),d.end());
    for(i=0;i<d.size()&&an!=1;i+=j){
        for(j=1;i+j<d.size()&&d[i+j]==d[i];j++);
        pack(d[i],j);
    }
    if(an>0)an--;
    printf("%d\n",an);
    return 0;
}