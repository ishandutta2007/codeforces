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
const int N = 202000;const ll inf =1e16;
int n,a[N];Vi e[N];ll f[N][2];Vi ans;bool b[N][2];
void dfs1(int u, int fa){
	ll mn=0;int deg=0;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa){
		dfs1(e[u][i],u);int v=e[u][i];deg++;
		f[u][0]+=f[v][0];umin(mn,f[v][1]-f[v][0]);
	}
	if(!deg){f[u][1]=0;f[u][0]=a[u];return;}
	f[u][1]=f[u][0]+mn;umin(f[u][0],f[u][1]+a[u]);
}
void dfs(int u, int fa){
	if(b[u][0]&&a[u]+f[u][1]==f[u][0]){
		b[u][1]=1;ans.pb(u);
	}
//	printf("%d:%d %d %lld %lld\n",u,b[u][0],b[u][1],f[u][0],f[u][1]);
	if(b[u][0]){
		ll tot=0;rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa)tot+=f[e[u][i]][0];
		if(tot==f[u][0])rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa)b[e[u][i]][0]=1;
	}
	if(b[u][1]){
		ll mn=inf,mn1=inf;
		rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa){
			ll tmp=f[e[u][i]][1]-f[e[u][i]][0];umin(mn,tmp);
		//	if(tmp<mn){mn1=mn;mn=tmp;}
		//	else if(tmp<mn1)mn1=tmp;
		}
		Vi c;
		rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa){
			ll tmp=f[e[u][i]][1]-f[e[u][i]][0];
			if(mn==tmp)c.pb(e[u][i]);
		}
		if(SZ(c)==1){
		rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa){
			ll tmp=f[e[u][i]][1]-f[e[u][i]][0];
			if(mn==tmp)b[e[u][i]][1]=1;else b[e[u][i]][0]=1;
		}
		}
		else{
		rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa){
			ll tmp=f[e[u][i]][1]-f[e[u][i]][0];b[e[u][i]][0]=1;
			if(mn==tmp)b[e[u][i]][1]=1;
		}	
		}
	}
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa)dfs(e[u][i],u);
}
int main() {
	read(n);rep(i,1,n)read(a[i]);
	rep(i,1,n-1){int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);}
	b[1][0]=1;dfs1(1,0);dfs(1,0);
	printf("%lld %d\n",f[1][0],SZ(ans));
	sort(ans.begin(),ans.end());
	rep(i,0,SZ(ans)-1)printf("%d ",ans[i]);
	return 0;
}