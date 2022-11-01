#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e5+4;
int n,col[N],son[N],siz[N],ans[N],num[N],vis[N],mx,sum;
vector<int>e[N];
void dfs_1(int x,int fa){
	siz[x]=1;
	for(auto v:e[x]){
		if(v==fa)continue;
		dfs_1(v,x);
		siz[x]+=siz[v];
		if(siz[v]>siz[son[x]])son[x]=v;
	} 
}
void calc(int x,int fa,int fl){
	num[col[x]]+=fl;
	if(fl==1&&num[col[x]]>=mx){
		if(num[col[x]]>mx){sum=col[x];mx=num[col[x]];}
		else sum+=col[x]; 
	}
	for(auto v:e[x])
		if(v!=fa&&!vis[v])calc(v,x,fl);
}
void dfs_2(int x,int fa,int keep){
	for(auto v:e[x])
		if(v!=fa&&v!=son[x])dfs_2(v,x,0);
	if(son[x]){
		dfs_2(son[x],x,1);
		vis[son[x]]=1;
	}
	calc(x,fa,1);
	ans[x]=sum;
	if(son[x])vis[son[x]]=0;
	if(!keep){calc(x,fa,-1);sum=mx=0;}
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)col[i]=read();
	for(int i=1,u,v;i<n;i++){
		u=read();v=read();
		e[u].push_back(v);e[v].push_back(u);
	}
	dfs_1(1,0);dfs_2(1,0,1);
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return (0-0);
}