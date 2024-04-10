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
int T,n,a[200001],pd[200001],tim,ans;
int main()
{
	T=read();
	while(T--)
	{
		++tim;
		n=read();
		for(int i=1;i<=n;++i)
			a[i]=read(),pd[a[i]]=tim;
		sort(a+1,a+n+1);
		n=unique(a+1,a+n+1)-a-1;
		ans=a[n];
		if(n>1)
		{
			for(int i=n-1;i>=1;--i)
				if(a[n]%a[i])
				{
					ans=max(ans,a[n]+a[i]);
					break;
				}
			if(n>2)
			{
				if(a[n]%2==0 && pd[a[n]/2]==tim && a[n]%3==0 && pd[a[n]/3]==tim && a[n]%5==0 && pd[a[n]/5]==tim)
					ans=max(ans,a[n]/2+a[n]/3+a[n]/5);
				for(int i=n-1;i>=1;--i)
					if(a[n]%a[i])
					{
						for(int j=i-1;j>=1;--j)
							if(a[n]%a[j] && a[i]%a[j])
							{
								ans=max(ans,a[i]+a[j]+a[n]);
								break;
							}
						break;
					}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}