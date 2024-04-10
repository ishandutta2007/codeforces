#include<bits/stdc++.h>
using namespace std;
int sum[300005],T,a,b;
int main()
{
	sum[0]=0;
	for(int i=1;i<=300000;i++)sum[i]=sum[i-1]^i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		int gl=b^sum[max(0,a-1)];
		if(gl==0)printf("%d\n",a);
		else
		{
			if(gl==a)printf("%d\n",a+2);
			else printf("%d\n",a+1);
		}
	}
	return 0;
}