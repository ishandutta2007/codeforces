#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn=2e5+1;
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define per(a,b,c) for(int a=b;a>=c;a--)
#define int long long
template<class T>inline void read(T &x) {
	T f=1;x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s&15);s=getchar();}
	x*=f;
}
int K,Ans,n,m,a[maxn],opt,x,y,Pos;
struct Segment_Tree {
	#define ls rt<<1
	#define rs rt<<1|1
	#define mid ((l+r)>>1)
	int minx[maxn<<2],sum[maxn<<2],tag[maxn<<2];
	inline void pushup(int rt) {
		sum[rt]=sum[ls]+sum[rs];
		minx[rt]=minx[rs];
	}
	inline void pushdown(int rt,int l,int r) {
		if(!tag[rt]) return;
		minx[ls]=tag[rt]; minx[rs]=tag[rt]; sum[ls]=(mid-l+1)*tag[rt]; sum[rs]=(r-mid)*tag[rt];
		tag[ls]=tag[rt]; tag[rs]=tag[rt]; tag[rt]=0;
	}
	inline void build(int rt,int l,int r) {
		if(l==r) return(void)(minx[rt]=a[l],sum[rt]=a[l]);
		build(ls,l,mid); build(rs,mid+1,r);
		pushup(rt);
	}
	inline void update(int rt,int l,int r,int L,int R,int ch) {
		if(L<=l&&r<=R) return(void)(minx[rt]=ch,tag[rt]=ch,sum[rt]=(r-l+1)*ch);
		if(L<=mid) update(ls,l,mid,L,R,ch);
		if(R>mid) update(rs,mid+1,r,L,R,ch);
		pushup(rt);
	}
	inline void query(int rt,int l,int r) {
		if(sum[rt]<=K) return(void)(K-=sum[rt],Ans+=(r-l+1));
		if(K<minx[rt]) return;
		pushdown(rt,l,r);
		query(ls,l,mid); query(rs,mid+1,r);
	}
	inline void query(int rt,int l,int r,int L,int R) {
		if(L<=l&&r<=R) return query(rt,l,r);
		pushdown(rt,l,r);
		if(L<=mid) query(ls,l,mid,L,R);
		if(R>mid) query(rs,mid+1,r,L,R);
	}
	inline int get(int rt,int l,int r,int x) {
		if(l==r) return sum[rt];
		pushdown(rt,l,r);
		if(x<=mid) return get(ls,l,mid,x);
		else return get(rs,mid+1,r,x);
	}
}t;
int L,R,Mid;
signed main() {
	read(n); read(m);
	rep(i,1,n) read(a[i]);
	t.build(1,1,n);
	rep(i,1,m) {
		read(opt); read(x); read(y);
		if(opt&1) {
			if(t.get(1,1,n,x)>=y) continue;
			L=1; R=x;
			while(L<=R) {
				Mid=((L+R)>>1);
				if(t.get(1,1,n,Mid)<y) R=(Mid-1),Pos=Mid;
				else L=(Mid+1);
			}
			t.update(1,1,n,Pos,x,y);
		}
		else {
			Ans=0; K=y;
			t.query(1,1,n,x,n);
			printf("%lld\n",Ans);
		}
	}
}