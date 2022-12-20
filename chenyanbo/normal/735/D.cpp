#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
inline int read()
{
	int ret=0; char c=getchar();
	while (c>57 || c<48)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

inline bool prime(int n)
{
	if (n<2)return 1; //true
	int c=sqrt(n); //+0.001
	for(int i=2; i<=c; ++i)
	{
		if(!(n%i))return 0;
	}
	return 1;
}
int n,a[10];
int main()
{
	n=read();
	a[2]=1; a[3]=1; a[4]=2; a[5]=1; a[6]=2; a[7]=1; a[8]=2; a[9]=2;
	if(n<10)
	{
		printf("%d\n",a[n]);
	}
	else
	{
		if(!(n&1))printf("%d\n",2);
		else
		if(prime(n))printf("%d\n",1);
		else 
		{
			if(prime(n-2))printf("2"); //50
			else puts("3");
		}
	}
}