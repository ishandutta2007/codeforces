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

int n,m,p[100010],val[100010],dep[100010],par[100010][20];
vector<int> v[100010];

inline int find_set(int x)
{
	return p[x]==x?x:p[x]=find_set(p[x]);
}

inline void dfs(int x,int pr)
{
	par[x][0]=pr;
	for(int i=0;i<v[x].size();i++) if(v[x][i]!=pr){
		dep[v[x][i]]=dep[x]+1;
		dfs(v[x][i],x);
	}
}

inline void init()
{
	for(int i=1;i<20;i++){
		for(int j=1;j<=n;j++){
			if(par[j][i-1]==-1) par[j][i]=-1;
			else par[j][i]=par[par[j][i-1]][i-1];
		}
	}
}

inline int lca(int x,int y)
{
	if(dep[x]>dep[y]) swap(x,y);
	for(int i=0;i<20;i++) if((dep[y]-dep[x])&(1<<i)) y=par[y][i];
	if(x==y) return x;
	for(int i=20-1;i>=0;i--) if(par[x][i]!=par[y][i]) x=par[x][i],y=par[y][i];
	return par[x][0];
}

inline int kth(int x,int k)
{
	for(int i=0;i<20;i++) if(k&(1<<i)){
		x=par[x][i];
	}
	return x;
}

inline void dfs2(int x,int pr)
{
	for(int i=0;i<v[x].size();i++) if(v[x][i]!=pr){
		val[v[x][i]]+=val[x];
		dfs2(v[x][i],x);
	}
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) p[i]=i;
	vector<pair<int,int> > e;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		int rootx=find_set(x),rooty=find_set(y);
		if(rootx!=rooty) v[x].push_back(y),v[y].push_back(x),p[rooty]=rootx;
		else e.push_back(make_pair(x,y));
	}
	dfs(1,-1);init();
	for(int i=0;i<e.size();i++){
		int x=e[i].first,y=e[i].second;
		int l=lca(x,y);
		if(l==x){
			val[1]++;val[y]++;
			int loc=kth(y,dep[y]-dep[x]-1);
			val[loc]--;
		}
		else if(l==y){
			val[1]++;val[x]++;
			int loc=kth(x,dep[x]-dep[y]-1);
			val[loc]--;
		}
		else{
			val[x]++;val[y]++;
		}
	}
	dfs2(1,-1);
	for(int i=1;i<=n;i++){
		if(val[i]==e.size()) cout<<1;
		else cout<<0;
	}
	cout<<'\n';
	return 0;
}