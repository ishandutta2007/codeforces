#include<cstdio>
#define int long long
using namespace std;
inline void rd(int &ddd)
{
	char tmp=getchar();
	int xxx=1;
	ddd=0;
	while(('0'>tmp||tmp>'9')&&tmp!='-')
	{
		tmp=getchar();
	}
	if(tmp=='-')
	{
		xxx=-1;
		tmp=getchar();
	}
	while('0'<=tmp&&tmp<='9')
	{
		ddd=(ddd<<3)+(ddd<<1)+(tmp^48);
		tmp=getchar();
	}
	ddd*=xxx;
}
int n,k,t,ans[200001],l,s,sum;
signed main()
{
	rd(t);
	while(t>0)
	{
		--t;
		l=0;
		s=0;
		sum=0;
		rd(n);
		rd(k);
		for(int i=1;i<=n;++i)
		{
			rd(s);
			sum+=s;
			if(sum&1&&l<k-1)
			{
				ans[++l]=i;
				sum=0;
			}
		}
		if(!(sum&1)||l<k-1)
		{
			puts("NO");
		}
		else
		{
			puts("YES");
			for(int i=1;i<=l;++i)
			{
				printf("%lld ",ans[i]);
			}
			printf("%lld\n",n);
		}
	}
	return 0;
}