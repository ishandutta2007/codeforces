#include<bits/stdc++.h>
#define int long long
#define maxn 200007
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
namespace in{
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
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
int n,m,res=inf,sumw,cnt;
struct node{
	int u,v,w,id;
	bool operator<(const node&b)const{return w<b.w;}
}a[maxn];
struct edge{
	int to,nxt,w;
}e[maxn<<1];
int tot,head[maxn];
inline void adde(int u,int v,int w){e[++tot]=(edge){v,head[u],w};head[u]=tot;}
int f[maxn];bool use[maxn];
int getf(int x){if(x==f[x])return x;return f[x]=getf(f[x]);}
int fa[maxn][19],w1[maxn][19],w2[maxn][19],dep[maxn];
void dfs(int u,int pa){
	fa[u][0]=pa;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;if(v==pa)continue;
		dep[v]=dep[u]+1;w1[v][0]=w2[v][0]=e[i].w;dfs(v,u);
	}
}
void build(){
	for(int j=1;j<=18;j++)
		for(int i=1;i<=n;i++){
			fa[i][j]=fa[fa[i][j-1]][j-1];
			w1[i][j]=w2[i][j]=max(w1[i][j-1],w1[fa[i][j-1]][j-1]);
		}
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=18;i>=0;i--)if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
	if(u==v)return u;
	for(int i=18;i>=0;i--)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int getmax(int u,int v,int maxx){
	int ans=-inf;
	for(int i=18;i>=0;i--)
		if(dep[fa[u][i]]>=dep[v]){
			if(maxx!=w1[u][i])ans=max(ans,w1[u][i]);
			else ans=max(ans,w2[u][i]);u=fa[u][i];
		}return ans;
}
bool cmp(node x,node y){return x.id<y.id;}
int ans[maxn];
signed main(){
	//freopen("1.in","r",stdin);
	in::read(n),in::read(m);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)in::read(a[i].u,a[i].v,a[i].w),a[i].id=i;
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++){
		int t1=getf(a[i].u),t2=getf(a[i].v);
		if(t1==t2)continue;
		f[t1]=t2,cnt++,sumw+=a[i].w;
		adde(a[i].u,a[i].v,a[i].w);adde(a[i].v,a[i].u,a[i].w);
		use[i]=1; 
	}
	w2[1][0]=-inf,dep[1]=1;dfs(1,0);build();
	for(int i=1;i<=m;i++){
		if(use[i]){ans[a[i].id]=sumw;continue;}
		int u=a[i].u,v=a[i].v,w=a[i].w,lc=lca(u,v);
		int max1=getmax(u,lc,w);int max2=getmax(v,lc,w);
		ans[a[i].id]=sumw-max(max1,max2)+w;
	}
	for(int i=1;i<=m;i++)out::write(ans[i]),out::putc('\n');
	out::flush();
}