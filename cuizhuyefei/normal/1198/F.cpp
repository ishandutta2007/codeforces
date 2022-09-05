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
const int N = 122222,inf=0x3f3f3f3f;
int n,a[N],p;bool vis[N];
Vi getfac(int n){
	Vi res;
	for(int i=2;i*i<=n;i++)if(n%i==0){
		while(n%i==0)n/=i;res.pb(i);
	}
	if(n>1)res.pb(n);
	return res;
}
int dis[1<<9|3][1<<9|3];Pii pre[1<<9|3][1<<9|3];
vector<Pii>q[19*19];
void solve(int p){
	Vi f=getfac(a[1]),g=getfac(a[p]);
	memset(dis,inf,sizeof(dis));dis[0][0]=0;
	static int id[N],m1[N],m2[N];int sz=0;
	rep(i,0,SZ(f)-1){
		int c=0;
		rep(j,1,n)if(j!=1&&j!=p&&a[j]%f[i]){
			id[++sz]=j;c++;
			if(c>=SZ(f)+SZ(g))break;
		}
	}
	rep(i,0,SZ(g)-1){
		int c=0;
		rep(j,1,n)if(j!=1&&j!=p&&a[j]%g[i]){
			id[++sz]=j;c++;
			if(c>=SZ(f)+SZ(g))break;
		}
	}
	sort(id+1,id+sz+1);sz=unique(id+1,id+sz+1)-id-1;
	rep(i,1,sz){
		m1[i]=m2[i]=0;
		rep(j,0,SZ(f)-1)m1[i]|=(a[id[i]]%f[j]!=0)<<j;
		rep(j,0,SZ(g)-1)m2[i]|=(a[id[i]]%g[j]!=0)<<j;
	}
	rep(i,0,sz)q[i].clear();q[0].pb(Pii(0,0));
//	cerr<<p<<endl;
//	cerr<<"f ";rep(i,0,SZ(f)-1)cerr<<f[i]<<' ';cerr<<endl;
//	cerr<<"g ";rep(i,0,SZ(g)-1)cerr<<g[i]<<' ';cerr<<endl;
//	rep(i,1,sz)cerr<<m1[i]<<' '<<m2[i]<<endl;
	rep(d,0,sz)rep(i,0,SZ(q[d])-1){
		int u=q[d][i].fi,v=q[d][i].se;
		rep(i,d+1,sz)if((m1[i]|u)!=u||(m2[i]|v)!=v){
			if(i<dis[m1[i]|u][v])dis[m1[i]|u][v]=i,pre[m1[i]|u][v]=Pii(u,v),q[i].pb(Pii(m1[i]|u,v));
			if(i<dis[u][m2[i]|v])dis[u][m2[i]|v]=i,pre[u][m2[i]|v]=Pii(u,v),q[i].pb(Pii(u,m2[i]|v));
			break;
		}
	}
	if(dis[(1<<SZ(f))-1][(1<<SZ(g))-1]==inf)return;
	puts("YES");static int ans[N];
	rep(i,1,n)ans[i]=1;ans[p]=2;int u=(1<<SZ(f))-1,v=(1<<SZ(g))-1;
	while(dis[u][v]){
		if(v!=pre[u][v].se)ans[id[dis[u][v]]]=2,v=pre[u][v].se;
		else u=pre[u][v].fi;
	}
	rep(i,1,n)printf("%d ",ans[i]);exit(0);
}
int main() {
	read(n);double gl=1;
	rep(i,1,n)read(a[i]);
	int c=0;
	while(1){
		p=R()%(n-1)+2;while(vis[p])p=R()%(n-1)+2;c++;vis[p]=1;
		solve(p);gl*=9.0/(n-1);if(gl<1e-5||c==n-1)break;
	}
	puts("NO");
	return 0;
}