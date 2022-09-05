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
const int N = 102000;
int n,mo,a[N],q,p[N],len,phi;
struct node{
	int l,r,sum,v,lzy_prod;ll a[10];//sum:ans v,a:lazy
}tree[N<<2],b[N];
int power(int a, ll n){
	int res=1;
	while(n){
		if(n&1)res=1LL*res*a%mo;a=1LL*a*a%mo;n>>=1;
	}
	return res;
}
void faa(int n, int m){
	for(int i=2;i*i<=n;i++)if(n%i==0){
		p[++len]=i;while(n%i==0)n/=i;
	}
	if(n>1)p[++len]=n;
	phi=mo;rep(i,1,len)phi=phi/p[i]*(p[i]-1);
	rep(i,1,m){
		int x=i;rep(j,1,len)while(x%p[j]==0)x/=p[j],b[i].a[j]++;
		b[i].v=x%mo;b[i].lzy_prod=i/x;
	}
}
void add(ll &x, ll y,int mo){x=(x+y);}//WA!
void sub(ll &x, ll y,int mo){x=(x-y);}
void upd(int k){tree[k].sum=(tree[k<<1].sum+tree[k<<1|1].sum)%mo;}
void merge(node &x,node y){
	x.v=1LL*x.v*y.v%mo;
	x.sum=1LL*x.sum*y.v%mo*y.lzy_prod%mo;
	x.lzy_prod=1LL*x.lzy_prod*y.lzy_prod%mo;
	rep(i,1,len)add(x.a[i],y.a[i],phi);//,x.sum=1LL*x.sum*power(p[i],y.a[i])%mo;
}
inline void pd(int k){
	merge(tree[k<<1],tree[k]);merge(tree[k<<1|1],tree[k]);
//	printf("%d %d <%d %d>\n",tree[k].l,tree[k].r,tree[k].a[1],tree[k].a[2]);
	/*tree[k<<1].v=1LL*tree[k<<1].v*tree[k].v%mo;
	tree[k<<1].sum=1LL*tree[k<
	<1].sum*tree[k].v%mo;
	rep(i,1,len)add(tree[k<<1].a[i],tree[k].a[i]),tree[k<<1].sum=1LL*tree[k<<1].sum*power(p[i],tree[k].a[i])%mo;
	
	tree[k<<1|1].v=1LL*tree[k<<1|1].v*tree[k].v%mo;
	tree[k<<1|1].sum=1LL*tree[k<<1|1].sum*tree[k].v%mo;
	rep(i,1,len)add(tree[k<<1|1].a[i],tree[k].a[i]),tree[k<<1|1].sum=1LL*tree[k<<1|1].sum*power(p[i],tree[k].a[i])%mo;*/
	tree[k].v=tree[k].lzy_prod=1;rep(i,1,len)tree[k].a[i]=0;
}
void build(int k, int l, int r){
	tree[k].l=l;tree[k].r=r;
	if(l==r){
		tree[k]=b[a[l]];tree[k].sum=a[l]%mo;
		tree[k].l=l;tree[k].r=r;
		return;
	}
	int mid=(l+r)>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	upd(k);tree[k].v=1;tree[k].lzy_prod=1;
}
void modify(int k, int l, int r, int x){
	if(r<tree[k].l||l>tree[k].r)return;
	if(l<=tree[k].l&&r>=tree[k].r){
		merge(tree[k],b[x]);
		return;
	}
	pd(k);
	modify(k<<1,l,r,x);modify(k<<1|1,l,r,x);
	upd(k);
}
void Div(int k,int pos, node x){
	if(tree[k].l==tree[k].r){
	//	printf("OwO %d\n",phi-1);
		tree[k].v=1LL*tree[k].v*power(x.v,phi-1)%mo;
	//	puts("OwO");
	//	rep(i,1,len)printf("<%d %d>\n",tree[k].a[i],x.a[i]);
		rep(i,1,len)sub(tree[k].a[i],x.a[i],phi);
		tree[k].sum=tree[k].v;
		rep(i,1,len)tree[k].sum=1LL*tree[k].sum*power(p[i],tree[k].a[i])%mo;
		tree[k].lzy_prod=1;rep(i,1,len)tree[k].lzy_prod=1LL*tree[k].lzy_prod*power(p[i],tree[k].a[i])%mo;
		return;
	}
	pd(k);
	if(pos<=tree[k<<1].r)Div(k<<1,pos,x);else Div(k<<1|1,pos,x);
	upd(k);
}
int query(int k,int l,int r){
	if(r<tree[k].l||l>tree[k].r)return 0;
	if(l<=tree[k].l&&r>=tree[k].r)return tree[k].sum;
	pd(k);
	int res=query(k<<1,l,r)+query(k<<1|1,l,r);
	return res%mo;
}
int main() {
	read(n);read(mo);faa(mo,1e5);
//	cerr<<"OwO"<<phi<<endl;
	rep(i,1,n)read(a[i]);read(q);
	build(1,1,n);
	while(q--){
		int op;read(op);
		if(op==1){
			int l,r,x;read(l);read(r);read(x);
			modify(1,l,r,x);
		}
		else if(op==2){
			int p,x;read(p);read(x);
			Div(1,p,b[x]);
		}
		else {int l,r;read(l);read(r);printf("%d\n",query(1,l,r)%mo);}
	}
	return 0;
}