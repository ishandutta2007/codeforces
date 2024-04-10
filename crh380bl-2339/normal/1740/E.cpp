#include<bits/stdc++.h>
using namespace std;
vector<int>e[100005];
int dp[100005];
int DFS1(int x){
    //printf("%d\n",x);
    int i;
    dp[x]=1;
    for(auto y:e[x]){
        dp[x]=max(dp[x], DFS1(y)+1);
    }
    return dp[x];
}
int DFS2(int x){
    int ans=dp[x],s=0;
    for(auto y:e[x]){
        s += DFS2(y);
    }
    return max(ans, s);
}
int main(){
    int n,i,x;
    scanf("%d",&n);
    for(i=2;i<=n;++i){
        scanf("%d",&x);
        e[x].push_back(i);
    }
    DFS1(1);
    printf("%d",DFS2(1));
    return 0;
}