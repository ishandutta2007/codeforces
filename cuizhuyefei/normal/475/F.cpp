#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 333333, inf = 0x3f3f3f3f, M = 2000003, K = 3533333;
int n,x[N],y[N],mx,res;struct dot{int x,y,v;}a[N<<1];Vi pos[N];
inline void lisan(int *a){
	static int s[N],b[N];rep(i,1,n)s[i]=a[i];
	sort(s+1,s+n+1);int len=unique(s+1,s+n+1)-s-1;s[0]=-inf;
	rep(i,1,len)b[i]=b[i-1]+min(s[i]-s[i-1],2);
	rep(i,1,n)a[i]=b[lower_bound(s+1,s+len+1,a[i])-s];
}
struct Border{
	int lc[M],rc[M],mx[M],sz,rt[N];
	Border(){rep(i,0,M-1)mx[i]=-inf;}
	inline void ins(int &k, int K, int p, int v, int l, int r){
		k=++sz;mx[k]=max(mx[K],v);if(l==r)return;int mid=(l+r)>>1;
		if(p<=mid)ins(lc[k],lc[K],p,v,l,mid),rc[k]=rc[K];
		else ins(rc[k],rc[K],p,v,mid+1,r),lc[k]=lc[K];
	}
	inline int query(int k, int l, int r, int L, int R){
		if(r<L||l>R||!k)return -inf;if(l<=L&&r>=R)return mx[k];int mid=(L+R)>>1;//0 is not small!
		if(r<=mid)return query(lc[k],l,r,L,mid);
		if(l>mid)return query(rc[k],l,r,mid+1,R);
		return max(query(lc[k],l,mid,L,mid),query(rc[k],mid+1,r,mid+1,R));
	}
}t[4];
inline void init1(){
	rep(i,0,N-1)pos[i].clear();
	rep(i,1,n)pos[y[i]].pb(x[i]);
	rep(i,1,mx){
		t[0].rt[i]=t[0].rt[i-1];
		per(j,SZ(pos[i])-1,0)t[0].ins(t[0].rt[i],t[0].rt[i],pos[i][j],i,1,mx);
	}
	per(i,mx,1){
		t[2].rt[i]=t[2].rt[i+1];
		per(j,SZ(pos[i])-1,0)t[2].ins(t[2].rt[i],t[2].rt[i],pos[i][j],-i,1,mx);
	}
	rep(i,0,N-1)pos[i].clear();
	rep(i,1,n)pos[x[i]].pb(y[i]);
	rep(i,1,mx){
		t[1].rt[i]=t[1].rt[i-1];
		per(j,SZ(pos[i])-1,0)t[1].ins(t[1].rt[i],t[1].rt[i],pos[i][j],i,1,mx);
	}
	per(i,mx,1){
		t[3].rt[i]=t[3].rt[i+1];
		per(j,SZ(pos[i])-1,0)t[3].ins(t[3].rt[i],t[3].rt[i],pos[i][j],-i,1,mx);
	}
}
int tmp[N];
struct Line{
	int lc[K],rc[K],mx[K],mxpos[K],sz,rt[N];
	inline void build(int &k, int l, int r){
		k=++sz;if(l==r){mx[k]=tmp[l];mxpos[k]=l;return;}int mid=(l+r)>>1;
		build(lc[k],l,mid);build(rc[k],mid+1,r);
		mx[k]=max(mx[lc[k]],mx[rc[k]]);mxpos[k]=mx[lc[k]]>mx[rc[k]]?mxpos[lc[k]]:mxpos[rc[k]];
	}
	inline void ins(int &k, int K, int p, int v, int l, int r){
		k=++sz;mxpos[k]=mx[K]>v?mxpos[K]:p;mx[k]=max(mx[K],v);//printf("ins %d %d\n",mx[k],mxpos[k]);
		if(l==r)return;int mid=(l+r)>>1;
		if(p<=mid)ins(lc[k],lc[K],p,v,l,mid),rc[k]=rc[K];
		else ins(rc[k],rc[K],p,v,mid+1,r),lc[k]=lc[K];
	}
	inline Pii query(int k, int l, int r, int L, int R){//(mx,mxpos)
		if(r<L||l>R||!k)return Pii(0,0);
		if(l<=L&&r>=R)return Pii(mx[k],mxpos[k]);int mid=(L+R)>>1;
		if(r<=mid)return query(lc[k],l,r,L,mid);
		if(l>mid)return query(rc[k],l,r,mid+1,R);
		return max(query(lc[k],l,mid,L,mid),query(rc[k],mid+1,r,mid+1,R));
	}
}T[2];
bool cmp0(dot a, dot b){return a.x!=b.x?a.x<b.x:a.y>b.y;}
bool cmp1(dot a, dot b){return a.y!=b.y?a.y<b.y:a.x>b.x;}
inline void init2(){
	int len=0;rep(i,1,n)a[++len].x=x[i],a[len].y=y[i];
	rep(i,1,mx)a[++len].x=i,a[len].y=1;
	rep(i,1,len)a[i].v=inf;
	sort(a+1,a+len+1,cmp0);
	rep(i,1,len)if(a[i-1].x==a[i].x)a[i].v=a[i-1].y;
	static vector<Pii>dots[N];
	rep(i,0,N-1)dots[i].clear();rep(i,1,len)dots[a[i].y].pb(Pii(a[i].x,a[i].v));
	rep(i,1,mx)tmp[i]=inf;per(i,SZ(dots[1])-1,0)tmp[dots[1][i].fi]=dots[1][i].se;
//	rep(i,1,mx)per(j,SZ(dots[i])-1,0)printf("%d %d %d\n",i,dots[i][j].fi,dots[i][j].se);
	T[0].build(T[0].rt[1],1,mx);
	rep(i,2,mx){
		T[0].rt[i]=T[0].rt[i-1];
		per(j,SZ(dots[i])-1,0)T[0].ins(T[0].rt[i],T[0].rt[i],dots[i][j].fi,dots[i][j].se,1,mx);
	}
	
	len=0;rep(i,1,n)a[++len].x=x[i],a[len].y=y[i];
	rep(i,1,mx)a[++len].x=1,a[len].y=i;
	rep(i,1,len)a[i].v=inf;
	sort(a+1,a+len+1,cmp1);
	rep(i,1,len)if(a[i-1].y==a[i].y)a[i].v=a[i-1].x;
	rep(i,0,N-1)dots[i].clear();rep(i,1,len)dots[a[i].x].pb(Pii(a[i].y,a[i].v));
	rep(i,1,mx)tmp[i]=inf;per(i,SZ(dots[1])-1,0)tmp[dots[1][i].fi]=dots[1][i].se;
	T[1].build(T[1].rt[1],1,mx);
	rep(i,2,mx){
		T[1].rt[i]=T[1].rt[i-1];
		per(j,SZ(dots[i])-1,0)T[1].ins(T[1].rt[i],T[1].rt[i],dots[i][j].fi,dots[i][j].se,1,mx);
	}
}
inline void solve(int l, int r, int L, int R){
//	printf("solve %d %d %d %d\n",l,r,L,R);
	R=t[0].query(t[0].rt[R],l,r,1,mx);if(R<L)return;
	r=t[1].query(t[1].rt[r],L,R,1,mx);if(r<l)return;
	L=-t[2].query(t[2].rt[L],l,r,1,mx);if(R<L)return;
	l=-t[3].query(t[3].rt[l],L,R,1,mx);if(r<l)return;
//	printf("solve %d %d %d %d\n",l,r,L,R);
	Pii u=T[0].query(T[0].rt[L-1],l,r,1,mx);
//	printf("<%d,%d>\n",u.fi,u.se);
	if(u.fi>R){solve(l,u.se-1,L,R);solve(u.se+1,r,L,R);return;}
	u=T[1].query(T[1].rt[l-1],L,R,1,mx);
	if(u.fi>r){solve(l,r,L,u.se-1);solve(l,r,u.se+1,R);return;}
	res++;
}
int main(){//freopen("1.in","r",stdin);
	read(n);rep(i,1,n)read(x[i]),read(y[i]);
	lisan(x);lisan(y);rep(i,1,n)mx=max(mx,max(x[i],y[i]));mx++;
//	rep(i,1,n)printf("%d %d\n",x[i],y[i]);
	init1();init2();//puts("OwO");
	solve(1,mx,1,mx);printf("%d\n",res);
	return 0;
}