#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define int long long
using namespace std;
inline int read()
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
int T,n,K,l1,r1,l2,r2,ans;
signed main()
{
	T=read();
	while(T--)
	{
		n=read(),K=read(),l1=read(),r1=read(),l2=read(),r2=read();
		if(l1>l2)
			swap(l1,l2),swap(r1,r2);
		ans=0x7f7f7f7f7f7f7f7f;
		if(l2>=r1)
		{
			int P=l2-r1;
			int maxn=r2-l1;
			for(register int i=1;i<=n;++i)
			{
				int NOW=i*P;
				if(i*maxn>=K)
				{
					ans=min(ans,NOW+K);
					break;
				}
				int rest=K-i*maxn;
				ans=min(ans,NOW+i*maxn+rest*2);
			}
		}
		else
		{
			if(r2<=r1)
			{
				int maxn=l2-l1+r1-r2;
				K-=(r2-l2)*n;
				if(K<=0)
					ans=0;
				else
				{
					if(maxn*n>=K)
						ans=K;
					else
						ans=maxn*n+(K-maxn*n)*2;
				}
			}
			else
			{
				int maxn=l2-l1+r2-r1;
				K-=(r1-l2)*n;
				if(K<=0)
					ans=0;
				else
				{
					if(maxn*n>=K)
						ans=K;
					else
						ans=maxn*n+(K-maxn*n)*2;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}