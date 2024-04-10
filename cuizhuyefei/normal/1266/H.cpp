#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 62,mo1=1e9+7,mo2=1e9+9;
inline int power(int a, int n, int mo) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}
int inv(int a, int mo){return power(a,mo-2,mo);}
int n,b[N],r[N],a[N][N];
struct YZR{
	int mo;
	int b[N][N],c[N][N];
	void ini(int MOO){
		mo=MOO;const ll MOD=1ll*mo*mo;
		rep(i,1,n-1)rep(j,1,n-1)b[i][j]=a[i][j];
		rep(i,1,n-1)c[i][i]=1;
		rep(i,1,n-1){
			if(!b[i][i]){
				rep(j,i+1,n-1)if(b[j][i]){
					rep(k,1,n-1)swap(b[i][k],b[j][k]),swap(c[i][k],c[j][k]);
					break;
				}
			}
			int xs=inv(b[i][i],mo);
			rep(j,1,n-1)b[i][j]=1ll*b[i][j]*xs%mo,c[i][j]=1ll*c[i][j]*xs%mo;
			rep(j,1,n-1)if(j!=i&&b[j][i]){
				xs=b[j][i];
				rep(k,1,n-1)b[j][k]=(b[j][k]-1ll*xs*b[i][k]+MOD)%mo,c[j][k]=(c[j][k]-1ll*xs*c[i][k]+MOD)%mo;
			}
		}
	}
	void solve(int *f, int *ans){
		rep(i,1,n-1)ans[i]=0;
		rep(i,1,n-1)rep(j,1,n-1)ans[i]=(ans[i]+1ll*c[i][j]*f[j])%mo;
	}
}yzr1,yzr2;
bool vis[N];Vi e[N];
void dfs(int u){vis[u]=1;for(int v:e[u])if(!vis[v])dfs(v);}
int main() {
	read(n);
	rep(i,1,n-1)read(b[i]),read(r[i]),a[i][i]=2;
	rep(i,1,n-1)a[b[i]][i]--,a[r[i]][i]--;
	yzr1.ini(mo1);yzr2.ini(mo2);
	int q;read(q);while(q--){
		int v;read(v);char s[N];scanf("%s",s+1);
		static int f[N],ans1[N],ans2[N];static ll ans[N];
		rep(i,1,n-1)f[i]=(s[i]=='R')+(i==1)-(i==v);
		rep(i,1,n-1)if(s[i]=='R')f[b[i]]--;
	//	rep(i,1,n-1)f[i]=(f[i]+mo)%mo;
		yzr1.solve(f,ans1);yzr2.solve(f,ans2);
		const ll mod=1ll*mo1*mo2;
		rep(i,1,n-1)ans[i]=((1ll*ans1[i]*inv(mo2,mo1)%mo1*mo2+1ll*ans2[i]*inv(mo1,mo2)%mo2*mo1)%mod+mod)%mod;
		static ll g[N];rep(i,1,n-1)g[i]=f[i];
		rep(i,1,n-1)rep(j,1,n-1)g[i]-=a[i][j]*ans[j];
		bool gg=0;
		rep(i,1,n-1)if(g[i]||!ans[i]&&s[i]=='R')gg=1;
	//	rep(i,1,n-1)printf("%lld %d %d\n",ans[i],ans1[i],ans2[i]);printf("--- %d\n",gg);
		rep(i,1,n)e[i].clear(),vis[i]=0;
		rep(i,1,n-1)e[s[i]=='R'?r[i]:b[i]].pb(i);
		dfs(v);
		rep(i,1,n-1)if(ans[i]&&!vis[i])gg=1;
		if(gg)puts("-1");
		else{
			ll res=0;rep(i,1,n-1)res+=2ll*ans[i]-(s[i]=='R');printf("%lld\n",res);
		}
	}
	return 0;
}