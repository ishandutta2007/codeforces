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
const int N = 1020*1020;
int n,m,a[1020][1020];Pii pos[N];
namespace lct{
	int n,fa[N],ch[N][2];bool rev[N];
	inline bool isroot(int u){return ch[fa[u]][0]!=u&&ch[fa[u]][1]!=u;}
	inline bool getid(int x){return ch[fa[x]][1]==x;}
	inline void pushdown(int x){
		if(rev[x]){
			rev[x]=0;
			rev[ch[x][0]]^=1;rev[ch[x][1]]^=1;
			swap(ch[x][0],ch[x][1]);
		}
	}
	inline void rotate(int x){
		int y=fa[x],z=fa[y],k=getid(x),c=ch[x][k^1];
		fa[x]=z;if(!isroot(y))ch[z][getid(y)]=x;
		fa[y]=x;ch[x][k^1]=y;
		fa[c]=y;ch[y][k]=c;
	}
	inline void splay(int x){
		static int sta[N];int top=0;
		for(int u=x;;u=fa[u]){sta[++top]=u;if(isroot(u))break;}
		while(top)pushdown(sta[top--]);
		while(!isroot(x)){
			int y=fa[x];
			if(isroot(y)){rotate(x);break;}
			if(getid(x)==getid(y))rotate(y),rotate(x);
			else rotate(x),rotate(x);
		}
	}
	inline void access(int u){
		int tmp=0;
		while(u){
			splay(u);ch[u][1]=tmp;
			tmp=u;u=fa[u];
		}
	}
	inline int findroot(int u){
		access(u);splay(u);
		while(ch[u][0])u=ch[u][0];
		splay(u);return u;
	}
	inline void makeroot(int u){
		access(u);splay(u);rev[u]^=1;
	}
	inline bool link(int u, int v){
	//	printf("link %d %d\n",u,v);
		if(findroot(u)==findroot(v))return 0;
		makeroot(u);splay(u);fa[u]=v;return 1;
	}
	inline void cut(int u, int v){
		makeroot(u);access(v);splay(v);
		if(ch[v][0]==u)fa[u]=ch[v][0]=0;
	}
}
struct node{
	int l,r,val,cnt,lzy;
}tree[N<<2];
inline void pushdown(int k){
	if(tree[k].lzy){
		int x=tree[k].lzy;tree[k].lzy=0;
		tree[k<<1].lzy+=x;tree[k<<1].val+=x;
		tree[k<<1|1].lzy+=x;tree[k<<1|1].val+=x;
	}
}
inline void upd(int k){
	tree[k].val=min(tree[k<<1].val,tree[k<<1|1].val);
	tree[k].cnt=(tree[k<<1].val==tree[k].val?tree[k<<1].cnt:0)+(tree[k<<1|1].val==tree[k].val?tree[k<<1|1].cnt:0);
}
void build(int k, int l, int r){
	tree[k].l=l;tree[k].r=r;
	if(l==r){tree[k].val=0;tree[k].cnt=1;return;}
	int mid=(l+r)>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	upd(k);
}
void modify(int k, int l, int r, int x){
	if(r<tree[k].l||l>tree[k].r)return;
	if(l<=tree[k].l&&r>=tree[k].r){
		tree[k].lzy+=x;tree[k].val+=x;return;
	}
	pushdown(k);
	modify(k<<1,l,r,x);modify(k<<1|1,l,r,x);upd(k);
}
int query(int k, int l, int r){
	if(r<tree[k].l||l>tree[k].r)return 0;
	if(l<=tree[k].l&&r>=tree[k].r)return tree[k].val==1?tree[k].cnt:0;
	pushdown(k);return query(k<<1,l,r)+query(k<<1|1,l,r);
}
int main() {
	read(n);read(m);rep(i,1,n)rep(j,1,m){
		read(a[i][j]);pos[a[i][j]]=Pii(i,j);
	}
	lct::n=n*m;ll res=0;build(1,1,n*m);
	int dx[]={1,-1,0,0};
	int dy[]={0,0,1,-1};
	for(int i=1,j=0;i<=n*m;i++){
		while(j+1<=n*m){
			bool ok=1;j++;
			int x=pos[j].fi,y=pos[j].se,cnt=0;
			rep(d,0,3)if(x+dx[d]>=1&&x+dx[d]<=n&&y+dy[d]>=1&&y+dy[d]<=m){
				if(a[x+dx[d]][y+dy[d]]>=i&&a[x+dx[d]][y+dy[d]]<=j)
					ok&=lct::link(a[x][y],a[x+dx[d]][y+dy[d]]),cnt++;
			}
			if(!ok){
				rep(d,0,3)if(x+dx[d]>=1&&x+dx[d]<=n&&y+dy[d]>=1&&y+dy[d]<=m){
					if(a[x+dx[d]][y+dy[d]]>=i&&a[x+dx[d]][y+dy[d]]<=j)lct::cut(a[x][y],a[x+dx[d]][y+dy[d]]);
				}
				j--;break;
			}
			//ins j
			modify(1,j,n*m,1-cnt);
		}
	//	printf("[%d %d] %d\n",i,j,query(1,i,j));
		res+=query(1,i,j);
		modify(1,i,n*m,-1);
		int x=pos[i].fi,y=pos[i].se;
		rep(d,0,3)if(x+dx[d]>=1&&x+dx[d]<=n&&y+dy[d]>=1&&y+dy[d]<=m){
			if(a[x+dx[d]][y+dy[d]]>=i&&a[x+dx[d]][y+dy[d]]<=j)
				lct::cut(a[x][y],a[x+dx[d]][y+dy[d]]),modify(1,a[x+dx[d]][y+dy[d]],n*m,1);
		}
	}
	cout<<res;
	return 0;
}