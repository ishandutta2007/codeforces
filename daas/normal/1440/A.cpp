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
int T,n,c0,c1,h,n0,n1;
char s[1001];
int main()
{
	T=read();
	while(T--)
	{
		n=read(),c0=read(),c1=read(),h=read();
		scanf("%s",s+1);
		n0=n1=0;
		for(int i=1;i<=n;++i)
			if(s[i]=='0')
				++n0;
			else
				++n1;
		if(c0>c1)
			swap(c0,c1),swap(n0,n1);
		if(c0+h<c1)
			printf("%d\n",c0*n0+(c0+h)*n1);
		else
			printf("%d\n",c0*n0+c1*n1);
	}
	return 0;
}