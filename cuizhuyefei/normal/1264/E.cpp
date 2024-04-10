#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}

const int N = 16009, M = 200000, inf = 0x3f3f3f3f;
	int S,T,edgenum=1,head[N],cur[N],to[M],nxt[M],cap[M],val[M];
	inline void addedge(int u, int v, int c, int w){
		to[++edgenum]=v;cap[edgenum]=c;val[edgenum]=w;
		nxt[edgenum]=head[u];head[u]=edgenum;
	}
	inline void add(int u, int v, int c, int w){
		assert(u<=T&&v<=T&&u&&v);
		addedge(u,v,c,w);addedge(v,u,0,-w);
	}
	int rec[N],dis[N],q[N];bool vis[N];
	inline void inc(int &x){x++;x=x==N?0:x;}
	inline bool spfa(){
		int f=0,r=1;memset(dis,inf,4*(T+2));dis[T]=0;q[f]=T;
		while(f!=r){
			int u=q[f];inc(f);vis[u]=0;
			L(i,u)if(cap[i^1]&&dis[to[i]]>dis[u]+val[i^1]){
				dis[to[i]]=dis[u]+val[i^1];rec[to[i]]=i;
				if(!vis[to[i]]){
					q[r]=to[i],inc(r);vis[to[i]]=1;//SLF 
				}
			}
		}
		return dis[S]<inf;
	}
	bool incir[N];
	inline int dfs(int u, int flow){
		if(u==T||!flow)return flow;assert(!incir[u]);int tot=0;incir[u]=1;
		for(register int &i=cur[u];i;i=nxt[i])if(cap[i]&&dis[u]==dis[to[i]]+val[i]&&!incir[to[i]]){
			int tmp=dfs(to[i],min(flow,cap[i]));
			cap[i]-=tmp;cap[i^1]+=tmp;tot+=tmp;flow-=tmp;if(!flow)break;
		}
		incir[u]=0;return tot;
	}
	inline Pii solve(){//int
		Pii res(0,0);
		while(spfa()){
			memcpy(cur,head,4*(T+2));
			int qaq=dfs(S,inf);res.fi+=qaq;res.se+=qaq*dis[S];
		}
		return res;
	}
int n,m,e[105][105],a[N],f[N],pos[105][105];
int C2(int x){return x*(x-1)/2;}
int main() {
	read(n);read(m);
	memset(e,-1,sizeof(e));
	rep(i,1,n)e[i][i]=0;
	rep(i,1,m){
		int u,v;read(u);read(v);e[u][v]=1;e[v][u]=0;f[u]++;
	}
	S=n+n*(n-1)/2+1;T=S+1;int bh=n;
	rep(i,1,n)rep(j,i+1,n)if(e[i][j]==-1){
		a[i]++;a[j]++;++bh;
		pos[i][j]=edgenum+1;
		add(i,bh,1,0);add(j,bh,1,0);add(bh,T,1,0);
	}
	rep(i,1,n)rep(j,1,a[i])add(S,i,1,C2(f[i]+j)-C2(f[i]+j-1));
	solve();
	rep(i,1,n)rep(j,i+1,n)if(e[i][j]==-1)
		if(!cap[pos[i][j]])e[i][j]=1,e[j][i]=0;else e[j][i]=1,e[i][j]=0;
	rep(i,1,n){rep(j,1,n)printf("%d",e[i][j]);puts("");}
	return 0;
}