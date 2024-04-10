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
int n,q,a[N];ll mi[15];
struct node{
	bool same;
	ll mn,x,add,zhi;int level;
}tree[N<<2];
inline void upgrade(int k){
	while(tree[k].x>mi[tree[k].level])tree[k].level++;
}
inline void pushadd(int k, ll x){
	if(tree[k].zhi)tree[k].zhi+=x;else tree[k].add+=x;
	tree[k].mn-=x;tree[k].x+=x;
}
inline void pushzhi(int k, ll x){
	tree[k].same=1;tree[k].zhi=x;tree[k].add=0;
	tree[k].x=x;tree[k].level=lower_bound(mi,mi+11,tree[k].x)-mi;tree[k].mn=mi[tree[k].level]-x;
}
inline void pushdown(int k){
	if(tree[k].add){
		pushadd(k<<1,tree[k].add);pushadd(k<<1|1,tree[k].add);
		tree[k].add=0;
	}
	if(tree[k].zhi){
		pushzhi(k<<1,tree[k].zhi);pushzhi(k<<1|1,tree[k].zhi);
		tree[k].zhi=0;
	}
}
inline void upd(int k){
	tree[k].same=0;tree[k].mn=min(tree[k<<1].mn,tree[k<<1|1].mn);
}
void build(int k, int l, int r){
	if(l==r){
		tree[k].same=1;
		tree[k].x=a[l];tree[k].level=0;upgrade(k);tree[k].mn=mi[tree[k].level]-a[l];
		return;
	}
	int mid=(l+r)>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	upd(k);
}
void zhi(int k, int l, int r, int x, int L, int R){
	if(l==L&&r==R){pushzhi(k,x);return;}
	int mid=(L+R)>>1;pushdown(k);
	if(r<=mid)zhi(k<<1,l,r,x,L,mid);
	else if(l>mid)zhi(k<<1|1,l,r,x,mid+1,R);
	else zhi(k<<1,l,mid,x,L,mid),zhi(k<<1|1,mid+1,r,x,mid+1,R);
	upd(k);
}
bool gg;
void add(int k, int l, int r, int x, int L, int R){
	if(l==L&&r==R){
		if(tree[k].mn>=x){pushadd(k,x);gg|=tree[k].mn==0;return;}
		if(tree[k].same||L==R){
			pushadd(k,x);upgrade(k);tree[k].mn=mi[tree[k].level]-tree[k].x;gg|=tree[k].mn==0;return;
		}
		pushdown(k);int mid=(L+R)>>1;
		add(k<<1,l,mid,x,L,mid);add(k<<1|1,mid+1,r,x,mid+1,R);upd(k);
		return;
	}
	int mid=(L+R)>>1;pushdown(k);
	if(r<=mid)add(k<<1,l,r,x,L,mid);
	else if(l>mid)add(k<<1|1,l,r,x,mid+1,R);
	else add(k<<1,l,mid,x,L,mid),add(k<<1|1,mid+1,r,x,mid+1,R);
	upd(k);
}
ll qry(int k, int p, int l, int r){
	if(l==r)return tree[k].x;
	pushdown(k);int mid=(l+r)>>1;
	if(p<=mid)return qry(k<<1,p,l,mid);return qry(k<<1|1,p,mid+1,r);
}
int main() {
	mi[0]=1;rep(i,1,13)mi[i]=mi[i-1]*42ll;
	read(n);read(q);
	rep(i,1,n)read(a[i]);build(1,1,n);
	while(q--){
		int op;read(op);
		if(op==1){
			int x;read(x);printf("%lld\n",qry(1,x,1,n));
		}
		else if(op==2){
			int l,r,x;read(l);read(r);read(x);zhi(1,l,r,x,1,n);
		}
		else{
			int l,r,x;read(l);read(r);read(x);
			gg=1;while(gg)gg=0,add(1,l,r,x,1,n);
		}
	}
	return 0;
}