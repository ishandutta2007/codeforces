 //#pragma GCC optimize(3,"Ofast","inline")
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
const int maxn=1e5+100,inf=(int)1e7+10;
int n,k;
struct node{
	int v,w,nxt;
}e[maxn<<1];
int cnt,head[maxn];
void add(int x,int y,int z){
	e[++cnt]=(node){y,z,head[x]};
	head[x]=cnt;
}
int maxp[maxn],size[maxn],dis[maxn],rem[maxn];
int vis[maxn],judge[inf],q[maxn];
int sum,rt;long long ans;
#define chkmax(a,b) (a)=max((a),(b))
void getrt(int u,int fa){
	size[u]=1;maxp[u]=0;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa||vis[v])continue;
		getrt(v,u);
		size[u]+=size[v];
		chkmax(maxp[u],size[v]);
	}
	chkmax(maxp[u],sum-size[u]);
	if(maxp[u]<maxp[rt])rt=u;
}
void getdis(int u,int fa){
	rem[++rem[0]]=dis[u];
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].v,w=e[i].w;
		if(v==fa||vis[v])continue;
		dis[v]=dis[u]+w;
		getdis(v,u);
	}
}
void calc(int u){
	int p=0;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].v,w=e[i].w;
		if(vis[v])continue;
		rem[0]=0;dis[v]=w;
		getdis(v,u);
		for(int j=rem[0];j;j--)
			ans+=judge[k-rem[j]];
		for(int j=rem[0];j;j--)
			q[++p]=rem[j],judge[rem[j]]++;
	}
	for(int i=1;i<=p;i++)
		judge[q[i]]--;
}
void solve(int u){
	vis[u]=judge[0]=1;calc(u);
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].v,w=e[i].w;
		if(vis[v])continue;
		sum=size[v];maxp[rt=0]=inf;
		getrt(v,0);solve(rt);
	}
}
signed main(){
	in::read(n,k);
	for(int i=1;i<n;i++){
		int u,v;in::read(u,v);
		add(u,v,1);add(v,u,1);
	}
	maxp[rt]=sum=n;
	getrt(1,0);
	solve(rt);
	out::write(ans);
	out::flush();
	return 0;
}