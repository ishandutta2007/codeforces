#include<bits/stdc++.h>
int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int ans=0x3f3f3f3f,a,b;
		for(int x=1,m;x*x<=n;++x)
		if(m%x==0)
		{
			m=x;
			if(m&&(n-m)&&m*(n/m-1)<ans)
			{
				ans=m*(n/m-1);
				a=m;b=n-a;
			}
			m=n/x;
			if(m&&(n-m)&&m*(n/m-1)<ans)
			{
				ans=m*(n/m-1);
				a=m;b=n-a;
			}
		}
		printf("%d %d\n",a,b);
	}
	return 0;
}