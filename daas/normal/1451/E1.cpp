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
	int x;
	scanf("%d",&x);
	return x;
	/*int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;*/
}
int n,a[700000],v1,v2,v3,v4,v5;
int get(int v,int id){return ((v&(1<<id))>>id);}
int main()
{
	n=read();
	printf("XOR %d %d\n",1,2);
	fflush(stdout);
	v1=read();
	printf("XOR %d %d\n",1,3);
	fflush(stdout);
	v2=read();
	printf("AND %d %d\n",1,2);
	fflush(stdout);
	v3=read();
	printf("AND %d %d\n",2,3);
	fflush(stdout);
	v4=read();
	printf("AND %d %d\n",1,3);
	fflush(stdout);
	v5=read();
	for(int i=16;i>=0;--i)
		if(get(v1,i)==0)
			a[1]+=(v3&(1<<i));
		else
			if(get(v2,i)==0)
				a[1]+=(v5&(1<<i));
			else
				if(get(v4,i)==0)
					a[1]+=(1<<i);
	a[2]=a[1]^v1;
	a[3]=a[1]^v2;
	for(int i=4;i<=n;++i)
	{
		printf("XOR %d %d\n",1,i);
		fflush(stdout);
		int v=read();
		a[i]=a[1]^v;
	}
	putchar('!');
	for(int i=1;i<=n;++i)
		printf(" %d",a[i]);
	putchar('\n');
	fflush(stdout);
	return 0;
}