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

pair<int,int> d[100010];
int vis[100010],col[100010];
vector<int> v[100010];

inline void dfs(int x,int id)
{
	col[x]=id;
	for(int i=0;i<v[x].size();i++) if(!col[v[x][i]]){
		dfs(v[x][i],id);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) cin>>d[i].first,d[i].second=i;
		sort(d+1,d+n+1);
		for(int i=1;i<=n;i++) vis[i]=0,v[i].clear();
		for(int i=n;i>=1;i--) if(!vis[d[i].second]){
			int x=d[i].second,y=d[i].first;vis[x]=1;
			while(y--){
				cout<<"? "<<x<<'\n';fflush(stdout);
				int u;cin>>u;v[x].push_back(u);v[u].push_back(x);
				if(vis[u]) break;
				vis[u]=1;
			}
		}
		for(int i=1;i<=n;i++) col[i]=0;
		int tot=0;
		for(int i=1;i<=n;i++) if(!col[i]){
			tot++;dfs(i,tot);
		}
		cout<<"! ";
		for(int i=1;i<=n;i++) cout<<col[i]<<' ';
		cout<<'\n';
		fflush(stdout);
	}
	return 0;
}