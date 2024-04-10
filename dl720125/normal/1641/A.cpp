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

int a[200010];
map<int,int> mp;

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n,x;cin>>n>>x;
		mp.clear();
		for(int i=1;i<=n;i++) cin>>a[i],mp[a[i]]++;
		int ans=0;
		for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
			int u=(it->first);
			if(u%x==0){
				int d=min(mp[u],mp[u/x]);
				mp[u]-=d;mp[u/x]-=d;
			}
		}
		for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++) ans+=(it->second);
		cout<<ans<<'\n';
	}
	return 0;
}