#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define inf 1000000000
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x; 
}
struct node{
	int u,v,w;
}a[300005];
bool cmp(node a,node b){
	return a.w<b.w;
}
int n,q;
int opt,l,r;
int cnt,dsu[600005],val[600005];
int dsu_find(int x){
	if (x==dsu[x])return x;
	return dsu[x]=dsu_find(dsu[x]);
}
vector<int> e[600005];
int fa[600005][25],depth[600005],idx,dfn[600005],nfd[600005];
void dfs(int now,int f,int d){
	fa[now][0]=f,depth[now]=d;
	for (int i=1;i<=20;i++)fa[now][i]=fa[fa[now][i-1]][i-1];
	for (int i=0;i<e[now].size();i++)dfs(e[now][i],now,d+1);
	if (now<=n){
		++idx;
		dfn[now]=idx;
		nfd[idx]=now;
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
int qwqmx[1200005],qwqmn[1200005];
int mx[1200005],mn[1200005],tag[1200005];
void build(int now,int nowl,int nowr){
	mx[now]=0,mn[now]=inf,tag[now]=0;
	if (nowl==nowr){
		qwqmx[now]=dfn[nowl];
		qwqmn[now]=dfn[nowl];
		return;
	}
	int mid=(nowl+nowr)/2;
	build(now*2,nowl,mid);
	build(now*2+1,mid+1,nowr);
	qwqmx[now]=max(qwqmx[now*2],qwqmx[now*2+1]);
	qwqmn[now]=min(qwqmn[now*2],qwqmn[now*2+1]);
	return;
}
void pushup(int now){
	mx[now]=max(mx[now*2],mx[now*2+1]);
	mn[now]=min(mn[now*2],mn[now*2+1]);
	return;
}
void pushdown(int now){
	if (tag[now]==1){
		mx[now*2]=qwqmx[now*2];
		mn[now*2]=qwqmn[now*2];
		mx[now*2+1]=qwqmx[now*2+1];
		mn[now*2+1]=qwqmn[now*2+1];
		tag[now*2]=1;
		tag[now*2+1]=1;
		tag[now]=0;
		return;
	}
	if (tag[now]==-1){
		mx[now*2]=0;
		mn[now*2]=inf;
		mx[now*2+1]=0;
		mn[now*2+1]=inf;
		tag[now*2]=-1;
		tag[now*2+1]=-1;
		tag[now]=0;
		return;
	}
	return;
}
void update(int now,int nowl,int nowr,int lt,int rt,int val){
	if (nowl!=nowr)pushdown(now);
	if (nowl>=lt&&nowr<=rt){
		if (val==1){
			mx[now]=qwqmx[now];
			mn[now]=qwqmn[now];
			tag[now]=1;
			return;
		}
		if (val==-1){
			mx[now]=0;
			mn[now]=inf;
			tag[now]=-1;
			return;
		} 
		return;
	}
	int mid=(nowl+nowr)/2;
	if (mid>=lt)update(now*2,nowl,mid,lt,rt,val);
	if (mid+1<=rt)update(now*2+1,mid+1,nowr,lt,rt,val);
	pushup(now);
	return;
}
int ask(int now){
	int x=mn[1],y=mx[1];
	int ans=-1;
	if (x>=1&&x<=n)ans=max(ans,val[lca(now,nfd[x])]);
	if (y>=1&&y<=n)ans=max(ans,val[lca(now,nfd[y])]);
	return ans;
}
int main(){
	cin>>n>>q;
	for (int i=1;i<n;i++)a[i].u=read(),a[i].v=read(),a[i].w=read();
	sort(a+1,a+n,cmp);
	cnt=n;
	for (int i=1;i<=2*n;i++)dsu[i]=i;
	for (int i=1;i<=n;i++)val[i]=-1;
	for (int i=1;i<n;i++){
		int x=dsu_find(a[i].u),y=dsu_find(a[i].v),z=a[i].w;
		int awa=++cnt;
		val[awa]=z;
		e[awa].push_back(x);
		e[awa].push_back(y);
		dsu[x]=dsu[y]=awa;
	}
	int root=dsu_find(1);
	dfs(root,0,1);
	build(1,1,n);
	while(q--){
		opt=read();
		if (opt==1){
			l=read(),r=read();
			update(1,1,n,l,r,1);
		}
		if (opt==2){
			l=read(),r=read();
			update(1,1,n,l,r,-1); 
		}
		if (opt==3){
			l=read();
			printf("%d\n",ask(l));
		}
	}
	return 0;
}