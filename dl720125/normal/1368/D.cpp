#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
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

int n,a[200010],num[20],pw[20];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	pw[0]=1ll;
	for(int i=1;i<20;i++) pw[i]=pw[i-1]*2ll;
	for(int i=1;i<=n;i++){
		for(int j=0;j<20;j++){
			num[j]+=a[i]%2;a[i]/=2;
		}
	}
	int ans=0ll;
	for(int i=1;i<=n;i++){
		int sum=0ll;
		for(int j=0;j<20;j++) if(num[j]>0){
			sum+=pw[j];num[j]--;
		}
		ans+=sum*sum;
	}
	cout<<ans<<endl;
	return 0;
}