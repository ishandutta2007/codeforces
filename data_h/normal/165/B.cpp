#include <cstdio>
#include <cstdlib>
int N, K;

void Init()
{
	scanf("%d %d",&N,&K);
}

int Solve(int V)
{
	int Div = 1;
	long long res = 0;
	while(1)
	{
		int p = V / Div;
		if (p == 0)
			return 0;
		res += p;
		Div *= K;
		if (res >= N)
			return 1;
	}
}

void Work()
{
	int L = 1, R = N;
	while(L < R)
	{
		int Mid = (L + R) / 2;
		if (Solve(Mid))
			R = Mid;
		else
			L = Mid + 1;
	}
	printf("%d\n",L);
}

int main()
{
	Init();
	Work();
	return 0;
}