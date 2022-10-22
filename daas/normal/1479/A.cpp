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
	int l=1,r=n;
	while(l!=r)
	{
		int mid=(l+r)/2;
		printf("? %d\n",mid);
		fflush(stdout);
		int v1=read();
		printf("? %d\n",mid+1);
		fflush(stdout);
		int v2=read();
		if(v1<v2) r=mid;
		else l=mid+1;
	}
	printf("! %d\n",l);
	return 0;
}