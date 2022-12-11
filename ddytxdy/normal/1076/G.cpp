#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+50;
int n,m,q;
LL read(){
	LL x=0;int c;
	while(!isdigit(c=getchar()));
	while(isdigit(c))x=x*10+(c^48),c=getchar();
	return x;
}
struct node{int f[6],p[6],laz;}t[N*4];
void init(node &x,bool op){
	x.p[0]=op*m;x.f[0]=!op*m;
	for(int i=1;i<=m;i++)x.p[i]=x.f[i]=i-1;
}
node merge(node x,node y){
	node ret;
	for(int i=0;i<=m;i++)ret.p[i]=x.p[y.p[i]];
	for(int i=0;i<=m;i++)ret.f[i]=x.f[y.f[i]];
	ret.laz=0;return ret;
}
void build(int x,int l,int r){
	if(l==r){init(t[x],read()&1);return;}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	t[x]=merge(t[x<<1],t[x<<1|1]);
}
void change(int x,int l,int r,int ql,int qr){
	if(l>=ql&&r<=qr){swap(t[x].f,t[x].p);t[x].laz^=1;return;}
	int mid=(l+r)>>1;
	if(t[x].laz){
		change(x<<1,l,mid,1,n);
		change(x<<1|1,mid+1,r,1,n);
		t[x].laz=0;
	}
	if(ql<=mid)change(x<<1,l,mid,ql,qr);
	if(qr>mid)change(x<<1|1,mid+1,r,ql,qr);
	t[x]=merge(t[x<<1],t[x<<1|1]);
}
node query(int x,int l,int r,int ql,int qr){
	if(l>=ql&&r<=qr)return t[x];
	int mid=(l+r)>>1;
	if(t[x].laz){
		change(x<<1,l,mid,1,n);
		change(x<<1|1,mid+1,r,1,n);
		t[x].laz=0;
	}
	if(ql>mid)return query(x<<1|1,mid+1,r,ql,qr);
	if(qr<=mid)return query(x<<1,l,mid,ql,qr);
	return merge(query(x<<1,l,mid,ql,qr),query(x<<1|1,mid+1,r,ql,qr));
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	build(1,1,n);
	for(int i=1,op,l,r;i<=q;i++){
		op=read();l=read();r=read();
		if(op==2)puts(query(1,1,n,l,r).p[0]==m?"2":"1");
		else if(read()&1)change(1,1,n,l,r);
	}
}