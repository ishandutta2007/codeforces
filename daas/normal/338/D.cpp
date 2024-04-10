#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int MAXK=1e4+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
ll n,m,a[MAXK];
int K;
ll gcd(ll x,ll y)
{
	ll z=x%y;
	while(z)
	{
		x=y;
		y=z;
		z=x%y;
	}
	return y;
}
void Exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b) {x=1,y=0;return;}
	Exgcd(b,a%b,y,x);
	y-=a/b*x;
}
ll ksc(ll x,ll y,ll p)
{
	ll d=(long double)x/p*y+0.5;
	ll bck=x*y-p*d;
	return bck<0?bck+p:bck;
}
int flag;
void Excrt(ll b1,ll p1,ll b2,ll p2,ll &B,ll &P)
{
	ll d=gcd(p1,p2);
	P=p1/d*p2;
	if((b2-b1)%d) {flag=1;return;}
	ll X,Y; Exgcd(p1/d,p2/d,X,Y);
	B=(ksc(ksc(p1,X,P),((b2-b1)/d%P+P)%P,P)+b1)%P;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	K=read();
	for(int i=1;i<=K;++i) scanf("%lld",&a[i]);
	ll X=a[1];
	for(int i=2;i<=K;++i)
	{
		ll d=gcd(X,a[i]);
		if(X/d>n/a[i]) {puts("NO");return 0;}
		X=X/d*a[i];
	}
	ll B=0,P=a[1];
	for(int i=2;i<=K;++i)
	{
		ll b=(-(i-1)%a[i]+a[i])%a[i],p=a[i];
		Excrt(B,P,b,p,B,P);
		if(flag) {puts("NO");return 0;}
	}
	if(!B) B=P;
	if(B+K-1>m) {puts("NO");return 0;}
	for(int i=1;i<=K;++i) if(gcd(B+i-1,X)!=a[i]) {puts("NO");return 0;}
	puts("YES");
	return 0;
}
//ore no turn,draw!