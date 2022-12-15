#include <cstdio>
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
using namespace std;
vector <int> v[200005];
long long dp[200005][2],mod=1e9+7,dis[200005],f[200005][2];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,m,s,t;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) v[i].clear(),dp[i][0]=dp[i][1]=-1,dis[i]=-1,f[i][0]=f[i][1]=0;
        scanf("%d%d",&s,&t);
        for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
        queue<int> q;
        dis[t]=0,q.push(t);
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto x:v[temp]) if(dis[x]==-1) dis[x]=dis[temp]+1,q.push(x);
        }
        dp[t][0]=1,q.push(t);
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto x:v[temp]) if(f[x][0]==0) q.push(x),f[x][0]=1;
            if(dp[temp][0]==-1) {
                dp[temp][0]=0;
                for (auto x:v[temp]) {
                    if (dis[x] == dis[temp] - 1) dp[temp][0] += dp[x][0];
                }
                dp[temp][0] %= mod;
            }
        }
        dp[t][1]=0,q.push(t);
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto x:v[temp]) if(f[x][1]==0) q.push(x),f[x][1]=1;
            if(dp[temp][1]==-1) {
                dp[temp][1]=0;
                for (auto x:v[temp]) {
                    if (dis[x] == dis[temp] - 1) dp[temp][1] += dp[x][1];
                    else if (dis[x] == dis[temp]) dp[temp][1] += dp[x][0];
                }
                dp[temp][1] %= mod;
            }
        }
        printf("%lld\n",(dp[s][0]+dp[s][1])%mod);
    }
    return 0;
}
//unordered_map