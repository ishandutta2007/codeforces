#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T;ll n,m;
ll dp[63][2][2][2];
ll dfs(int x,int f1,int f2,int f3){
    if(x==62)return (!f1)&&(f2^f3);
    ll &op=dp[x][f1][f2][f3];
    if(op!=-1)return op;op=0;
    for(int i=0;i<2;i++){
        int cp=i+((n>>x)&1)+f2;
        op+=dfs(x+1,(((m>>x)&1)?(i?f1:0):(i?1:f1)),cp/2,f3^i^(cp&1));
    }		
    return op;
}
void sol(){
    memset(dp,-1,sizeof(dp));
    scanf("%lld%lld",&n,&m);m--;
    printf("%lld\n",dfs(0,0,0,0));
}
int main(){
    cin>>T;while(T--)sol();
    return 0;
}