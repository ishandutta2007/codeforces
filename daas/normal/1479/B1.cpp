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
int n,a[100010],p[100010],ans;
int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i) p[i]=(a[i]!=a[i+1] && a[i]!=a[i-1]);
	for(int l=1,r;l<=n;l=r+1)
	{
		r=l;
		if(!p[l]) continue;
		while(r+1<=n && p[r+1]) ++r;
		int L=a[l-1],R=a[r+1];
		ans+=(r-l+1);
		if(L==R && L)
		{
			--ans;
			int flag=0;
			for(int i=l;i<r;++i)
				if(a[i]!=L && a[i+1]!=L)
				{
					flag=1;
					break;
				}
			ans+=flag;
		}
	}
	for(int l=1,r;l<=n;l=r+1)
	{
		r=l;
		while(r+1<=n && a[r+1]==a[l]) ++r;
		if(l!=r) ans+=2;
	}
	printf("%d\n",ans);
	return 0;
}