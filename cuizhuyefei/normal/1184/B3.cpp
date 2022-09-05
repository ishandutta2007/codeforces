#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
#define int long long
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
const int N = 233220, M = 2030030;
const ll inf = 1e15;
int S,T,head[N],cur[N],nxt[M],cap[M],to[M],edgenum=1; //1.WA--edgenum=1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void addedge(int u, int v, int c){
	to[++edgenum]=v;cap[edgenum]=c;nxt[edgenum]=head[u];head[u]=edgenum;
}
void add(int u, int v, int c){
	addedge(u,v,c);addedge(v,u,0);
}
int dis[N],q[N];
inline bool bfs() {
	const int inf=0x3f3f3f3f;
	rep(i,0,T)dis[i]=inf;
//	memset(dis,inf,sizeof(int)*(T+2));//2.memsetsizeof()
	int f=0,r=1; q[f]=T; dis[T]=0;
	while (f!=r) {
		int u=q[f++];
		L(i,u) if (cap[i^1]&&dis[to[i]]==inf){
			q[r++]=to[i];dis[to[i]]=dis[u]+1;if(to[i]==S)return 1;//3.
		}
	}
	return dis[S]<inf;
}
inline int dfs(int u, int flow) {
	if (u==T||!flow)return flow;int res=0;
	for(register int &i=cur[u];i;i=nxt[i])if(cap[i]&&dis[u]==dis[to[i]]+1){//4. 
		int tmp=dfs(to[i],min(flow,cap[i]));
		res+=tmp;flow-=tmp;cap[i]-=tmp;cap[i^1]+=tmp;if(!flow)break;
	}
	return res;
}
inline int dinic() {
	int res=0;
	while (bfs()) {
		rep(i,0,T)cur[i]=head[i];
	//	memcpy(cur,head,sizeof(int)*(T+2));
		res+=dfs(S,inf);
	}
	return res;
}
int n,m,ans[233333];
namespace yzr{
	const int N = 233333;
	int dis[111][111],A[N],B[N],C[N],D[N],E[N],F[N];
	Pii s[N];int len,val[N];
	void init(){
		int dot;read(n);read(m);dot=n;
		rep(i,0,n)rep(j,0,n)dis[i][j]=0x3f3f3f3f;
		rep(i,1,n)val[i]=-inf;
		while(m--){
			int u,v;read(u);read(v);
			umin(dis[u][v],1LL);umin(dis[v][u],1LL);
		}
		rep(i,1,n)dis[i][i]=0;
		rep(k,1,n)rep(i,1,n)rep(j,1,n)
			umin(dis[i][j],dis[i][k]+dis[k][j]);
	//	rep(i,1,n){rep(j,1,n)printf("%d ",dis[i][j]);puts("");}
		read(n);int n2;read(n2);read(m);
		rep(i,1,n){
			read(A[i]);read(B[i]);read(C[i]);read(D[i]);ans[i]=-inf;
			s[++len]=Pii(B[i],i);
		}
		rep(i,1,n2){
			int x,d,g;read(x);read(d);read(g);E[i]=x;F[i]=g;
			s[++len]=Pii(d,-i);
		}
		sort(s+1,s+len+1);
		rep(i,1,len)
			if(s[i].se<0){
				umax(val[E[-s[i].se]],F[-s[i].se]);
			}
			else{
				rep(j,1,dot)if(dis[j][A[s[i].se]]<=C[s[i].se])
					umax(ans[s[i].se],val[j]-D[s[i].se]);
			}
	}
}
signed main() {
	yzr::init();
	S=n+1;T=S+1;
	while(m--){
		int u,v;read(u);read(v);add(u,v,inf);
	}
//	rep(i,1,n)cerr<<ans[i]<<' ';cerr<<endl;
	ll res=0;
	rep(i,1,n)
		if(ans[i]>0){res+=ans[i];add(S,i,ans[i]);}
		else{add(i,T,-ans[i]);}
	cout<<res-dinic();
	return 0;
}