//starusc
/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=2e5+4,M=3e5+4;
struct edge{
	int v,w,nxt;
}e[M<<1];
int first[N],cnt;
inline void add(int u,int v,int w){
	e[++cnt].v=v;e[cnt].w=w;
	e[cnt].nxt=first[u];first[u]=cnt;
}
int n,m,s,dis[N],vis[N];
priority_queue<pair<int,int> >q;
inline void dijkstra(){
	dis[s]=1;q.push(make_pair(-1,s));
	while(!q.empty()){
		int x=q.top().second;q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=first[x],v;i;i=e[i].nxt){
			v=e[i].v;
			if(!dis[v]||dis[v]>dis[x]+e[i].w){
				dis[v]=dis[x]+e[i].w;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
}
int tim,ans,dfn[N],idx[N],cou[N],fa[N],sdom[N],idom[N];
vector<int>e1[N],e2[N],e_s[N],e_i[N]; 
void dfs_1(int x){
	dfn[x]=++tim;idx[tim]=x;
	for(auto v:e1[x])
		if(!dfn[v]){fa[v]=x;dfs_1(v);}
}
void dfs_ans(int x){
	cou[x]=1;
	for(auto v:e_i[x]){
		dfs_ans(v);
		cou[x]+=cou[v];
	}
}
namespace dsu{
	int fa[N],mn[N];
	int find(int x){
		if(x==fa[x])return x;
		int ret=find(fa[x]);
		if(dfn[sdom[mn[fa[x]]]]<dfn[sdom[mn[x]]])mn[x]=mn[fa[x]];
		return fa[x]=ret;
	}
}
inline void tarjan(){
	for(int i=tim,x;i>1;i--){
		x=idx[i];
		for(auto v:e2[x]){
			dsu::find(v);
			if(dfn[sdom[dsu::mn[v]]]<dfn[sdom[x]])sdom[x]=sdom[dsu::mn[v]];
		}
		e_s[sdom[x]].push_back(x);
		dsu::fa[x]=fa[x];
		x=idx[i-1];
		for(auto v:e_s[x]){
			dsu::find(v);
			if(sdom[dsu::mn[v]]==x)idom[v]=sdom[v];
			else idom[v]=dsu::mn[v];
		}
	}
	for(int i=2;i<=tim;i++){
		if(idom[idx[i]]!=sdom[idx[i]])idom[idx[i]]=idom[idom[idx[i]]];
		e_i[idom[idx[i]]].push_back(idx[i]);
	}
}
signed main(){
	n=read();m=read();s=read();
	for(int i=1,u,v,w;i<=m;i++){
		u=read();v=read();w=read();
		add(u,v,w);add(v,u,w); 
	}
	dijkstra();
	for(int i=1,u,v;i<cnt;i+=2){
		u=e[i].v;v=e[i+1].v;
		if(dis[u]==dis[v]+e[i].w){
			e1[v].push_back(u);
			e2[u].push_back(v);
		}
		else if(dis[v]==dis[u]+e[i].w){
			e1[u].push_back(v);
			e2[v].push_back(u);
		}
	}
	for(int i=1;i<=n;i++)sdom[i]=dsu::fa[i]=dsu::mn[i]=i;
	dfs_1(s);
	tarjan();
	dfs_ans(s);
	for(int i=1;i<=n;i++)
		if(i!=s)ans=max(ans,cou[i]);
	cout<<ans;
	return (0-0);
}