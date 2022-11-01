#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e5+4;
struct edge{
	int v,nxt;
}e[N<<1];
int first[N],cnt=0;
inline void add(int u,int v){
	e[++cnt].v=v;e[cnt].nxt=first[u];first[u]=cnt;
}
int n,m,c[N],siz[N],son[N],cou[N],sum[N],ans[N];
vector<pair<int,int> >q[N];
void dfs_1(int x,int fa){
	siz[x]=1;
	for(int i=first[x],v;i;i=e[i].nxt){
		v=e[i].v;
		if(v==fa)continue;
		dfs_1(v,x);
		siz[x]+=siz[v];
		if(siz[v]>siz[son[x]])son[x]=v;
	}
}
void calc(int x,int fa){
	++sum[++cou[c[x]]];
	for(int i=first[x];i;i=e[i].nxt)
		if(e[i].v!=fa)calc(e[i].v,x);
}
void del(int x,int fa){
	 --sum[cou[c[x]]--];
	for(int i=first[x];i;i=e[i].nxt)
		if(e[i].v!=fa)del(e[i].v,x);
}
void solve(int x,int fa){
	for(int i=first[x],v;i;i=e[i].nxt){
		v=e[i].v;
		if(v==fa||v==son[x])continue;
		solve(v,x);
		del(v,x);
	}
	if(son[x])solve(son[x],x);
	for(int i=first[x],v;i;i=e[i].nxt){
		v=e[i].v;
		if(v==fa||v==son[x])continue;
		calc(v,x);
	}
	++sum[++cou[c[x]]];
	for(auto i:q[x])
		ans[i.second]=sum[i.first];
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=1,u,v;i<n;i++){
		u=read();v=read();
		add(u,v);add(v,u);
	}
	for(int i=1,x,k;i<=m;i++){
		x=read();k=read();
		q[x].push_back(make_pair(k,i));
	}
	dfs_1(1,0);
	solve(1,0);
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<"\n";
	return (0-0);
}