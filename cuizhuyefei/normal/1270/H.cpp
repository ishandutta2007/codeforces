#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 505000,lim=1e6+10,inf=0x3f3f3f3f;
int n,a[N],q;
struct node{
	int cnt,mn,lzy;
}tree[lim<<2];
void pushdown(int k){
	if(tree[k].lzy){
		tree[k<<1].lzy+=tree[k].lzy;tree[k<<1].mn+=tree[k].lzy;
		tree[k<<1|1].lzy+=tree[k].lzy;tree[k<<1|1].mn+=tree[k].lzy;
		tree[k].lzy=0;
	}
}
void upd(int k){
	tree[k].mn=min(tree[k<<1].mn,tree[k<<1|1].mn);
	tree[k].cnt=(tree[k].mn==tree[k<<1].mn)*tree[k<<1].cnt+(tree[k].mn==tree[k<<1|1].mn)*tree[k<<1|1].cnt;
}
node merge(node a, node b){
	node c;
	c.mn=min(a.mn,b.mn);
	c.cnt=(c.mn==a.mn)*a.cnt+(c.mn==b.mn)*b.cnt;
	return c;
}
void build(int k, int l, int r){
	if(l==r){tree[k].mn=0;tree[k].cnt=0;return;}
	int mid=(l+r)>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	upd(k);
}
void modify(int k, int l, int r, int x, int L, int R){
	if(l==L&&r==R){tree[k].lzy+=x;tree[k].mn+=x;return;}
	int mid=(L+R)>>1;pushdown(k);
	if(r<=mid)modify(k<<1,l,r,x,L,mid);
	else if(l>mid)modify(k<<1|1,l,r,x,mid+1,R);
	else modify(k<<1,l,mid,x,L,mid),modify(k<<1|1,mid+1,r,x,mid+1,R);
	upd(k);
}
void activate(int k, int p, int x, int l, int r){
	if(l==r){tree[k].cnt+=x;return;}
	int mid=(l+r)>>1;pushdown(k);
	if(p<=mid)activate(k<<1,p,x,l,mid);else activate(k<<1|1,p,x,mid+1,r);
	upd(k);
}
node qry(int k, int l, int r, int L, int R){
	if(l==L&&r==R)return tree[k];
	int mid=(L+R)>>1;pushdown(k);
	if(r<=mid)return qry(k<<1,l,r,L,mid);
	else if(l>mid)return qry(k<<1|1,l,r,mid+1,R);
	return merge(qry(k<<1,l,mid,L,mid),qry(k<<1|1,mid+1,r,mid+1,R));
}
int main() {
	set<int>Set;
	read(n);read(q);rep(i,1,n)read(a[i]),Set.insert(a[i]);a[n+1]=-1;
	build(1,0,lim);
	rep(i,1,n)modify(1,min(a[i],a[i+1])+1,max(a[i],a[i+1]),1,0,lim);
	rep(i,1,n)activate(1,a[i],1,0,lim);
//	printf("%d %d\n",tree[1].mn,tree[1].cnt);
	while(q--){
		int p,x;read(p);read(x);
		modify(1,min(a[p],a[p+1])+1,max(a[p],a[p+1]),-1,0,lim);
		if(p>1)modify(1,min(a[p],a[p-1])+1,max(a[p],a[p-1]),-1,0,lim);
		Set.erase(a[p]);activate(1,a[p],-1,0,lim);a[p]=x;activate(1,a[p],1,0,lim);Set.insert(a[p]);
		modify(1,min(a[p],a[p+1])+1,max(a[p],a[p+1]),1,0,lim);
		if(p>1)modify(1,min(a[p],a[p-1])+1,max(a[p],a[p-1]),1,0,lim);
		printf("%d\n",qry(1,0,*Set.rbegin(),0,lim).cnt);//,qry(1,0,*Set.rbegin(),0,lim).mn);
	}
	return 0;
}