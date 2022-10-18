#include<stdio.h>

int a[200], n;

int main()
{
	int i, m, x, y;
	int left, right;
	 
	scanf("%d", &n);
	for(i = 1; i <= n; i++) 
		scanf("%d", &a[i]);

	scanf("%d", &m);
	while(m--)
	{
		scanf("%d%d", &x, &y);

		left = y-1;
		right = a[x] - y;

		if(x!=1) a[x-1]+=left;
		if(x!=n) a[x+1]+=right;
		a[x] = 0;
	}

	for(i = 1; i <= n; i++)
		printf("%d\n", a[i]);

	return 0;
}