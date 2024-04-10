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

int n,c[1010];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>c[i];
	long long ans=0ll;
	for(int i=1;i<=n;i++) if(i%2==1){
		long long l=1ll,r=1ll*c[i];
		for(int j=i+1;j<=n;j++){
			if(j%2==0){
				l-=1ll*c[j];r-=1ll*c[j];
				if(r<0ll){
					ans+=r-l+1ll;
					break;
				}
				if(l<=0ll) ans+=1ll-l,l=0ll; 
			}
			else{
				l+=1ll*c[j];r+=1ll*c[j];
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}