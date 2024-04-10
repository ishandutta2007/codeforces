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
const int N = 555555;
int n,m,a[N],dep[N],fa[N];Vi e[N];bool vis[N],ok;
int dis[N],pre[N],col[N],dfn[N],num;
void print(Vi res){//baoliu
	if(SZ(res)==n)return;ok=1;puts("Yes");
	static bool vis[N];rep(i,1,n)vis[i]=0;
	rep(i,0,SZ(res)-1)vis[res[i]]=1;
	res.clear();rep(i,1,n)if(!vis[i])res.pb(i);
	printf("%d\n",SZ(res));rep(i,0,SZ(res)-1)printf("%d ",res[i]);puts("");
}
void dfs1(int u){
	vis[u]=1;rep(i,0,SZ(e[u])-1)if(!vis[e[u][i]])dfs1(e[u][i]);
}

bool fd;int A,B;
void dfs2(int u, int Fa, int Dep){
	fa[u]=Fa;dep[u]=Dep;dfn[u]=num;
	rep(i,0,SZ(e[u])-1)if(a[e[u][i]]==2&&e[u][i]!=Fa)
		if(!dep[e[u][i]])dfs2(e[u][i],u,Dep+1);
		else if(dep[e[u][i]]<dep[u]){
			fd=1;if(!A||dep[B]-dep[A]>dep[u]-dep[e[u][i]])A=e[u][i],B=u;
		}
}

void bfs(int s){
	rep(i,1,n)dis[i]=1e9,pre[i]=0;dis[s]=0;
	static int q[N];int f=0,r=1;q[f]=s;
	while(f!=r){
		int u=q[f++];
		rep(i,0,SZ(e[u])-1)if(dis[e[u][i]]>dis[u]+1)
			dis[e[u][i]]=dis[u]+1,q[r++]=e[u][i],pre[e[u][i]]=u;
	}
}
bool cmp(int x, int y){return dep[x]<dep[y];}
void solve(){
	rep(i,1,n)if(!a[i]){
		Vi res;res.pb(i);print(res);return;
	}
	rep(i,1,n)vis[i]=dep[i]=0;dfs1(1);int cnt=0;rep(i,1,n)cnt+=vis[i];
	if(cnt<n){
		Vi res;rep(i,1,n)if(vis[i])res.pb(i);print(res);return;
	}
	Vi dot;
	rep(i,1,n)if(a[i]==1)dot.pb(i);
	if(SZ(dot)==0){
		fd=0;A=B=0;dfs2(1,0,1);
		if(fd){Vi res;for(int u=B;;u=fa[u]){res.pb(u);if(u==A)break;}print(res);}
		return;
	}
	if(SZ(dot)>=2){
		bfs(dot[0]);
		int t=0;rep(i,1,n)if(a[i]==1&&i!=dot[0]&&(!t||dis[i]<dis[t]))t=i;
		Vi res;for(int u=t;;u=pre[u]){res.pb(u);if(u==dot[0])break;}print(res);
		return;
	}
	int rt=dot[0];rep(i,1,n)dep[i]=dfn[i]=0;num=0;
//	cerr<<rt<<endl;
	rep(i,0,SZ(e[rt])-1)if(!dep[e[rt][i]]){
		fd=0;A=B=0;
		num++,dfs2(e[rt][i],rt,1);
	//	cerr<<num<<' '<<fd<<endl;
		if(fd){
			Vi res;for(int u=B;;u=fa[u]){res.pb(u);if(u==A)break;}print(res);
			return;
		}
	}
	cnt=num;assert(cnt*2%3==1);
//	cerr<<cnt<<endl;
	if(cnt>2){
		Vi res;rep(i,1,n)if(dfn[i]<=2)res.pb(i);print(res);return;
	}
	Vi b[3];rep(u,1,n){rep(i,0,SZ(e[u])-1)if(e[u][i]==rt)b[dfn[u]].pb(u);}
	rep(i,1,2)if(SZ(b[i])>2){
		sort(b[i].begin(),b[i].end(),cmp);
		Vi res;rep(j,1,n)if(dfn[j]!=i)res.pb(j);
		for(int u=b[i][1];u;u=fa[u]){res.pb(u);if(u==b[i][0])break;}print(res);
		return;
	}
}
int main() {
	int T;read(T);while(T--){
		read(n);read(m);rep(i,0,n)e[i].clear();ok=0;
		while(m--){
			int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);
		}
		rep(i,1,n)a[i]=SZ(e[i])%3;
		solve();if(!ok)puts("No");
	}
	return 0;
}