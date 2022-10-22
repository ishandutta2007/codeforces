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

int x[6010],y[6010],cnt[2][2];

signed main()
{
	ios::sync_with_stdio(false);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		x[i]/=2;y[i]/=2;
		cnt[x[i]%2][y[i]%2]++;
	}
	long long ans=0ll;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			ans+=1ll*cnt[i][j]*(cnt[i][j]-1)*(cnt[i][j]-2)/6;
		}
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				for(int l=0;l<2;l++) if(k!=i||l!=j){
					ans+=1ll*cnt[i][j]*(cnt[i][j]-1)/2*cnt[k][l];
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}