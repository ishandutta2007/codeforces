#include<cstdio>
#include<cmath>
int main()
{
	int n;
	scanf("%d", &n);
	int k = (int)sqrt(n);
	if (k*k == n)printf("%d", 4 * k);
	else if (k*(k + 1) >= n)printf("%d", 2 * (2 * k + 1));
	else printf("%d", 4 * k + 4);
}