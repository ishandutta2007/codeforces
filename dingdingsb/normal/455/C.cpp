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
const int maxn=3e5+100;
int fa[maxn];
int getfa(int x){
	if(x==fa[x])return x;
	return fa[x]=getfa(fa[x]);
}
struct node{int v,nxt;}e[maxn<<1];
int tot=0,head[maxn];
inline void add(int u,int v){e[++tot]=(node){v,head[u]};head[u]=tot;}
int maxp,dis[maxn];
#define v e[i].v
void dfs(int u,int fa){
	//
	if(dis[u]>dis[maxp])maxp=u;
	for(int i=head[u];i;i=e[i].nxt){
		if(v==fa)continue;
		dis[v]=dis[u]+1,dfs(v,u);
	} 
}
int n,m,q,x,y;
bool vis[maxn];
int c[maxn];
signed main(){
	in::read(n,m,q);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
		in::read(x,y),fa[getfa(x)]=getfa(y),add(x,y),add(y,x);
	for(int i=1;i<=n;i++)
		if(!vis[getfa(i)]){
			dis[maxp=0]=-1;dfs(i,0);
			int st=maxp;dis[maxp=0]=-1;dfs(st,0);
			c[getfa(i)]=dis[maxp]-dis[st],vis[getfa(i)]=true;
		}
	for(int i=1;i<=q;i++){
		int opt;in::read(opt);
		if(opt==1){
			in::read(x);
			out::write(c[getfa(x)]);out::putc('\n');
		}
		else{
			in::read(x,y);
			if(getfa(x)==getfa(y))continue;
			c[getfa(y)]=max((c[getfa(x)]+1)/2+(c[getfa(y)]+1)/2+1,max(c[getfa(x)],c[getfa(y)]));
			fa[getfa(x)]=getfa(y);
		}
	}
	out::flush();
	return 0;
}