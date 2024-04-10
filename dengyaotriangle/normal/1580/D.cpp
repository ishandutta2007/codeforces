#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=4005;

int n,m;
int a[maxn];
int ch[maxn][2];
long long dp[maxn][maxn];
int sz[maxn];
long long tmp[maxn];
void dfs(int u){
    sz[u]=1;
    dp[u][0]=0;
    dp[u][1]=m*(long long)a[u];
    for(int i=0;i<2;i++){
        int v=ch[u][i];
        if(v){
            dfs(v);
            for(int i=0;i<=sz[u]+sz[v];i++)tmp[i]=LLONG_MIN;
            for(int i=0;i<=sz[u];i++){
                for(int j=0;j<=sz[v];j++){
                    tmp[i+j]=max(tmp[i+j],dp[u][i]+dp[v][j]+j*(long long)j*a[u]);
                }
            }
            for(int i=0;i<=sz[u]+sz[v];i++)dp[u][i]=tmp[i];
            sz[u]+=sz[v];
        }
    }
    for(int i=0;i<=sz[u];i++)dp[u][i]-=i*(long long)i*a[u];
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    stack<int> stk;
    for(int i=1;i<=n;i++){
        while(!stk.empty()&&a[stk.top()]>a[i]){
            ch[i][0]=stk.top();
            stk.pop();
        }
        if(!stk.empty())ch[stk.top()][1]=i;
        stk.push(i);
    }
    int rt=min_element(a+1,a+1+n)-a;
    dfs(rt);
    cout<<dp[rt][m];
    return 0;
}