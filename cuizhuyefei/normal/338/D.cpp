#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 233333;
ll n,m,l,a[N],p[N],res[N];
inline ll gcd(ll a, ll b) {return !b?a:gcd(b,a%b);}
inline void exgcd(ll a, ll b, ll &x, ll &y) {
	if (!b) {x=1; y=0; return;}
	exgcd(b,a%b,y,x); y-=a/b*x;
}
inline void GG() {puts("NO"); exit(0);}
inline void add(ll &a, ll b, ll mo) {a=a+b<mo?a+b:a+b-mo;}
inline ll mul(ll a, ll n, ll mo) {
	bool flag=0; ll res=0; if (n<0) n=-n,flag^=1; if (a<0) a=-a,flag^=1;
	while (n) {
		if (n&1) add(res,a,mo);
		add(a,a,mo); n>>=1;
	}
	if (flag) res=mo-res;
	return res;
}
int main() { //freopen("1.in","r",stdin);
	read(n);read(m);read(l);rep(i,1,l)read(p[i]),res[i]=p[i];
	rep(i,1,l) {a[i]=(p[i]-(i-1))%p[i]; a[i]=a[i]<0?a[i]+p[i]:a[i];}
//	rep(i,1,l) printf("%d %d\n",a[i],p[i]);
	rep(i,1,l-1) {
	//	printf("%d : %d %d\n",i,a[i],p[i]);
		ll x,y; exgcd(p[i],p[i+1],x,y); ll GCD=gcd(p[i],p[i+1]);
		if ((a[i+1]-a[i])%GCD!=0) GG();
		if (1.0*p[i]*p[i+1]/GCD>1e12+3) GG();
		
		
	//	x%=(p[i+1]/GCD); x*=((a[i+1]-a[i])/GCD%(p[i+1]/GCD)); x%=(p[i+1]/GCD);
		x=mul(x,((a[i+1]-a[i])/GCD),p[i+1]/GCD);
		//x=(x*((a[i+1]-a[i])/GCD))%(p[i+1]/GCD)
		
		p[i+1]=p[i]*(p[i+1]/GCD); a[i+1]=x*p[i]+a[i]; a[i+1]%=p[i+1]; //WA
		a[i+1]=a[i+1]<0?a[i+1]+p[i+1]:a[i+1];
	}
//	rep(i,l,l) printf("%d : %d %d\n",i,a[i],p[i]);
	if (a[l]<=0) a[l]+=p[l];
	if (p[l]<=n&&a[l]+l-1<=m) {
		rep(i,1,l) if (gcd(p[l],a[l]+i-1)!=res[i]) GG();
		puts("YES");
	} else GG();
	return 0;
}
/*
1. <=n && <=m
2. check again
*/