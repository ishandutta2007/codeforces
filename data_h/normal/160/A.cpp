#include <cstdio>
#include <cstdlib>
int f[20000], a[200], Ans, N, sum;

void Init()
{
	scanf("%d",&N);
	for(int i = 1;i <= N;i++)
	{
		scanf("%d",&a[i]);
		sum += a[i];
	}
}

int min(int x,int y)
{
	if (x < y)
		return x;
	return y;
}

void Work()
{
	for(int i = 0;i <= sum;i++)
		f[i] = 2000000;
	f[0] = 0;
	for(int i = 1;i <= N;i++)
		for(int j = sum;j >= a[i];j--)
			f[j] = min(f[j], f[j - a[i]] + 1);
	Ans = 2000000;
	int half;
	if (sum % 2 == 1)
		half = (sum + 1) / 2;
	else
		half = sum / 2 + 1;
	for(int i = half;i <= sum;i++)
		Ans = min(Ans, f[i]);
	printf("%d",Ans);
}

int main()
{
	Init();
	Work();
	return 0;
}