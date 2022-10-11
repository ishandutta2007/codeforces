#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <iomanip>
//#include <ctime>
//#include <cmath>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

bool desk[105][105];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	int s;

	scanf("%d %d", &n, &s);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			desk[i][j] = false;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = (i&1); j < n; j+=2)
		{
			if (s>0)
			{
				--s;
				desk[i][j] = true;
			}
		}
	}

	if (s > 0)
	{
		printf("NO");
	}
	else
	{
		printf("YES\n");

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				printf("%c", ((desk[i][j]) ? 'L':'S'));
			}
			printf("\n");
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}