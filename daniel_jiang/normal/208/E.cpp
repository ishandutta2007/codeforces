// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define dec(x) fixed<<setprecision(x)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T> inline void rd(T &x){
	int fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
template<class T> inline void wr(T x){
	if(x<0) x=-x,putchar('-');
	if(x<10){putchar(x+'0');return ;}
	int tmp[30]={0},cnt=0;
	while(x) tmp[cnt++]=x%10,x/=10;
	for(re i=cnt-1;i>=0;--i) putchar(tmp[i]+'0');
}

// ---------- IO ---------- //

const int N=1e5+5,M=6e6+5,logN=20;
int n,m,hd[N],tot,cnt,ans[N],rt[N],cntroot,root[N],fa[N],deep[N],rb,up[N][logN];
struct edge{int nxt,t;}es[N<<1];
inline void add(int x,int y){es[++tot]=(edge){hd[x],y};hd[x]=tot;}
struct question{int x,y;}q[N];
vector<int> Q[N];

struct SGT{
	#define mid ((l+r)>>1)
	#define xl Xl[x]
	#define xr Xr[x]
	int Xl[M],Xr[M],sum[M];
	inline void pushup(int x){
		sum[x]=sum[xl]+sum[xr];
	}
	inline int modify(int x,int l,int r,int k,int v){
		if(!x) x=++cnt;
		if(l==r){sum[x]+=v;return x;}
		if(k<=mid) xl=modify(xl,l,mid,k,v);
		else xr=modify(xr,mid+1,r,k,v);
		pushup(x);return x;
	}
	inline int merge(int x,int a,int l,int r){
		if(!x||!a) return (x|a);
		if(l==r){sum[x]+=sum[a];return x;}
		xl=merge(xl,Xl[a],l,mid),xr=merge(xr,Xr[a],mid+1,r);
		pushup(x);return x;
	}
	inline int query(int x,int l,int r,int k){
		if(!x) return 0;
		if(l==r) return sum[x];
		if(k<=mid) return query(xl,l,mid,k);
		else return query(xr,mid+1,r,k);
	}
}S;

inline void pre(int x){
	rb=max(rb,deep[x]=deep[fa[x]]+1);
	for(re i=1;i<logN;++i) up[x][i]=up[up[x][i-1]][i-1];
	for(re i=hd[x];i;i=es[i].nxt)
		if(es[i].t!=fa[x]) pre(es[i].t);
}

inline void dfs(int x){
	for(re i=hd[x];i;i=es[i].nxt)
		if(es[i].t!=fa[x]) dfs(es[i].t),rt[x]=S.merge(rt[x],rt[es[i].t],1,n);
	for(re i=0;i<Q[x].size();++i)
		ans[Q[x][i]]=S.query(rt[x],1,n,q[Q[x][i]].y)-1;
}

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(n);
	for(re i=1;i<=n;++i){
		rd(fa[i]);add(i,fa[i]),add(fa[i],i);up[i][0]=fa[i];
		if(fa[i]==0) root[++cntroot]=i;
	}
	for(re i=1;i<=cntroot;++i) pre(root[i]);
	rd(m);
	for(re i=1;i<=m;++i){
		int u,v;rd(u);rd(v);int awa=u;
		for(re j=logN-1;j>=0;--j){
			if(v<(1<<j)) continue;
			u=up[u][j];v^=(1<<j);
		}
		q[i]=(question){u,deep[awa]};Q[u].pb(i);
	}
	for(re i=1;i<=n;++i) rt[i]=S.modify(rt[i],1,n,deep[i],1);
	for(re i=1;i<=cntroot;++i) if(!fa[root[i]]) dfs(root[i]);
	for(re i=1;i<=m;++i) wr(ans[i]),putchar(' ');puts("");
	return 0;
}

// ---------- Main ---------- //