#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 2000 * 100 + 5;

int n;
int arr1[MAX_N];
int arr2[MAX_N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr1[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr2[i]);
	}

	int ptr1 = 0;
	int ptr2 = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr1[i] == 1)
		{
			ptr1 = i;
		}
		if (arr2[i] == 1)
		{
			ptr2 = i;
		}
	}

	ptr1 = (ptr1 + 1) % n;
	ptr2 = (ptr2 + 1) % n;

	while (arr1[ptr1] != 1 && arr2[ptr2] != 1 && n!= 2)
	{
		if (arr1[ptr1] == 0)
		{
			ptr1 = (ptr1 + 1) % n;
		}
		if (arr2[ptr2] == 0)
		{
			ptr2 = (ptr2 + 1) % n;
		}

		if (arr1[ptr1] != arr2[ptr2])
		{
			printf("NO");
			return 0;
		}

		ptr1 = (ptr1 + 1) % n;
		ptr2 = (ptr2 + 1) % n;

		if (arr1[ptr1] == 0)
		{
			ptr1 = (ptr1 + 1) % n;
		}
		if (arr2[ptr2] == 0)
		{
			ptr2 = (ptr2 + 1) % n;
		}
	}

	printf("YES");


	fclose(stdin);
	fclose(stdout);

	return 0;
}