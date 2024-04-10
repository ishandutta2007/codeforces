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

int n,m,cnt[200010];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	int ans=n;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		cnt[min(x,y)]++;
		if(cnt[min(x,y)]==1) ans--;
	}
	int q;cin>>q;
	for(int i=1;i<=q;i++){
		int flag;cin>>flag;
		if(flag==1){
			int x,y;cin>>x>>y;
			cnt[min(x,y)]++;
			if(cnt[min(x,y)]==1) ans--;
		}
		else if(flag==2){
			int x,y;cin>>x>>y;
			cnt[min(x,y)]--;
			if(cnt[min(x,y)]==0) ans++;
		}
		else{
			cout<<ans<<'\n';
		} 
	}
	return 0;
}