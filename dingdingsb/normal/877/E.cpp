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
	}tree[maxn<<2];
	#define l(x) tree[(x)].l
	#define r(x) tree[(x)].r
	#define mid(x) (tree[(x)].l+tree[(x)].r>>1)
	#define tag(x) tree[(x)].tag
	#define val(x) tree[(x)].val
	#define lson x<<1
	#define rson x<<1|1
	int a[maxn];
	void pushdown(int x){
		if(tag(x)){
			tag(lson)^=1,val(lson)=r(lson)-l(lson)+1-val(lson);
			tag(rson)^=1,val(rson)=r(rson)-l(rson)+1-val(rson);
			tag(x)=0;
		}
	} 
	void pushup(int x){
		val(x)=val(lson)+val(rson);
	}
	void build(int x,int l,int r){
		l(x)=l,r(x)=r;tag(x)=0;
		if(l==r){val(x)=a[l];return;}
		build(lson,l(x),mid(x));
		build(rson,mid(x)+1,r(x));
		pushup(x);
	}
	void change(int x,int l,int r){//[l,r] 
		if(r<l(x)||r(x)<l)return;
		if(l<=l(x)&&r(x)<=r){
			tag(x)^=1;
			val(x)=r(x)-l(x)+1-val(x);
			return;
		}
		pushdown(x);
		change(lson,l,r);
		change(rson,l,r);
		pushup(x);
	}
	int query(int x,int l,int r){
		if(r<l(x)||r(x)<l)return 0;
		if(l<=l(x)&&r(x)<=r)return val(x);
		pushdown(x);
		return query(lson,l,r)+query(rson,l,r); 
	}
}T; 
int n,m,a;
struct Graph{
	struct node{
		int v,nxt;
	}e[maxn<<1];
	int cnt,head[maxn];
	void add(int x,int y){e[++cnt]=(node){y,head[x]};head[x]=cnt;}
	int tot,dfn[maxn],size[maxn];
	void dfs(int x,int fa){
		dfn[x]=++tot,size[x]=1;
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
	in::read(n);
	for(int i=1;i<n;i++)
		in::read(a),G.add(a,i+1);
	G.dfs(1,0);
	for(int i=1;i<=n;i++)
		in::read(a),T.a[G.dfn[i]]=a;
	T.build(1,1,n);
	in::read(m);
	while(m--){
		char opt=get();
		int x;in::read(x);
		if(opt=='g'){
			out::write(T.query(1,G.dfn[x],G.dfn[x]+G.size[x]-1));
			out::putc('\n');	
		}
		else{
			T.change(1,G.dfn[x],G.dfn[x]+G.size[x]-1);
		}
		//for(int i=1;i<=n;i++)
		//	out::write(T.query(1,i,i)),out::putc(' ');
		//out::putc('\n');
	}
	out::flush();
	return 0;
}