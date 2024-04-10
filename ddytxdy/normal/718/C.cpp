#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int N=1e5+50,mod=1e9+7;
int n,m,a[N],k,x,y,d;
struct node{
	LL f[3][3];int n,m;
	node(){
		n=m=2;
		memset(f,0,sizeof(f));
		f[1][1]=f[2][2]=1;
	}
	void init(){
		memset(f,0,sizeof(f));
		f[1][1]=f[2][2]=1;
	}
	void print(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)printf("%lld ",f[i][j]);
			puts("");
		}
	}
	bool no(){
		return f[1][1]!=1||f[2][2]!=1||f[1][2]||f[2][1];
	}
}b,c;
struct node1{
	int l,r;node sum,la;
}t[N*4];
node jia(node a,node b){
	node c;
	c.f[1][1]=c.f[2][2]=0;
	c.n=a.n;c.m=a.m;
	for(int i=1;i<=c.n;i++)for(int j=1;j<=c.m;j++)
		c.f[i][j]=(a.f[i][j]+b.f[i][j])%mod;
	return c;
}
node mul(node a,node b){
	node c;
	c.f[1][1]=c.f[2][2]=0;
	c.n=a.n;c.m=b.m;
	int x=a.m;
	for(int i=1;i<=c.n;i++){
		for(int j=1;j<=c.m;j++){
			for(int k=1;k<=x;k++){
				(c.f[i][j]+=a.f[i][k]*b.f[k][j])%=mod;
			}
		}
	}
	return c;
}
node power(node a,LL x){
	node ret;
	ret.n=a.n;ret.m=a.m;
	while(x){
		if(x&1)ret=mul(a,ret);
		a=mul(a,a);x>>=1;
	}
	return ret;
}
void build(int x,int l,int r){
	t[x].l=l;t[x].r=r;t[x].la.init(); 
	if(l==r){
		t[x].sum=mul(power(c,a[l]-1),b);
		return;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	t[x].sum=jia(t[x<<1].sum,t[x<<1|1].sum);
}
void change(int x,int l,int r,node d){
	if(t[x].l>=l&&t[x].r<=r){
		t[x].sum=mul(d,t[x].sum);
		t[x].la=mul(d,t[x].la);
		return;
	}
	if(t[x].la.no()){
		change(x<<1,1,n,t[x].la);
		change(x<<1|1,1,n,t[x].la);
		t[x].la.init();
	}
	int mid=(t[x].l+t[x].r)>>1;
	if(l<=mid)change(x<<1,l,r,d);
	if(r>mid)change(x<<1|1,l,r,d);
	t[x].sum=jia(t[x<<1].sum,t[x<<1|1].sum);
}
int ask(int x,int l,int r){
	if(t[x].l>=l&&t[x].r<=r)return t[x].sum.f[2][1];
	if(t[x].la.no()){
		change(x<<1,1,n,t[x].la);
		change(x<<1|1,1,n,t[x].la);
		t[x].la.init();
	}
	int mid=(t[x].l+t[x].r)>>1;
	int ret=0;
	if(l<=mid)ret+=ask(x<<1,l,r);
	if(r>mid)(ret+=ask(x<<1|1,l,r))%=mod;
	return ret;
}
int main(){
//	freopen("data.txt","r",stdin);
//	freopen("my.txt","w",stdout);
	c.f[1][1]=c.f[2][1]=c.f[1][2]=1;
	c.f[2][2]=0;c.n=c.m=2;
	b.f[1][1]=b.f[2][1]=1;b.n=2;b.m=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,1,n);
	while(m--){
		scanf("%d%d%d",&k,&x,&y);
		if(k==1)scanf("%d",&d),change(1,x,y,power(c,d));
		else printf("%d\n",ask(1,x,y));
	}
	return 0;
}