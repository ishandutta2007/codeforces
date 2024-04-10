#include<bits/stdc++.h>
namespace in{
	//char buf[1<<21],*p1=buf,*p2=buf;
	//inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	inline int getc(){return getchar();}
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
const int N=3e5+100;
typedef long long ll;
int tot=0,n,m;
pair<ll,int>a[N*2];
vector<pair<ll,int>>v[N];
vector<int>e[N];
#define pb push_back
int rt[N],dep[N],dis[N*2],lc[N*2],rc[N*2];
ll f[N],tag[N*2];
void work(int x,ll val){
	tag[x]+=val;a[x].first+=val;
}
void pushdown(int x){
	if(tag[x]){
		work(lc[x],tag[x]);
		work(rc[x],tag[x]);
		tag[x]=0;
	}
}
int merge(int x,int y){
	if(!x||!y)return x^y;
	if(a[x].first>a[y].first)swap(x,y);
	pushdown(x);
	rc[x]=merge(rc[x],y);
	if(dis[rc[x]]>dis[lc[x]])swap(lc[x],rc[x]);
	dis[x]=dis[rc[x]]+1;
	return x;
}
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	for(auto Seg:v[u])
		a[++tot]={Seg.first,Seg.second},
		dis[tot]=1,rt[u]=merge(rt[u],tot);
	ll sum=0;
	for(auto v:e[u])if(v!=fa)
		dfs(v,u),work(rt[v],-f[v]),
		rt[u]=merge(rt[u],rt[v]),sum+=f[v];
	work(rt[u],sum);
	while(rt[u]&&dep[u]<=dep[a[rt[u]].second])pushdown(rt[u]),rt[u]=merge(lc[rt[u]],rc[rt[u]]);
	if(!rt[u])out::write(-1),out::flush(),exit(0);
	f[u]=a[rt[u]].first;
}
signed main(){
	in::read(n,m);tot=n;dep[1]=1;
	for(int i=1,u,v;i<n;i++)
		in::read(u,v),e[u].pb(v),e[v].pb(u);
	for(int i=1,x,y,k;i<=m;i++){
		in::read(x,y,k);
		v[x].pb({k,y});
	}
	ll ans=0;
	for(auto v:e[1])dfs(v,1),ans+=f[v];
	out::write(ans);out::flush();
}