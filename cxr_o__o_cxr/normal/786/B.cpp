#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e5+4,inf=1e18;
int n,m,s,dis[N*10],vis[N*10];
struct edge{int v,w;};
vector<edge>e[N*10];
#define lc (p<<1)
#define rc (p<<1|1)
struct segment{
	int tin[N<<2],tou[N<<2],cnt;//in out 
	inline void build(int p,int l,int r){
		if(l==r){
			tin[p]=tou[p]=l;
			return;
		}
		int mid=(l+r)>>1;
		build(lc,l,mid);build(rc,mid+1,r);
		tin[p]=++cnt;tou[p]=++cnt;
		e[tou[lc]].push_back((edge){tou[p],0});
		e[tou[rc]].push_back((edge){tou[p],0});
		e[tin[p]].push_back((edge){tin[lc],0});
		e[tin[p]].push_back((edge){tin[rc],0});
	}
	inline void modify_in(int u,int p,int l,int r,int L,int R,int w){
		if(L<=l&&r<=R){
			e[u].push_back((edge){tin[p],w});
			return;
		}
		int mid=(l+r)>>1;
		if(L<=mid)modify_in(u,lc,l,mid,L,R,w);
		if(mid<R)modify_in(u,rc,mid+1,r,L,R,w);//
	}
	inline void modify_out(int v,int p,int l,int r,int L,int R,int w){
		if(L<=l&&r<=R){
			e[tou[p]].push_back((edge){v,w});
			return;
		}
		int mid=(l+r)>>1;
		if(L<=mid)modify_out(v,lc,l,mid,L,R,w);
		if(mid<R)modify_out(v,rc,mid+1,r,L,R,w);
	}
}t;
inline void dijkstra(){
	memset(dis,-1,sizeof(dis));
	priority_queue<pair<int,int> >q;
	q.push(make_pair(0,s));
	dis[s]=0;
	while(!q.empty()){
		int x=q.top().second;q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=0,v,w;i<e[x].size();i++){
			v=e[x][i].v;w=e[x][i].w;
			if(dis[v]==-1||dis[v]>dis[x]+w){
				dis[v]=dis[x]+w;
				q.push(make_pair(-dis[v],v));
			}
		}
	} 
}
signed main(){
	n=read();m=read();s=read();
	t.cnt=n;t.build(1,1,n);
	for(int i=1,fl,a,b,c,v;i<=m;i++){
		fl=read();a=read();b=read();c=read();
		if(fl==1){
			e[a].push_back((edge){b,c});
			continue;
		}
		v=read();
		if(fl==2)t.modify_in(a,1,1,n,b,c,v);
		else t.modify_out(a,1,1,n,b,c,v);
	}
	dijkstra();
	for(int i=1;i<=n;i++)
		printf("%lld ",dis[i]);
	return (0-0);
}