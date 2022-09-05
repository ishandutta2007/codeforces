#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
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
const int N = 233333, M = N*8, inf = 0x3f3f3f3f;
int n,m,S,T,head[N],cur[N],nxt[M],cap[M],to[M],edgenum=1; //1.WA--edgenum=1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void addedge(int u, int v, int c){
	to[++edgenum]=v;cap[edgenum]=c;nxt[edgenum]=head[u];head[u]=edgenum;
}
void add(int u, int v, int c){
	if(c){addedge(u,v,c);addedge(v,u,0);}
}
void addedge(int u, int v, int l, int r){
	if(l>r){puts("-1");exit(0);}
	add(u,v,r-l);add(S,v,l);add(u,T,l);
}
int dis[N],q[N];
inline bool bfs() {
	memset(dis,inf,4*(T+2));//2.memsetsizeof()
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
		memcpy(cur,head,4*(T+2)); res+=dfs(S,inf);
	}
	return res;
}
int A[N],B[N],a[N],b[N];map<int,int>m1,m2;int c1[N],c2[N];int t1,t2;
void ins(map<int,int>&Map, int *cnt, int &t, int x){
	if(!Map.count(x))Map[x]=++t;cnt[Map[x]]++;
}
int main() {
	read(n);read(m);int rr,bb;read(rr);read(bb);
	rep(i,1,n)read(A[i]),read(B[i]),ins(m1,c1,t1,A[i]),ins(m2,c2,t2,B[i]);
	rep(i,1,t1)a[i]=c1[i];rep(i,1,t2)b[i]=c2[i];
	while(m--){
		int op,l,d;read(op);read(l);read(d);
		if(op==1)umin(a[m1[l]],d);else umin(b[m2[l]],d);
	}
	int s=t1+t2+1,t=s+1;S=t+1;T=S+1;
	rep(i,1,t1){
	//	cerr<<(c1[i]-a[i]+1)/2<<' '<<(a[i]+c1[i])/2<<endl;
		addedge(s,i,(c1[i]-a[i]+1)/2,(a[i]+c1[i])/2);
	}
	rep(i,1,t2){
	//	cerr<<(c2[i]-b[i]+1)/2<<' '<<(b[i]+c2[i])/2<<endl;
		addedge(t1+i,t,(c2[i]-b[i]+1)/2,(b[i]+c2[i])/2);
	}
	static int e[N];
	rep(i,1,n){
	//	cerr<<m1[A[i]]<<' '<<m2[B[i]]<<endl;
		e[i]=edgenum+1,addedge(m1[A[i]],t1+m2[B[i]],0,1);
	}
	addedge(t,s,0,inf);
	dinic();
	L(i,S)if(cap[i]){puts("-1");return 0;}
	L(i,T)if(cap[i^1]){puts("-1");return 0;}
	S=s;T=t;dinic();
	ll res=0;static char ans[N];
	rep(i,1,n)if(!cap[e[i]])res+=min(rr,bb),ans[i]=rr<bb?'r':'b';
	else res+=max(rr,bb),ans[i]=rr<bb?'b':'r';
	printf("%lld\n",res);rep(i,1,n)printf("%c",ans[i]);
	return 0;
}