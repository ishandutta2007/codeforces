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
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 20220, M = 240030, inf = 0x3f3f3f3f;
int n,m,k,A[N],B[N],C[N],ans[1<<13|3],S,T,head[N],cur[N],nxt[M],cap[M],to[M],edgenum=1;
void addedge(int u, int v, int c){
	to[++edgenum]=v;cap[edgenum]=c;nxt[edgenum]=head[u];head[u]=edgenum;
}
void add(int u, int v, int c){
	addedge(u,v,c);addedge(v,u,0);
}
int dis[N],q[N];
pair<int*,int>rec[10000000];int top;
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
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
int dfs(int u, int flow) {
	if (u==T||!flow)return flow;int res=0;
	for(register int &i=cur[u];i;i=nxt[i])if(cap[i]&&dis[u]==dis[to[i]]+1){//4. 
		int tmp=dfs(to[i],min(flow,cap[i]));
		res+=tmp;flow-=tmp;
		rec[++top]=mp(cap+i,cap[i]);
		rec[++top]=mp(cap+(i^1),cap[i^1]);
		cap[i]-=tmp;cap[i^1]+=tmp;if(!flow)break;
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
static int w[N];
void dfs2(int dep, int S, int cur){
	ans[S]=cur;
	rep(i,dep,k){
		int lst=top;
		add(A[i],B[i],25);
		int tmp=cur+dinic();
		dfs2(i+1,S|1<<i-1,tmp);
		while(top>lst){
			*rec[top].fi=rec[top].se;
			top--;
		}
		edgenum-=2;head[A[i]]=nxt[head[A[i]]];head[B[i]]=nxt[head[B[i]]];
	}
}
void dfs3(int dep, int S, int &res, int cur){
	if(dep>k){
		umin(res,cur+ans[(1<<k)-1-S]);
		return;
	}
	dfs3(dep+1,S,res,cur);
	dfs3(dep+1,S|1<<dep-1,res,cur+w[dep]);
}
int main() {
	read(n);read(m);read(k);int q;read(q);S=1;T=n;
	rep(i,1,m){
		read(A[i]),read(B[i]),read(C[i]);
		if(i>k)add(A[i],B[i],C[i]);
	}
	int tmp=dinic();top=0;
	dfs2(1,0,tmp);
	while(q--){
		rep(i,1,k)read(w[i]);
		int res=2e9;
		/*rep(s,0,(1<<k)-1){
			int cur=ans[(1<<k)-1-s];
			rep(i,1,k)if(s>>i-1&1)cur+=w[i];
			umin(res,cur);
		}*/
		dfs3(1,0,res,0);
		printf("%d\n",res);
	}
	return 0;
}