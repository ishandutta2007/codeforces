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

int n,tot,num[300010],val[300010],sum[300010],deg[300010];
pair<int,int> a[100010],b[100010];
vector<int> v[300010],rev[300010],g[300010],res;
bool vis[300010];

inline void dfs(int x)
{
	vis[x]=1;
	for(int i=0;i<v[x].size();i++) if(!vis[v[x][i]]){
		dfs(v[x][i]); 
	}
	res.push_back(x);
}

inline void rdfs(int x,int id)
{
	num[x]=id;vis[x]=1;
	if(x<=n) val[id]++;
	for(int i=0;i<rev[x].size();i++) if(!vis[rev[x][i]]){
		rdfs(rev[x][i],id);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].first,a[i].second=i;
		for(int i=1;i<=n;i++) cin>>b[i].first,b[i].second=i;
		sort(a+1,a+n+1);sort(b+1,b+n+1);
		for(int i=1;i<=3*n;i++) v[i].clear(),rev[i].clear(),g[i].clear();
		for(int i=n+1;i<=2*n;i++){
			v[i].push_back(a[i-n].second);
			rev[a[i-n].second].push_back(i);
			if(i>n+1) v[i].push_back(i-1),rev[i-1].push_back(i);
		}
		for(int i=2*n+1;i<=3*n;i++){
			v[i].push_back(b[i-2*n].second);
			rev[b[i-2*n].second].push_back(i);
			if(i>2*n+1) v[i].push_back(i-1),rev[i-1].push_back(i);
		}
		for(int i=2;i<=n;i++){
			v[a[i].second].push_back(n+i-1);
			rev[n+i-1].push_back(a[i].second);
		}
		for(int i=2;i<=n;i++){
			v[b[i].second].push_back(2*n+i-1);
			rev[2*n+i-1].push_back(b[i].second);
		}
		for(int i=1;i<=3*n;i++) vis[i]=0;
		res.clear();
		for(int i=1;i<=3*n;i++) if(!vis[i]){
			dfs(i);
		}
		for(int i=1;i<=3*n;i++) vis[i]=0,num[i]=0,deg[i]=0,val[i]=0;
		tot=0;
		for(int i=res.size()-1;i>=0;i--) if(!vis[res[i]]){
			tot++;rdfs(res[i],tot);
		}
		for(int i=1;i<=3*n;i++){
			for(int j=0;j<v[i].size();j++){
				int u=v[i][j];
				if(num[i]!=num[u]) g[num[i]].push_back(num[u]),deg[num[u]]++;
			}
		}
		queue<int> q; 
		for(int i=1;i<=3*n;i++) sum[i]=0;
		for(int i=1;i<=3*n;i++) if(deg[i]==0) q.push(i),sum[i]=val[i];
		while(!q.empty()){
			int t=q.front();q.pop();
			for(int i=0;i<g[t].size();i++){
				int u=g[t][i];
				sum[u]+=sum[t];deg[u]--;
				if(deg[u]==0){
					sum[u]+=val[u];
					q.push(u);
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(sum[num[i]]==val[num[i]]) cout<<'1';
			else cout<<'0';
		}
		cout<<'\n';
	}
	return 0;
}