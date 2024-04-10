#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PLL;
typedef vector<int> Vi;
typedef long double ld;
ll n,m,a,d,t[112000],mx,ans;
ll f=1,f1=1;
PLL now;
//fi : (0 t[m]) (1 a*i)
inline void LOCAL() {freopen("1.in","r",stdin);}
inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
//	freopen("1.in","r",stdin);
	read(n);read(m);read(a);read(d);
	rep(i,1,m) read(t[i]); mx=max(t[m],n*a); rep(i,m+1,110000) t[i]=2e18;
	if (t[1]<a) now=PLL(0,t[1]);
	else now=PLL(1,a);
	while (now.se<=mx) { //1. se<=mx
	//	printf("%lld %lld %lld\n",now.fi,now.se,ans);
	//	if (now.fi==1 && f>m) ans--;
	//	if (now.fi==0 && now.se>n*a) ans--;
		ll pos=now.se+d;
		while (f<=m && t[f]<=pos) f++;
		ll num=pos/a; num++;
		if (num>n) {
			ans++;
			if (f<=m) {now=PLL(0,t[f]); continue;}
			else break;
		}
		if (t[f]<=num*a) {ans++; now=PLL(0,t[f]);}
		else {
			ll cvr=1+d/a,delta=(t[f]/a)-num;
			if (f>m) {ans++; ans+=(n-num)/cvr+1; break;}
			if (delta>cvr+cvr) {
				ll times=delta/cvr-1; if (num+times*cvr>n) times=(n-num)/cvr+1; // 
			//	printf("<%lld %lld %lld %lld>\n",cvr,delta,times,num);
				ans+=times+1;
				if (num+times*cvr<=n) now=PLL(1,a*(num+times*cvr));
				else now=PLL(0,t[f]);
			}
			else {
				ans++; 
				if (num<=n) now=PLL(1,num*a); else now=PLL(0,t[f]);
			}
		}
	}
	printf("%lld",ans);
	return 0;
}