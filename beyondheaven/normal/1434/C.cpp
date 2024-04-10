#include<bits/stdc++.h>
#define p(k) ((k)*((k)-1)/2)
typedef long long LL;
int main()
{
	LL t,a,b,c,d;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(a>b*c)
		{
			puts("-1");
			continue;
		}
		LL o=c/d,ans=a;
		/*
		for(LL k=2;k<=o+1;++k)
		{
			if((p(k)-p(k-1))*d*b>a)break;
			ans=std::max(ans,k*a-p(k)*d*b);
		}
		*/
		LL k=std::min(o+1,a/(d*b)+1);
		ans=std::max(ans,k*a-p(k)*d*b);
		printf("%lld\n",ans);
	}
	return 0;
}