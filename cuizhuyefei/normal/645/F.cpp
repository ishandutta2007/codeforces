#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> vec;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 1000500, mo = 1e9+7;
inline int power(int a, int n){int res=1; rep(i,1,n)res*=a; return res;}
int n,m,prime[N],len,mrk[N],mu[N],cnt[N];
ll ans;
bool occ[N];
int fac[N],ifac[N],phi[N];
inline void exgcd(int a, int b, int &x, int &y) {
	if (!b) {x=1; y=0; return;}
	exgcd(b,a%b,y,x); y-=a/b*x;
}
inline int inv(int a) {int x,y; exgcd(a,mo,x,y); return x>=0?x:x+mo;}
inline int C(int n, int m) {
	if (m>n) return 0;
	return 1LL*fac[n]*ifac[m]%mo*ifac[n-m]%mo;
}
int a[20],b[20],c[N];
inline void dfs(int dep, int tot, int now) {
	if (dep>tot) {
		ll del=C(cnt[now]+1,m)-C(cnt[now],m); cnt[now]++;
		ans+=1LL*del*phi[now]%mo;
		return;
	}
	rep(i,0,b[dep]) {dfs(dep+1,tot,now); now*=a[dep];}
}
inline void insert(int x) {
//	ll del=C(cnt[x]+1,m)-C(cnt[x],m); cnt[x]++;
	int len=0; //del*=phi[x]; del%=mo; printf("%d %lld\n",x,del);
	while (mrk[x]) {
		a[++len]=mrk[x]; b[len]=0;
		while (x%a[len]==0) {x/=a[len]; b[len]++;}
	}
	if (x>1) {a[++len]=x; b[len]=1;}
	dfs(1,len,1);
}
int main() { //freopen("1.in","r",stdin);
	int nn,q; read(nn); read(m); read(q); rep(i,1,nn) read(c[i]);
	n=1000000;
	fac[0]=1; rep(i,1,n) fac[i]=1LL*fac[i-1]*i%mo;
	ifac[n]=inv(fac[n]); per(i,n-1,0) ifac[i]=1LL*ifac[i+1]*(i+1)%mo;
	phi[1]=1;
	rep(i,2,n) {
		if (!mrk[i]) {prime[++len]=i; phi[i]=i-1;}
		rep(j,1,len) {
			int v=prime[j]*i; if (v>n) break;
			phi[v]=(i%prime[j]==0) ? phi[i]*prime[j] : phi[i]*(prime[j]-1);
			mrk[v]=prime[j]; if (i%prime[j]==0) break;
		}
	}
	mu[1]=1;
	rep(i,2,n) if (!mrk[i]) mu[i]=-1;
	else {
		int v=mrk[i],lst=i/v; if (lst%v==0) mu[i]=0; else mu[i]=mu[v]*mu[lst];
	}
	rep(i,1,nn) {insert(c[i]); ans%=mo;}
	while (q--) {
		int x; read(x); insert(x); ans%=mo;
		printf("%lld\n",ans>=0?ans:ans+mo);
	}
	return 0;
}