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

int a[500010];

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vector<int> v;
		for(int i=1;i<=n;i++){
			int x;cin>>x;v.push_back(x); 
		}
		bool flag=false;
		for(int i=1;i<=n-1;i++){
			vector<int> nw;
			for(int j=1;j<v.size();j++) nw.push_back(v[j]-v[j-1]);
			if(v.size()<n-i+1) nw.push_back(v[0]);
			sort(nw.begin(),nw.end());
			v.clear();
			for(int j=0;j<nw.size();j++) if(nw[j]!=0) v.push_back(nw[j]);
			if(v.empty()){
				cout<<0<<'\n';
				flag=true;break;
			}
		}
		if(!flag) cout<<v[0]<<'\n';
	}
	return 0;
}