#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/
const int maxn=100005;
int a[maxn],n;
struct info{
	int llen,rlen,len,l,r;
};
namespace seg{
	const int maxn=100005*50;
	int ls[maxn],rs[maxn];
	info a[maxn];int tot;
	inline info merge(const info &ls,const info &rs){
		info tmp;
		tmp.llen=ls.llen;
		if(ls.l)
			if(ls.llen==(ls.r-ls.l+1))
				tmp.llen+=rs.llen;
		tmp.rlen=rs.rlen;
		if(rs.l)
			if(rs.rlen==(rs.r-rs.l+1))
				tmp.rlen+=ls.rlen;
		tmp.len=max(max(ls.len,rs.len),ls.rlen+rs.llen);
		return tmp;
	}
	inline void update(int x){
		assert(x);
		int tmpl=a[x].l,tmpr=a[x].r;
		a[x]=merge(a[ls[x]],a[rs[x]]);
		a[x].l=tmpl,a[x].r=tmpr;
	}
	inline void modify(int &x,int y,int lq,int rq,int place){
		x=++tot;ls[x]=ls[y];rs[x]=rs[y];a[x]=a[y];a[x].l=lq;a[x].r=rq;
		if(a[x].l==a[x].r){
			a[x].llen=a[x].rlen=a[x].len=1;
			return;
		}
		int md=(a[x].l+a[x].r)>>1;
		if(place<=md){
			modify(ls[x],ls[y],lq,md,place);
		}
		else
			modify(rs[x],rs[y],md+1,rq,place);
		update(x);
	}
	inline info query(int x,int lq,int rq){
		if(!x)return (info){0,0,0,0,0};
		if(lq<=a[x].l&&a[x].r<=rq)
			return a[x];
		int md=(a[x].l+a[x].r)>>1;
		if(rq<=md)return query(ls[x],lq,rq);
		if(lq>md) return query(rs[x],lq,rq);
		return merge(query(ls[x],lq,rq),query(rs[x],lq,rq));
	}
}
pin h[maxn];
int root[maxn];
int main(){
    // judge();
	read(n);
	rep(i,1,n)read(a[i]);
	rep(i,1,n)h[i]=mk(a[i],i);
	sort(h+1,h+1+n);
	per(i,n,1){
		seg::modify(root[i],root[i+1],1,n,h[i].w2);
	}
	int m;read(m);
	rep(i,1,m){
		int l,r,w;read(l);read(r);read(w);
		int ansl=1,ansr=n,ans=0;
		while(ansl<=ansr){
			int md=(ansl+ansr)>>1;
			int v=seg::query(root[md],l,r).len;
			if(v>=w){
				ans=md;
				ansl=md+1;
			}else
				ansr=md-1;
		}
		printf("%d\n",h[ans].w1);
	}
    return 0;
}