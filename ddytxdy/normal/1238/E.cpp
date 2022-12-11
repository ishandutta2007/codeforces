#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50,M=1.1e6;
int n,m,d[25][25],dp[M],mx,val[M][20],goal,cnt[M];char s[N];
void cmin(int &x,int y){y<x?x=y:0;}
void dfs(int x,int now,int sum){
    if(x==m){val[now][goal]=sum;return;}
    if(x==goal)dfs(x+1,now,sum);
    else{
        dfs(x+1,now,sum-d[goal][x]);
        dfs(x+1,now+(1<<x),sum+d[goal][x]);
    }
}
int main(){
    scanf("%d%d%s",&n,&m,s+1);mx=1<<m;
    for(int i=1;i<n;i++)
        if(s[i+1]!=s[i])d[s[i]-'a'][s[i+1]-'a']++,d[s[i+1]-'a'][s[i]-'a']++;
    for(goal=0;goal<m;goal++)dfs(0,0,0);
    for(int i=1;i<mx;i++)cnt[i]=i&1?cnt[i>>1]+1:cnt[i>>1];
    memset(dp,0x3f,sizeof(dp));dp[0]=0;
    for(int i=0;i<mx;i++)
        for(int j=0;j<m;j++)if(!(i>>j&1))
            cmin(dp[i^(1<<j)],dp[i]+val[i][j]*(cnt[i]+1));
    printf("%d\n",dp[mx-1]);
    return 0;
}