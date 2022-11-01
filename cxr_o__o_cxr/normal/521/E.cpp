//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=2e5+4;
struct edge{
	int v,nxt;
}e[N<<1];
int first[N],cnt=1;
inline void add(int u,int v){
	e[++cnt]=(edge){v,first[u]};first[u]=cnt;
}
int n,m,vis[N],dep[N],tag[N<<1],fa[N];
void dfs(int x){
	vis[x]=1;
	dep[x]=dep[fa[x]]+1;
	for(int i=first[x],v;i;i=e[i].nxt){
		v=e[i].v;
		if(vis[v])continue;
		tag[i]=tag[i^1]=1;
		fa[v]=x;
		dfs(v);
	}
}
inline int getlca(int u,int v){
	if(dep[u]<dep[v])u^=v^=u^=v;
	while(dep[u]>dep[v])u=fa[u];
	while(u!=v){u=fa[u];v=fa[v];}
	return u;
}
void out(int s,int t){
	if(s!=t)out(s,fa[t]);
	cout<<t<<" ";
}
inline void solve(int e1,int e2){
	int u1=e[e1].v,v1=e[e1^1].v,u2=e[e2].v,v2=e[e2^1].v;
	if(dep[u1]>dep[v1])u1^=v1^=u1^=v1;
	if(dep[u2]>dep[v2])u2^=v2^=u2^=v2;
	int s=getlca(v1,v2),t=dep[u1]>dep[u2]?u1:u2;
	cout<<dep[v1]-dep[s]+dep[t]-dep[u1]+2<<" ";out(s,v1);out(u1,t);puts("");
	cout<<dep[v2]-dep[s]+dep[t]-dep[u2]+2<<" ";out(s,v2);out(u2,t);puts("");
	cout<<dep[s]-dep[t]+1<<" ";
	while(s!=t){
		cout<<s<<" ";
		s=fa[s];
	}
	cout<<t<<"\n";
}
int main(){
	n=read();m=read();
	for(int i=1,u,v;i<=m;i++){
		u=read();v=read();
		add(u,v);add(v,u);
	} 
	for(int i=1;i<=n;i++)
		if(!vis[i])dfs(i);
	memset(vis,0,sizeof(vis));
	for(int i=2,u,v;i<=cnt;i+=2)if(!tag[i]){
		u=e[i].v;v=e[i^1].v;
		if(dep[u]>dep[v])u^=v^=u^=v;
		while(u!=v){
			if(vis[v]){
				puts("YES");
				solve(vis[v],i);
				return (0-0); 
			}
			vis[v]=i;
			v=fa[v];
		}
	}
	puts("NO");
	return (0-0);
}