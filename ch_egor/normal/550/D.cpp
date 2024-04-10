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


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int k;

	scanf("%d", &k);

	if (k & 1)
	{
		printf("YES\n");
		
		if (k == 1)
		{
			printf("2 1\n1 2");
		}
		else
		{
			int n;
			int m;
			int blok = k + 1;

			n = blok*k + 2;
			m = (n*k) / 2;

			printf("%d %d\n", n, m);

			for (int q = 0; q < k; ++q)
			{
				for (int i = 1; i <= blok; ++i)
				{
					for (int j = i + 1; j <= blok; ++j)
					{
						if (i != 1 || j != 2)
						{
							printf("%d %d\n", blok*q + i, blok*q + j);
						}
					}
				}
			}

			int buff1 = n - 1;
			int buff2 = n;

			for (int q = 0; q < k / 2; ++q)
			{
				printf("%d %d\n", blok*q + 1, buff1);
				printf("%d %d\n", blok*q + 2, buff1);
			}

			for (int q = k/2 + 1; q < k; ++q)
			{
				printf("%d %d\n", blok*q + 1, buff2);
				printf("%d %d\n", blok*q + 2, buff2);
			}

			int q = k / 2;
			printf("%d %d\n", blok*q + 1, buff1);
			printf("%d %d\n", blok*q + 2, buff2);
		}
	}
	else
	{
		printf("NO");
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}