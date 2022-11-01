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
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}inline void read(i64 &x){
	x=0;i64 f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
const int maxn=1000005;
namespace lct{
	const int maxn=1000005*3;
	int fa[maxn],v[maxn],son[maxn][2],size[maxn],S[maxn],top;bool rev[maxn];pin mini[maxn];
	inline bool isroot(int x){return son[fa[x]][0]!=x&&son[fa[x]][1]!=x;}
	inline void update(int x){assert(x);mini[x]=min(mk(v[x],x),min(mini[son[x][1]],mini[son[x][0]]));size[x]=size[son[x][0]]+size[son[x][1]]+1;}
	inline void pushdown(int x){if(rev[x])swap(son[x][0],son[x][1]),rev[son[x][0]]^=1,rev[son[x][1]]^=1,rev[x]=0;}
	inline void rotate(int x){
		int y=fa[x],z=fa[y],d=(son[y][1]==x);if(!isroot(y))son[z][son[z][1]==y]=x;
		fa[x]=z;fa[y]=x;fa[son[x][!d]]=y;son[y][d]=son[x][!d];son[x][!d]=y;update(y);update(x);
	}inline void splay(int x){
		S[top=1]=x;for(int i=x;!isroot(i);i=fa[i])S[++top]=fa[i];per(i,top,1)pushdown(S[i]);
		for(int y=fa[x],z=fa[y];!isroot(x);y=fa[x],z=fa[y]){
			if(!isroot(y))((son[z][1]==y)^(son[y][1]==x))?rotate(x):rotate(y);rotate(x);
		}
	}
	inline void access(int x){int t=0;while(x){splay(x);son[x][1]=t;update(x);t=x;x=fa[x];}}
	inline void makeroot(int x){access(x);splay(x);rev[x]^=1;}
	inline void link(int x,int y){makeroot(x);fa[x]=y;}
	inline void cut(int x,int y){makeroot(x);access(y);splay(x);fa[y]=son[x][1]=0;update(x);}
	inline int find(int x){access(x);splay(x);while(son[x][0])x=son[x][0];splay(x);return x;}
	inline int query(int x,int y){makeroot(x);access(y);splay(x);assert(size[x]&1);return (size[x]+1)>>1;}
	inline pin querymini(int x,int y){makeroot(x);access(y);splay(x);return mini[x];}
}
int st[maxn],ed[maxn],col[maxn],n,m,k,q;
int nxt[maxn],x[maxn],y[maxn],times[maxn];
int tr[maxn];
map<int,int> mp[55];
int tot,active[maxn];const int inf=1e9;
int main(){
	// judge();
	read(n);read(m);read(k);read(q);lct::v[0]=inf;lct::mini[0]=mk(inf,0);
	rep(i,1,m)read(st[i]),read(ed[i]),assert(st[i]!=ed[i]);int tot=m;
	rep(i,1,q){
		read(x[i]);read(y[i]);
	}
	rep(i,1,m)times[i]=inf;
	per(i,q,1){
		nxt[i]=times[x[i]];
		times[x[i]]=i;
	}
	rep(i,1,q){
		if(active[x[i]]){
			// if(mp[1].count(1)&&mp[1].count(2))printf("www%d %d %d\n",i,lct::find(mp[1][1]),lct::find(mp[1][2]));
			// assert(lct::find(mp[active[x[i]]][st[x[i]]])==lct::find(x[i]));
			// assert(lct::find(mp[active[x[i]]][ed[x[i]]])==lct::find(x[i]));
			lct::cut(mp[active[x[i]]][st[x[i]]],x[i]);
			lct::cut(mp[active[x[i]]][ed[x[i]]],x[i]);
			// if(mp[1].count(1)&&mp[1].count(2))printf("www%d %d %d\n",i,lct::find(mp[1][1]),lct::find(mp[1][2]));
		}lct::v[x[i]]=nxt[i];lct::update(x[i]);
		// printf("%d %d %d\n",i,st[x[i]],ed[x[i]]);
		// printf("%d %d\n",mp[y[i]].count(st[x[i]]),mp[y[i]].count(ed[x[i]]));
		if((!mp[y[i]].count(st[x[i]]))||(!mp[y[i]].count(ed[x[i]]))){
			if(!mp[y[i]].count(st[x[i]]))
				mp[y[i]][st[x[i]]]=++tot,lct::v[tot]=inf,lct::update(tot),tr[tot]=st[x[i]];
			if(!mp[y[i]].count(ed[x[i]]))
				mp[y[i]][ed[x[i]]]=++tot,lct::v[tot]=inf,lct::update(tot),tr[tot]=ed[x[i]];
			active[x[i]]=y[i];
			lct::link(mp[active[x[i]]][st[x[i]]],x[i]);
			lct::link(mp[active[x[i]]][ed[x[i]]],x[i]);
			col[x[i]]=y[i];
			puts("YES");
			continue;
		}
		// if(mp[1].count(1)&&mp[1].count(2))printf("!!!%d %d\n",lct::find(mp[1][1]),lct::find(mp[1][2]));
		if(lct::find(mp[y[i]][st[x[i]]])!=lct::find(mp[y[i]][ed[x[i]]])){
			active[x[i]]=y[i];
			lct::link(mp[active[x[i]]][st[x[i]]],x[i]);
			lct::link(mp[active[x[i]]][ed[x[i]]],x[i]);
			// if(mp[1].count(1)&&mp[1].count(2))printf("!!!%d %d\n",lct::find(mp[1][1]),lct::find(mp[1][2]));
			col[x[i]]=y[i];
			puts("YES");
			continue;
		}
		int v=lct::query(mp[y[i]][st[x[i]]],mp[y[i]][ed[x[i]]]);
		// if(k==2&&i==1516){
			// printf("%d\n",v);//return 0;
		// }
		// printf("%d %d\n",i,v);
		if((v&1)){
			// if(mp[1].count(1)&&mp[1].count(2))printf("ppp%d %d\n",lct::find(mp[1][1]),lct::find(mp[1][2]));
			if(active[x[i]])lct::link(mp[active[x[i]]][st[x[i]]],x[i]);
			if(active[x[i]])lct::link(mp[active[x[i]]][ed[x[i]]],x[i]);
			// if(mp[1].count(1)&&mp[1].count(2))printf("ppp%d %d\n",lct::find(mp[1][1]),lct::find(mp[1][2]));
			if(!active[x[i]]&&(col[x[i]])){
				y[i]=col[x[i]];
				pin tmp=lct::querymini(mp[y[i]][st[x[i]]],mp[y[i]][ed[x[i]]]);
				if(tmp.w1<nxt[i]){
					// tmp.w2=tr[tmp.w2];
					assert(1<=tmp.w2<=m);
					// printf("%dreplace%d,and %d %d\n",x[i],tmp.w2,nxt[i],tmp.w1);
					// if(mp[1].count(1)&&mp[1].count(2))printf("???%d %d\n",lct::find(mp[1][1]),lct::find(mp[1][2]));
					// assert(lct::find(mp[active[tmp.w2]][st[tmp.w2]])==lct::find(tmp.w2));
					// assert(lct::find(mp[active[tmp.w2]][ed[tmp.w2]])==lct::find(tmp.w2));
					lct::cut(mp[active[tmp.w2]][st[tmp.w2]],tmp.w2);
					lct::cut(mp[active[tmp.w2]][ed[tmp.w2]],tmp.w2);
					// if(mp[1].count(1)&&mp[1].count(2))printf("???%d %d\n",lct::find(mp[1][1]),lct::find(mp[1][2]));
					active[tmp.w2]=0;
					active[x[i]]=y[i];
					lct::link(mp[active[x[i]]][st[x[i]]],x[i]);
					lct::link(mp[active[x[i]]][ed[x[i]]],x[i]);
					// if(mp[1].count(1)&&mp[1].count(2))printf("???%d %d\n",lct::find(mp[1][1]),lct::find(mp[1][2]));
				}
			}
			puts("NO");
			continue;
		}active[x[i]]=0;
		puts("YES");col[x[i]]=y[i];
		pin tmp=lct::querymini(mp[y[i]][st[x[i]]],mp[y[i]][ed[x[i]]]);
		assert(1<=tmp.w2<=m);
		if(tmp.w1<nxt[i]){
			// tmp.w2=tr[tmp.w2];
			assert(1<=tmp.w2<=m);
			// printf("%dreplace%d,and %d %d\n",x[i],tmp.w2,nxt[i],tmp.w1);
			// if(mp[1].count(1)&&mp[1].count(2))printf("???%d %d\n",lct::find(mp[1][1]),lct::find(mp[1][2]));
			// assert(lct::find(mp[active[tmp.w2]][st[tmp.w2]])==lct::find(tmp.w2));
			// assert(lct::find(mp[active[tmp.w2]][ed[tmp.w2]])==lct::find(tmp.w2));
			lct::cut(mp[active[tmp.w2]][st[tmp.w2]],tmp.w2);
			lct::cut(mp[active[tmp.w2]][ed[tmp.w2]],tmp.w2);
			// if(mp[1].count(1)&&mp[1].count(2))printf("???%d %d\n",lct::find(mp[1][1]),lct::find(mp[1][2]));
			active[tmp.w2]=0;
			active[x[i]]=y[i];
			lct::link(mp[active[x[i]]][st[x[i]]],x[i]);
			lct::link(mp[active[x[i]]][ed[x[i]]],x[i]);
			// if(mp[1].count(1)&&mp[1].count(2))printf("???%d %d\n",lct::find(mp[1][1]),lct::find(mp[1][2]));
		}
	}
	return 0;
}