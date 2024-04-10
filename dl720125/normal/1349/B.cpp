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

int n,k,a[100010];
cc_hash_table<int,bool,custom_hash> mp;
bool vis[100010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		mp.clear();
		cin>>n>>k;
		for(int i=1;i<=n;i++){cin>>a[i];mp[a[i]]=1;}
		if(!mp[k]){
			cout<<"no\n";
			continue; 
		}
		if(n==1){
			cout<<"yes\n";
			continue;
		}
		for(int i=1;i<=n;i++) vis[i]=0; 
		for(int i=1;i<=n;i++) if(a[i]>=k) vis[i]=1;
		bool ok=false;
		for(int i=1;i<n;i++){
			if(vis[i]&&vis[i+1]) ok=true;
		}
		for(int i=1;i<n-1;i++){
			if(vis[i]&&vis[i+2]) ok=true;
		}
		if(ok) cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;
}