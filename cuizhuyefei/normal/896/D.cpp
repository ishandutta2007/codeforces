#include<cstdio>
#include<cstring>
#include<cmath>
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
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
ll n,m,mo,l,r,a[11][200400],ans,cur;
ll ta[11],Time[11],size;

inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline void exgcd(ll a, ll b, ll &x, ll &y) {
	if (!b) {x=1; y=0; return;}
	exgcd(b,a%b,y,x); y-=a/b*x;
}
inline ll inv(ll a, ll mo) {
	ll x,y; exgcd(a,mo,x,y); return x>=0 ? x : x+mo;
}
inline ll mul(ll a, ll b, ll mo) {return a*b%mo;}
inline ll power(ll a, ll n, ll mo) {
	ll ans=1;
	while (n) {
		if (n&1) ans=ans*a%mo;
		a=a*a%mo;
		n>>=1;
	}
	return ans;
}
inline ll getfac(ll n, ll mo, ll Ex) { //Ex 
	if (!n) return 1;
	/*ll res=getfac(n/mo,mo,Ex),zq=1,tmp=n%mo;
	rep(i,1,mo-1) {ll tmp=i; while (tmp%Ex==0) tmp/=Ex; zq=zq*tmp%mo; if (tmp==i) res=res*zq%mo;}
	return mul(res,power(zq,n/mo,mo),mo); //w e x theorem*/
	ll res=getfac(n/Ex,mo,Ex);//,tmp=n%mo,zq=1;
	rep(i,1,size) if (Ex==ta[i]) {
	//	printf("%d\n",mo);
		if (mo>n) return res*a[i][n]%mo;
		return res*power(a[i][mo-1],n/mo,mo)%mo*a[i][n%mo]%mo;
	}
//	rep(i,1,mo-1) {if (i%Ex!=0) zq=zq*i%mo; if (i==tmp) res=res*zq%mo; if (i>n) break;}
//	return res*power(zq,n/mo,mo)%mo;
}
ll getmi(ll n, ll p) {
	ll res=0;
	while (n>=p) res+=n/p,n/=p;
	return res;
}
inline ll C(ll n, ll m, ll p, ll mi) {
	ll e1=getmi(n,p),e2=getmi(m,p),e3=getmi(n-m,p); //a (mod p^mi) * p^e
//	puts("OwO");
	if (e1-e2-e3>=mi) return 0;
	ll MO=power(p,mi,1e15),a1=getfac(n,MO,p),a2=getfac(m,MO,p),a3=getfac(n-m,MO,p);
//	puts("OwO");
	return a1*inv(a2,MO)%MO*inv(a3,MO)%MO*power(p,e1-e2-e3,MO)%MO;
}
inline void solve(int i) {
	int cnt=0; while (cur%i==0) cur/=i,cnt++; 
	ll c=C(n,m,i,cnt),M=power(i,cnt,1e15); //attention!!!!!!!!!!!!!!!!!!!!!!!!!!!
//	printf("< %d %d %lld>\n",i,cnt,c);
	ans+=mul(mul(c,mo/M,mo),inv(mo/M,M),mo); if (ans>=mo) ans-=mo;
}
inline ll Lucas(int N, int M) {
	if (M<0) return 0; n=N; m=M;
	ll mx=sqrt(mo)+0.5; cur=mo; ans=0;
//	printf("%d %d %d\n",cur,2,mx);
	/*rep(i,2,mx) 
		if (cur%i==0) solve(i);
	if (cur>1) solve(cur);*/
	rep(i,1,size) solve(ta[i]);
//	printf("%lld %lld %lld\n",n,m,ans);
	return ans;
}
inline ll getans(int n, int m) {
	if (m<0) return 0;
	ll res=0;
	rep(i,0,n) {
		ll L=max((i-m+1)/2,0),R=i/2;
	//	printf("%d %lld %lld\n",n,Lucas(n,i),((Lucas(i,R)-Lucas(i,L-1)+mo)%mo)%mo);
		(res+=Lucas(n,i)*((Lucas(i,R)-Lucas(i,L-1)+mo)%mo)%mo)%=mo;
	}
	return res;
}
inline void getmax() {
	ll cur=mo,mx=sqrt(mo)+0.5; 
	rep(i,2,mx) if (cur%i==0){
		ta[++size]=i;
		while (cur%i==0) cur/=i,Time[size]++;
	}
	if (cur>1) {ta[++size]=cur; Time[size]=1;}
}
int main() {
//	freopen("1.in","r",stdin);
	ll n; read(n); read(mo); read(l); read(r); getmax();
	rep(j,1,size) {
		a[j][0]=1; int MO=power(ta[j],Time[j],1e15); //printf("%d %d\n",ta[j],Time[j]);
		for (int i=1; i<=n; i++) {a[j][i]=a[j][i-1]*(i%ta[j]==0 ? 1 : i)%MO;}
	}
	printf("%lld",(getans(n,r)-getans(n,l-1)+mo)%mo);
	return 0;
}
/*
1.complexity
2.pre
*/