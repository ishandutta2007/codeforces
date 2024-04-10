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

int n,val[200010],p[200010],mx[200010],pre[200010],vis[200010];
vector<pair<int,pair<int,int> > > v[200010];
vector<pair<int,int> > now[200010];

inline void add(int &x,int y)
{
	x+=y;
	if(x>=MOD) x-=MOD;
}

inline int my_pow(int x,int y)
{
	if(y==0) return 1;
	if(y==1) return x;
	int res=my_pow(x,y/2);
	if(y%2==0) return 1ll*res*res%MOD;
	else return 1ll*res*res%MOD*x%MOD;
}

inline void init()
{
	for(int i=1;i<=200000;i++) pre[i]=i;
	for(int i=2;i<=200000;i++){
		if(!vis[i]){
			for(int j=i;j<=200000;j+=i){
				vis[j]=1;
				now[j].push_back(make_pair(i,0));
				while(pre[j]%i==0) pre[j]/=i,now[j].back().second++;
			}
		}
	}
}

inline void dfs(int x,int pr)
{
	for(int i=0;i<v[x].size();i++) if(v[x][i].first!=pr){
		int a=v[x][i].second.first,b=v[x][i].second.second;
		val[v[x][i].first]=1ll*val[x]*b%MOD*my_pow(a,MOD-2)%MOD;
		dfs(v[x][i].first,x);
	}
}

inline void dfs2(int x,int pr)
{
	for(int i=0;i<v[x].size();i++) if(v[x][i].first!=pr){
		int a=v[x][i].second.first,b=v[x][i].second.second;
		for(int j=0;j<now[a].size();j++){
			p[now[a][j].first]+=now[a][j].second;
		}
		for(int j=0;j<now[b].size();j++){
			p[now[b][j].first]-=now[b][j].second;
		}
		for(int j=0;j<now[a].size();j++){
			mx[now[a][j].first]=max(mx[now[a][j].first],p[now[a][j].first]);
		}
		for(int j=0;j<now[b].size();j++){
			mx[now[b][j].first]=max(mx[now[b][j].first],p[now[b][j].first]);
		}
		dfs2(v[x][i].first,x);
		for(int j=0;j<now[a].size();j++){
			p[now[a][j].first]-=now[a][j].second;
		}
		for(int j=0;j<now[b].size();j++){
			p[now[b][j].first]+=now[b][j].second;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	init();
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++){
			int x,y,a,b;cin>>x>>y>>a>>b;
			v[x].push_back(make_pair(y,make_pair(a,b)));
			v[y].push_back(make_pair(x,make_pair(b,a)));
		}
		val[1]=1;dfs(1,-1);
		int sum=0;
		for(int i=1;i<=n;i++) add(sum,val[i]);
		for(int i=1;i<=n;i++) p[i]=0,mx[i]=0;
		dfs2(1,-1);
		for(int i=1;i<=n;i++) sum=1ll*sum*my_pow(i,mx[i])%MOD;
		cout<<sum<<'\n';
	}
	return 0;
}