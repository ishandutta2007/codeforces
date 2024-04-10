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

int num[1000010],sum[1000010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n,c;cin>>n>>c;
		for(int i=1;i<=c;i++) num[i]=0,sum[i]=0;
		for(int i=1;i<=n;i++){
			int x;cin>>x;num[x]=1;
		}
		for(int i=1;i<=c;i++) sum[i]=sum[i-1]+num[i];
		if(!num[1]){
			cout<<"No\n";
			continue;
		}
		bool flag=true;
		for(int i=2;i<=c&&flag;i++) if(num[i]){
			for(int j=2;i*j<=c&&flag;j++) if(!num[j]){
				int l=i*j,r=i*(j+1);
				if(sum[min(r-1,c)]-sum[l-1]>0){
					flag=false;
				}
			}
		}
		if(flag) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}