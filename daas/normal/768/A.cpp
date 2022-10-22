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
int n,a[100001];
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	sort(a+1,a+n+1);
	int bjl=1,bjr=n;
	while(bjl+1<=n && a[bjl+1]==a[bjl])
		++bjl;
	while(bjr-1>=1 && a[bjr-1]==a[bjr])
		--bjr;
	printf("%d\n",max(bjr-bjl-1,0));
	return 0;
}