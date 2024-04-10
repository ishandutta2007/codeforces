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

int a[310],pos[310];
pair<int,int> b[310];

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		for(int i=1;i<=n*m;i++) cin>>a[i],b[i].first=a[i],b[i].second=-i;
		sort(b+1,b+n*m+1);
		for(int i=1;i<=n*m;i++) pos[-b[i].second]=i;
		int ans=0;
		for(int i=1;i<=n*m;i++){
			for(int j=i+1;j<=n*m;j++) ans+=(pos[i]<pos[j]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}