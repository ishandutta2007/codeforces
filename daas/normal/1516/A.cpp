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
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,a[200],K;
int main()
{
	T=read();
	while(T--)
	{
		n=read(),K=read();
		int tmp=0;
		for(int i=1;i<=n;++i)
		{
			a[i]=read();
			int v=min(a[i],K-tmp);
			tmp+=v;
			a[i]-=v;
		}
		a[n]+=tmp;
		for(int i=1;i<=n;++i) printf("%d ",a[i]);
		putchar('\n');
	}
	return 0;
}