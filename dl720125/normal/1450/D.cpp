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

int a[300010],cnt[300010],ans[300010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) cnt[i]=0,ans[i]=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cnt[a[i]]++;
		bool flag=true;
		for(int i=1;i<=n;i++) if(cnt[i]!=1){
			flag=false;break;
		}
		if(flag) ans[1]=1;
		int l=1,r=n;
		for(int i=1;i<=n;i++){
			if(cnt[i]==0) break;
			ans[n-i+1]=1;
			if(cnt[i]>=2) break;
			if(cnt[i]==1&&a[l]!=i&&a[r]!=i) break;
			if(a[l]==i) l++;
			if(a[r]==i) r--;
		}
		for(int i=1;i<=n;i++) cout<<ans[i];
		cout<<'\n'; 
	}
	return 0;
}