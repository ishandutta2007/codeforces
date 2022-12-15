#pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
long long dp[2005][2005],pre[2005][2005],mod;
int n;
vector <int> v[2005],vv[2005];
long long c[2005][2005],ac[2005],p[2005][2005],s[2005][2005];
void dfs(int x,int from){
    for(auto t:v[x]) if(t!=from) dfs(t,x),ac[t]=0,vv[x].push_back(t);
    swap(v[x],vv[x]);
    for(int i=1;i<=n;i++){
        dp[x][i]=1;
        if(x==1){
            for(auto t:v[x]) dp[x][i]*=pre[t][i-1],dp[x][i]%=mod;
        }
        else{
            for(auto t:v[x]) dp[x][i]*=pre[t][i],dp[x][i]%=mod;
            //cout<<dp[x][i]<<endl;
            if(i>1) {
                for(int j=0;j<v[x].size();j++) p[x][j]=j==0?pre[v[x][j]][i-1]:(p[x][j-1]*pre[v[x][j]][i-1])%mod;
                for(int j=int(v[x].size())-1;j>=0;j--) s[x][j]=j==v[x].size()-1?pre[v[x][j]][i-1]:(s[x][j+1]*pre[v[x][j]][i-1])%mod;
                for(int j=0;j<v[x].size();j++) ac[v[x][j]]+=(j?p[x][j-1]:1LL)*(j==v[x].size()-1?1LL:s[x][j+1])%mod,ac[v[x][j]]%=mod;
                //cout<<fac<<endl;
                for (auto t:v[x])
                    if (t != from)
                        dp[x][i] += ac[t] * dp[t][i] % mod,dp[x][i]%=mod;
                dp[x][i] %= mod;
            }
        }
        pre[x][i]=(pre[x][i-1]+dp[x][i])%mod;
    }
}
long long ans[2005];
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        cin>>n>>mod;
        for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
        dfs(1,0);
        c[0][0]=c[1][0]=c[1][1]=1;
        for(int i=2;i<=n;i++){
            c[i][0]=1;
            for(int j=1;j<=i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
        for(int i=2;i<=n;i++){
            ans[i-1]=dp[1][i];
            for(int j=1;j<i-1;j++) ans[i-1]-=c[i-1][j]*ans[j]%mod,ans[i-1]%=mod;
        }
        for(int i=1;i<n;i++) printf("%lld ",(ans[i]%mod+mod)%mod);
    }
    return 0;
}
//unordered_map
//cf