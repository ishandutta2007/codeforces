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
using in::read;
using out::write;
using out::putc;
using out::flush;
using namespace std;
const int N=1e6+10,M=N<<2;
int n;vector<int>e[N];
//WYHAK
#define mp make_pair
#define mid (l+r>>1)
pair<int,int>val[M];
int lc[M],rc[M],tot;
int st[M],tp;
int newnode(){
	int x;if(tp)x=st[tp--];else x=++tot;
	lc[x]=rc[x]=0;val[x]=mp(0,0);
	return x;
}
void upd(int&x,int l,int r,int pos){
	if(!x)x=newnode();
	if(l==r){
		val[x].first++;
		val[x].second=-l;
		return;
	}
	if(pos<=mid)upd(lc[x],l,mid,pos);
	else upd(rc[x],mid+1,r,pos);
	val[x]=max(val[lc[x]],val[rc[x]]);
}
int merge(int x,int y,int l,int r){
	if(!x||!y)return x^y;
	st[++tp]=y;
	if(l==r){
		val[x].first+=val[y].first;
		return x;
	}
	lc[x]=merge(lc[x],lc[y],l,mid);
	rc[x]=merge(rc[x],rc[y],mid+1,r);
	val[x]=max(val[lc[x]],val[rc[x]]);
	return x;
}
//ASHDASD
int mdep,fa[N],dep[N],sz[N],rt[N];
void dfs1(int u){
	dep[u]=dep[fa[u]]+1;sz[u]=1;
	mdep=max(mdep,dep[u]);
	for(auto v:e[u])if(v!=fa[u])fa[v]=u,dfs1(v),sz[u]+=sz[v];
}
int ans[N];
void dfs2(int u){
	sort(e[u].begin(),e[u].end(),[&](const int&x,const int&y){return sz[x]>sz[y];});
	for(auto v:e[u])if(v!=fa[u])
		dfs2(v),rt[u]=merge(rt[u],rt[v],1,mdep);
	upd(rt[u],1,mdep,dep[u]);
	ans[u]=-val[rt[u]].second-dep[u];
}
signed main(){
	read(n);
	for(int i=1,x,y;i<n;i++)
		read(x,y),e[x].push_back(y),e[y].push_back(x);
	dfs1(1);
	dfs2(1);
	for(int i=1;i<=n;i++)
		write(ans[i]),putc('\n');
    flush();
    return 0;
}