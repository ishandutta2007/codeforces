#include<bits/stdc++.h>
//#define faster
namespace in{
	#ifdef faster
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	#else
	inline int getc(){return getchar();}
	#endif
	template <typename T>inline void read(T& t){
		t=0;int f=0;char ch=getc();while (!isdigit(ch)){if(ch=='-')f = 1;ch=getc();}
	    while(isdigit(ch)){t=t*10+ch-48;ch = getc();}if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
}
namespace out{
	char buffer[1<<21];int p1=-1;const int p2 = (1<<21)-1;
	inline void flush(){fwrite(buffer,1,p1+1,stdout),p1=-1;}
	inline void putc(const char &x) {if(p1==p2)flush();buffer[++p1]=x;}
	template <typename T>void write(T x) {
		static char buf[15];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
		while (len>=0)putc(buf[len]),--len;
	}
}
using namespace std;
 
const int maxn=3010,maxe=200*maxn;
struct Graph{
	struct node{
		int v,w,nxt;
	}e[maxe<<1];
	int head[maxn],cur[maxn],tot;
	int dis[maxn];
	int s,t;
	void init(int _s,int _t){s=_s,t=_t;tot=1;memset(head,0,sizeof head);}
	Graph(int _s=0,int _t=0){init(_s,_t);}
	void add(int u,int v,int w){
		//printf("%d %d %d\n",u,v,w);
		e[++tot]=(node){v,w,head[u]},head[u]=tot;
		e[++tot]=(node){u,0,head[v]},head[v]=tot;
	}
	#define v e[i].v
	inline bool bfs(){
		queue<int>q;
		memset(dis,0,sizeof dis);
		memcpy(cur,head,sizeof head);
		dis[s]=1;q.push(s);
		while(q.size()){
			int u=q.front();q.pop();
			for(int i=head[u];i;i=e[i].nxt)
				if(!dis[v]&&e[i].w){
					dis[v]=dis[u]+1,q.push(v);
					if(v==t)return true;
				}
		}
		return  false;
	}
	int dfs(int u,int flow){
		if(u==t)return flow;
		int rest=flow;
		for(int i=cur[u];i&&rest;i=e[i].nxt){
			if(dis[v]==dis[u]+1&&e[i].w){
				int tmp=dfs(v,min(rest,e[i].w));
				rest-=tmp,e[i].w-=tmp,e[i^1].w+=tmp;
			}
			cur[u]=i;
		}
		if(rest==0)dis[u]=-1;
		return flow-rest;
	}
	#undef v
	int dinic(){
		int ans=0;
		while(bfs())
			while(int sth=dfs(s,2e9))
				ans+=sth;
		return ans;
	}
}G;
int n,a[maxn],b[maxn],sum;
bool t[120];
signed main(){
	in::read(n);
	G.init(0,n+1); 
	for(int i=1;i<=n;i++)in::read(a[i]);
	for(int i=1;i<=n;i++)in::read(b[i]);
	for(int i=1;i<=n;i++){
		if(b[i]>0)sum+=b[i],G.add(G.s,i,b[i]);
		else G.add(i,G.t,-b[i]);
	}
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof t);
		for(int j=i-1;j>=1;j--)
			if(a[i]%a[j]==0&&!t[a[j]])
				t[a[j]]=1,
				G.add(i,j,2e9);
	}out::write(sum-G.dinic());out::flush();
	return 0;
	//cout<<"fuck you"
}