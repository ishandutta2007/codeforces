#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
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

int n,k,deg[200010],dep[200010],par[200010],sz[200010];
vector<int> v[200010];

inline void dfs(int x,int pr)
{
	par[x]=pr;sz[x]=1;
	for(int i=0;i<v[x].size();i++) if(v[x][i]!=pr){
		int u=v[x][i];
		dep[u]=dep[x]+1;
		dfs(u,x);
		sz[x]+=sz[u];
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
		deg[x]++;deg[y]++;
	}
	dfs(1,-1);
	priority_queue<pair<int,int> > q;
	for(int i=2;i<=n;i++) if(deg[i]==1) q.push(make_pair(dep[i],i));
	long long ans=0ll;
	while(!q.empty())
	{
		pair<int,int> t=q.top();
		q.pop();
		ans+=(long long)t.first;k--;
		if(k==0) break;
		int u=par[t.second];
		deg[u]--;
		if(deg[u]==1){
			q.push(make_pair(dep[u]-(sz[u]-1),u));
		}
	}
	cout<<ans<<endl;
	return 0;
}