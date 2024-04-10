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

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		vector<long long> v;
		for(int i=1;i<=n;i++){
			long long sum=0ll,now=0ll;
			for(int j=1;j<=m;j++){
				long long x;cin>>x;
				sum+=x;now+=sum;
			}
			v.push_back(now);
		}
		long long val;
		if(v[0]==v[1]) val=v[0];
		else if(v[0]==v[2]) val=v[0];
		else val=v[1];
		for(int i=0;i<v.size();i++){
			if(v[i]!=val){
				cout<<i+1<<' '<<val-v[i]<<'\n';
				break;
			}
		}
	}
	return 0;
}