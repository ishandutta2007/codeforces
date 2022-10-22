#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
//#define int long long
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

int n,rem[200010],par[200010],val[200010],tot[200010],sum[200010],dp[200010],ok[200010];
vector<int> v[200010];

inline void dfs1(int x,int pr)
{
	par[x]=pr;
	int cnt=0;
	for(int i=0;i<v[x].size();i++) if(v[x][i]!=pr){
		dfs1(v[x][i],x);val[x]+=val[v[x][i]];cnt++;
		if(rem[v[x][i]]) rem[x]++;
	}
	if(cnt==0) ok[x]=1;
	if(rem[x]){
		val[x]+=rem[x]-1;rem[x]=0;
	}
	else rem[x]=1;
}

inline void dfs2(int x,int pr)
{
	tot[x]+=val[x]+rem[x];dp[x]+=sum[x];
	for(int i=0;i<v[x].size();i++) if(v[x][i]!=pr){
		tot[v[x][i]]+=tot[x];dp[v[x][i]]+=dp[x];
		dfs2(v[x][i],x);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) v[i].clear(),rem[i]=0,par[i]=0,val[i]=0,tot[i]=0,sum[i]=0,dp[i]=0,ok[i]=0;
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs1(1,-1);
		for(int i=1;i<=n;i++){
			for(int j=0;j<v[i].size();j++) if(v[i][j]!=par[i]){
				sum[i]+=val[v[i][j]]+rem[v[i][j]];
			}
		}
		dfs2(1,-1);
		int ans=n;
		for(int i=1;i<=n;i++) if(ok[i]){
			ans=min(ans,1+dp[i]-tot[i]+tot[1]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}