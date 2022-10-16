#include <iostream>
#include <cstdio>
#define int long long
#define inf 1000000000000000000
using namespace std;
int read(){
	int x=0,fg=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if (ch=='-')fg=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*fg;
}
struct node{
	int l,r,k,b;
	node(){
		l=r=0;
		k=0,b=inf;
		return;
	}
}tree[2000005];
int root[100005],cnt;
int val(int k,int b,int x){
	return k*x+b;
}
void ins(int &now,int nowl,int nowr,int k,int b){
	if (now==0){
		now=++cnt;
		tree[now].k=k;
		tree[now].b=b;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (val(k,b,mid)<val(tree[now].k,tree[now].b,mid))swap(k,tree[now].k),swap(b,tree[now].b);
	if (nowl==nowr)return;
	if (k>tree[now].k)ins(tree[now].l,nowl,mid,k,b);
	if (k<tree[now].k)ins(tree[now].r,mid+1,nowr,k,b);
	return;
}
int ask(int now,int nowl,int nowr,int pos){
	if (now==0)return inf;
	int ans=val(tree[now].k,tree[now].b,pos);
	if (nowl==nowr)return ans;
	int mid=(nowl+nowr)/2;
	if (pos<=mid)ans=min(ans,ask(tree[now].l,nowl,mid,pos));
	else ans=min(ans,ask(tree[now].r,mid+1,nowr,pos));
	return ans;
}
int merge(int x,int y,int nowl,int nowr){
	if (x==0)return y;
	if (y==0)return x;
	int mid=(nowl+nowr)/2;
	if (nowl==nowr){
		if (val(tree[y].k,tree[y].b,mid)<val(tree[x].k,tree[x].b,mid))swap(tree[x].k,tree[y].k),swap(tree[x].b,tree[y].b);
		return x;
	}
	tree[x].l=merge(tree[x].l,tree[y].l,nowl,mid);
	tree[x].r=merge(tree[x].r,tree[y].r,mid+1,nowr);
	ins(x,nowl,nowr,tree[y].k,tree[y].b);
	return x;
}
int n,a[100005],b[100005],u[200005],v[200005],first[100005],nxt[200005];
int f[100005];
void dfs(int now,int fa){
	int fg=1;
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=fa){
			fg=0;
			dfs(v[i],now);
			root[now]=merge(root[now],root[v[i]],-100000,100000);
		}
	if (fg==1)f[now]=0;
	else f[now]=ask(root[now],-100000,100000,a[now]);
	ins(root[now],-100000,100000,b[now],f[now]);
	return;
}
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=n;i++)b[i]=read();
	for (int i=1;i<n;i++){
		u[i]=read(),v[i]=read();
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	dfs(1,0);
	for (int i=1;i<=n;i++)printf("%lld ",f[i]);
	puts("");
	return 0;
}