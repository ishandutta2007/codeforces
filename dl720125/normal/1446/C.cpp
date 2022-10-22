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

int n,a[200010],val[200010][30];
cc_hash_table<long long,bool> mp;

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<30;j++){
			val[i][j]=((a[i]&(1<<j))>0);
		}
		int now=0;
		for(int j=29;j>=0;j--){
			now=now*2+val[i][j];
			mp[j*2000000000ll+(long long)(now)]=1;
		}
	}
	int ans=n;
	for(int i=1;i<=n;i++){
		int tot=1,now=0;
		for(int j=29;j>=0;j--){
			now=now*2+val[i][j];
			if(val[i][j]==0){
				if(mp[j*2000000000ll+(long long)(now+1)]) tot++;
			}
			if(val[i][j]==1){
				if(mp[j*2000000000ll+(long long)(now-1)]) tot++;
			}
		}
		ans=min(ans,n-tot);
	}
	cout<<ans<<endl;
	return 0;
}