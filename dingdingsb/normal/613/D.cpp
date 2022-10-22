#include<bits/stdc++.h>
namespace in{
	#ifndef slow
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
const int N=1e5+100;
int n,k,q,ans,tp,cnt;
int dfn[N],top[N],son[N],sz[N],fa[N],dep[N],st[N];
vector<int>e[N];pair<int,int>a[N];
void dfs1(int u){
	dep[u]=dep[fa[u]]+1;sz[u]=1;
	for(auto v:e[u])if(v!=fa[u])
		fa[v]=u,dfs1(v),sz[u]+=sz[v],(sz[v]>sz[son[u]])&&(son[u]=v);
}
void dfs2(int u){
	if(!top[u])top[u]=u;dfn[u]=++cnt;
	if(son[u])top[son[u]]=top[u],dfs2(son[u]);
	for(auto v:e[u])if(v!=fa[u]&&v!=son[u])dfs2(v);
}
inline int lca(int x,int y){
	while(top[x]!=top[y])
		if(dep[top[x]]>dep[top[y]])x=fa[top[x]];
		else y=fa[top[y]];
	if(dep[x]<dep[y])return x;return y;
}
void ins(int x){
	if(tp==0)return st[tp=1]=x,(void)(1);
	int z=lca(st[tp],x);
	while(tp>1&&dep[z]<dep[st[tp-1]])
		e[st[tp-1]].push_back(st[tp]),--tp;
	if(dep[z]<dep[st[tp]])e[z].push_back(st[tp--]);
	if(!tp||(st[tp]!=z))st[++tp]=z;
	st[++tp]=x;
}
void dfs3(int u){
	//printf("%d\n",u);
	if(sz[u]){
		for(auto v:e[u]){
			dfs3(v);
			if(sz[v])
				sz[v]=0,ans++;
		}
	}else{
		for(auto v:e[u])
			dfs3(v),sz[u]+=sz[v],sz[v]=0;
		if(sz[u]>1)
			ans++,sz[u]=0;
	}
	e[u].clear();
}
signed main(){
	in::read(n);
	for(int i=1,u,v;i<n;i++)
		in::read(u,v),e[u].push_back(v),e[v].push_back(u);
	dfs1(1);dfs2(1);
	memset(sz,0,sizeof sz);
	for(int i=1;i<=n;i++)e[i].clear();
	in::read(q);
	while(q--){
		in::read(k);
		for(int i=1;i<=k;i++)
			in::read(a[i].second),sz[a[i].second]=1,a[i].first=dfn[a[i].second];
		for(int i=1;i<=k;i++)if(sz[fa[a[i].second]]){
			out::write(-1);out::putc('\n');
			while(k)sz[a[k--].second]=0;
			goto loop;
		}
		ans=0;sort(a+1,a+1+k);
		if(a[1].second!=1)st[tp=1]=1;
		for(int i=1;i<=k;i++)ins(a[i].second);
		if(tp)while(--tp)e[st[tp]].push_back(st[tp+1]);
		dfs3(1);sz[1]=0;
		out::write(ans);out::putc('\n');
		loop:;
	}
	out::flush();
	return 0;
}