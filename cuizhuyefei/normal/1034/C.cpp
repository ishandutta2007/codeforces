#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
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
const int N = 2333333,mo=1e9+7;
int n,a[N],f[N],fa[N];ll size[N],dp[N],tot;
Vi e[N];
ll gcd(ll a, ll b){return !b?a:gcd(b,a%b);}
void dfs(int u){
	size[u]=a[u];
	per(i,SZ(e[u])-1,0)dfs(e[u][i]),size[u]+=size[e[u][i]];
	ll g=gcd(tot,size[u]),t=tot/g;
	if(t<=n)f[t]++;
}
int main() {
	read(n);rep(i,1,n)read(a[i]),tot+=a[i];
	rep(i,2,n)read(fa[i]),e[fa[i]].pb(i);
	dfs(1);per(i,n,1)for(int j=i+i;j<=n;j+=i)f[j]+=f[i];//f[i]=i
//	rep(i,1,n)printf("%d:%d\n",i,f[i]);
	dp[1]=1;
	rep(i,1,n)if(dp[i])for(int j=i+i;j<=n;j+=i)if(f[j]==j)
		dp[j]=(dp[j]+dp[i])%mo;
	ll res=0;rep(i,1,n)res=(res+dp[i])%mo;cout<<res;
	return 0;
}