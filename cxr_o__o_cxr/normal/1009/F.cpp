#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e6+4;
int n,ans[N],g[N],dep[N],son[N],*f[N],*nw=g;
vector<int>e[N];
void dfs_1(int x,int fa){
	for(auto v:e[x]){
		if(v==fa)continue;
		dfs_1(v,x);
		if(dep[v]>dep[son[x]])son[x]=v;
	}
	dep[x]=dep[son[x]]+1;
}
void dfs_2(int x,int fa){
	f[x][0]=1;
	if(son[x]){
		f[son[x]]=f[x]+1;
		dfs_2(son[x],x);
		ans[x]=ans[son[x]]+1;
	}
	for(auto v:e[x]){
		if(v==fa||v==son[x])continue;
		f[v]=nw;nw+=dep[v];
		dfs_2(v,x);
		for(int i=1;i<=dep[v];i++){
			f[x][i]+=f[v][i-1];
			if(f[x][i]>f[x][ans[x]]||(f[x][i]==f[x][ans[x]]&&i<ans[x]))ans[x]=i;
		}
	} 
	if(f[x][ans[x]]==1)ans[x]=0;
}
int main(){
	n=read();
	for(int i=1,u,v;i<n;i++){
		u=read();v=read();
		e[u].push_back(v);e[v].push_back(u);
	}
	dfs_1(1,0);
	f[1]=nw;nw+=dep[1];
	dfs_2(1,0);
	for(int i=1;i<=n;i++)cout<<ans[i]<<"\n";
	return (0-0);
}