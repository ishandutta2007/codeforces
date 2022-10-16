#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define ll long long
#define inf 1000000000000000000
using namespace std;
int Iread(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
ll Lread(){
	ll x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write_num(ll x){
	if (x==0)return;
	write_num(x/10);
	putchar('0'+x%10);
}
void Lwrite(ll x){
	if (x==0)putchar('0');
	else write_num(x);
	puts("");
	return;
}
int n,m,u[200005],v[200005],first[100005],nxt[200005];
ll w[200005];
int fa[100005][25],depth[100005];
ll sum[100005];
int tot,uu[45],vv[45];
ll ww[45];
int id_tot,id[100005];
ll dis[85][100005];
void dfs(int now,int f,int d,ll s){
	fa[now][0]=f,depth[now]=d,sum[now]=s;
	for (int i=1;i<=20;i++)fa[now][i]=fa[fa[now][i-1]][i-1];
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==f)continue;
		if (depth[v[i]]==0)dfs(v[i],now,d+1,s+w[i]);
		else if (depth[v[i]]<depth[now]){
			++tot;
			uu[tot]=now,vv[tot]=v[i],ww[tot]=w[i];
			if (id[now]==0)id[now]=++id_tot;
			if (id[v[i]]==0)id[v[i]]=++id_tot;
		}
	}
	return;
}
int lca(int a,int b){
	if (depth[a]<depth[b])swap(a,b);
	for (int i=20;i>=0;i--)
		if (depth[fa[a][i]]>=depth[b])a=fa[a][i];
	if (a==b)return a;
	for (int i=20;i>=0;i--)
		if (fa[a][i]!=fa[b][i])a=fa[a][i],b=fa[b][i];
	return fa[a][0];
}
ll tree_dis(int a,int b){
	return sum[a]+sum[b]-2*sum[lca(a,b)];
}
int q,x,y;
struct node{
	int id;
	ll dis;
	bool operator <(const node &x)const{
		return x.dis<dis;
	}
};
node make_node(int id,ll dis){
	node ans;
	ans.id=id,ans.dis=dis;
	return ans;
}
priority_queue<node> h;
int book[100005];
void dijkstra(int s){
	int awa=id[s];
	memset(dis[awa],0x3f,sizeof(dis[awa]));
	memset(book,0,sizeof(book));
	dis[awa][s]=0;
	h.push(make_node(s,0));
	while(!h.empty()){
		node qaq=h.top();
		h.pop();
		int now=qaq.id;
		if (book[now]==1)continue;
		book[now]=1;
		for (int i=first[now];i;i=nxt[i])
			if (dis[awa][v[i]]>dis[awa][now]+w[i]){
				dis[awa][v[i]]=dis[awa][now]+w[i];
				h.push(make_node(v[i],dis[awa][v[i]]));
			}
	}
	return;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		u[i]=Iread(),v[i]=Iread(),w[i]=Lread();
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+m]=v[i],v[i+m]=u[i],w[i+m]=w[i];
		nxt[i+m]=first[u[i+m]],first[u[i+m]]=i+m;
	}
	dfs(1,0,1,0);
	for (int i=1;i<=n;i++)
		if (id[i]!=0)dijkstra(i);
	cin>>q;
	while(q--){
		x=Iread(),y=Iread();
		ll ans=tree_dis(x,y);
		for (int i=1;i<=tot;i++)ans=min(ans,min(dis[id[uu[i]]][x]+dis[id[vv[i]]][y]+ww[i],dis[id[uu[i]]][y]+dis[id[vv[i]]][x]+ww[i]));
		Lwrite(ans);
	}
	return 0;
}