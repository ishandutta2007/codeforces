#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000000000000007ll
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

int n,m,x[200010],p[200010],a[600010];
vector<int> v[600010];
map<int,int> mp,pm;

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>x[i]>>p[i];
		mp.clear();pm.clear();
		for(int i=1;i<=n;i++){
			mp[x[i]-p[i]+1]=1;mp[x[i]+1]=1;mp[x[i]+p[i]+1]=1;
		}
		int cnt=0;
		for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
			cnt++;pm[it->first]=cnt;a[cnt]=(it->first);
		}
		for(int i=1;i<=cnt;i++) v[i].clear();
		for(int i=1;i<=n;i++){
			v[pm[x[i]-p[i]+1]].push_back(0);
			v[pm[x[i]+1]].push_back(1);
			v[pm[x[i]+p[i]+1]].push_back(2);
		}
		long long val=0ll,v1=-INF,v2=-INF;
		int num=0;
		for(int i=1;i<=cnt;i++){
			if(val>1ll*m){
				v1=max(v1,val-1ll*m+1ll*(a[i]-1));
				v2=max(v2,val-1ll*m-1ll*(a[i]-1));
			}
			for(int j=0;j<v[i].size();j++){
				if(v[i][j]==0) num++;
				else if(v[i][j]==1) num-=2;
				else num++;
			}
			val+=1ll*num;
			if(val>1ll*m){
				v1=max(v1,val-1ll*m+1ll*a[i]);
				v2=max(v2,val-1ll*m-1ll*a[i]);
			}
			if(i<cnt){
				val+=1ll*(a[i+1]-a[i]-1)*num;
			}
		}
		for(int i=1;i<=n;i++){
			if(1ll*p[i]+1ll*x[i]>=v1&&1ll*p[i]-1ll*x[i]>=v2) cout<<1;
			else cout<<0;
		}
		cout<<'\n';
	}
	return 0;
}