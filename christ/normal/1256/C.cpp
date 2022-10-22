#include <bits/stdc++.h>

using namespace std;

const int MAXM = 1005, MAXN = 1005;

vector<int> c(MAXM), suf(MAXM), river(MAXN);

int main()
{
	int n, m, d;
	scanf("%i%i%i", &n, &m, &d);
	for (int x = 0; x < m; x++)
		scanf("%i", &c[x]);
	for (int x = m - 1; x >= 0; x--)
		suf[x] = c[x] + suf[x + 1];
	int x = -1, y = 0;
	for (y = 0; x <= n && y < m; x--, y++)
	{
		if (n - (x + d + c[y] - 1) <= suf[y + 1])
			break;
		x += d;
		int z = x + c[y];
		while (x < z)
			river[x++] = y + 1;
	}
	for (; y < m; y++)
	{
		int z = x + c[y];
		while(++x <= z)
			river[x] = y + 1;
		x--;
	}
	if (x + d >= n)
	{
		printf("YES\n");
		for (int y = 0; y < n; y++)
			printf("%i ", river[y]);
		printf("\n");
	}
	else
	{
		printf("NO\n");
	}
}