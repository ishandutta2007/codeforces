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
int n;
int main()
{
	n=read();
	puts("YES");
	for(int i=1;i<=n;++i)
	{
		int x=read(),y=read();
		read(),read();
		printf("%d\n",(x%2+2)%2*2+(y%2+2)%2+1);
	}
	return 0;
}