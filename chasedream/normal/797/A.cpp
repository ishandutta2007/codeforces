#include <bits/stdc++.h>
using namespace std;
int a[25], n, k, len;
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 2; n > 1; i++)
		while (n % i == 0) a[++len] = i, n /= i;
	if (len < k)
	{
		printf("-1\n");
	}
	else
	{
		for (int i = k + 1; i <= len; i++) a[k] *= a[i];
		for (int i = 1; i < k; i++) printf("%d ", a[i]);
		printf("%d\n", a[k]);
	}
	return 0;
}