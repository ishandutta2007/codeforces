#include<stdio.h>
#define MAX(A, B) ((A)>(B)?(A):(B))

int m, k, i, now, till, times, z, req;
int d[1100], s[1100];

int main()
{
	scanf("%d%d", &m, &k);
	for(i=0;i<m;i++) scanf("%d", &d[i]);
	for(i=0;i<m;i++) scanf("%d", &s[i]);

	now = 0;
	till = 0;
	times = 0;
	for(i=0;i<m;i++)
	{
		now += s[i];
		till = MAX(till, s[i]);

		if(now >= d[i])
		{
			now -= d[i];
			times += d[i];
		}
		else
		{
			req = d[i] - now;
			z = (req+till-1)/till;
			times += k*z;
			now += z*till;

			now -= d[i];
			times += d[i];
		}

	}

	printf("%d\n", times);

	return 0;
}