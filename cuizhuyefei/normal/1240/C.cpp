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
int n,k;vector<Pii> e[N];ll f[N][2],s[N];
ll qry(int len, int len1){
	umin(len,len1);ll res=0;
	rep(i,1,len)res+=max(s[i],0LL);
	return res;
}
void dfs(int u, int fa){
	ll sum=0;
	rep(i,0,SZ(e[u])-1)if(e[u][i].fi!=fa)
		dfs(e[u][i].fi,u),sum+=f[e[u][i].fi][0];
	int len=0;
	rep(i,0,SZ(e[u])-1)if(e[u][i].fi!=fa)
		s[++len]=f[e[u][i].fi][1]-f[e[u][i].fi][0]+e[u][i].se;
	sort(s+1,s+len+1);reverse(s+1,s+len+1);
	f[u][0]=sum+qry(len,k);
	f[u][1]=sum+qry(len,k-1);
}
int main() {
	int T;read(T);while(T--){
		read(n);read(k);
		rep(i,1,n)e[i].clear();
		rep(i,1,n-1){
			int u,v,w;read(u);read(v);read(w);
			e[u].pb(Pii(v,w));e[v].pb(Pii(u,w));
		}
		dfs(1,0);
		printf("%lld\n",f[1][0]);
	}
	return 0;
}