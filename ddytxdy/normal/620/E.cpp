#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
#define lowbit(x) x&-x
using namespace std;
const int N=4e5+50;
int n,m,k,x,y,ver[N*2],nxt[N*2],head[N],tot,l[N],f[N],r[N],cnt;LL a[N];
void add(int x,int y){
	ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;
}
struct node{
	int l,r,la;LL val;
}t[N*4];
void dfs(int x){
	l[x]=++cnt;f[cnt]=x;
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(!l[y])dfs(y);
	}
	r[x]=cnt;
}
void build(int x,int l,int r){
	t[x].l=l;t[x].r=r;t[x].la=0;
	if(l==r){
		t[x].val=a[f[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	t[x].val=t[x<<1].val|t[x<<1|1].val;
}
void change(int x,int l,int r,int d){
	if(t[x].l>=l&&t[x].r<=r){
		t[x].val=(1ll<<d);t[x].la=d;
		return;
	}
	if(t[x].la){
		change(x<<1,1,n,t[x].la);
		change(x<<1|1,1,n,t[x].la);
		t[x].la=0;
	}
	int mid=(t[x].l+t[x].r)>>1;
	if(l<=mid)change(x<<1,l,r,d);
	if(r>mid)change(x<<1|1,l,r,d);
	t[x].val=t[x<<1].val|t[x<<1|1].val;
}
LL ask(int x,int l,int r){
	if(t[x].l>=l&&t[x].r<=r)return t[x].val;
	if(t[x].la){
		change(x<<1,1,n,t[x].la);
		change(x<<1|1,1,n,t[x].la);
		t[x].la=0;
	}
	int mid=(t[x].l+t[x].r)>>1;
	LL ret=0;
	if(l<=mid)ret=ask(x<<1,l,r);
	if(r>mid)ret|=ask(x<<1|1,l,r);
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&x),a[i]=(1ll<<x);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	dfs(1);
	build(1,1,n);
	while(m--){
		scanf("%d%d",&k,&x);
		if(k==1)scanf("%d",&y),change(1,l[x],r[x],y);
		else{
			LL val=ask(1,l[x],r[x]);int ans=0;
			while(val)ans++,val-=lowbit(val);
			printf("%d\n",ans);
		}
	}
	return 0;
}