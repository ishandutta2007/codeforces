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
const int N=1e5+10;
int n,m;vector<int>e[N];
int dep[N],buc[N];
int ans[N];
vector<pair<int,int>>q1[N],q2[N];
#define mp make_pair
#define pb push_back
//
#define mid (l+r>>1)
int tot,lc[N<<5],rc[N<<5],val[N<<5];
void upd(int&x,int l,int r,int pos){
	if(!x)x=++tot;
	val[x]++;
	if(l==r)return;
	if(pos<=mid)upd(lc[x],l,mid,pos);
	else upd(rc[x],mid+1,r,pos);
}
int qry(int x,int l,int r,int pos){
	if(l==r)return val[x];
	if(pos<=mid)return qry(lc[x],l,mid,pos);
	else return qry(rc[x],mid+1,r,pos);
}
int merge(int x,int y,int l,int r){
	//printf("%d %d %d %d\n",x,y,l,r);
	if(!x||!y)return x^y;
	val[x]+=val[y];
	if(l==r)return x;
	lc[x]=merge(lc[x],lc[y],l,mid);
	rc[x]=merge(rc[x],rc[y],mid+1,r);
	return x;
}
// 
int fa[N],rt[N];
void dfs(int u){
	if(u!=0)
	dep[u]=dep[fa[u]]+1,
	buc[dep[u]]=u,upd(rt[u],1,n,dep[u]);
	for(auto v:e[u])
		dfs(v),rt[u]=merge(rt[u],rt[v],1,n);
	//
	for(auto&qry:q1[u])
		if(dep[u]>qry.first)
			q2[buc[dep[u]-qry.first]].pb(mp(dep[u],qry.second));
	//
	for(auto&qry:q2[u])
		ans[qry.second]=::qry(rt[u],1,n,qry.first)-1;
}
signed main(){
	read(n);
	for(int i=1,x;i<=n;i++)
		read(fa[i]),e[fa[i]].pb(i);
	read(m);
	for(int i=1,x,y;i<=m;i++)
		read(x,y),q1[x].pb(mp(y,i));
	dfs(0);
	for(int i=1;i<=m;i++)
		write(ans[i]),putc(' ');
    flush();
    return 0;
}