#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <ctime>
#include <map>
#include <set>

using namespace std;

vector < vector < pair<int,int> > > g;
int ans;
int dp[3002],up[3002],f[3002][2];

void dfs(int v,int par = -1) {
    int cur=0;
    for(int i=0;i<g[v].size();++i) {
        if (g[v][i].first!=par) {
            up[g[v][i].first]=up[v]+g[v][i].second;
            f[g[v][i].first][0]=g[v][i].second+f[v][0];
            f[g[v][i].first][1]=min((1-g[v][i].second)+f[v][1],f[v][0]+g[v][i].second);
            dfs(g[v][i].first,v);
            cur+=g[v][i].second+dp[g[v][i].first];
        }
    }
    dp[v]=cur;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,a,b;
    scanf("%d",&n);
//  n=3000;
    g.resize(n);
    for(int i=1;i<n;++i) {
        scanf("%d%d",&a,&b); --a; --b;
//      a=i; b=0;
        g[a].push_back(make_pair(b,0));
        g[b].push_back(make_pair(a,1));
    }
    ans=n-1;
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j)
            dp[j]=n+1,up[j]=0,f[j][0]=f[j][1]=n+1;
//      memset(f,0,sizeof(f));
        f[i][0]=f[i][1]=0;
        dfs(i);
        for(int j=0;j<n;++j) {
            ans=min(ans,max(dp[i]-up[j]+f[j][1],0));
        }
    }
    printf("%d\n",ans);
    return 0;
}