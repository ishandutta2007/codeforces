#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 233333, inf = 0x3f3f3f3f;
int n,res=1,coll[N],colr[N];bool vis[N];struct rec{int x1,y1,x2,y2;}a[N];
inline int Abs(int x){return x>0?x:-x;}
inline int sgn(int x){return x>0?1:(x==0?0:-1);}
void lisan(){
	static int v[N<<1];int len=0;
	rep(i,1,n)v[++len]=a[i].x1,v[++len]=a[i].x2,v[++len]=a[i].x2+1;
	sort(v+1,v+len+1);len=unique(v+1,v+len+1)-v-1;
	rep(i,1,n){
		a[i].x1=lower_bound(v+1,v+len+1,a[i].x1)-v;a[i].x2=lower_bound(v+1,v+len+1,a[i].x2)-v;
	}
	len=0;rep(i,1,n)v[++len]=a[i].y1,v[++len]=a[i].y2,v[++len]=a[i].y2+1;
	sort(v+1,v+len+1);len=unique(v+1,v+len+1)-v-1;
	rep(i,1,n){
		a[i].y1=lower_bound(v+1,v+len+1,a[i].y1)-v;a[i].y2=lower_bound(v+1,v+len+1,a[i].y2)-v;
	}
}
struct line{int p,l,r,c;}b[N];int len;
bool cmp(line a, line b){return a.p!=b.p?a.p<b.p:a.c<b.c;}//time
struct node{
	set<int>Set;int max,min,l,r;
}tree[(N*2)<<2];
inline void update(int k){
	if(tree[k].l!=tree[k].r){
		tree[k].max=max(tree[k<<1].max,tree[k<<1|1].max);
		tree[k].min=min(tree[k<<1].min,tree[k<<1|1].min);
	}
	else tree[k].max=0,tree[k].min=0;
	if(SZ(tree[k].Set)){
		int u=(*tree[k].Set.rbegin());
		if(!vis[u])tree[k].max=max(tree[k].max,u);
		else tree[k].min=max(tree[k].min,u);//WA:minumax 
	}
	if(tree[k].min>tree[k].max)tree[k].max=0;
}
inline void build(int k, int l, int r){
	tree[k].l=l;tree[k].r=r;int mid=(l+r)>>1;
	if(l==r){return;}//!!
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);update(k);
}
inline void modify(int k, int l, int r, int c, int t){
	//if(k==1)printf("<%d %d> %d %d\n",l,r,c,t);
	if(l<=tree[k].l&&r>=tree[k].r){
		if(t){if(t>0)tree[k].Set.insert(c);else tree[k].Set.erase(c);}
		update(k);return;
	}
	if(r<=tree[k<<1].r)modify(k<<1,l,r,c,t);
	else if(l>tree[k<<1].r)modify(k<<1|1,l,r,c,t);
	else modify(k<<1,l,r,c,t),modify(k<<1|1,l,r,c,t);
	update(k);
}
int main() {
	read(n);rep(i,1,n)read(a[i].x1),read(a[i].y1),read(a[i].x2),read(a[i].y2),a[i].y2--,a[i].x2--;
	lisan();rep(i,1,n)coll[i]=a[i].y1,colr[i]=a[i].y2;
	rep(i,1,n){
		len++;b[len].l=a[i].y1;b[len].r=a[i].y2;b[len].p=a[i].x1;b[len].c=i;
		len++;b[len].l=a[i].y1;b[len].r=a[i].y2;b[len].p=a[i].x2+1;b[len].c=-i;
	}
	sort(b+1,b+len+1,cmp);int mx=n*4;build(1,1,mx);
	rep(i,1,len){
		int j;for(j=i;j<=len;j++)if(b[j].p!=b[i].p)break;
		//[i,j-1]
		rep(k,i,j-1)modify(1,b[k].l,b[k].r,Abs(b[k].c),sgn(b[k].c));
		while(tree[1].max){
			res++;int u=tree[1].max;vis[u]=1;
			modify(1,coll[u],colr[u],0,0);
			//printf("<%d>find %d\n",i,u);
		}
		i=j-1;
	}
	cout<<res;return 0;
}