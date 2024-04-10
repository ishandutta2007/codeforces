#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=10007;
const ll inf=1e18;
namespace flow{
	const int N=1e5+7, M=2e5+7;
	struct Edge{int to,nxt;ll f;}e[M<<1];
	int s_e,head[N],cur[N];
	inline void add_e(int x,int y,ll f){
		e[++s_e]={y,head[x],f},head[x]=s_e;
		e[++s_e]={x,head[y],0ll},head[y]=s_e;
	}
	int n,s,t,dep[N];
	inline void init(int _n,int _s,int _t){
		n=_n,s=_s,t=_t,s_e=1,fill(head+1,head+n+1,0);
	}
	bool bfs(){
		for(int i=1;i<=n;i++)dep[i]=0,cur[i]=head[i];
		queue<int>q;q.push(s),dep[s]=1;
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int i=head[x],y;i;i=e[i].nxt)
				if(!dep[y=e[i].to] && e[i].f)dep[y]=dep[x]+1,q.push(y);
		}
		return dep[t];
	}
	ll dfs(int x,ll minx){
		if(x==t)return minx;ll flow=0;
		for(int &i=cur[x],y;i;i=e[i].nxt)
			if(dep[y=e[i].to]==dep[x]+1 && e[i].f){
				ll fl=dfs(y,min(minx-flow,e[i].f));
				flow+=fl,e[i].f-=fl,e[i^1].f+=fl;
				if(flow==minx)return flow;
			}
		return dep[x]=0,flow;
	}
	inline ll dinic(){
		ll flow=0;
		while(bfs())flow+=dfs(s,inf);
		return flow;
	}
}
struct Node {int u, v;} b[N];
int n, m, fl[N], a[N], deg[N], f[N];
inline void GG() {puts("NO"), exit(0);}
int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	n=read(), m=read();
	for (int i=1; i<=n; i++) fl[i]=read();
	for (int i=1; i<=n; i++) a[i]=read();
	for (int i=1; i<=m; i++) b[i].u=read(), b[i].v=read(), deg[b[i].u]++, deg[b[i].v]++;
	for (int i=1; i<=n; i++) {
		if (!fl[i]) continue;
		if ((a[i]%2+2)%2!=deg[i]%2) GG();
		f[i]=(a[i]+deg[i])/2; // chu bian de liu liang
		if (f[i]<0 || f[i]>deg[i]) GG();
	}
	int s=n+m+1, t=n+m+2; flow::init(t, s, t);
	for (int i=1; i<=m; i++) {
		int u=b[i].u, v=b[i].v;
		flow::add_e(i, u+m, 1), flow::add_e(i, v+m, 1);
	}
	for (int i=1; i<=m; i++) flow::add_e(s, i, 1);
	for (int i=1; i<=n; i++) if (fl[i]) flow::add_e(i+m, t, f[i]);
	if (flow::dinic()!=accumulate(f+1, f+n+1, 0)) GG();
	puts("YES");
	for (int i=1; i<=m; i++) {
		if (flow::e[(i-1)*4+4].f) swap(b[i].u, b[i].v);
		printf("%d %d\n", b[i].u, b[i].v);
	}
	return 0;
}