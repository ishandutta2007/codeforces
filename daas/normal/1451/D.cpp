#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int read()
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
int T,D,K;
int main()
{
	T=read();
	while(T--)
	{
		D=read(),K=read();
		int l=0,r=D/K,lim;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(2ll*mid*mid*K*K<=1ll*D*D)
				lim=mid,l=mid+1;
			else
				r=mid-1;
		}
		int x=lim*K,y=(lim+1)*K;
		if(1ll*x*x+1ll*y*y<=1ll*D*D)
			puts("Ashish");
		else
			puts("Utkarsh");
	}
	return 0;
}