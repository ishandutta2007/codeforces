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
int T,n;
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		if(n==1)
		{
			puts("0");
			continue;
		}
		int ans=0;
		if(n%2)
			--n,++ans;
		if(n!=2)
			n=2,++ans;
		printf("%d\n",ans+1);
	}
	return 0;
}