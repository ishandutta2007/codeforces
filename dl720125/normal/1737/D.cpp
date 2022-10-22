#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000007
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n,m,dp[510][510],val[510][510];
vector<int> v[510];

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) val[i][j]=INF,dp[i][j]=INF;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<=m;i++){
			int x,y,w;cin>>x>>y>>w;
			val[x][y]=min(val[x][y],w);
			val[y][x]=min(val[y][x],w);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dp[1][n]=dp[n][1]=0;
		queue<pair<int,int> > q;
		q.push(make_pair(1,n));q.push(make_pair(n,1));
		while(!q.empty()){
			pair<int,int> t=q.front();q.pop();
			int x=t.first,y=t.second;
			if(x==y){
				for(int i=1;i<=n;i++){
					int u=i;
					if(dp[u][y]>dp[x][y]+1){
						dp[u][y]=dp[x][y]+1;
						q.push(make_pair(u,y));
					}
				}
				for(int i=1;i<=n;i++){
					int u=i;
					if(dp[x][u]>dp[x][y]+1){
						dp[x][u]=dp[x][y]+1;
						q.push(make_pair(x,u));
					}
				}
			}
			else{
				for(int i=0;i<(int)v[x].size();i++){
					int u=v[x][i];
					if(dp[u][y]>dp[x][y]+1){
						dp[u][y]=dp[x][y]+1;
						q.push(make_pair(u,y));
					}
				}
				for(int i=0;i<(int)v[y].size();i++){
					int u=v[y][i];
					if(dp[x][u]>dp[x][y]+1){
						dp[x][u]=dp[x][y]+1;
						q.push(make_pair(x,u));
					}
				}
			}
		}
		long long ans=1ll*INF*INF;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(val[i][j]!=INF){
			ans=min(ans,1ll*(dp[i][j]+1)*val[i][j]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}