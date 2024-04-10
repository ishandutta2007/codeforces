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

const int N=1e5+5;
int n,a[N],hd[N],tot,son[N],cnt[N],sz[N],nw,st[N],tp;
ll ans[N],sum;
struct edge{int t,nxt;}es[N<<1];

inline void add(int u,int v){
	es[++tot]=(edge){v,hd[u]};hd[u]=tot;
}

inline void get_son(int x,int fa){
	sz[x]=1;
	for(re i=hd[x];i;i=es[i].nxt)
		if(es[i].t!=fa){
			get_son(es[i].t,x);sz[x]+=sz[es[i].t];
			if(sz[es[i].t]>sz[son[x]]) son[x]=es[i].t;
		}
}

inline void clear(){
	while(tp) cnt[st[tp--]]=0;sum=nw=0;
}

inline void insert(int x){
	++cnt[st[++tp]=a[x]];
	if(cnt[a[x]]>nw) nw=cnt[sum=a[x]];
	else if(cnt[a[x]]==nw) sum+=a[x];
}

inline void merge(int x,int fa){
	insert(x);
	for(re i=hd[x];i;i=es[i].nxt)
		if(es[i].t!=fa) merge(es[i].t,x);
}

inline void dfs(int x,int fa){
	for(re i=hd[x];i;i=es[i].nxt)
		if(es[i].t!=fa&&es[i].t!=son[x]) dfs(es[i].t,x),clear();
	if(son[x]) dfs(son[x],x);insert(x);
	for(re i=hd[x];i;i=es[i].nxt)
		if(es[i].t!=fa&&es[i].t!=son[x]) merge(es[i].t,x);
	ans[x]=sum;
}

// ---------- DSU on Tree ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(n);
	for(re i=1;i<=n;++i) rd(a[i]);
	for(re i=1;i<n;++i){
		int u,v;rd(u);rd(v);
		add(u,v);add(v,u);
	}
	get_son(1,0);dfs(1,0);
	for(re i=1;i<=n;++i) wr(ans[i]),putchar(' ');puts("");
	return 0;
}

// ---------- Main ---------- //