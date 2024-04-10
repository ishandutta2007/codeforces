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

int x[1010],y[1010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,k;cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
		bool flag=false;
		for(int i=1;i<=n;i++){
			int cnt=0;
			for(int j=1;j<=n;j++) if(j!=i){
				if(abs(x[j]-x[i])+abs(y[j]-y[i])<=k){
					cnt++;
				}
			}
			if(cnt==n-1){
				cout<<1<<'\n';flag=true;break;
			}
		}
		if(!flag) cout<<-1<<'\n';
	}
	return 0;
}