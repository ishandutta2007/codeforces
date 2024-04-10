#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e5+4;
int n,Q,dep[N],fa[N][20],siz[N],son[N],sum[N],vis[N],ans[N];
vector<int>e[N];
vector<pair<int,int> >q[N];
void dfs_1(int x){
	dep[x]=dep[fa[x][0]]+1;
	for(int i=1;(1<<i)<=dep[x];i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	siz[x]=1;
	for(auto v:e[x]){
		dfs_1(v);
		siz[x]+=siz[v];
		if(siz[v]>siz[son[x]])son[x]=v;
	}
}
inline int jump(int x,int k){
	for(int i=18;i>=0;i--)
		if((k>>i)&1)x=fa[x][i];
	return x;
}
void calc(int x,int fl){
	sum[dep[x]]+=fl;
	for(auto v:e[x])
		if(!vis[v])calc(v,fl);
}
void dfs_2(int x,int keep){
	for(auto v:e[x])if(v!=son[x])dfs_2(v,0);
	if(son[x]){
		dfs_2(son[x],1);
		vis[son[x]]=1;
	}
	calc(x,1);
	for(auto v:q[x])
		ans[v.second]=sum[v.first]-1;
	if(son[x])vis[son[x]]=0;
	if(!keep)calc(x,-1);
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)e[fa[i][0]=read()].push_back(i);
	for(int i=1;i<=n;i++)
		if(!fa[i][0])dfs_1(i);
	Q=read();
	for(int i=1,x;i<=Q;i++){
		x=read();
		q[jump(x,read())].push_back(make_pair(dep[x],i));
	} 
	for(int i=1;i<=n;i++)
		if(!fa[i][0])dfs_2(i,0);
	for(int i=1;i<=Q;i++)cout<<ans[i]<<" ";
	return (0-0);
}