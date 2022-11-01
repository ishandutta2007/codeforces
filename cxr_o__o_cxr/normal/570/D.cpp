#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=5e5+4;
int n,Q,siz[N],son[N],dis[N],dep[N],d[N],ans[N],vis[N];
char s[N];
vector<int>e[N];
vector<pair<int,int> >q[N];
void dfs_1(int x,int fa){
	siz[x]=1;
//	dis[x]=dis[fa]^(1<<(s[x]-'a'));
	dep[x]=dep[fa]+1; 
	for(auto v:e[x]){
		if(v==fa)continue;
		dfs_1(v,x);
		siz[x]+=siz[v];
		if(siz[v]>siz[son[x]])son[x]=v;
	}
} 
void calc(int x,int fa){
//	d[dep[x]]^=dis[x];
	d[dep[x]]^=(1<<s[x]-'a');
	for(auto v:e[x])
		if(v!=fa&&!vis[v])calc(v,x);
}
void dfs_2(int x,int fa,int keep){
	for(auto v:e[x])
		if(v!=fa&&v!=son[x])dfs_2(v,x,0);
	if(son[x]){
		dfs_2(son[x],x,1);
		vis[son[x]]=1;
	}
	calc(x,fa);
	for(auto v:q[x]){
//		cerr<<v.second<<" "<<d[v.first]<<"\n";
		if(!d[v.first]){ans[v.second]=1;continue;}
		for(int i=0;i<26;i++)
			if(d[v.first]==(1<<i)){ans[v.second]=1;break;}
	}
	if(son[x])vis[son[x]]=0;
	if(!keep)calc(x,fa);
}
int main(){
	n=read();Q=read();
	for(int i=2;i<=n;i++)e[read()].push_back(i);
	scanf("%s",s+1);
	for(int i=1,x;i<=Q;i++){x=read();q[x].push_back(make_pair(read(),i));}
	dfs_1(1,0);dfs_2(1,0,1);
//	for(int i=1;i<=n;i++)cerr<<dis[i]<<" "<<s[i]-'a'<<"\n";puts("");
	for(int i=1;i<=Q;i++)puts(ans[i]?"Yes":"No");
	return (0-0);
}