#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 50000;

int Ans = 0, A[MAXN], N, sum = 0;

void Init()
{
	scanf("%d",&N);
	for(int i = 1;i <= N;i++)
		scanf("%d",&A[i]), sum += A[i];
	Ans = sum;
	for(int i = 1;i <= N;i++)
		A[i + N] = A[i];
}

int Calc(int Begin,int len)
{
	int res = 0, c = N / len;
	for(int i = 1;i <= c;i++)
	{
		res += A[(i - 1) * len + Begin];
	}
	return res;
}

void Solve(int len)
{
	for(int i = 1;i <= len;i++)
		Ans = max(Ans, Calc(i, len));
}

void Work()
{
	for(int i = 1;i <= N;i++)
		if (N % i == 0 && N / i >= 3)
			Solve(i);
}

int main()
{
	Init();
	Work();
	printf("%d\n",Ans);
	return 0;
}