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

int n,a[100010],val[200010],tot[90000010];

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=min(i+300,n);j++){
			if((a[j]-a[i])%(j-i)==0){
				int u=(a[j]-a[i])/(j-i);
				val[u+100000]++;
				ans=max(ans,val[u+100000]+1);
			}
		}
		for(int j=i+1;j<=min(i+300,n);j++){
			if((a[j]-a[i])%(j-i)==0){
				int u=(a[j]-a[i])/(j-i);
				val[u+100000]--;
			}
		}
	}
	for(int i=-400;i<=400;i++){
		for(int j=1;j<=n;j++){
			tot[a[j]-i*j+45000000]++;
			ans=max(ans,tot[a[j]-i*j+45000000]);
		}
		for(int j=1;j<=n;j++){
			tot[a[j]-i*j+45000000]--;
		}
	}
	cout<<n-ans<<'\n';
	return 0;
}