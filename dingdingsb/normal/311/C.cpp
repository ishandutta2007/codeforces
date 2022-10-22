#include<bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
namespace Graph{
	const int N=1e4+10;
	ll dis[N];bool vis[N];
	vector<pair<ll,int>>E[N];
	void init(){
		for(int i=0;i<N;i++)E[i].clear();
		memset(dis,0x7f,sizeof dis); 
		memset(vis,0,sizeof vis);
	}
	void add(int u,int v,ll w){
		E[u].push_back({v,w});
	}
	void Dij(int s=1){
		dis[s]=0;
		priority_queue<pair<ll,int>>q;q.push({0,s});
		while(q.size()){
			int u=q.top().second;q.pop();
			if(vis[u])continue;vis[u]=1;
			for(auto [v,w]:E[u])
				if(dis[v]>dis[u]+w)
					dis[v]=dis[u]+w,q.push({-dis[v],v});
		}
	}
}
const int N=1e5+10;
ll a[N];ll c[N];
priority_queue<pair<int,int>>q;
int n,m;ll h;
int k;vector<ll>s;
void Deal(){
	while(q.size())q.pop();
	Graph::init();
	for(int i=0;i<k;i++){
		for(auto v:s)
			Graph::add(i,(i+v)%k,(i+v)/k);
	}
	Graph::Dij();
	for(int i=1;i<=n;i++)
		if(c[i]/k>=Graph::dis[c[i]%k])
			q.push({a[i],-i});
}
signed main(){
	scanf("%lld%lld%lld%lld",&h,&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&c[i],&a[i]); 
	Deal();
	while(m--){
		int op;scanf("%lld",&op);
		if(op==1){
			int x;scanf("%lld",&x);
			s.push_back(x);Deal();
		}else if(op==2){
			int x,y;scanf("%lld%lld",&x,&y);
			a[x]-=y;
		}else{
			if(!q.size()){
				puts("0");continue;}
			auto p=q.top();q.pop();
			while(a[-p.second]!=p.first){
				p.first=a[-p.second];q.push(p);
				p=q.top(),q.pop();
			}
			printf("%lld\n",p.first);
			p.first=a[-p.second]=0;
			q.push(p);
		}
	}
}