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
#define int long long
const int N = 3333,mo=998244353;
int n,m,a[666666],w[666666],f[N][N],g[N][N],ans[666666];
inline int power(int a,int n){
	int res=1;
	while(n){
		if(n&1)res=1LL*res*a%mo;a=1LL*a*a%mo;n>>=1;
	}
		
	return res;
}
void add(int &x,int y){x=(x+y)%mo;}
void solve(Vi s, int xs, int *dp){if(!SZ(s))return;
	int x=w[s[0]];memset(g,0,sizeof(g));
	g[0][0]=1;int tot=0;rep(i,0,SZ(s)-1)tot=(tot+w[s[i]])%mo;
	rep(t,0,m-1){
		int ni=power((tot+t*xs)%mo,mo-2);
		rep(i,0,t){
			add(g[t+1][i+1],1LL*g[t][i]*(x+i*xs)%mo*ni%mo);
			add(g[t+1][i],1LL*g[t][i]*((1LL*tot+t*xs-(1LL*x+i*xs))%mo)%mo*ni%mo);
		}
	}
	rep(i,0,m)rep(j,0,i)add(ans[s[0]],1LL*g[i][j]*(w[s[0]]+j*xs)%mo*dp[i]%mo);
	rep(i,1,SZ(s)-1)ans[s[i]]=1LL*ans[s[0]]*w[s[i]]%mo*power(w[s[0]],mo-2)%mo;
}
signed main() {
	read(n);read(m);
	rep(i,1,n)read(a[i]);
	rep(i,1,n)read(w[i]);
	ll t0=0,t1=0;rep(i,1,n)if(!a[i])t0+=w[i];else t1+=w[i];
	t0%=mo;t1%=mo;
	f[0][0]=1;//0
	static int qaq[N*10];
	rep(i,-2*m,3*m)qaq[i+2*N]=power((t0+t1+i)%mo,mo-2);
	rep(t,0,m-1)rep(i,0,t)if(f[t][i]){
	//	int ni=power((t0+t1+t-i-i)%mo,mo-2);
		int ni=qaq[t-i-i+2*N];
		add(f[t+1][i],1LL*f[t][i]*(t1+t-i)%mo*ni%mo);
		add(f[t+1][i+1],1LL*f[t][i]*(t0-i)%mo*ni%mo);
	}
	Vi b[2];rep(i,1,n)b[a[i]].pb(i);
	static int dp[N];
	rep(i,0,m)dp[i]=f[m][i];
	solve(b[0],-1,dp);
	rep(i,0,m)dp[i]=f[m][m-i];
	solve(b[1],1,dp);
	rep(i,1,n)printf("%lld\n",(ans[i]%mo+mo)%mo);
	return 0;
}
/*signed main() {
	read(n);read(m);
	rep(i,1,n)read(a[i]);
	rep(i,1,n)read(w[i]);
	ll t0=0,t1=0;rep(i,1,n)if(!a[i])t0+=w[i];else t1+=w[i];
	t0%=mo;t1%=mo;
	f[0][0]=1;//0
	rep(t,0,m-1)rep(i,0,t)if(f[t][i]){
		int ni=power((t0+t1+t-i-i)%mo,mo-2);
		add(f[t+1][i],1LL*f[t][i]*(t1+t-i)%mo*ni%mo);
		add(f[t+1][i+1],1LL*f[t][i]*(t0-i)%mo*ni%mo);
	}
	Vi b[2];rep(i,1,n)b[a[i]].pb(i);
	static int dp[N];
	rep(i,0,m)dp[i]=f[m][i];
	solve(b[0],-1,dp);
	rep(i,0,m)dp[i]=f[m][m-i];
	solve(b[1],1,dp);
	rep(i,1,n)printf("%lld\n",(ans[i]%mo+mo)%mo);
	return 0;
}*/