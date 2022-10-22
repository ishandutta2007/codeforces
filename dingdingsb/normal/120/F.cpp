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
int ans;struct tree{
	struct node{int v,nxt;}e[220];
	int head[120],cnt;int dis[120];
	void clear(){cnt=0;memset(head,0,sizeof head);}
	void add(int u,int v){
		e[++cnt]=(node){v,head[u]};head[u]=cnt;
		e[++cnt]=(node){u,head[v]};head[v]=cnt;
	}void dfs(int u,int fa,int now,int &ans){
		dis[u]=now;
		if(dis[u]>dis[ans])ans=u;
		for(int i=head[u];i;i=e[i].nxt)
			if(e[i].v!=fa)
				dfs(e[i].v,u,now+1,ans);
	}int get(){
		int st=0,ed=0;
		memset(dis,0,sizeof dis);dis[0]=-1;dfs(1,-1,0,st);
		memset(dis,0,sizeof dis);dis[0]=-1;dfs(st,-1,0,ed);
		return dis[ed];
	}
}G;
signed main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int n,nx,ans=0,u,v;
	in::read(n);
	while(n--){
		in::read(nx);G.clear();
		for(int i=1;i<nx;i++)
			in::read(u,v),G.add(u,v);
		ans+=G.get();
	}
	out::write(ans);
	out::flush();
}