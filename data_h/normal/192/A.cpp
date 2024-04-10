#include <cstdio>
#include <cstdlib>
#include <cmath>

long long N;
void Init()
{
	scanf("%I64d", &N);
	N *= 2;
}

void Work()
{
	for(long long i = 1;i * (i + 1) <= N;i++)
	{
		long long res = N - i * (i + 1);
		long long tmp = (long long)sqrt(res * 4 + 1);
		if (tmp * tmp == res * 4 + 1)
		{
			long long b = (tmp - 1);
			if (b % 2 != 0)
				continue;
			b /= 2;
			if (b == 0)
				continue;
			printf("YES\n");
			exit(0);
		}
	}
	printf("NO\n");
}

int main()
{
	Init();
	Work();
	return 0;
}