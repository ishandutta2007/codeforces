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

int n,a[100010],b[100010];

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		long long sum=0ll;
		for(int i=1;i<=n;i++) cin>>b[i],sum+=1ll*b[i];
		vector<int> v0,v1;
		for(int i=1;i<=n;i++){
			if(a[i]==0) v0.push_back(b[i]);
			else v1.push_back(b[i]);
		}
		sort(v0.begin(),v0.end());sort(v1.begin(),v1.end()); 
		if(v0.size()==v1.size()){
			sum=sum*2ll-1ll*min(v0[0],v1[0]);
		}
		else if(v0.size()>v1.size()){
			sum=sum*2ll;
			for(int i=0;i<v0.size()-v1.size();i++) sum-=1ll*v0[i]; 
		}
		else{
			sum=sum*2ll;
			for(int i=0;i<v1.size()-v0.size();i++) sum-=1ll*v1[i];
		}
		cout<<sum<<'\n';
	}
	return 0;
}