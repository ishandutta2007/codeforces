#include<bits/stdc++.h>
namespace in{
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	template <typename T>inline void read(T& t){t=0;int f=0;char ch=getc();while (!isdigit(ch)){if(ch=='-')f = 1;ch=getc();}while(isdigit(ch)){t=t*10+ch-48;ch = getc();}if(f)t=-t;}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
}
namespace out{
	char buffer[1<<21];int p1=-1;const int p2 = (1<<21)-1;
	inline void flush(){fwrite(buffer,1,p1+1,stdout),p1=-1;}
	inline void putc(const char &x) {if(p1==p2)flush();buffer[++p1]=x;}
	template <typename T>void write(T x) {static char buf[15];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}while (len>=0)putc(buf[len]),--len;}
}
using namespace std;
int n;const int maxn=5e5+10;
struct DATA{
	int val[maxn<<4];void build(int x,int l,int r){val[x]=0;if(l==r)return;int mid=l+r>>1;build(x<<1,l,mid);build(x<<1|1,mid+1,r);}
	void change(int x,int l,int r,int L,int R,int Val){if(L<=l&&r<=R){val[x]=Val;return;}if(r<L||l>R)return;if(val[x]==Val)return;if(val[x]!=-1)val[x<<1]=val[x<<1|1]=val[x];int mid=l+r>>1;val[x]=-1;change(x<<1,l,mid,L,R,Val);change(x<<1|1,mid+1,r,L,R,Val);if(val[x<<1]==val[x<<1|1])val[x]=val[x<<1];}
	int qry(int x,int l,int r,int pos){if(val[x]!=-1)return val[x];int mid=l+r>>1;if(pos<=mid)return qry(x<<1,l,mid,pos);else return qry(x<<1|1,mid+1,r,pos);}
};
struct SHUPOU{// 
	vector<int>e[maxn];int size[maxn],fath[maxn],deep[maxn],dfn[maxn],top[maxn],cnt;DATA TREE;
	void dfs1(int u){for(auto v:e[u])if(v!=fath[u]){fath[v]=u,size[v]=1,deep[v]=deep[u]+1;dfs1(v);size[u]+=size[v];} }
	void dfs2(int u){dfn[u]=++cnt;int mx=-1,son;for(auto v:e[u])if(v!=fath[u])if(size[v]>mx)mx=size[v],son=v;if(mx==-1)return;top[son]=top[u];dfs2(son);for(auto v:e[u])if(v!=fath[u]&&v!=son)top[v]=v,dfs2(v);}
	void init(){cnt=0;top[1]=deep[1]=size[1]=1;dfs1(1);dfs2(1);}void upd_son(int x,int val){TREE.change(1,1,n,dfn[x],dfn[x]+size[x]-1,val);}
	void upd(int x,int y,int val){while(top[x]!=top[y]){if(deep[top[x]]<deep[top[y]])swap(x,y);TREE.change(1,1,n,dfn[top[x]],dfn[x],val);x=fath[top[x]];}if(deep[x]<deep[y])swap(x,y);TREE.change(1,1,n,dfn[y],dfn[x],val);}
}G;
signed main(){
	in::read(n);for(int i=1;i<n;i++){int u,v;in::read(u,v);G.e[u].push_back(v);G.e[v].push_back(u);}G.init();int q;in::read(q);
	while(q--){int opt,x;in::read(opt,x);if(opt==1)G.upd_son(x,1);if(opt==2)G.upd(x,1,0);if(opt==3)out::putc(G.TREE.qry(1,1,n,G.dfn[x])+'0'),out::putc('\n');}out::flush();return 0;
}