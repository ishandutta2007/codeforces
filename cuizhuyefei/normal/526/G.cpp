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
const int N = 166666,inf=0x3f3f3f3f;
int n,q,dis[N];vector<Pii>e[N];
int bfs(int s){
	memset(dis,inf,sizeof(dis));
	static int q[N];int f=0,r=1;q[f]=s;dis[s]=0;
	int res=s;
	while(f!=r){
		int u=q[f++];if(dis[u]>dis[res])res=u;
		rep(i,0,SZ(e[u])-1)if(dis[e[u][i].fi]>dis[u]+e[u][i].se){
			dis[e[u][i].fi]=dis[u]+e[u][i].se;q[r++]=e[u][i].fi;
		}
	}
	return res;
}


//bool cmp(Pii a, Pii b){return dep[a.fi]-dep[a.se]>dep[b.fi]-dep[b.se];}
struct Tree{
	int dep[N],fa[N],mx[N],son[N],top[N];bool istop[N];
	Pii s[N];int len,qz[N],jmp[N][17],col[N],val[N];
//	bool cmp(Pii a, Pii b){return dep[a.fi]-dep[a.se]>dep[b.fi]-dep[b.se];}
//	bool operator<(Pii a, Pii b)const{return dep[a.fi]-dep[a.se]>dep[b.fi]-dep[b.se];}
	void dfs1(int u, int Fa, int Dep){
		fa[u]=Fa;dep[u]=mx[u]=Dep;
		rep(i,0,SZ(e[u])-1)if(e[u][i].fi!=Fa){
			dfs1(e[u][i].fi,u,Dep+e[u][i].se);
			if(mx[e[u][i].fi]>mx[u])mx[u]=mx[e[u][i].fi],son[u]=e[u][i].fi;
		}
	}
	void ini(int rt){
		dfs1(rt,0,0);rep(i,1,n)istop[i]=1;
		rep(i,1,n)istop[son[i]]=0;
		rep(i,1,n)if(istop[i]){
			int u=i;while(son[u])u=son[u];s[++len]=Pii(dep[u]-dep[fa[i]],u);top[u]=i;
		//	cerr<<u<<' '<<i<<endl;
		}
		sort(s+1,s+len+1);reverse(s+1,s+len+1);
		rep(i,1,len){qz[i]=qz[i-1]+s[i].fi;int u=s[i].se;s[i]=Pii(u,top[u]);}
		rep(i,1,n)jmp[i][0]=fa[i];
		rep(j,1,16)rep(i,1,n)jmp[i][j]=jmp[jmp[i][j-1]][j-1];
		rep(i,1,n)col[i]=len+1;
		rep(i,1,len)for(int u=s[i].fi;;u=fa[u]){col[u]=i;if(u==s[i].se)break;}
	//	rep(i,1,n)printf("%d ",dep[i]);puts("");
	//	rep(i,1,n)printf("%d ",col[i]);puts("");
	}
	int solve(int x, int y){
		y=min(2*y-1,len);if(y>=len)return qz[len];
		if(col[x]<=y)return qz[y];
		int u=x;per(i,16,0)if(col[jmp[u][i]]>y)u=jmp[u][i];u=fa[u];
		int res=mx[x]-dep[u]-(qz[y]-qz[y-1]);
	//	cerr<<mx[x]-dep[u]<<' '<<(dep[s[y].fi]-dep[s[y].se])<<endl;
		if(col[u]<=y)umax(res,mx[x]-(dep[s[col[u]].fi]));
		return qz[y]+res;
		//-dep[s[col[u]].se]
	}
}a,b;
int main() {
	read(n);read(q);
	rep(i,1,n-1){
		int u,v,w;read(u);read(v);read(w);
		e[u].pb(Pii(v,w));e[v].pb(Pii(u,w));
	}
	int s=bfs(1),t=bfs(s);a.ini(s);b.ini(t);
//	cerr<<"qwq "<<s<<' '<<t<<endl;
	int ans=0;
	while(q--){
		int x,y;read(x);read(y);
		x=(x+ans-1)%n+1;y=(y+ans-1)%n+1;
	//	cerr<<x<<' '<<y<<endl;//' '<<a.solve(x,y);return 0;//<<' '<<b.solve(x,y)<<endl;
		printf("%d\n",ans=max(a.solve(x,y),b.solve(x,y)));
	}
	return 0;
}