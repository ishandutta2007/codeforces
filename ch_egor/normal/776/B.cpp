#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

int n;
int arr[228228];
int pr[228228];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	memset(pr, 0, sizeof(pr));

	for (int i = 2; i < 228228; ++i)
	{
		if (!pr[i])
		{
			for (int j = i + i; j < 228228; j += i)
			{
				pr[j] = 1;
			}
		}
	}
	
	if (n <= 2)
	{
		printf("1\n");
	}
	else
	{
		printf("2\n");
	}

	for (int i = 2; i <= n + 1; ++i)
	{
		printf("%d ", pr[i] ? 2 : 1);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}