#include<bits/stdc++.h>
#define pb push_back
using namespace std;

//#define DEBUG
#ifdef DEBUG
template<typename ...Args>
int debug(const Args &...args){
	return fprintf(stderr,args...);
}
#else
#define debug(...) void()
#endif

typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
/*
const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
*/
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n,m,q;

struct C{
	int x,y,a,b;
}c[64];
int a[128],b[128];
bool mrk[128][128];

int lim;
struct E{
	int t,n,v;
}e[1<<18];
int cnt=1,last[512],S,T,_last[512];
inline void adde(int x,int y,int u,int v){
//	printf("adde %d %d   %d %d\n",x,y,u,v);
	e[++cnt]=(E){y,last[x],u},last[x]=cnt;
	e[++cnt]=(E){x,last[y],v},last[y]=cnt;
}

int que[512],hd,tl;
int dep[512];
bool bfs(){
	hd=tl=0; memset(dep+1,-1,lim<<2);
	dep[S]=1; que[++tl]=S;
	while (hd<tl){
		int u=que[++hd],v;
		for (int i=last[u];i;i=e[i].n)
			if (e[i].v&&!~dep[v=e[i].t]){
				dep[v]=dep[u]+1;
				if (v==T) return 1;
				que[++tl]=v;
			}
	}
	return 0;
}
int dfs(int x,int flw){
	if (x==T) return flw;
	int t,used=0;
	for (int &i=_last[x],v;i;i=e[i].n)
		if (e[i].v&&dep[x]+1==dep[v=e[i].t]){
			t=dfs(v,min(flw-used,e[i].v));
			e[i].v-=t; e[i^1].v+=t;
			used+=t; if (used==flw) return used;
		}
	if (!used) dep[x]=-1;
	return used;
}
int dinic(){
	int z=0;
	while (bfs()){
		memcpy(_last+1,last+1,lim<<2);
		z+=dfs(S,1e9);
	}
	return z;
}

void solve(){
	read(),q=read();
	if (!q) return puts("0"),void();
	rep(i,1,q){
		c[i].x=read(),c[i].y=read();
		c[i].a=read(),c[i].b=read();
		a[++*a]=c[i].x,a[++*a]=c[i].a+1;
		b[++*b]=c[i].y,b[++*b]=c[i].b+1;
	}
	sort(a+1,a+*a+1); *a=unique(a+1,a+*a+1)-a-1;
	sort(b+1,b+*b+1); *b=unique(b+1,b+*b+1)-b-1;
	n=*a-1,m=*b-1;
	rep(i,1,q){
		C &o=c[i];
		o.x=lower_bound(a+1,a+*a+1,o.x)-a;
		o.a=lower_bound(a+1,a+*a+1,o.a+1)-a-1;
		o.y=lower_bound(b+1,b+*b+1,o.y)-b;
		o.b=lower_bound(b+1,b+*b+1,o.b+1)-b-1;
//		printf("test %d: %d %d %d %d\n",i,o.x,o.y,o.a,o.b);
		rep(u,o.x,o.a) rep(v,o.y,o.b) mrk[u][v]=1;
	}
	lim=n+m+2; S=n+m+1,T=lim;
	rep(i,1,n) rep(j,1,m) if (mrk[i][j])
		adde(i,j+n,1e9,0);
	rep(i,1,n) adde(S,i,a[i+1]-a[i],0);
	rep(i,1,m) adde(i+n,T,b[i+1]-b[i],0);
	printf("%d\n",dinic());
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}