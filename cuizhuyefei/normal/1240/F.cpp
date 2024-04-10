#include<cstdio>
#include<cstring>
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
inline void read(int &x) {
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
const int N = 16009;
int n,m,k,A[N],B[N],w[N],head[N],to[N],edgenum=1,nxt[N];
int ans[N],val[N],gg[N];
inline void addedge(int u, int v){
	to[++edgenum]=v;nxt[edgenum]=head[u];head[u]=edgenum;
}
namespace flow{
	const int M = 200000, inf = 0x3f3f3f3f;
	int S,T,edgenum=1,head[N],cur[N],to[M],nxt[M],cap[M],val[M];
	inline void addedge(int u, int v, int c, int w){
		to[++edgenum]=v;cap[edgenum]=c;val[edgenum]=w;
		nxt[edgenum]=head[u];head[u]=edgenum;
	}
	inline void add(int u, int v, int c, int w){
		assert(u<=T&&v<=T&&u&&v);w=-w;
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
	inline void solve(){
		S=2*n+1;T=S+1;
		rep(i,1,n){
			add(S,i,inf,0);add(n+i,T,inf,0);add(i,n+i,2,0);
		}
		static int bh[N];
		rep(i,1,m){
			if(A[i]>B[i])swap(A[i],B[i]);
			bh[i]=edgenum+1;
			add(n+A[i],B[i],1,w[A[i]]+w[B[i]]);
		}
		while(spfa()){
		//	cerr<<dis[S]<<endl;
			if(dis[S]>=0)break;
			memcpy(cur,head,4*(T+2));
			dfs(S,inf);
		}
		rep(i,1,m)printf("%d\n",cap[bh[i]]==0);
	}
}
int fa[N],faedge[N],dep[N];bool fd;
vector<Vi>dot[N];
void getans(int u, int fa){
	L(i,u)if(to[i]!=fa&&!gg[i>>1]){
		if(val[u]<0)val[u]++,val[to[i]]++,ans[i>>1]=1;
		else val[u]--,val[to[i]]--,ans[i>>1]=0;
		getans(to[i],u);
	}
}
void dfs(int u, int Fa, int Dep){
	fa[u]=Fa;dep[u]=Dep;
	L(i,u)if(to[i]!=Fa&&!gg[i>>1]){
		if(!dep[to[i]])faedge[to[i]]=i,dfs(to[i],u,Dep+1);
		else if(dep[u]>dep[to[i]]){
		if(dep[u]-dep[to[i]]&1){
			if(fd)return;fd=1;
			gg[i>>1]=1;
			for(int j=u,x=1;j!=to[i];j=fa[j],x^=1)
				gg[faedge[j]>>1]=1,ans[faedge[j]>>1]=x;
		}
		else{
			if(fd)return;fd=1;
			Vi s;
			for(int j=u,x=1;j!=to[i];j=fa[j],x^=1)s.pb(faedge[j]>>1);
			s.pb(i>>1);
			rep(i,0,SZ(s)-1)gg[s[i]]=1;
			dot[u].pb(s);
		}
		}
	}
}
namespace yzr{
	int cnt[166][1666],ans[N],fa[N],faedge[N],dep[N],a,b;bool find;
	bool isok(int u, int x){
		rep(i,1,k)if(cnt[u][i]+3<=cnt[u][x]+1)return 0;
		return 1;
	}
	void spj(int u){
		int mx=0,mn=1e9;
		rep(i,1,k)umax(mx,cnt[u][i]),umin(mn,cnt[u][i]);
		assert(mx-mn<=2);
	}
	void dfs(int u, int Fa, int Dep){
		fa[u]=Fa;dep[u]=Dep;
		L(i,u)if(to[i]!=Fa&&((dep[u]&1)&&ans[i>>1]==b||!(dep[u]&1)&&ans[i>>1]==a)){
			if(((dep[u]&1)&&cnt[to[i]][a]<cnt[to[i]][b]||!(dep[u]&1)&&cnt[to[i]][b]<cnt[to[i]][a])){
				if(find)return;find=1;
				static int s[N];int len=0;s[++len]=i>>1;
				for(int j=u;dep[j]>1;j=fa[j])s[++len]=faedge[j]>>1;
				int A=a,B=b;
				while(len){
					cnt[to[s[len]<<1]][A]++;cnt[to[s[len]<<1|1]][A]++;
					cnt[to[s[len]<<1]][B]--;cnt[to[s[len]<<1|1]][B]--;
					assert(ans[s[len]]==B);
					ans[s[len]]=A;swap(A,B);len--;
				}
				for(int j=u;dep[j]>=1;j=fa[j])spj(j);spj(to[i]);
			}
			else if(!dep[to[i]])faedge[to[i]]=i,dfs(to[i],u,Dep+1);
		}
	}
	void solve(){
		rep(j,1,m){
			bool ok=0;
			rep(i,1,k)if(isok(A[j],i)&&isok(B[j],i)){
				ok=1;ans[j]=i;cnt[A[j]][i]++;cnt[B[j]][i]++;break;
			}
		if(!ok){
			a=b=1;int u=A[j],v=B[j];
			rep(i,2,k)if(cnt[u][i]<cnt[u][a])a=i;
			rep(i,2,k)if(cnt[v][i]<cnt[v][b])b=i;
			assert(cnt[u][b]-cnt[u][a]==2&&cnt[v][a]-cnt[v][b]==2);
			find=0;rep(i,1,n)dep[i]=fa[i]=0;dfs(u,0,1);assert(find);
			assert(isok(u,b));assert(isok(v,b));ans[j]=b,cnt[u][b]++,cnt[v][b]++;
		//	if(cnt[u][b]-cnt[u][a]<2)ans[j]=b,cnt[A[j]][b]++,cnt[B[j]][b]++;
		//	else ans[j]=a,cnt[A[j]][a]++,cnt[B[j]][a]++;
		}
			addedge(A[j],B[j]),addedge(B[j],A[j]);
		}
		rep(i,1,m)printf("%d\n",ans[i]);
	//	memset(cnt,0,sizeof(cnt));
	//	rep(i,1,m)cnt[A[i]][ans[i]]++,cnt[B[i]][ans[i]]++;
	//	rep(i,1,n)spj(i);
		exit(0);
	}
}
int main() {
	read(n);read(m);read(k);
	rep(i,1,n)read(w[i]);
	rep(i,1,m)read(A[i]),read(B[i]);
	if(k==1){
		rep(i,1,m)puts("1");
		return 0;
	}
	if(k>2)yzr::solve();
	rep(i,1,m)addedge(A[i],B[i]),addedge(B[i],A[i]);
	while(1){
		rep(i,1,n)dep[i]=0;fd=0;
		rep(i,1,n)if(!dep[i])dfs(i,0,1);
		if(!fd){
			rep(i,1,n)if(dep[i]==1)getans(i,0);
			rep(i,1,n)assert(val[i]>=-2&&val[i]<=2);
			rep(i,1,n)rep(j,0,SZ(dot[i])-1){
				if(val[i]<=0){
					val[i]+=2;
					rep(k,0,SZ(dot[i][j])-1)ans[dot[i][j][k]]=k+1&1;
				}
				else{
					val[i]-=2;
					rep(k,0,SZ(dot[i][j])-1)ans[dot[i][j][k]]=k&1;
				}
			}
			break;
		}
	}
	rep(i,1,m)printf("%d\n",ans[i]+1);
//	memset(val,0,sizeof(val));
//	rep(i,1,m)val[A[i]]+=ans[i]?1:-1,val[B[i]]+=ans[i]?1:-1;
	rep(i,1,n)assert(val[i]>=-2&&val[i]<=2);
	return 0;
}