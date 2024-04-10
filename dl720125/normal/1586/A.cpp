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

int n,a[110];

inline bool check(int x)
{
	if(x==1) return true;
	for(int i=2;i*i<=x;i++) if(x%i==0) return false;
	return true;
}

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		cin>>n;
		int sum=0;
		for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
		if(!check(sum)){
			cout<<n<<'\n';
			for(int i=1;i<=n;i++) cout<<i<<' ';
			cout<<'\n';
		}
		else{
			for(int i=1;i<=n;i++){
				if(!check(sum-a[i])){
					cout<<n-1<<'\n';
					for(int j=1;j<=n;j++) if(j!=i) cout<<j<<' ';
					cout<<'\n';
					break;
				}
			}
		}
	}
	return 0;
}