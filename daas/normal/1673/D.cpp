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
const int mod=1e9+7;
inline int MOD(int x) {return x+((x>>31)&mod);}
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,b,q,y,c,r,z,ans;
ll L,R;
int gcd(int x,int y)
{
	int z=x%y;
	while(z)
	{
		x=y;
		y=z;
		z=x%y;
	}
	return y;
}
int flag;
ll get(ll x)
{
	if((x-b)%q) {flag=1;return 0;}
	return (x-b)/q;
}
void solve(int t)
{
	if((ll)q*t/gcd(q,t)!=r) return;
	ans=MOD(ans+(ll)(r/t)*(r/t)%mod-mod);
}
int main()
{
	T=read();
	while(T--)
	{
		b=read(),q=read(),y=read();
		c=read(),r=read(),z=read();
		if(r%q) {puts("0");continue;}
		flag=0;
		L=get(c),R=get(c+(ll)r*(z-1));
		if(!(0<=L && R<=y-1) || flag) {puts("0");continue;}
		if(L-r/q<0 || R+r/q>=y) {puts("-1");continue;}
		ans=0;
		for(int i=1;i<=sqrt(r) && !flag;++i) if(r%i==0)
		{
			solve(i);
			if(i!=r/i) solve(r/i);
		}
		printf("%d\n",ans);
	}
	return 0;
}
//ore no turn,draw!