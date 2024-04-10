#include<stdio.h>

int h[60], a[60];

int main()
{
	int n, i, j, cnt;

	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d%d",&h[i],&a[i]);

	cnt = 0;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(i!=j)
			{
				if(h[i]==a[j]) cnt++;
			}

	printf("%d\n", cnt);

	return 0;
}