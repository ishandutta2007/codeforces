#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
struct node{
	int id,dis;
	bool operator <(const node &x)const{
		return x.dis<dis;
	}
};
node make_node(int id,int dis){
	node ans;
	ans.id=id,ans.dis=dis;
	return ans;
}
priority_queue<node> h;
int n,m,u[200005],v[200005],w[200005],first[100005],nxt[200005];
int k,p[200005];
int book[200005],dis[200005],qwq[200005];
void dijkstra(){
	memset(dis,0x3f,sizeof(dis));
	for (int i=1;i<=k;i++)dis[p[i]]=0,h.push(make_node(p[i],0)),qwq[p[i]]=p[i];
	while(!h.empty()){
		node awa=h.top();
		h.pop();
		int now=awa.id;
		if (book[now]==1)continue;
		book[now]=1;
		for (int i=first[now];i;i=nxt[i])
			if (dis[v[i]]>dis[now]+w[i]){
				dis[v[i]]=dis[now]+w[i];
				qwq[v[i]]=qwq[now];
				h.push(make_node(v[i],dis[v[i]]));
			}
	}
	return;
}
struct edge{
	int u,v,w;
}e[100005];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int dsu[100005];
int dsu_find(int x){
	if (x==dsu[x])return x;
	return dsu[x]=dsu_find(dsu[x]);
}
int ans;
signed main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+m]=v[i],v[i+m]=u[i],w[i+m]=w[i];
		nxt[i+m]=first[u[i+m]],first[u[i+m]]=i+m;
	}
	cin>>k;
	for (int i=1;i<=k;i++)scanf("%lld",&p[i]);
	dijkstra();
	for (int i=1;i<=m;i++)e[i].u=qwq[u[i]],e[i].v=qwq[v[i]],e[i].w=dis[u[i]]+dis[v[i]]+w[i];
	sort(e+1,e+1+m,cmp);
	for (int i=1;i<=n;i++)dsu[i]=i;
	for (int i=1;i<=m;i++){
		int x=e[i].u,y=e[i].v,z=e[i].w;
		x=dsu_find(x),y=dsu_find(y);
		if (x==y)continue;
		ans+=z;
		dsu[x]=y;
	}
	ans+=dis[1];
	cout<<ans<<endl;
	return 0;
}