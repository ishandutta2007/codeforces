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
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1220, M = 240030, inf = 0x3f3f3f3f;
int n,m,S,T,head[N],cur[N],nxt[M],cap[M],to[M],edgenum=1; //1.WA--edgenum=1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void addedge(int u, int v, int c){
	to[++edgenum]=v;cap[edgenum]=c;nxt[edgenum]=head[u];head[u]=edgenum;
}
void add(int u, int v, int c){
	addedge(u,v,c);addedge(v,u,0);
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
int a[N],la,b[N],lb,A[N],B[N],C[N],D[N];
int main() {
	read(n);read(m);
	rep(i,1,m){
		read(A[i]);read(B[i]);read(C[i]);read(D[i]);
		a[++la]=A[i];a[++la]=C[i]+1;
		b[++lb]=B[i];b[++lb]=D[i]+1;
	}
	sort(a+1,a+la+1);la=unique(a+1,a+la+1)-a-1;
	sort(b+1,b+lb+1);lb=unique(b+1,b+lb+1)-b-1;
	//[1..la] [la+1..la+lb] [la+lb+1..la+lb+m]
	S=la+lb+m+1;T=S+1;
	rep(i,1,la-1)add(S,i,a[i+1]-a[i]);
	rep(i,1,lb-1)add(la+i,T,b[i+1]-b[i]);
	rep(i,1,m){
		int l=lower_bound(a+1,a+la+1,A[i])-a;
		int r=lower_bound(a+1,a+la+1,C[i]+1)-a;
		rep(j,l,r-1)add(j,la+lb+i,inf);
		l=lower_bound(b+1,b+lb+1,B[i])-b;
		r=lower_bound(b+1,b+lb+1,D[i]+1)-b;
		rep(j,l,r-1)add(la+lb+i,la+j,inf);
	}
	cout<<dinic();
	return 0;
}