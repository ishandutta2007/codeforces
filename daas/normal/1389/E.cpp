#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define int long long
using namespace std;
inline int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int T,M,D,W;
inline int gcd(int x,int y)
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
signed main()
{
	T=read();
	while(T--)
	{
		M=read(),D=read(),W=read();
		int d=gcd(D-1,W),minn=min(M,D);
		W/=d;
		int t=(minn-1)/W;
		printf("%lld\n",minn*t-(1+t)*t/2*W);
	}
	return 0;
}