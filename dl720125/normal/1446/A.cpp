#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
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

int a[200010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,w;cin>>n>>w;
		for(int i=1;i<=n;i++) cin>>a[i];
		int sum=0,r=(w+1)/2;
		vector<int> v;
		for(int i=1;i<=n;i++) if(a[i]<=w){
			v.push_back(i);sum+=a[i];
		}
		if(sum<r) cout<<-1<<'\n';
		else{
			bool flag=false;
			for(int i=0;i<v.size();i++){
				if(a[v[i]]>=r){
					cout<<1<<'\n'<<v[i]<<'\n';
					flag=true;
					break;
				}
			}
			if(!flag){
				for(int i=0;i<v.size();i++){
					if(sum<=w){
						cout<<v.size()-i<<'\n';
						for(int j=i;j<v.size();j++) cout<<v[j]<<" ";
						cout<<'\n';
						break;
					}
					sum-=a[v[i]];
				}
			}
		}
	}
	return 0;
}