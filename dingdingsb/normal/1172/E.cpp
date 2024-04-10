#include<bits/stdc++.h>
namespace in{
	#ifdef slow
	inline int getc(){return getchar();}
	#else
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	#endif
	template <typename T>inline void read(T& t){
		t=0;int f=0;char ch=getc();while (!isdigit(ch)){if(ch=='-')f = 1;ch=getc();}
	while(isdigit(ch)){t=t*10+ch-48;ch = getc();}if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
	char getC(){char c=getc();while(!isalpha(c))c=getc();return c;}
}
namespace out{
	char buffer[1<<21];int p1=-1;const int p2 = (1<<21)-1;
	inline void flush(){fwrite(buffer,1,p1+1,stdout),p1=-1;}
	inline void putc(const char &x) {if(p1==p2)flush();buffer[++p1]=x;}
	template <typename T>void write(T x) {
		static char buf[25];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
		while (len>=0)putc(buf[len]),--len;
	}
	inline void puts(char *s){int now=0;while(s[now]!='\0')putc(s[now]),now++;putc('\n');}
}
using namespace std;
typedef long long ll;
const int N=4e5+100;
int pa[N],f[N],c[N][2],sz[N],szi[N];
ll sz2i[N];
int n,m,col[N];
ll ans,delta[N];
bool flag[N];vector<pair<int,int>>upd[N];
#define sz2(x) (1ll*sz[x]*sz[x])
#define lc c[x][0]
#define rc c[x][1]
#define get(x) (c[f[(x)]][1]==(x))
#define nroot(x) (c[f[(x)]][0]==(x)||c[f[(x)]][1]==(x))
void pushup(int x){
	sz[x]=sz[lc]+1+sz[rc]+szi[x];
}
void rotate(int x){
	int fa=f[x],ffa=f[fa],k=get(x),w=c[x][!k];
	if(nroot(fa))c[ffa][get(fa)]=x;c[x][!k]=fa;c[fa][k]=w;
	if(w)f[w]=fa;f[fa]=x;f[x]=ffa;pushup(fa);pushup(x);
}
void splay(int x){
	while(nroot(x)){
		int fa=f[x];
		if(nroot(fa))
			rotate(get(x)==get(fa)?fa:x);
		rotate(x);
	}
	pushup(x);
}
void access(int x){
	for(int y=0;x;x=f[y=x]){
		splay(x);
		szi[x]+=sz[rc];
		szi[x]-=sz[y];
		sz2i[x]+=sz2(rc);
		sz2i[x]-=sz2(y);
		rc=y;
		pushup(x);
	}
}
int findroot(int x){
	access(x);splay(x);
	while(lc)x=lc;
	splay(x);return x;
}
void add(int x){
	int fa=pa[x];splay(x);
	ans-=sz2i[x]+sz2(rc);
	int z=findroot(fa);
	access(x);splay(z);
	ans-=sz2(c[z][1]);
	f[x]=fa;
	splay(fa);
	szi[fa]+=sz[x];
	sz2i[fa]+=sz2(x);
	pushup(fa);access(x);splay(z);
	ans+=sz2(c[z][1]);
}
void del(int x){
	int fa=pa[x];access(x);
	ans+=sz2i[x];
	int z=findroot(fa);
	access(x);splay(z);
	ans-=sz2(c[z][1]);
	splay(x);
	lc=f[lc]=0;
	pushup(x);splay(z);
	ans+=sz2(c[z][1]);
}
vector<int>e[N];
#define pb push_back
void dfs(int u){
	for(auto v:e[u])
		if(v!=pa[u])
			pa[v]=u,dfs(v);
}
signed main(){
	ll lst=0;in::read(n,m);
	for(int i=1;i<=n;i++)
		in::read(col[i]),
		upd[col[i]].pb({i,0});
	for(int i=1;i<=n+1;i++)sz[i]=1;
	for(int i=1,u,v;i<n;i++)
		in::read(u,v),e[u].pb(v),e[v].pb(u);
	for(int i=1,u,x;i<=m;i++){
		in::read(u,x);
		upd[col[u]].pb({u,i});
		col[u]=x;
		upd[col[u]].pb({u,i});
	}
	pa[1]=n+1;dfs(1);
	for(int i=1;i<=n;i++)add(i);
	for(int i=1;i<=n;i++){
		if(upd[i].size()==0){
			delta[0]+=1ll*n*n;
			continue;
		}
		if(upd[i][0].second){
			delta[0]+=1ll*n*n;
			lst=1ll*n*n;
		}else lst=0;
		for(int j=0;j<upd[i].size();j++){
			int u=upd[i][j].first;
			if(flag[u]^=1)del(u);
			else add(u);
			if(j==upd[i].size()-1||upd[i][j+1].second!=upd[i][j].second){
				delta[upd[i][j].second]+=ans-lst;
				lst=ans;
			}
		}
		for(int j=upd[i].size()-1;j>=0;j--){
			int u=upd[i][j].first;
			if(flag[u]^=1)del(u);
			else add(u);
		}
	}
	ans=1ll*n*n*n;
	for(int i=0;i<=m;i++){
		ans-=delta[i];
		out::write(ans);
		out::putc('\n');
	}
	out::flush();
	return 0;
	//cout<<"f**k you";
}