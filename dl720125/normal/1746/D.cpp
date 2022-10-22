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

int n,k,a[200010],s[200010];
long long dp[200010][2];
vector<int> v[200010];

inline void dfs1(int x,int val)
{
	a[x]=val;
	if((int)v[x].size()==0) return;
	int nw=val/(int)v[x].size();
	for(int i=0;i<(int)v[x].size();i++){
		dfs1(v[x][i],nw);
	}
}

inline void dfs2(int x)
{
	for(int i=0;i<(int)v[x].size();i++){
		dfs2(v[x][i]);
	}
	dp[x][0]=1ll*a[x]*s[x];dp[x][1]=1ll*(a[x]+1)*s[x];
	if((int)v[x].size()==0) return;
	int rem=a[x]%(int)v[x].size();
	vector<long long> g;
	for(int i=0;i<(int)v[x].size();i++){
		dp[x][0]+=dp[v[x][i]][0];dp[x][1]+=dp[v[x][i]][0];
		g.push_back(dp[v[x][i]][1]-dp[v[x][i]][0]);
	}
	sort(g.begin(),g.end());reverse(g.begin(),g.end());
	for(int i=0;i<=rem;i++){
		if(i<rem) dp[x][0]+=g[i];
		dp[x][1]+=g[i];
	}
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=2;i<=n;i++){
			int x;cin>>x;v[x].push_back(i);
		}
		for(int i=1;i<=n;i++) cin>>s[i];
		dfs1(1,k);
		dfs2(1);
		cout<<dp[1][0]<<'\n';
	}
	return 0;
}