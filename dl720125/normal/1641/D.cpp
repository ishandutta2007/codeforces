#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 2000000007
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

int n,m,cnt,a[100010][6],c[100010],val[500010],u[100010],dp[100010];
map<int,int> mp,pm;

signed main()
{
	unsigned seed=chrono::steady_clock::now().time_since_epoch().count();
	mt19937 Rand(seed);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin>>a[i][j],mp[a[i][j]]=1;
		cin>>c[i];
	}
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
		pm[it->first]=++cnt;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=pm[a[i][j]];
	int ans=INF;
	for(int t=1;t<=30;t++){
		for(int i=1;i<=cnt;i++) val[i]=Rand()%15;
		for(int i=0;i<(1<<15);i++) u[i]=INF;
		for(int i=1;i<=n;i++){
			int mask=0;
			for(int j=1;j<=m;j++) mask|=(1<<val[a[i][j]]);
			u[mask]=min(u[mask],c[i]);
		}
		for(int i=0;i<(1<<15);i++) dp[i]=u[i];
		for(int i=0;i<(1<<15);i++){
			for(int j=0;j<15;j++) if(i&(1<<j)){
				dp[i]=min(dp[i],dp[i^(1<<j)]);
			}
		}
		for(int i=0;i<(1<<15);i++){
			int r=((1<<15)-1)^i;
			if(u[i]!=INF&&dp[r]!=INF) ans=min(ans,u[i]+dp[r]);
		}
	}
	if(ans==INF) ans=-1;
	cout<<ans<<'\n';
	return 0;
}