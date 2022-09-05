#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 16009, M = 200000, inf = 0x3f3f3f3f;
ll ans[N];int len,n,m;
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
	inline void solve(){//int
		while(spfa()){
			memcpy(cur,head,4*(T+2));
			int qaq=dfs(S,1);
			ans[len+1]=ans[len]+dis[S];len++;
		}
	}
int main() {
	read(n);read(m);
	S=1;T=n;
	while(m--){
		int u,v,w;read(u);read(v);read(w);
		add(u,v,1,w);
	}
	solve();
	int q;read(q);while(q--){
		int c;read(c);double r=1e30;
		rep(i,1,len)umin(r,1.0*(ans[i]+c)/i);
		printf("%.11lf\n",r);
	}
	return 0;
}