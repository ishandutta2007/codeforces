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

int n,m,q,a[300010],b[300010],num[300010];
vector<int> v[300010],g[300010],res;
bool vis[300010];

inline void dfs(int x)
{
	vis[x]=1;
	for(int i=0;i<v[x].size();i++) if(!vis[v[x][i]]){
		g[x].push_back(v[x][i]);
		g[v[x][i]].push_back(x);
		dfs(v[x][i]);
	}
}

inline bool dfs2(int x,int y,int pr)
{
	if(x==y){
		res.push_back(x);
		return true;
	}
	for(int i=0;i<g[x].size();i++) if(g[x][i]!=pr){
		if(dfs2(g[x][i],y,x)){
			res.push_back(x);
			return true;
		}
	}
	return false;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>a[i]>>b[i];
		num[a[i]]++;num[b[i]]++;
	}
	int cnt=0;
	for(int i=1;i<=n;i++) if(num[i]%2==1) cnt++;
	if(cnt>0){
		cout<<"NO\n";
		cout<<cnt/2<<"\n";
		return 0;
	}
	cout<<"YES\n";
	for(int i=1;i<=q;i++){
		res.clear();
		dfs2(a[i],b[i],-1);
		reverse(res.begin(),res.end());
		cout<<res.size()<<'\n';
		for(int j=0;j<res.size();j++) cout<<res[j]<<' ';
		cout<<'\n';
	}
	return 0;
}