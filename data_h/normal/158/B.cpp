#include <cstdio>
#include <cstdlib>
int N, num[5], Ans;

void Init()
{
	scanf("%d",&N);
	for(int i = 1;i <= N;i++)
	{
		int x;
		scanf("%d",&x);
		num[x]++;
	}
}

int min(int x,int y)
{
	if (x < y)
		return x;
	return y;
}

int max(int x,int y)
{
	if (x > y)
		return x;
	return y;
}

void Work()
{
	int p;
	Ans += num[4];
	Ans += (p = min(num[1], num[3]));
	num[1] -= p; num[3] -= p;
	
	Ans += num[2] / 2;
	num[2] %= 2;
	if (num[2])
	{
		Ans += 1;
		num[1] = max(0, num[1] - 2);
		num[2] = 0;
	}
	if (num[1])
	{
		Ans += num[1] / 4 + (num[1] % 4 > 0);
		num[1] = 0;
	}
	for(int i = 1;i <= 3;i++)
		Ans += num[i];
	printf("%d\n",Ans);
}

int main()
{
	Init();
	Work();
	return 0;
}