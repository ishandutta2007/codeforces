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
int n,a[101],maxn,ans;
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read(),maxn=max(maxn,a[i]);
	for(int i=1;i<=n;++i)
		ans+=maxn-a[i];
	printf("%d\n",ans);
	return 0;
}