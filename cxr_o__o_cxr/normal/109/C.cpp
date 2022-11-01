//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
#define ll long long
const int N=1e5+4;
struct edge{
	int v,w,nxt;
}e[N<<1];
int first[N],cnt;
inline void add(int u,int v,int w){
	e[++cnt].v=v;e[cnt].w=w;
	e[cnt].nxt=first[u];first[u]=cnt;
}
inline bool check(int x){
	while(x){
		if(x%10!=4&&x%10!=7)return 0;
		x/=10;
	}
	return 1;
}
int n,siz[N],f[N],g[N];
ll ans;
void dfs_1(int x,int fa){
	siz[x]=1;
	for(int i=first[x],v;i;i=e[i].nxt){
		v=e[i].v;
		if(v==fa)continue;
		dfs_1(v,x);
		siz[x]+=siz[v];
		f[x]+=e[i].w?siz[v]:f[v];
	}
}
void dfs_2(int x,int fa,int w){
	if(w)g[x]=n-siz[x];
	else g[x]=g[fa]+f[fa]-(w?siz[x]:f[x]);
	ans+=(ll)(g[x]+f[x])*(g[x]+f[x]-1);
	for(int i=first[x],v;i;i=e[i].nxt){
		v=e[i].v;
		if(v==fa)continue;
		dfs_2(v,x,e[i].w);
	}
}
int main(){
	n=read();
	for(int i=1,u,v,w;i<n;i++){
		u=read();v=read();w=check(read());
		add(u,v,w);add(v,u,w);
	}
	dfs_1(1,0);
	dfs_2(1,0,1);
	cout<<ans<<"\n"; 
	return (0-0);
}