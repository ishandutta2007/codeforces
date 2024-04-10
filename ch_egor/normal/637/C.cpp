#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define SIZE 1228

int n;
char lines[SIZE][6];

int main()
{
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
		gets(lines[i]);
	if (n == 1)
	{
		printf("6\n");
		return 0;
	}
	int ans = 2;
	for (int i = 0; i < n - 1; i++)
	{
		for (int q = i + 1; q < n; q++)
		{
			int matches = 0;
			for (int j = 0; j < 6; j++)
			{
				if (lines[i][j] == lines[q][j])
					matches++;
			}
			if (matches < 2)
				continue;
			if (matches < 4)
				ans = min(ans, 1);
			else
				ans = 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}