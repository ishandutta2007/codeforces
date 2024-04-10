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

int n,a[100010],sum[100010];
vector<int> v[100010];

inline void dfs(int x,int pr,int val,bool flag)
{
	if(!flag){
		vector<int> res;
		for(int i=0;i<v[x].size();i++) if(v[x][i]!=pr){
			res.push_back(v[x][i]);
		}
		if(res.empty()) a[x]=1,sum[x]=1;
		else{
			dfs(res[0],x,0,0);
			int now=sum[res[0]];
			a[x]=-((pr!=-1)+(int)res.size())*now;
			sum[x]=a[x]+now;
			for(int i=1;i<res.size();i++){
				dfs(res[i],x,-now,1);sum[x]+=sum[res[i]];
			}
		}
	}
	else{
		vector<int> res;
		for(int i=0;i<v[x].size();i++) if(v[x][i]!=pr){
			res.push_back(v[x][i]);
		}
		if(res.empty()) a[x]=-val,sum[x]=-val;
		else{
			a[x]=-(1+(int)res.size())*val;
			sum[x]=a[x];
			for(int i=0;i<res.size();i++){
				dfs(res[i],x,-val,1);sum[x]+=sum[res[i]];
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int root=-1;
		for(int i=1;i<=n;i++) if(v[i].size()>1){
			root=i;break;
		}
		dfs(root,-1,0,0);
		for(int i=1;i<=n;i++) cout<<a[i]<<' ';
		cout<<'\n';
	}
	return 0;
}