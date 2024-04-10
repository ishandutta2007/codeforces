#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
vector <int> v[100005];
int dp[100005][2];
void dfs(int x){
    for(auto t:v[x]) dfs(t);
    int mx=0;
    for(auto t:v[x]) mx=max(mx,dp[t][0]),dp[x][1]+=max(dp[t][0],dp[t][1]);
    dp[x][0]=mx+1;
}
int main(){
    int T = 1, kase = 0;
    //cin >> T;
    while (T--){
        int n;
        cin>>n;
        for(int i=2,x;i<=n;i++) scanf("%d",&x),v[x].push_back(i);
        dfs(1),printf("%d\n",max(dp[1][0],dp[1][1]));
    }
    return 0;
}