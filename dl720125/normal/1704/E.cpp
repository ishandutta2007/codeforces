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

int a[1010],vis[1010],deg[1010],dist[1010];
vector<int> v[1010];

inline void add(int &x,int y)
{
	x+=y;
	if(x>=MOD) x-=MOD;
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		int ans=0;
		for(int i=1;i<=n;i++) v[i].clear(),deg[i]=0;
		for(int i=1;i<=m;i++){
			int x,y;cin>>x>>y;
			v[x].push_back(y);deg[y]++;
		}
		int root=-1;
		for(int i=1;i<=n;i++) if(v[i].size()==0) root=i;
		bool ok=true;
		for(int i=1;i<=n;i++){
			bool flag=false;
			for(int j=1;j<=n;j++) if(a[j]!=0){
				flag=true;break;
			}
			if(!flag){
				ok=false;break;
			}
			add(ans,1);
			for(int j=1;j<=n;j++) vis[j]=0;
			for(int j=1;j<=n;j++) if(a[j]!=0){
				a[j]--;vis[j]=1;
			}
			for(int j=1;j<=n;j++) if(vis[j]){
				for(int k=0;k<v[j].size();k++) a[v[j][k]]++;
			}
		}
		if(!ok){
			cout<<ans<<'\n';
			continue;
		}
		queue<int> q;
		for(int i=1;i<=n;i++) dist[i]=0;
		for(int i=1;i<=n;i++) if(deg[i]==0){
			add(dist[i],a[i]);q.push(i);
		}
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int i=0;i<v[x].size();i++){
				int u=v[x][i];
				add(dist[u],dist[x]);deg[u]--;
				if(deg[u]==0){
					add(dist[u],a[u]);
					q.push(u);
				}
			}
		}
		add(ans,dist[root]);
		cout<<ans<<'\n';
	}
	return 0;
}