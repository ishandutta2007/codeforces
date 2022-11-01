#include <bits/stdc++.h>
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
#define ls(x) ((x)<<1)
#define rs(x) (((x)<<1)|1)
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
const int maxn=200005;
int head[maxn],t[maxn<<1],ne[maxn<<1],v[maxn<<1],num,w[maxn];
inline void addedge(int x,int y,int z){
	ne[++num]=head[x];head[x]=num;t[num]=y;v[num]=z;
	ne[++num]=head[y];head[y]=num;t[num]=x;v[num]=z;
}
int dep[maxn],fa[maxn],top[maxn],dfn[maxn],sz[maxn],son[maxn],tree[maxn],clk;
inline void dfs1(int x){sz[x]=1;
	forE(i,x)if(t[i]!=fa[x]){
		w[t[i]]=v[i];dep[t[i]]=dep[x]+1;fa[t[i]]=x;dfs1(t[i]);sz[x]+=sz[t[i]];if(sz[t[i]]>sz[son[x]])son[x]=t[i];
	}
}
inline void dfs2(int x,int zhong){
	top[x]=zhong;dfn[x]=++clk;tree[clk]=x;if(!son[x])return;
	dfs2(son[x],zhong);forE(i,x)if(t[i]!=fa[x]&&t[i]!=son[x])dfs2(t[i],t[i]);
}
int f[maxn];
struct info{
	int l,r,v,len;
	inline info(){};
	inline info(int _l,int _r,int _v,int _len){l=_l;r=_r;v=_v;len=_len;}
}a[maxn<<2];
namespace seg{
	int l[maxn<<2],r[maxn<<2];info a[maxn<<2];
	inline info merge(const info &a,const info &b){
		info res=info(a.l,b.r,a.v+b.v-f[a.r]-f[b.l]+f[a.r+b.l],a.len+b.len);
		if(a.l==a.len)res.l=a.l+b.l;
		if(b.r==b.len)res.r=b.r+a.r;
		return res;
	}
	inline void build(int x,int lq,int rq){
		l[x]=lq;r[x]=rq;a[x]=info(0,0,0,1);if(lq==rq)return;
		int mid=(lq+rq)>>1;build(ls(x),lq,mid);build(rs(x),mid+1,rq);
		a[x]=merge(a[ls(x)],a[rs(x)]);
	}
	inline void add(int x,int place){
		if(l[x]==r[x]){assert(a[x].l!=1);a[x]=info(1,1,f[1],1);return;}int mid=(l[x]+r[x]>>1);
		if(place<=mid)add(ls(x),place);else add(rs(x),place);a[x]=merge(a[ls(x)],a[rs(x)]);
	}
	inline info query(int x,int lq,int rq){
		if(lq>rq)return info(0,0,0,0);
		if(l[x]>=lq&&rq>=r[x])return a[x];int mid=(l[x]+r[x])>>1;
		if(mid>=rq)return query(ls(x),lq,rq);if(lq>mid)return query(rs(x),lq,rq);
		return merge(query(ls(x),lq,rq),query(rs(x),lq,rq));
	}
}
struct event{
	int v,l,r,pre;
}Q[maxn<<2];
inline bool operator < (const event &a,const event &b){
	return a.v>b.v||(a.v==b.v&&a.r<b.r);
}
inline void add(int x){
	seg::add(1,dfn[x]);
}
inline int calc(int x,int y){
	int lastx=0,lasty=0,ans=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]>dep[top[y]]){
			info tmp=seg::query(1,dfn[top[x]],dfn[x]);
			assert(tmp.len==(dep[x]-dep[top[x]]+1));
			if((tmp.l==tmp.r)&&(tmp.l==(dep[x]-dep[top[x]]+1))){
				lastx+=tmp.l;
			}else{
				ans+=tmp.v-f[tmp.r]-f[tmp.l]+f[tmp.r+lastx];
				lastx=tmp.l;
			}
			x=fa[top[x]];
		}else{
			info tmp=seg::query(1,dfn[top[y]],dfn[y]);
			assert(tmp.len==(dep[y]-dep[top[y]]+1));
			if((tmp.l==tmp.r)&&(tmp.l==(dep[y]-dep[top[y]]+1))){
				lasty+=tmp.l;
			}else{
				ans+=tmp.v-f[tmp.r]-f[tmp.l]+f[tmp.r+lasty];
				lasty=tmp.l;
			}
			y=fa[top[y]];
		}
	}
	if(dep[x]>dep[y]){
		info tmp=seg::query(1,dfn[y]+1,dfn[x]);
			assert(tmp.len==(dep[x]-dep[y]));
		if((tmp.l==tmp.r)&&(tmp.l==(dep[x]-dep[y]))){
			ans=ans+f[tmp.l+lastx+lasty];
		}else{
			ans=ans+tmp.v-f[tmp.r]+f[tmp.r+lastx]-f[tmp.l]+f[tmp.l+lasty];
		}
	}else{
		info tmp=seg::query(1,dfn[x]+1,dfn[y]);
			assert(tmp.len==(dep[y]-dep[x]));
		if((tmp.l==tmp.r)&&(tmp.l==(dep[y]-dep[x]))){
			ans=ans+f[tmp.l+lastx+lasty];
		}else{
			ans=ans+tmp.v-f[tmp.r]+f[tmp.r+lasty]-f[tmp.l]+f[tmp.l+lastx];
		}
	}return ans;
}int n,q,tot;
int ans[maxn];
int main(){
//	judge();
	read(n);read(q);
	rep(i,1,n-1)read(f[i]);
	rep(i,1,n)head[i]=-1;
	rep(i,1,n-1){
		int x,y,z;read(x);read(y);read(z);	
		addedge(x,y,z);
	}dfs1(1);dfs2(1,1);seg::build(1,1,n);
	rep(i,2,n)Q[++tot]=(event){w[i],i,0,0};
	rep(i,1,q){
		tot++;
		read(Q[tot].l);
		read(Q[tot].r);
		read(Q[tot].v);
		Q[tot].pre=i;
	}
	sort(Q+1,Q+1+tot);
	rep(i,1,tot){
		if(!Q[i].r)
			add(Q[i].l);
		else
			ans[Q[i].pre]=calc(Q[i].l,Q[i].r);
	}
	rep(i,1,q)printf("%d\n",ans[i]);
	return 0;
}