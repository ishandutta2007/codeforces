#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=2e5+4;
int n,Q,tot,siz[N],son[N],dep[N],ans[N],vis[N],a[N],fa[N];
vector<int>e[N];
vector<pair<int,int> >q[N];
map<int,bool>mp[N];
map<string,int>mp2;
void dfs_1(int x,int fa){
	siz[x]=1;
	dep[x]=dep[fa]+1;
	for(auto v:e[x]){
		if(v==fa)continue;
		dfs_1(v,x);
		siz[x]+=siz[v];
		if(siz[v]>siz[son[x]])son[x]=v;
	}
} 
void calc(int x,int fa,int fl){
	if(fl==1)mp[dep[x]][a[x]]=1;
	else mp[dep[x]].erase(a[x]); 
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
	for(auto v:q[x]){
		ans[v.second]=mp[v.first].size();
	}
	if(son[x])vis[son[x]]=0;
	if(!keep)calc(x,fa,-1);
}
string s;
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		cin>>s;
		if(!mp2[s])a[i]=mp2[s]=++tot;
		else a[i]=mp2[s];
		e[fa[i]=read()].push_back(i);
	}
	for(int i=1;i<=n;i++)
		if(!fa[i])dfs_1(i,0);
	Q=read();
	for(int i=1,x;i<=Q;i++){x=read();q[x].push_back(make_pair(dep[x]+read(),i));}
	for(int i=1;i<=n;i++)
		if(!fa[i])dfs_2(i,0,0);
	for(int i=1;i<=Q;i++)cout<<ans[i]<<"\n";
	return (0-0);
}