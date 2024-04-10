#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
inline int read()
{
	int ret=0; char c=getchar();
	while (c>57 || c<48)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int ans,tt,n,stac,t[100000];//+0123   4

int main()
{
	n=read();
	for(int i=n; i>=n-1000&& i; --i)
	{
		ans=0;
		tt=i;
		while(tt)
		{
			ans+=tt%10;
			tt/=10;
		}//<stack> //_
		if(ans+i==n)t[++stac]=i;
	}
	printf("%d\n",stac);
	for(int i=1; i<=stac; ++i)
	{
		printf("%d\n",t[stac-i+1]);
	}
}