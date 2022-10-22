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
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int a,b;cin>>a>>b;
		vector<int> v;
		if((a+b)%2==0){
			int x=(a+b)/2;
			for(int i=0;i<=x;i++){
				if(a-i>=0&&a-i<=x) v.push_back(a-i+x-i);
			}
		}
		else{
			int x=(a+b)/2;
			for(int i=0;i<=x;i++){
				if(a-i>=0&&a-i<=x+1) v.push_back(a-i+x-i);
			}
			for(int i=0;i<=x+1;i++){
				if(a-i>=0&&a-i<=x) v.push_back(a-i+x+1-i);
			}
		}
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		cout<<v.size()<<'\n';
		for(int i=0;i<v.size();i++) cout<<v[i]<<' ';
		cout<<'\n';
	}
	return 0;
}