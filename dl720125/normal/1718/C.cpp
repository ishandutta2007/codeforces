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

int n,q,a[200010];

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n>>q;
		for(int i=1;i<=n;i++) cin>>a[i];
		vector<int> vec,v;
		for(int i=1;i<n;i++) if(n%i==0) vec.push_back(i);
		for(int i=0;i<vec.size();i++){
			bool flag=true;
			for(int j=i+1;j<vec.size();j++) if(vec[j]%vec[i]==0){
				flag=false;break;
			}
			if(flag) v.push_back(vec[i]);
		}
		int tot=v.size();
		vector<vector<long long> > g;
		vector<multiset<long long> > s;
		g.resize(tot);s.resize(tot);
		for(int i=0;i<v.size();i++) g[i].resize(v[i],0);
		for(int i=1;i<=n;i++){
			for(int j=0;j<v.size();j++){
				int id=i%v[j];
				g[j][id]+=1ll*a[i];
			}
		}
		for(int i=0;i<v.size();i++) for(int j=0;j<v[i];j++) s[i].insert(-g[i][j]);
		long long ans=0ll;
		for(int i=0;i<v.size();i++) ans=max(ans,1ll*v[i]*(-(*s[i].begin())));
		cout<<ans<<'\n';
		for(int i=1;i<=q;i++){
			int p,x;cin>>p>>x;
			ans=0ll;
			for(int j=0;j<v.size();j++){
				int id=p%v[j];
				s[j].erase(s[j].find(-g[j][id]));
				g[j][id]-=1ll*a[p];g[j][id]+=1ll*x;
				s[j].insert(-g[j][id]);
				ans=max(ans,1ll*v[j]*(-(*s[j].begin())));
			}
			a[p]=x;
			cout<<ans<<'\n';
		}
	}
	return 0;
}