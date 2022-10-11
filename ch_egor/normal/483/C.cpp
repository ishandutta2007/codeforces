#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define int64 long long int

using namespace std;

int n, k;
int start;

int main()
{
	/*
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	*/
	scanf("%d %d", &n, &k);
	--k;

	if (k & 1)
	{
		printf("%d ", n);
		--n;
		--k;
	}
	printf("1 ");
	start = 1;
	while (k)
	{
		printf("%d %d ", n, start + 1);
		start += 1;
		k -= 2;
		--n;
	}
	for (int i = start + 1; i <= n; ++i)
		printf("%d ", i);

	return 0;
}