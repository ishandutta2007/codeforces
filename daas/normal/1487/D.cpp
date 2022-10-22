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
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,ans,mem[30001];
int main()
{
	for(int a=1;a<=sqrt(2000000000-1);++a)
	{
		int c=(a*a+1)/2;
		int b=c-1;
		if(a<=b && b<=c && 1ll*a*a+1ll*b*b==1ll*c*c && a+b>c) mem[++ans]=c;
	}
	T=read();
	while(T--)
	{
		n=read();
		if(n<mem[1])
		{
			puts("0");
			continue;
		}
		int l=1,r=ans,Out;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(mem[mid]<=n) Out=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",Out);
	}
	return 0;
}