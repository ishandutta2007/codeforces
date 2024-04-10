#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
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
inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int M = 1020000;
ll mo = 1e9+7,n;
ll f[8][M];
inline ll power(ll a, int n) {
	ll res=1; a%=mo;
	while (n) {
		if (n&1) res=res*a%mo;
		a=a*a%mo;
		n>>=1;
	}
	return res;
}
inline int inv(int a) {return power(a,mo-2);}
inline ll mul(ll a, ll b) {return (a%mo)*(b%mo)%mo;}
int main() { //freopen("1.in","r",stdin);
	read(n);
	rep(i,1,6) rep(j,1,1000000) f[i][j]=(f[i][j-1]+power(j,i))%mo;
	ll ans=0,ans1=0,ans2=0,ans3=0;
	for (ll x=0; x<=1000000; x++) { //x>=0, y>=1
		ll k=n-1LL*x*x; if (k<0) break; k=sqrt(k);
		ans+=mul(mul(mul(n,n+1),n+2),k);
		ll y2=f[2][k],y4=f[4][k],y6=f[6][k];
		ans+=mul(3*n+4,x*x%mo*k+y2);
		ans-=mul(3*n+6,x*x%mo*x%mo*x%mo*k%mo+mul(2*x*x,y2)+y4);
		ans+=2*(mul(x*x*x,x*x*x%mo*k)+mul(3*x*x%mo*x%mo*x%mo,y2)+mul(3*x*x,y4)+y6);
	}
//	printf("%lld %lld %lld %lld\n",ans,ans1,ans2,ans3);
	ans%=mo; ans=(ans+mo)%mo; ans=ans*inv(6)%mo;
//	cout<<ans%mo<<endl;
	ans=ans*4+mul(mul(n,n+1),n+2)*inv(6)%mo;
	cout<<ans%mo;
	return 0;
}