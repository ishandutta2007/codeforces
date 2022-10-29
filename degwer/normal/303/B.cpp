#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{
	for(;;)
	{
		if(a<b)
		{
			swap(a,b);
		}
		a%=b;
		if(a==0)
		{
			return b;
		}
	}
}
int main()
{
	int mx,my,rx,ry,hx,hy;
	scanf("%d%d%d%d%d%d",&mx,&my,&rx,&ry,&hx,&hy);
	int g=gcd(hx,hy);
	hx/=g;
	hy/=g;
	int siz=min(mx/hx,my/hy);
	hx*=siz;
	hy*=siz;
	int cx,cy;
	if(hx>rx*2)
	{
		cx=0;
	}
	else
	{
		if(hx>(mx-rx)*2)
		{
			cx=mx-hx;
		}
		else
		{
			cx=(2*rx-hx)/2;
		}
	}
	if(hy>ry*2)
	{
		cy=0;
	}
	else
	{
		if(hy>(my-ry)*2)
		{
			cy=my-hy;
		}
		else
		{
			cy=(2*ry-hy)/2;
		}
	}
	printf("%d %d %d %d\n",cx,cy,cx+hx,cy+hy);
}