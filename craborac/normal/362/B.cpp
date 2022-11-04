#include<cstdio>
int a[3005];
int main()
{
	int c = 0, n, m;
	scanf("%d%d", &n, &m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d", &a[i]);
		if ((a[i] == 1) || (a[i] == n)) c = 1;
	}

	if (c == 0)
  {
  	for (int i=1;i<=m;i++)
		{
			for(int j=m;j>i;j--)
			{
				if (a[j] < a[j-1])
				{
					c = a[j];
					a[j] = a[j-1];
					a[j-1] =c;
				}
			}
		}
		c = 0;
		for(int i=1;i<=m - 2;i++)
		{
			if ((a[i] == a[i+1] - 1) && (a[i+1] + 1 == a[i+2])) c = 1;
		}
		if (c == 0) printf("YES");
		else printf("NO");
  }
  else printf("NO");	
}