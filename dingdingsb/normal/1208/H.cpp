#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
const int N=1e5+100;
int n,q,nowk,col[N];//0=red 1=blue
vector<int>e[N];
struct dtkdSGT{
	/*
	
	 
	(1)
	(2)
	(2)k k + 2 sum [k_i<=k] > m   
	*/
	int cnt,sum[N<<6],lc[N<<6],rc[N<<6];
	void pushup(int x){sum[x]=sum[lc[x]]+sum[rc[x]];}
	void upd(int&x,int l,int r,int pos,int val){
		if(!x)x=++cnt;
		if(l==r)return sum[x]+=val,void();
		if(pos<=mid)upd(lc[x],l,mid,pos,val);
		else upd(rc[x],mid+1,r,pos,val);
		pushup(x);
	}
	int qry(int x,int l,int r,int pre,int m){
		if(l==r)return l;
		if(mid+2*(pre+sum[lc[x]])>m)return qry(lc[x],l,mid,pre,m);
		else return qry(rc[x],mid+1,r,pre+sum[lc[x]],m);
	}
	int ct(int x,int l,int r,int ql,int qr){
		if(!x)return 0;
		if(ql<=l&&r<=qr)return sum[x];
		if(r<ql||qr<l)return 0;
		return ct(lc[x],l,mid,ql,qr)+ct(rc[x],mid+1,r,ql,qr);
	}
}T;
int fa[N],son[N],sz[N],top[N],dep[N],lcnt[N],lrt[N];
void dfs1(int u){
	dep[u]=dep[fa[u]]+1;sz[u]=1;
	for(auto v:e[u])if(v!=fa[u])
		fa[v]=u,dfs1(v),sz[u]+=sz[v],lcnt[u]++;
	if(lcnt[u])lcnt[u]--;
}
void dfs2(int u){
	if(!top[u])top[u]=u;
	if(~col[u])return;
	pair<int,int>mx=mp(0,0);
	for(auto v:e[u])if(v!=fa[u])chkmx(mx,mp(sz[v],v));
	top[son[u]=mx.se]=top[u];
	for(auto v:e[u])if(v!=fa[u])dfs2(v);
}

int root[N],pa[N],ch[N][2];//
bool isroot(int x){return ch[pa[x]][0]!=x&&ch[pa[x]][1]!=x;}
struct node{
	//
	int k,a,b,c;
	// x>k a   x=k b   x<k-1 c
	node(int x=0){k=a=b=c=x;}
	int operator()(int x)const{
		if(x>k)return a;
		if(x==k)return b;
		if(x<k)return c;
	}
	friend node operator+(const node&f,const node&g){
		// f(g(x))
		node res=g;
		res.a=f(g.a);res.b=f(g.b);res.c=f(g.c);
		return res;
	}
}f[N],mul[N];
//fmul
void pushup(int x){
	mul[x]=f[x];
	if(ch[x][1])mul[x]=mul[x]+mul[ch[x][1]];
	if(ch[x][0])mul[x]=mul[ch[x][0]]+mul[x];
}
void upd(int x){
	// f
	int k=T.qry(lrt[x],-n-1,n+1,0,lcnt[x]);
	int delta=k+2*T.ct(lrt[x],-n-1,n+1,-n-1,k)-lcnt[x];
	assert(delta>0);
	int cnt0=T.ct(lrt[x],-n-1,n+1,k,k);
	f[x].k=k;
	if(delta==1)f[x].a=k+1;else f[x].a=k;
	f[x].b=k;
	if(delta-1-2*cnt0+2>1)f[x].c=k-1;
	else f[x].c=k;
}
int build(int l,int r,vector<int>&arr){
	if(l>r)return 0;
	int x=arr[mid];
	ch[x][0]=build(l,mid-1,arr);if(ch[x][0])pa[ch[x][0]]=x;
	ch[x][1]=build(mid+1,r,arr);if(ch[x][1])pa[ch[x][1]]=x;
	pushup(x);
	return x;
}
void dfs3(int u){
	//
	vector<int>now;
	for(int x=u;x;x=son[x])now.pb(x);
	for(auto x:now)
		for(auto y:e[x])if(y!=fa[x]&&y!=son[x])
			dfs3(y),T.upd(lrt[x],-n-1,n+1,mul[root[y]](0),1),pa[root[y]]=x;
	for(auto x:now){
		if(son[x])upd(x);
		else{
			assert(sz[x]==1);
			if(col[x]==0)f[x]=node(-n-1);
			else f[x]=node(n+1);
		}
	}
	root[u]=build(0,now.size()-1,now);
}
void mdf(int x){
	//x
	if(col[x]==0)f[x]=node(-n-1);
	else f[x]=node(n+1);
	for(;x;x=pa[x])
		if(isroot(x)){
			T.upd(lrt[pa[x]],-n-1,n+1,mul[x](0),-1);
			pushup(x);
			T.upd(lrt[pa[x]],-n-1,n+1,mul[x](0),1);
			upd(pa[x]);
		}else pushup(x);
}
node qry(int x){
	//
	node res=f[x];
	if(ch[x][1])res=res+mul[ch[x][1]];
	while(!isroot(x)){
		if(x==ch[pa[x]][0]){
			x=pa[x];res=res+f[x];
			if(ch[x][1])res=res+mul[ch[x][1]];
		}
		else x=pa[x];
	}
	return res;
}

signed main(){
	read(n,nowk);
	for(int i=1,u,v;i<n;i++)read(u,v),e[u].pb(v),e[v].pb(u);
	for(int i=1;i<=n;i++)read(col[i]);
	dfs1(1);
	dfs2(1);
	dfs3(1);
	read(q);while(q--){
		int op;read(op);
		if(op==1){
			int v;read(v);node res=qry(v);
			assert(res.a==res.b&&res.b==res.c);
			write((int)(nowk<res(0)));pc('\n');
		}else if(op==2){
			int v;read(v);read(col[v]);
			mdf(v);
		}else read(nowk);
	}
}
//orzorzorz