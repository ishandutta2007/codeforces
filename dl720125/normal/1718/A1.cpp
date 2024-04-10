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

int n,a[100010],pre[100010],dp[100010];
map<int,int> mp,vis;

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		pre[1]=1;
		for(int i=2;i<=n;i++){
			if(a[i-1]==a[i]) pre[i]=pre[i-1];
			else pre[i]=i;
		}
		dp[0]=0;
		mp.clear();vis.clear();mp[0]=0;vis[0]=1;
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=0) dp[i]=dp[pre[i]-1]+(i-pre[i]+2)/2;
			else dp[i]=dp[pre[i]-1];
			sum^=a[i];
			if(vis[sum]){
				dp[i]=min(dp[i],dp[mp[sum]]+(i-mp[sum]-1));
			}
			mp[sum]=i;vis[sum]=1;
		}
		cout<<dp[n]<<'\n';
	}
	return 0;
}