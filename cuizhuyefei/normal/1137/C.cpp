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
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 200004;
int n,m,d,a[102000][55],dp[102000][55],vis[102000][55];
inline int Nxt(int x){return x+1<d?x+1:0;}
int head[N],to[N],nxt[N],edgenum,cur;
inline void add(int u, int v) {
	to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum;
}
int dfn[N],low[N],sta[N],top,num,cnt,bel[N];Vi dot[N];
bool insta[N];
inline void tarjan(int u) {
	dfn[u]=low[u]=++num; sta[++top]=u; insta[u]=1;
	L(i,u) if (!dfn[to[i]]) {
		tarjan(to[i]); low[u]=min(low[u],low[to[i]]);
	}
	else if (insta[to[i]]) low[u]=min(low[u],dfn[to[i]]);
	if (dfn[u]==low[u]) {
		cnt++;
		while (1) {
			int x=sta[top--]; insta[x]=0; 
			dot[cnt].pb(x);bel[x]=cnt; if (x==u) break;
		}
	}
}
Pii q[102000*55];
void bfs(int s){
	int f=0,r=1;q[f]=Pii(s,0);vis[s][0]=1;
	while(f!=r){
		Pii t=q[f++];int u=t.fi;//printf("vis %d %d\n",t.fi,t.se);
		L(i,u)if(bel[to[i]]==cur&&!vis[to[i]][Nxt(t.se)]){
			vis[to[i]][Nxt(t.se)]=1;q[r++]=Pii(to[i],Nxt(t.se));
		}
	}
}
struct QAQ{
	int val[55];
	void init(int ok[55],int dp[55]){
		rep(i,0,d-1)val[i]=ok[i]?dp[i]:0;
	}
	inline int query(ll s){//querymax
		int res=0;rep(i,0,d-1)if(s>>i&1)umax(res,val[i]);
		return res;
	}
}yzr[102000],qaq[102000];
Vi rev[N];int dis[N];
void dfs(int s){
	static int q[N];int f=0,r=1;q[f]=s;dis[s]=0;
	static int vis[N];
	while(f!=r){
		int u=q[f++];
		rep(i,0,SZ(rev[u])-1)if(bel[rev[u][i]]==cur&&!vis[rev[u][i]]){
			vis[rev[u][i]]=1;dis[rev[u][i]]=Nxt(dis[u]);
			q[r++]=rev[u][i];
		}
	}
}
int main() {
	read(n); read(m);read(d);
	rep(i,1,m) {
		int x,y; read(x); read(y);add(x,y);rev[y].pb(x);
	}
	rep(i,1,n)if(!dfn[i])tarjan(i);
	rep(i,1,n){
		char t[5555];scanf("%s",t);
		rep(j,0,d-1)a[i][j]=t[j]=='1';
	}
	ll all=(1LL<<d)-1;
	for(cur=1;cur<=cnt;cur++){
		int x=dot[cur][0];
	//	printf("sz=%d %d\n",SZ(dot[cur]),x);
		bfs(x);
		rep(t,0,SZ(dot[cur])-1){
			int u=dot[cur][t];//int v[55];
		//	rep(i,0,d-1)v[i]=vis[u][i];
			qaq[u].init(a[u],a[u]);
		}
		rep(t,0,SZ(dot[cur])-1){
			int u=dot[cur][t];
			ll S=0;per(j,d-2,0)S=2*S+vis[u][j];S=2*S+vis[u][d-1];
			L(i,u)if(bel[to[i]]!=cur){//dp[to[i]]-->dp[x]
				rep(j,0,d-1){
					umax(dp[x][j],yzr[to[i]].query(((S<<j)&all)+(S>>(d-j))));
				//	printf("<%d %d> %d %d %lld\n",x,to[i],j,yzr[to[i]].query(((S<<j)&all)+(S>>(d-j))),((S<<j)&all)+(S>>(d-j)));
				}
			}
		}
		rep(t,0,SZ(dot[cur])-1){
			int u=dot[cur][t];
			ll S=0;rep(j,0,d-1)if(vis[u][j])S|=1LL<<j;
		//	rep(j,0,d-1)printf("%d",a[u][j]);puts("");
		//	rep(j,0,d-1)printf("%d",vis[u][j]);puts("");
		//	printf("<%lld>\n",S);
			rep(j,0,d-1){
				dp[x][j]+=(qaq[u].query(((S<<j)&all)+(S>>(d-j))));
			//	printf("query %d %d:%d\n",x,j,(qaq[u].query(((S<<j)&all)+(S>>(d-j)))));
			}
			
		}
		
		
		dfs(x);
		
		
		rep(t,0,SZ(dot[cur])-1){
			int u=dot[cur][t];
			if(u!=x){
				rep(i,0,d-1)dp[u][i]=dp[x][(i+dis[u])%d];
			}
			int All[55];rep(i,0,d-1)All[i]=1;
			yzr[u].init(All,dp[u]);
		}
	}
//	rep(i,1,n){rep(j,0,d-1)printf("%d ",dp[i][j]);puts("");}
	printf("%d",dp[1][0]);
	return 0;
}