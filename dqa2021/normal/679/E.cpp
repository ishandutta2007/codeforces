#include<cstdio>
#include<algorithm>
#include<cctype>
#include<assert.h>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
typedef long long ll;
ll p[50]; int m=11;
ll getnext(ll x){
	assert(x<p[m]);
	return p[upper_bound(p,p+m,x)-p];
}
bool check(ll x){
	int k=lower_bound(p,p+m,x)-p;
	return k<=m&&p[k]==x;
}

int n,q;
#define ls (x<<1)
#define rs (x<<1|1)
#define mid (l+r>>1)
struct Node{
	ll cov;  //no then -1
	ll dis;
	ll mx,mn;
	ll tag;
}node[262144];
void pushup(int x){
	node[x].dis=min(node[ls].dis,node[rs].dis);
	node[x].mn=min(node[ls].mn,node[rs].mn);
	node[x].mx=max(node[ls].mx,node[rs].mx);
}
void pushdown(int x){
	if (~node[x].cov){
		node[ls]=node[rs]=node[x];
		node[x].cov=-1; node[x].tag=0;
		return;
	}
	node[ls].tag+=node[x].tag;
	node[ls].dis-=node[x].tag;
	node[ls].mn+=node[x].tag;
	node[ls].mx+=node[x].tag;
	node[rs].tag+=node[x].tag;
	node[rs].dis-=node[x].tag;
	node[rs].mn+=node[x].tag;
	node[rs].mx+=node[x].tag;
	node[x].tag=0;
}
void build(int x,int l,int r){
	if (l==r){
		ll v=read();
		ll k=getnext(v);
		node[x]=(Node){v,k-v,v,v,0};
		return;
	}
	build(ls,l,mid); build(rs,mid+1,r);
	node[x].cov=-1;
	pushup(x);
}
ll query(int x,int l,int r,int p,ll tag=0){
	if (node[x].mn==node[x].mx) return node[x].mx+tag;
	tag+=node[x].tag;
	assert(l!=r);
	if (p<=mid) return query(ls,l,mid,p,tag);
	return query(rs,mid+1,r,p,tag);
}
void modify(int x,int l,int r,int ql,int qr,ll v,ll k){
	if (ql<=l&&r<=qr){
		node[x]=(Node){v,k-v,v,v,0};
		return;
	}
	pushdown(x);
	if (ql<=mid) modify(ls,l,mid,ql,qr,v,k);
	if (mid<qr) modify(rs,mid+1,r,ql,qr,v,k);
	pushup(x);
}
bool flg;  //init
void _update(int x,int l,int r){
	if (node[x].dis>0) return;
	if (node[x].mx==node[x].mn){
		if (check(node[x].mx)) flg=1;
		ll u=node[x].mn,k=getnext(u);
		node[x]=(Node){u,k-u,u,u,0};
		return;
	}
	pushdown(x);
	_update(ls,l,mid);
	_update(rs,mid+1,r);
	pushup(x);
}
void update(int x,int l,int r,int ql,int qr,ll v){
	if (ql<=l&&r<=qr){
		node[x].dis-=v;
		node[x].mx+=v;
		node[x].mn+=v;
		node[x].tag+=v;
		_update(x,l,r);
		return;
	}
	pushdown(x);
	if (ql<=mid) update(ls,l,mid,ql,qr,v);
	if (mid<qr) update(rs,mid+1,r,ql,qr,v);
	pushup(x);
}
#undef mid
#undef ls
#undef rs
int main()
{
	p[0]=1; for (int i=1;i<=11;i++) p[i]=p[i-1]*42;
	n=read(),q=read();
	build(1,1,n);
	int o,x,y,z;
	while (q--){
		o=read(),x=read(); if (o&2) y=read(),z=read();
		if (o==1){
			printf("%I64d\n",query(1,1,n,x));
			continue;
		}
		if (o==2){
			ll k=getnext(z);
			modify(1,1,n,x,y,z,k);
			continue;
		}
		do{
			flg=0;
			update(1,1,n,x,y,z);
		}while (flg);
	}
	return 0;
}