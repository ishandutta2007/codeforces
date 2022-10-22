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
		if(n>m){
			cout<<"No\n";continue;
		}
		if(n%2==1){
			cout<<"Yes\n";
			for(int i=1;i<=n-1;i++) cout<<1<<' ';
			cout<<m-n+1<<'\n';
			continue;
		}
		if((m-n)%2==1){
			cout<<"No\n";continue;
		}
		cout<<"Yes\n";
		int val=m/n,rem=m%n;
		for(int i=1;i<=n-rem;i++) cout<<val<<' ';
		for(int i=1;i<=rem;i++) cout<<val+1<<' ';
		cout<<'\n';
	}
	return 0;
}