#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+100;
vector<int> E[maxn];
int n;
int f[maxn];
int dp[maxn];
int sz[maxn];
void max_job(int u){
    int ans = 0;
    for (int v : E[u]){
        ans = max(ans,sz[u] - sz[v] + dp[v]);
    }
    dp[u] = ans;
}
void min_job(int u){
    int sum = 0;
    for (int v : E[u]){
        sum += dp[v] - 1;
    }
    dp[u] = sum+ 1;
}
void dfs(int u){
    if (E[u].size() == 0){
        sz[u] = 1;
        dp[u] = 1;
        return;
    }
    for (int v : E[u]){
        dfs(v);
        sz[u] += sz[v];
    }
    if (f[u] == 0)min_job(u);
    else max_job(u);
}
void debug(){
    for (int i=1;i<=n;i++){
        printf("dp[%d]=%d\n",i,dp[i]);
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",f+i);
    }
    for (int i=2;i<=n;i++){
        int fa;
        scanf("%d",&fa);
        E[fa].push_back(i);
    }
    dfs(1);
    cout<<dp[1]<<endl;
    //debug();
    return 0;
}