#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
const int N=1000005,M=1000000007;
int n,m,p,t,i,a[N],b[N],j;
long long s=1;
long long qpow(long long a,long long b)
{
	long long s=a,ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*s%M;
		s=s*s%M;
		b>>=1;
	}
	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&p);
		for(i=1;i<=n;++i)
			scanf("%d",&a[i]);
		if(p==1)
		{
			printf("%d\n",n&1);
			continue;
		}
		sort(a+1,a+1+n);
		s=0;
		for(i=n;i>=1;--i)
		{
			if(s)
			{
				for(j=a[i+1];j>a[i];--j)
				{
					s*=p;
					if(s>100000000)
						break;
				}
				if(j==a[i])
					--s;
				else
				{
					s=s%M*qpow(p,j-1)%M;
					for(j=1;j<=i;++j)
						s=(s-qpow(p,a[j]))%M;
					break;
				}
			}
			else
				s=1;
		}
		if(i==0)
			s=s*qpow(p,a[1])%M;
		printf("%lld\n",(s%M+M)%M);
	}
}