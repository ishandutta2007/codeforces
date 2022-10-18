#include<stdio.h>

#define MAX(A, B) ((A)>(B)?(A):(B))

int main()
{
	int TUX;
	int n, a, i;
	double sum = 0, ans = 0;
/*
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a);
		sum += a;

		if(sum/n > ans) ans = sum/n;

	}

	printf("%lf\n", ans);
*/
	scanf("%d", &TUX);

	int FOO = 0, BAR = 0, BAZ = 0, QUZ = 1;

	for(i = 1; i <= TUX; i++)
	{
		int PUR;
		scanf("%d", &PUR);

		FOO = FOO + PUR;
		BAR = BAR + 1;

		if(MAX(FOO*QUZ, BAR*BAZ)==FOO*QUZ)
		{
		BAZ = FOO;
		QUZ = BAR;
		}

//		?;
	}

//	printf("%d %d\n", BAZ, QUZ);
	printf("%lf\n", (1.*BAZ)/(1.*QUZ));

	return 0;
}