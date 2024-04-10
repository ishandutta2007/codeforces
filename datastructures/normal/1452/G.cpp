#include <iostream>
#include <cstdio>
#include <cstring>
#define inf 1000000000
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,u[400005],v[400005],first[200005],nxt[400005];
int k,a[200005];
int q[200005],head,tail;
int c[200005],ans[200005];
void bfs(){
	memset(c,-1,sizeof(c));
	head=1,tail=0;
	for (int i=1;i<=k;i++){
		c[a[i]]=0;
		q[++tail]=a[i];
	}
	while(head<=tail){
		int now=q[head];
		head++;
		for (int i=first[now];i;i=nxt[i])
			if (c[v[i]]==-1){
				c[v[i]]=c[now]+1;
				q[++tail]=v[i];
			}
	}
	return;
}
int book[200005];
int sz[200005];
void getsz(int now,int fa){
	sz[now]=1;
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=fa&&book[v[i]]==0){
			getsz(v[i],now);
			sz[now]+=sz[v[i]];
		}
	return;
}
int num,mn,root;
void getroot(int now,int fa){
	int mx=0;
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=fa&&book[v[i]]==0){
			mx=max(mx,sz[v[i]]);
			getroot(v[i],now);
		}
	mx=max(mx,num-sz[now]);
	if (mx<mn)mn=mx,root=now;
	return;
}
int dis[200005],tot,awa[200005];
void calc(int now,int fa,int d){
	dis[now]=d;
	awa[++tot]=now;
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=fa&&book[v[i]]==0)calc(v[i],now,d+1);
	return;
}
struct BIT{
	int tree[500005],maxn;
	BIT(){
		memset(tree,0,sizeof(tree));
		maxn=300000;
		return;
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int pos,int val){
		pos=maxn-pos;
		while(pos<=maxn)tree[pos]=max(tree[pos],val),pos+=lowbit(pos);
		return;
	}
	void mem(int pos){
		pos=maxn-pos;
		while(pos<=maxn)tree[pos]=0,pos+=lowbit(pos);
		return;
	}
	int ask(int pos){
		pos=maxn-pos;
		int ans=0;
		while(pos)ans=max(ans,tree[pos]),pos-=lowbit(pos);
		return ans;
	}
}bit;
void dfs(int now){
	book[now]=1;
	tot=0;
	calc(now,0,0);
	for (int i=1;i<=tot;i++)
		if (c[awa[i]]>dis[awa[i]])bit.add(c[awa[i]]-dis[awa[i]]-1,c[awa[i]]);
	for (int i=1;i<=tot;i++)ans[awa[i]]=max(ans[awa[i]],bit.ask(dis[awa[i]]));
	for (int i=1;i<=tot;i++)
		if (c[awa[i]]>dis[awa[i]])bit.mem(c[awa[i]]-dis[awa[i]]-1);	
	for (int i=first[now];i;i=nxt[i]){
		if (book[v[i]]==1)continue;
		getsz(v[i],0);
		num=sz[v[i]],mn=inf,root=0;
		getroot(v[i],0);
		dfs(root);
	}
	return;
}
int main(){
	cin>>n;
	for (int i=1;i<n;i++){
		u[i]=read(),v[i]=read();
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	cin>>k;
	for (int i=1;i<=k;i++)a[i]=read();
	bfs();
	getsz(1,0);
	num=sz[1],mn=inf,root=0;
	getroot(1,0);
	dfs(root);
	for (int i=1;i<=k;i++)ans[a[i]]=0;
	for (int i=1;i<=n;i++)printf("%d ",ans[i]);
	cout<<endl;
	return 0;
}
//dis[x]+dis[y]<=c[y]-1
//dis[x]<=c[y]-dis[y]-1