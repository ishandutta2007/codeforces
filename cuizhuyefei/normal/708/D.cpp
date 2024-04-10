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
int n,m,res,indeg[N];
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
	inline int solve(){//int
		int res(0);
		while(spfa()){
			memcpy(cur,head,4*(T+2));
			int qaq=dfs(S,inf);res+=qaq*dis[S];
		}
		return res;
	}
int main() {
	read(n);read(m);S=n+1;T=S+1;
	while(m--){
		int u,v,f,c;read(u);read(v);read(f);read(c);
		if(c<f){
			add(u,v,f-c,1);add(u,v,inf,2);add(v,u,c,1);
		}
		else{
			res+=c-f;add(u,v,inf,2);add(v,u,c-f,0);add(v,u,f,1);
		}
		indeg[v]+=c;indeg[u]-=c;
	}
	ll s=0,t=0;
	rep(i,1,n)if(indeg[i]>0)add(S,i,indeg[i],0),s+=indeg[i];
	else add(i,T,-indeg[i],0),t+=-indeg[i];
	add(n,1,inf,0);
	cout<<res+solve();
	return 0;
}