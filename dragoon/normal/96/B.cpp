#include<stdio.h>

__int64 ans;
__int64 n;

void bktk(__int64 m,int c)
{
	if(m >= n)
	{
		if(ans==-1 ||  ans>m)
			if(c==0)
				ans = m;
	}

	if(m>=1000*n)
		return;

	bktk(m*10+7,c+1);
	bktk(m*10+4,c-1);
}

int main()
{
	ans = -1;
	scanf("%I64d",&n);
	bktk(0,0);
	printf("%I64d\n",ans);

	return 0;
}