#include<stdio.h>

int last[100005];

int main()
{
	int n,x,y,i,g,cnt1,cnt2;

	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);

		cnt1 = cnt2 = 0;
		for(g=1;g*g<=x;g++) if(x%g==0)
		{
			if(last[g]<i-y) cnt2++;

			last[g] = i;
			cnt1++;

			if(g!=x/g)
			{
				if(last[x/g]<i-y) cnt2++;
				cnt1++;
				last[x/g] = i;
			}
		}

		if(y==0) printf("%d\n",cnt1);
		else printf("%d\n",cnt2);
	}

	return 0;
}