#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
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
int n,l,r,ans;
int main()
{
	n=read(),l=read(),r=read();
	int Pmin=(1<<l)-1;
	printf("%d ",Pmin+(n-l));
	if(r>=n)
		printf("%d\n",(1<<n)-1);
	else
	{
		int Pmax=(1<<r)-1,Pmax2=(1<<(r-1));
		printf("%d\n",Pmax+Pmax2*(n-r));
	}
	return 0;
}