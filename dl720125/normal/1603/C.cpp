#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define MOD 998244353
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

inline void add(int &x,int y)
{
	x+=y;
	if(x>=MOD) x-=MOD;
}

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		int ans=0;
		vector<pair<int,int> > v;v.push_back(make_pair(a[n],1));
		for(int i=n-1;i>=1;i--){
			vector<int> res;
			int val=0;
			for(int j=0;j<(int)v.size();j++){
				int len=(a[i]-1)/v[j].first+1;
				add(val,1ll*(len-1)*v[j].second%MOD);
				b[a[i]/len]+=v[j].second;
				res.push_back(a[i]/len);
			}
			b[a[i]]++;
			res.push_back(a[i]);
			v.clear();
			for(int j=0;j<(int)res.size();j++){
				if(b[res[j]]){
					v.push_back(make_pair(res[j],b[res[j]]));
					b[res[j]]=0;
				}
			}
			add(ans,1ll*val*i%MOD);
		}
		cout<<ans<<'\n';
	}
	return 0;
}