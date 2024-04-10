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
const int N = 303000,inf=0x3f3f3f3f;
int n,m,a,b,c;Vi e[N];set<int>Set[N];bool mrk[N];
Vi res;
void bfs(){
	static int q[N],dis[N],pre[N];
	memset(dis,inf,sizeof(dis));int f=0,r=1;dis[1]=0;q[f]=1;
	while(f!=r){
		int u=q[f++];
		rep(i,0,SZ(e[u])-1)if(dis[e[u][i]]>dis[u]+1){
			dis[e[u][i]]=dis[u]+1;q[r++]=e[u][i];pre[e[u][i]]=u;
		}
	}
	if(dis[n]<inf){
		static int sta[N];int top=0;
		for(int u=n;;u=pre[u]){
			sta[++top]=u;if(u==1)break;
		}
		per(i,top,1)res.pb(sta[i]);
	//	printf("%d\n",top-1);per(i,top,1)printf("%d ",sta[i]);
	//	exit(0);
	}
}
bool dfn[N];int s[N],len,rt,vis[N],num;
void getdot(int u){
	dfn[u]=1;s[++len]=u;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=1&&!dfn[e[u][i]])getdot(e[u][i]);
}
void dfs(int u, int fa){
	if(!a&&u!=rt&&!Set[u].count(rt)){
		a=rt;b=fa;c=u;
		return;
	}
	vis[u]=num;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa&&e[u][i]!=1&&vis[e[u][i]]!=num)
		dfs(e[u][i],u);
}
int main() {
	read(n);read(m);
	rep(i,1,m){
		int u,v;read(u);read(v);
		e[u].pb(v);e[v].pb(u);
		Set[u].insert(v);Set[v].insert(u);
	}
	bfs();
	rep(i,0,SZ(e[1])-1)mrk[e[1][i]]=1;
	rep(u,1,n)rep(i,0,SZ(e[u])-1)if(mrk[u]==1&&mrk[e[u][i]]==0&&u!=1&&e[u][i]!=1){
		int v=e[u][i];
		if(!SZ(res)||5<SZ(res)){
			res.resize(5);res[0]=1;res[1]=u;res[2]=v;res[3]=1;res[4]=n;
		}
	//	printf("4\n");
	//	printf("%d %d %d %d %d",1,u,v,1,n);
	//	return 0;
	}
	rep(i,1,n)if(!dfn[i]&&mrk[i]){
		len=0;getdot(i);
		rep(j,1,len)if(!a)num++,rt=s[j],dfs(s[j],0);
	}
	if(a){
		if(!SZ(res)||6<SZ(res)){
			res.clear();
			res.pb(1);
			res.pb(a);
			res.pb(b);
			res.pb(c);
			res.pb(a);
			res.pb(n);
		}
	//	printf("5\n");
	//	printf("%d %d %d %d %d %d",1,a,b,c,a,n);
	}
	if(SZ(res)){
		printf("%d\n",SZ(res)-1);
		rep(i,0,SZ(res)-1)printf("%d ",res[i]);
	}
	else puts("-1");
	return 0;
}