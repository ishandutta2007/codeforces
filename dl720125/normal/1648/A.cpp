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

int n,m;
vector<int> r[100010],c[100010];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;cin>>x;
			r[x].push_back(j);
			c[x].push_back(i);
		}
	}
	long long ans=0ll;
	for(int i=1;i<=100000;i++) if(!r[i].empty()){
		sort(r[i].begin(),r[i].end());
		long long sum=0ll;
		for(int j=0;j<r[i].size();j++){
			ans+=1ll*r[i][j]*j-sum;
			sum+=1ll*r[i][j]; 
		}
	}
	for(int i=1;i<=100000;i++) if(!c[i].empty()){
		sort(c[i].begin(),c[i].end());
		long long sum=0ll;
		for(int j=0;j<c[i].size();j++){
			ans+=1ll*c[i][j]*j-sum;
			sum+=1ll*c[i][j]; 
		}
	}
	cout<<ans<<'\n';
	return 0;
}