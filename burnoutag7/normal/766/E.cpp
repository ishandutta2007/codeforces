#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int a[100005];
vector<int> g[100005];
ll dp[100005][20][2],cnt[20];

void dfs(int x,int p){
    for(int i=0;i<20;i++)dp[x][i][a[x]>>i&1]=1;
    ll sum[20][2]={};
    memset(sum,0,sizeof(sum));
    for(int y:g[x])if(y!=p){
        dfs(y,x);
        for(int i=0;i<20;i++){
            if(a[x]>>i&1){
                dp[x][i][0]+=dp[y][i][1];
                dp[x][i][1]+=dp[y][i][0];
            }else{
                dp[x][i][0]+=dp[y][i][0];
                dp[x][i][1]+=dp[y][i][1];
            }
            sum[i][0]+=dp[y][i][0];
            sum[i][1]+=dp[y][i][1];
        }
    }
    for(int i=0;i<20;i++)if(a[x]>>i&1){
        ll cur=0;
        for(int y:g[x])if(y!=p){
            cur+=dp[y][i][1]*(sum[i][1]-dp[y][i][1]);
            cur+=dp[y][i][0]*(sum[i][0]-dp[y][i][0]);
        }
        cnt[i]+=cur>>1;
    }else{
        ll cur=0;
        for(int y:g[x])if(y!=p){
            cur+=dp[y][i][0]*(sum[i][1]-dp[y][i][1]);
            cur+=dp[y][i][1]*(sum[i][0]-dp[y][i][0]);
        }
        cnt[i]+=cur>>1;
    }
    for(int i=0;i<20;i++)cnt[i]+=dp[x][i][1];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1);
    ll ans=0;
    for(int i=0;i<20;i++){
        ans+=cnt[i]<<i;
    }
    cout<<ans<<endl;

    return 0;
}