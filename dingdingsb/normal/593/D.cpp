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
		static char buf[35];
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
int n,m;
struct mylong{
	long long num;
	void operator=(long long b){
		num=b;
	}
	mylong operator+(mylong b){
		mylong c;
		if(log10(b.num)+log10(num)>18.1)
			c=2e18;
		else c=b.num*num;
		return c; 
	}
};
const int N=200000+100;
template<class A,class B>
struct SGT{
	B a[N];// 
	struct node{
		int l,r;
		A val;
	}T[N*4];
	B* operator[](const int x){return a+x;}
	void build(int x,int l,int r){
		T[x].l=l,T[x].r=r;
		if(l==r){
			T[x].val=a[l];
			return;
		}
		int mid=l+r>>1;
		build(x<<1,l,mid);
		build(x<<1|1,mid+1,r);
		T[x].val=T[x<<1].val+T[x<<1|1].val;
	}
	void change(int x,int pos,B val){
		if(T[x].r==T[x].l){
			T[x].val=val;
			return;
		}
		int mid=T[x].l+T[x].r>>1;
		if(pos<=mid)change(x<<1,pos,val);
		else change(x<<1|1,pos,val);
		T[x].val=T[x<<1].val+T[x<<1|1].val;
	}
	A query(int x,int l,int r){
		if(l<=T[x].l&&T[x].r<=r)return T[x].val;
		int mid=T[x].l+T[x].r>>1;
		if(r<=mid)
			return query(x<<1,l,r);
		if(l>mid)
			return query(x<<1|1,l,r);
		return query(x<<1,l,r)+query(x<<1|1,l,r);
	}
};
SGT<mylong,long long>T;
vector<int>e[N];
int fath[N];
int deep[N];
int size[N];
int dfn[N];
int top[N];
int cnt;
void dfs1(int u){
	size[u]=1;
	for(auto v:e[u])
		if(v!=fath[u])
			fath[v]=u,
			deep[v]=deep[u]+1,
			dfs1(v),
			size[u]+=size[v];
}
void dfs2(int u){
	if(!fath[u])top[u]=u;
	dfn[u]=++cnt;
	int mx=-1,son;
	for(auto v:e[u])
		if(v!=fath[u])
			if(size[v]>mx)
				mx=size[v],
				son=v;
	if(mx==-1)return;
	top[son]=top[u];dfs2(son);
	for(auto v:e[u])
		if(v!=fath[u]&&v!=son)
			top[v]=v,
			dfs2(v);
}
struct node{int u,v,id;long long w;}E[N];
signed main(){
	in::read(n,m);
	for(int i=1;i<n;i++)
		in::read(E[i].u,E[i].v,E[i].w),
		e[E[i].u].push_back(E[i].v),
		e[E[i].v].push_back(E[i].u);
	dfs1(1);dfs2(1);
	for(int i=1;i<n;i++)
		if(fath[E[i].u]==E[i].v)E[i].id=dfn[E[i].u];
		else E[i].id=dfn[E[i].v];
	for(int i=1;i<n;i++)*T[E[i].id]=E[i].w;
	T.build(1,1,n);
	while(m--){
		int opt,x,y,p;
		long long c;
		in::read(opt);
		if(opt==1){
			in::read(x,y,c);
			mylong ans;ans=1;
            while(top[x] != top[y]){
                if(deep[top[x]]<deep[top[y]]) swap(x, y);
                ans=ans+T.query(1,dfn[top[x]],dfn[x]);
                x=fath[top[x]];
            }
            if(deep[x]>deep[y])swap(x,y);
            if(dfn[x]!=dfn[y])ans=ans+T.query(1,dfn[x]+1,dfn[y]);
            out::write(c/ans.num);
            out::putc('\n');
		}
		else if(opt==2){
			in::read(p,c);
			T.change(1,E[p].id,c);
		}
	}
	out::flush();
	return 0;
}