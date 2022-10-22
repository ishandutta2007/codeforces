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

int n,m,col[200010],xx[200010],yy[200010];
vector<pair<int,int> > v[200010];
vector<pair<int,int> > u[200010];
bool vis[200010],used[200010];

inline void dfs1(int x,int pr)
{
	vis[x]=1;
	for(int i=0;i<v[x].size();i++) if(v[x][i].first!=pr){
		if(!vis[v[x][i].first]){
			dfs1(v[x][i].first,x);
			u[x].push_back(make_pair(v[x][i].first,v[x][i].second));
			u[v[x][i].first].push_back(make_pair(x,v[x][i].second));
			col[v[x][i].second]=1;
		}
	}
}

inline void dfs2(int x,int pr)
{
	used[x]=1;
	for(int i=0;i<u[x].size();i++) if(u[x][i].first!=pr){
		if(!used[u[x][i].first]){
			dfs2(u[x][i].first,x);
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) v[i].clear(),u[i].clear(),vis[i]=0;
		for(int i=1;i<=m;i++) col[i]=0;
		for(int i=1;i<=m;i++){
			cin>>xx[i]>>yy[i];
			v[xx[i]].push_back(make_pair(yy[i],i));
			v[yy[i]].push_back(make_pair(xx[i],i));
		}
		dfs1(1,-1);
		for(int i=1;i<=n;i++) used[i]=0;
		for(int i=1;i<=m;i++) if(!col[i]){
			used[xx[i]]=1;used[yy[i]]=1;
		}
		vector<int> g;
		for(int i=1;i<=n;i++) if(used[i]) g.push_back(i);
		if(m==n+2&&g.size()==3){
			int pos=-1;
			for(int i=1;i<=m;i++) if(!col[i]){
				pos=i;break;
			}
			for(int i=1;i<=n;i++) used[i]=0;
			used[xx[pos]]=1;
			for(int i=0;i<u[xx[pos]].size();i++){
				dfs2(u[xx[pos]][i].first,xx[pos]);
				if(used[yy[pos]]){
					col[u[xx[pos]][i].second]=0;
					col[pos]=1;
					break;
				}
			}
		}
		for(int i=1;i<=m;i++) cout<<col[i];
		cout<<'\n';
	}
	return 0;
}