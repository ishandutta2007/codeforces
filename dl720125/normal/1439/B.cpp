#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
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

int n,m,k,deg[100010];
vector<int> v[100010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++) deg[i]=0,v[i].clear();
		cc_hash_table<long long,bool> mp;
		for(int i=1;i<=m;i++){
			int x,y;cin>>x>>y;
			v[x].push_back(y);v[y].push_back(x);
			mp[1ll*x*n+1ll*y]=1;mp[1ll*y*n+1ll*x]=1;
			deg[x]++;deg[y]++;
		}
		set<pair<int,int> > s;
		for(int i=1;i<=n;i++) s.insert(make_pair(deg[i],i));
		bool flag=false; 
		while(!s.empty()){
			int val=s.begin()->first,x=s.begin()->second;
			if(val==k-1){
				bool ok=true;
				vector<int> res;
				for(int i=0;i<v[x].size();i++){
					int u=v[x][i];
					if(deg[u]){
						for(int j=0;j<res.size();j++) if(!mp[1ll*u*n+1ll*res[j]]){
							ok=false;break;
						}
						if(!ok) break;
						res.push_back(u);
					}
				}
				if(ok){
					flag=true;
					res.push_back(x);
					cout<<2<<'\n';
					for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
					cout<<'\n';
					break;
				}
			}
			if(val>=k){
				flag=true;
				cout<<1<<" "<<s.size()<<'\n';
				while(!s.empty()){
					cout<<s.begin()->second<<" ";s.erase(s.begin());
				}
				cout<<'\n';
				break;
			}
			s.erase(s.begin());
			for(int i=0;i<v[x].size();i++){
				int u=v[x][i];
				if(deg[u]){
					deg[x]--;
					s.erase(s.find(make_pair(deg[u],u)));
					deg[u]--;
					if(deg[u]) s.insert(make_pair(deg[u],u));
				}
			}
		}
		if(!flag) cout<<-1<<'\n';
	}
	return 0;
}