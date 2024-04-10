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
int n,p[N],q;ll ans[N];vector<Pii>que[N];
struct node{
	int lzy,val,cnt,time;
	ll ans;
}tree[N<<2];
inline void pushlzy(int k, int x){
	tree[k].lzy+=x;tree[k].val+=x;
}
inline void pushtime(int k, int x){
	tree[k].time+=x;tree[k].ans+=1LL*x*tree[k].cnt;
}
inline void upd(int k){
	tree[k].ans=tree[k<<1].ans+tree[k<<1|1].ans;
	tree[k].val=min(tree[k<<1].val,tree[k<<1|1].val);
	tree[k].cnt=0;
	tree[k].cnt+=tree[k<<1].val==tree[k].val?tree[k<<1].cnt:0;
	tree[k].cnt+=tree[k<<1|1].val==tree[k].val?tree[k<<1|1].cnt:0;
}
inline void pushdown(int k){
	if(tree[k].lzy){
		pushlzy(k<<1,tree[k].lzy);pushlzy(k<<1|1,tree[k].lzy);
		tree[k].lzy=0;
	}
	if(tree[k].time){
		if(tree[k<<1].val==tree[k].val)pushtime(k<<1,tree[k].time);
		if(tree[k<<1|1].val==tree[k].val)pushtime(k<<1|1,tree[k].time);
		tree[k].time=0;
	}
}
void build(int k, int l, int r){
	tree[k].val=l;tree[k].cnt=1;
	if(l==r)return;int mid=(l+r)>>1;
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void modify(int k, int l, int r, int x, int L, int R){
	if(l==L&&r==R){pushlzy(k,x);return;}
	int mid=(L+R)>>1;pushdown(k);
	if(r<=mid)modify(k<<1,l,r,x,L,mid);
	else if(l>mid)modify(k<<1|1,l,r,x,mid+1,R);
	else modify(k<<1,l,mid,x,L,mid),modify(k<<1|1,mid+1,r,x,mid+1,R);
	upd(k);
}
ll qry(int k, int l, int r, int L, int R){
	if(l==L&&r==R)return tree[k].ans;
	int mid=(L+R)>>1;pushdown(k);
	if(r<=mid)return qry(k<<1,l,r,L,mid);
	if(l>mid)return qry(k<<1|1,l,r,mid+1,R);
	return qry(k<<1,l,mid,L,mid)+qry(k<<1|1,mid+1,r,mid+1,R);
}
int stamx[N],topmx,stamn[N],topmn;
int main() {
	read(n);rep(i,1,n)read(p[i]);
	read(q);rep(i,1,q){int l,r;read(l);read(r);que[r].pb(Pii(l,i));}
	build(1,1,n);
	rep(i,1,n){
		pushlzy(1,-1);
		while(topmx&&p[stamx[topmx]]<p[i])
			modify(1,stamx[topmx-1]+1,stamx[topmx],-p[stamx[topmx]],1,n),topmx--;
		stamx[++topmx]=i;modify(1,stamx[topmx-1]+1,stamx[topmx],p[stamx[topmx]],1,n);
		while(topmn&&p[stamn[topmn]]>p[i])
			modify(1,stamn[topmn-1]+1,stamn[topmn],p[stamn[topmn]],1,n),topmn--;
		stamn[++topmn]=i;modify(1,stamn[topmn-1]+1,stamn[topmn],-p[stamn[topmn]],1,n);
		pushtime(1,1);
		rep(j,0,SZ(que[i])-1)ans[que[i][j].se]=qry(1,que[i][j].fi,i,1,n);
	}
	rep(i,1,q)printf("%lld\n",ans[i]);
	return 0;
}