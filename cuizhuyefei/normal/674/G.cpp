#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 166666;
int n,m,k,a[N];
struct node{
	int len,zhi;Pii a[7];
}tree[N<<2];
inline void pushdown(int k, int l, int r, int mid){
	if(tree[k].zhi){
		tree[k<<1].zhi=tree[k].zhi;
		tree[k<<1].len=1;tree[k<<1].a[1]=Pii(tree[k].zhi,mid-l+1);
		tree[k<<1|1].zhi=tree[k].zhi;
		tree[k<<1|1].len=1;tree[k<<1|1].a[1]=Pii(tree[k].zhi,r-mid);
		tree[k].zhi=0;
	}
}
inline node merge(const node &a, const node &b, int zhi=0){
	node c=a;c.zhi=zhi;
	rep(i,1,b.len){
		bool fd=0;
		rep(j,1,c.len)if(c.a[j].fi==b.a[i].fi){
			fd=1;c.a[j].se+=b.a[i].se;break;
		}
		if(!fd){
			c.a[++c.len]=b.a[i];
			if(c.len>k){
				int mn=1e9;rep(j,1,c.len)umin(mn,c.a[j].se);
				rep(j,1,c.len)c.a[j].se-=mn;
				int x=0;rep(j,1,c.len)if(c.a[j].se)c.a[++x]=c.a[j];
				c.len=x;
			}
		}
	}
	return c;
}
inline void upd(int k){
	tree[k]=merge(tree[k<<1],tree[k<<1|1],tree[k].zhi);
}
void build(int k, int l, int r){
	if(l==r){tree[k].len=1;tree[k].a[1]=Pii(a[l],1);return;}
	int mid=(l+r)>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	upd(k);
}
void modify(int k, int l, int r, int x, int L, int R){
	if(l==L&&r==R){
		tree[k].zhi=x;tree[k].len=1;tree[k].a[1]=Pii(x,R-L+1);return;
	}
	int mid=(L+R)>>1;pushdown(k,L,R,mid);
	if(r<=mid)modify(k<<1,l,r,x,L,mid);
	else if(l>mid)modify(k<<1|1,l,r,x,mid+1,R);
	else modify(k<<1,l,mid,x,L,mid),modify(k<<1|1,mid+1,r,x,mid+1,R);
	upd(k);
}
node qry(int k, int l, int r, int L, int R){
	if(l==L&&r==R)return tree[k];
	int mid=(L+R)>>1;pushdown(k,L,R,mid);
	if(r<=mid)return qry(k<<1,l,r,L,mid);
	if(l>mid)return qry(k<<1|1,l,r,mid+1,R);
	return merge(qry(k<<1,l,mid,L,mid),qry(k<<1|1,mid+1,r,mid+1,R));
}
int main() {
	read(n);read(m);read(k);k=100/k;
	rep(i,1,n)read(a[i]);build(1,1,n);
	while(m--){
		int op,l,r;read(op);read(l);read(r);
		if(op==1){
			int x;read(x);modify(1,l,r,x,1,n);
		}
		else{
			node tmp=qry(1,l,r,1,n);
			printf("%d ",tmp.len);
			rep(i,1,tmp.len)printf("%d ",tmp.a[i].fi);puts("");
		}
	}
	return 0;
}