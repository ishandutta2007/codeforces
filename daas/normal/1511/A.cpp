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
int T,n,a[51];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		int F=0,ans=0;
		for(int i=1;i<=n;++i)
		{
			a[i]=read();
			if(a[i]==1) ++ans;
			if(a[i]==3) ++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}