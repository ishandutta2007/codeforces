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
int n;
int main()
{
	n=read();
	if(n+1<4)
		puts("1");
	else
		puts("2");
	for(int i=2;i<=n+1;++i)
	{
		int flag=0;
		for(int j=2;j*j<=i;++j)
			if(i%j==0)
			{
				flag=1;
				break;
			}
		if(flag)
			printf("2 ");
		else
			printf("1 ");
	}
	putchar('\n');
	return 0;
}