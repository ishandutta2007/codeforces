#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#define int long long
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,m,qwq;
int u[400005],v[400005],w[400005],first[200005],nxt[400005];
int dsu[200005],sz[200005];
set<int> c;
int dsu_find(int x){
	if (x==dsu[x])return x;
	return dsu[x]=dsu_find(dsu[x]);
}
int book[200005],sta[200005],tot;
int cnt;
struct edge{
	int u,v,w;
	bool operator <(const edge &x)const{
		return w<x.w;
	}
}e[200005];
int d[1005][1005];
int ans;
int dis[1005];
int prim(){
	int ans=0;
	memset(dis,0x7f,sizeof(dis));
	memset(book,0,sizeof(book));
	dis[1]=0;
	for (int i=1;i<=n;i++){
		int id=-1;
		for (int j=1;j<=n;j++)
			if (book[j]==0&&(id==-1||dis[j]<dis[id]))id=j;
		book[id]=1;
		ans+=dis[id];
		for (int j=1;j<=n;j++)dis[j]=min(dis[j],d[id][j]);
	}
	return ans;
}
void work(){
	int ans=1000000000000000;
	for (int i=1;i<=m;i++)d[u[i]][v[i]]=d[v[i]][u[i]]=w[i];
	for (int i=1;i<=n;i++)
		for (int j=1;j<i;j++)
			if (d[i][j]==0){
				d[i][j]=d[j][i]=qwq;
				ans=min(ans,prim());
				d[i][j]=d[j][i]=0;
			}
	cout<<ans<<endl;
	return;
}
signed main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		u[i]=read(),v[i]=read(),w[i]=read();
		qwq^=w[i];
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+m]=v[i],v[i+m]=u[i],w[i+m]=w[i];
		nxt[i+m]=first[u[i+m]],first[u[i+m]]=i+m;
	}
	for (int i=1;i<=n;i++)dsu[i]=i,sz[i]=1;
	for (int i=1;i<=n;i++)c.insert(i);
	for (int i=1;i<=n;i++){
		for (int j=first[i];j;j=nxt[j]){
			int awa=dsu_find(v[j]);
			book[awa]++,sta[++tot]=awa;
		}
		for (set<int>::iterator it=c.begin();it!=c.end();){
			set<int>::iterator _it=it;
			it++;
			int x=dsu_find(*_it),y=dsu_find(i);
			if (book[x]<sz[x]&&x!=y){
				dsu[x]=y;
				sz[y]+=sz[x];
				sz[x]=0;
				c.erase(_it);
			}
		}
		while(tot>0)book[sta[tot]]--,tot--;
	}
	for (int i=1;i<=n;i++)
		if (dsu_find(i)==i)cnt++;
	for (int i=1;i<=m;i++)
		e[i].u=dsu_find(u[i]),e[i].v=dsu_find(v[i]),e[i].w=w[i];
	sort(e+1,e+1+m);
	if (n-cnt==n*(n-1)/2-m){
		work();
		return 0;
	}
	for (int i=1;i<=m;i++){
		int x=dsu_find(e[i].u),y=dsu_find(e[i].v),z=e[i].w;
		if (x==y)continue;
		dsu[x]=y;
		ans+=z;
	}
	cout<<ans<<endl;
	return 0;
}