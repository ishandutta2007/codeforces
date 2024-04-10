#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,m,q,add[100004],to;
int u,v[100004],w[100004];
vector<int>g[100004];
ll dis[100004];
void dij(){
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >pq;
	fill(dis+1,dis+n+1,1e18);
	dis[1]=0;pq.push({0,1});
	while(!pq.empty()){
		auto [val,x]=pq.top();pq.pop();
		if(val>dis[x])continue;
		for(auto y:g[x]){
			to=v[y];
			if(dis[to]>val+w[y])dis[to]=val+w[y],pq.push({dis[to],to});
		}
	}
}
int tot,head[100004],nxt[200004],info[200004];
void ins(int k,int x){
	info[++tot]=x,nxt[tot]=head[k],head[k]=tot;
}
int top(int k){
	int ret=info[head[k]];
	head[k]=nxt[head[k]];
	return ret;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v[i],&w[i]);
		g[u].push_back(i);
	}
	dij();
	while(q--){
		int op,x;scanf("%d%d",&op,&x);
		if(op==1){
			if(dis[x]<1e18)printf("%I64d\n",dis[x]);
			else puts("-1");
		}else{
			tot=0;
			for(register int i=0;i<x;++i){
				int p;scanf("%d",&p);
				w[p]++;
			}
			fill(add+1,add+n+1,x+1);
			ins(add[1]=0,1);
			for(register int i=0;i<=x;++i)
				for(;head[i];){
					register int j=top(i);
					if(add[j]<i)continue;
					for(auto y:g[j]){
						to=v[y];
						register ll val=dis[j]+add[j]+w[y]-dis[to];
						if(val<add[to])ins(add[to]=val,to);
					}
				}
			for(register int i=1;i<=n;++i)dis[i]+=add[i];
		}
	}
}