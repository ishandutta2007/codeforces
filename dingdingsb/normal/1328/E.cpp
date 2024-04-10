 #pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
namespace in{
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){
	    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
	}
	template <typename T>inline void read(T& t){
	    t=0;int f=0;char ch=getc();
	    while (!isdigit(ch)){
	        if(ch=='-')f = 1;
	        ch=getc();
	    }
	    while(isdigit(ch)){
   	    	t=t*10+ch-48;
   	    	ch = getc();
   		}
		if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){
	    read(t);read(args...);
	}
}
namespace out{
	char buffer[1<<21];
	int p1=-1;
	const int p2 = (1<<21)-1;
	inline void flush() {
		fwrite(buffer,1,p1+1,stdout),
		p1=-1;
	}
	inline void putc(const char &x) {
		if(p1==p2)flush();
		buffer[++p1]=x;
	}
	template <typename T>void write(T x) {
		static char buf[15];
		static int len=-1;
		if(x>=0){
			do{
    			buf[++len]=x%10+48,x/=10;
    		}while (x);
		}else{
    		putc('-');
			do {
    			buf[++len]=-(x%10)+48,x/=10;
			}while(x);
		}
		while (len>=0)
			putc(buf[len]),--len;
	}
}
using namespace std;
const int maxn=200000+10;
struct TREE{
	struct node{
		int l,r;
		int tag,val;
		bool tag2;
	}tree[maxn<<2];
	#define l(x) tree[(x)].l
	#define r(x) tree[(x)].r
	#define mid(x) (tree[(x)].l+tree[(x)].r>>1)
	#define tag(x) tree[(x)].tag
	#define tag2(x) tree[(x)].tag2
	#define val(x) tree[(x)].val
	#define lson x<<1
	#define rson x<<1|1
	void pushdown(int x){
		if(tag2(x)){
			val(lson)=tag(lson)=0;
			tag2(lson)=1;
			val(rson)=tag(rson)=0;
			tag2(rson)=1;
			tag2(x)=0;
		}
		if(tag(x)){
			val(lson)+=tag(x);
			tag(lson)+=tag(x);
			val(rson)+=tag(x);
			tag(rson)+=tag(x);
			tag(x)=0;
		}
	}
	void pushup(int x){
		val(x)=max(val(lson),val(rson));
	}
	void build(int x,int l,int r){
		l(x)=l,r(x)=r,tag(x)=val(x)=0;
		if(l==r)return;
		int mid=l+r>>1;
		build(lson,l,mid);
		build(rson,mid+1,r);
	}
	void change(int x,int l,int r,int val){
		if(l(x)>r||r(x)<l)return;
		if(l<=l(x)&&r(x)<=r){
			val(x)+=val;
			tag(x)+=val;
			return;
		}
		pushdown(x);
		change(lson,l,r,val);
		change(rson,l,r,val);
		pushup(x);
	}
	int query(int x,int l,int r){
		if(l(x)>r||r(x)<l)return 0;
		if(l<=l(x)&&r(x)<=r)return val(x);
		pushdown(x);
		return max(query(lson,l,r),query(rson,l,r));
	}
	void clear(){
		val(1)=tag(1)=0;
		tag2(1)=1;
	}
}T; 
int n,m,a,b;
struct Graph{
	struct node{
		int v,nxt;
	}e[maxn<<1];
	int cnt,head[maxn];
	void add(int x,int y){e[++cnt]=(node){y,head[x]};head[x]=cnt;}
	int tot,dfn[maxn],size[maxn],fath[maxn];
	void dfs(int x,int fa){
		dfn[x]=++tot,size[x]=1,fath[x]=fa;
		for(int i=head[x];i;i=e[i].nxt)
			if(e[i].v!=fa)dfs(e[i].v,x),size[x]+=size[e[i].v];
	}
}G;
char get(){
	char c=in::getc();
	while(!isalpha(c))c=in::getc();
	return c;
}
signed main(){
	//freopen("in.cpp","r",stdin);
	in::read(n,m);
	int u,v;
	for(int i=1;i<n;i++)
		in::read(u,v),G.add(u,v),G.add(v,u);
	G.dfs(1,0);
	T.build(1,1,n);
	for(int i=1;i<=m;i++){
		T.clear(); 
		in::read(a);
		for(int j=1;j<=a;j++){
			in::read(b);//cout<<G.dfn[G.fath[b]]<<" "<<G.dfn[G.fath[b]]+G.size[G.fath[b]]-1<<endl;
			if(b!=1)T.change(1,G.dfn[G.fath[b]],G.dfn[G.fath[b]]+G.size[G.fath[b]]-1,1);
			else T.change(1,G.dfn[1],G.dfn[1]+G.size[1]-1,1);
		}
		//for(int i=1;i<=n;i++)
		//	cout<<T.query(1,i,i)<<" ";
		//cout<<endl; 
		if(T.query(1,1,n)==a)printf("YES\n");
		else printf("NO\n");
	}
	out::flush();
	return 0;
}