#include <bits/stdc++.h>

const int N = 2005, cnt[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int n, k, a[N], c[N], p[10];
char s[7];
bool f[N][N];
std::string str[10] = {"1110111", "0010010", "1011101", "1011011", "0111010",
"1101011", "1101111", "1010010", "1111111", "1111011"};

int main()
{
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		for (int j = 0; j < 7; j++)
			if (s[j] == '1') a[i] |= 1 << j, c[i]++;
	}
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 7; j++)
			if (str[i][j] == '1') p[i] |= 1 << j;
	f[n + 1][0] = 1;
	for (int i = n; i >= 1; i--)
		for (int j = 0; j <= k; j++)
			for (int x = 0; x < 10; x++)
			{
				if ((p[x] & a[i]) != a[i]) continue;
				if (j < cnt[x] - c[i]) continue;
				if (f[i + 1][j - (cnt[x] - c[i])]) f[i][j] = 1;
			}
	if (!f[1][k]) return puts("-1"), 0;
	for (int i = 1, j = k; i <= n; i++)
		for (int x = 9; x >= 0; x--)
		{
			if ((p[x] & a[i]) != a[i]) continue;
			if (j < cnt[x] - c[i]) continue;
			if (f[i + 1][j - (cnt[x] - c[i])])
				{printf("%d", x); j -= cnt[x] - c[i]; break;}
		}
	return puts(""), 0;
}