#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long int64;
#define mk(a,b) make_pair(a,b)
#define w1 first
#define w2 second
typedef pair<int,int> pin;
const int maxn=200005,inf=1<<29;
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
vector<int> a[maxn];int ffa[maxn];
namespace lct{
	int son[maxn][2],fa[maxn],tag[maxn],size[maxn],S[maxn],top;
	inline void update(int x){size[x]=size[son[x][0]]+size[son[x][1]]+1;}
	inline void pushdown(int x){if(tag[x]){tag[x]^=1;swap(son[x][0],son[x][1]);tag[son[x][0]]^=1;tag[son[x][1]]^=1;}}
	inline bool isroot(int x){return son[fa[x]][0]!=x&&son[fa[x]][1]!=x;}
	inline void rotate(int x){
		int y=fa[x],z=fa[y],d=(son[y][1]==x);
		if(!isroot(y))son[z][son[z][1]==y]=x;
		fa[x]=z;fa[y]=x;fa[son[x][!d]]=y;son[y][d]=son[x][!d];son[x][!d]=y;update(y);update(x);
	}
	inline void splay(int x){
		S[top=1]=x;
		for(int i=x;!isroot(i);i=fa[i])S[++top]=fa[i];
		per(i,top,1)pushdown(S[i]);
		for(int y=fa[x],z=fa[y];!isroot(x);y=fa[x],z=fa[y]){
			if(!isroot(y))(son[y][1]==x)^(son[z][1]==y)?rotate(x):rotate(y);
			rotate(x);
		}
	}
	inline int kth(int x,int k){
		pushdown(x);if(size[son[x][0]]+1==k)return x;
		return k<=size[son[x][0]]?kth(son[x][0],k):kth(son[x][1],k-size[son[x][0]]-1);
	}
	inline void access(int x){int t=0;while(x){splay(x);son[x][1]=t;update(x);t=x;x=fa[x];}}
	inline void makeroot(int x){access(x);splay(x);tag[x]^=1;}
	inline void link(int x,int y){makeroot(x);access(y);splay(y);fa[x]=y;}
	inline void cut(int x,int y){makeroot(x);access(y);splay(x);son[x][1]=fa[y]=0;update(x);}
	inline int query(int x,int y){makeroot(x);access(y);splay(y);return size[y];}
	inline int kthfa(int x,int k){makeroot(1);access(x);splay(x);return kth(son[x][0],size[x]-k);}
} 
namespace treap{
	struct sigh{
		int son[maxn][2],rev[maxn],fa[maxn],size[maxn],S[maxn],top;
		inline bool isroot(int x){return son[fa[x]][0]!=x&&son[fa[x]][1]!=x;}
		inline void update(int x){size[x]=size[son[x][0]]+size[son[x][1]]+1;}
		inline void pushdown(int x){if(rev[x]){swap(son[x][0],son[x][1]);rev[son[x][0]]^=1;rev[son[x][1]]^=1;rev[x]=0;}}
		inline void rotate(int x){
			int y=fa[x],z=fa[y],d=(son[y][1]==x);
			if(!isroot(y))son[z][son[z][1]==y]=x;
			fa[x]=z;fa[y]=x;fa[son[x][!d]]=y;son[y][d]=son[x][!d];son[x][!d]=y;update(y);update(x);
		}
		inline void splay(int x){
			S[top=1]=x;
			for(int i=x;!isroot(i);i=fa[i])S[++top]=fa[i];
			per(i,top,1)pushdown(S[i]);
			for(int y=fa[x],z=fa[y];!isroot(x);y=fa[x],z=fa[y]){
				if(!isroot(y))((son[z][1]==y)^(son[y][1]==x))?rotate(x):rotate(y);
				rotate(x);
			}
		}
		inline void access(int x){int t=0;while(x){splay(x);son[x][1]=t;update(x);t=x;x=fa[x];}}
		inline void makeroot(int x){access(x);splay(x);rev[x]^=1;}
		inline void link(int x,int y){if(x==0||y==0)return;makeroot(x);fa[x]=y;}
		inline void cut(int x,int y){if(x==0||y==0)return;makeroot(x);access(y);splay(x);son[x][1]=fa[y]=0;update(x);}
		inline int query(int n){makeroot(1);access(n);splay(n);return size[n];}
	}deadline;
	int l[maxn],r[maxn],tag[maxn],fix[maxn],lower[maxn],upper[maxn],deep[maxn],size[maxn],root,succ[maxn],prev[maxn];
	bool sigh[maxn];
	int tree[maxn][2],pre[maxn],click;
	inline void update(int x){
		if(!x)return;
		lower[x]=inf,upper[x]=-inf;
		if(l[x])lower[x]=min(lower[x],lower[l[x]]),upper[x]=max(upper[x],upper[l[x]]);
		if(r[x])lower[x]=min(lower[x],lower[r[x]]),upper[x]=max(upper[x],upper[r[x]]);
		lower[x]=min(lower[x],deep[x]);upper[x]=max(upper[x],deep[x]);
		size[x]=size[l[x]]+size[r[x]]+1;
	}
	inline void pushdown(int x){
		if(tag[x]){if(l[x])deep[l[x]]+=tag[x],tag[l[x]]+=tag[x],lower[l[x]]+=tag[x],upper[l[x]]+=tag[x];if(r[x])deep[r[x]]+=tag[x],tag[r[x]]+=tag[x],lower[r[x]]+=tag[x],upper[r[x]]+=tag[x];tag[x]=0;update(x);}
	}
	inline int merge(int x,int y){
		if(x)pushdown(x);if(y)pushdown(y);
		if(x==0||y==0)return x+y;
		if(fix[x]<fix[y]){
			r[x]=merge(r[x],y);update(x);return x;
		}
		else{
			l[y]=merge(x,l[y]);update(y);return y;
		}
	}
	inline pin split(int x,int k){
		if(!x)return mk(0,0);pushdown(x);
		if(k<=size[l[x]]){
			pin tmp=split(l[x],k);
			l[x]=tmp.w2;tmp.w2=x;update(x);return tmp;
		}
		else{
			pin tmp=split(r[x],k-size[l[x]]-1);
			r[x]=tmp.w1;tmp.w1=x;update(x);return tmp;
		}
	}
	inline void forever(int x){
		root=merge(root,x);update(root);
	}
	inline void dfs(int x,int dep){
		++click;
		deep[click]=dep;pre[click]=(x<<1)-1;fix[click]=rand();update(click);sigh[click]=0;forever(click);if(click>1)deadline.link(pre[click],pre[click-1]);prev[(x<<1)-1]=pre[click-1];succ[pre[click-1]]=pre[click];
		for(int i=0;i<a[x].size();i++)dfs(a[x][i],dep+1);
		++click;
		deep[click]=dep;pre[click]=(x<<1)-0;fix[click]=rand();update(click);sigh[click]=1;forever(click);if(click>1)deadline.link(pre[click],pre[click-1]);prev[(x<<1)-0]=pre[click-1];succ[pre[click-1]]=pre[click];
	}
	inline int query(int x,int k){
		if(!x)exit(0);pushdown(x);
		if(r[x])if(k<=upper[r[x]]&&k>=lower[r[x]])return query(r[x],k);
		if(deep[x]==k)return pre[x];
		return query(l[x],k);
	}
	inline void change(int u,int v){
		if(v==1){return;}
		int f=lct::kthfa(u,v);
		lct::cut(u,ffa[u]);lct::link(u,f);ffa[u]=f;
		int x=deadline.query((u<<1)-1),y=deadline.query(u<<1),z=deadline.query(f<<1);
		pin tmp1=split(root,x-1);
		pin tmp2=split(tmp1.w2,y-x+1);
		pin tmp3=split(tmp2.w2,z-y-1);
		tag[tmp2.w1]+=-v+1;
		deep[tmp2.w1]+=-v+1;pushdown(tmp2.w1);pushdown(tmp3.w2);
		root=merge(merge(merge(tmp1.w1,tmp3.w1),tmp2.w1),tmp3.w2);x=(u<<1)-1,y=u<<1,z=f<<1;
		deadline.cut(prev[x],x);deadline.cut(y,succ[y]);deadline.cut(prev[z],z);
		deadline.link(x,prev[z]);deadline.link(y,z);deadline.link(prev[x],succ[y]);
		succ[prev[x]]=succ[y];prev[succ[y]]=prev[x];succ[prev[z]]=x;
		prev[x]=prev[z];prev[z]=y;succ[y]=z;
	}
}
int n,m;
int main(){
	read(n);read(m);
	rep(i,1,n){
		int x,y;read(x);
		rep(j,1,x){
			read(y);a[i].push_back(y);lct::link(i,y);
			ffa[y]=i;
		}
	}
	treap::dfs(1,0);
	rep(i,1,m){
		int t,u,v;read(t);
		if(t==1){
			read(u);read(v);
			printf("%d\n",lct::query(u,v)-1);
		}
		if(t==2){
			read(u);read(v);treap::change(u,v);
		}
		if(t==3){
			read(u);if(u==0){puts("1");continue;}
			printf("%d\n",(treap::query(treap::root,u)+1)/2);
		}
	}
    return 0;
}