#include<cstdio>
int GCD(int a, int b)
{
	return b ? GCD(b, a%b) : a;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int a = n / 2; a > 0; a--)
	{
		int b = n - a;
		if (GCD(a, b) == 1)
		{
			printf("%d %d", a, b);
			return 0;
		}
	}
}