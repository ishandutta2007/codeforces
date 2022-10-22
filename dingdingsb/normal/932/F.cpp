#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define pb push_back
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
typedef long long ll;
const ll inf=0x7f7f7f7f7f7f7f7fll;
const int N=1e5+10,M=1e5;
int n,a[N],b[N];ll dp[N];
vector<int>e[N];int fa[N];
//LCT merge 
//-  
struct rec{
	int k;ll b;
	ll operator()(const int x){return 1ll*x*k+b;}
}f[N];
int cnt=0;
int newrec(int k,ll b){f[++cnt]={k,b};return cnt;}
//-  
struct node{
	int ls,rs,index;
}t[N<<3];
int tot;
#define id t[x].index
#define lc t[x].ls
#define rc t[x].rs
#define mid ((l+r)/2)
//-  
void upd(int&x,int l,int r,int y){
	//
	if(!x)x=++tot;
	if(f[y](l)<=f[id](l)&&f[y](r)<=f[id](r))return id=y,void();
	if(f[y](l)>=f[id](l)&&f[y](r)>=f[id](r))return;
	//
	if(f[y].k>f[id].k){
		if(f[y](mid)<f[id](mid))upd(rc,mid+1,r,id),id=y;
		else upd(lc,l,mid,y);
	} else{
		if(f[y](mid)<f[id](mid))upd(lc,l,mid,id),id=y;
		else upd(rc,mid+1,r,y);
	}
}
//-  
ll qry(int x,int l,int r,int X){
	if(!x)return inf;
	if(l==r)return f[id](X);
	if(X<=mid)return min(f[id](X),qry(lc,l,mid,X));
	else return min(f[id](X),qry(rc,mid+1,r,X));
}
//- 
int merge(int x,int y,int l,int r){
	if(!x||!y)return x|y;
	if(l==r){
		if(f[id](l)>f[t[y].index](l))id=t[y].index;
		return x;
	}
	lc=merge(lc,t[y].ls,l,mid);
	rc=merge(rc,t[y].rs,mid+1,r);
	upd(x,l,r,t[y].index);
	return x;
} 
//dfs
int rt[N];
void dfs(int u){
	if(e[u].size()+(u==1)==1){
		dp[u]=0;
		upd(rt[u],-M,M,newrec(b[u],0));
		return;
	}else{
		for(auto v:e[u])if(v!=fa[u]){
			fa[v]=u;dfs(v);
			rt[u]=merge(rt[u],rt[v],-M,M);
		}
		dp[u]=qry(rt[u],-M,M,a[u]);
		upd(rt[u],-M,M,newrec(b[u],dp[u]));
	}
} 
signed main(){
	f[0].b=inf;
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++)read(b[i]);
	for(int i=1;i<n;i++){
		int u,v;read(u,v);
		e[u].pb(v);e[v].pb(u);
	}
	dfs(1);
	for(int i=1;i<=n;i++)
		write(dp[i]),putc(' ');
    flush();
    return 0;
}