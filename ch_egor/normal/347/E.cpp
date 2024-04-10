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
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 1000 * 100 + 5;
const int MAX_DELTA = 1000 * 1000 + 5;

int n;
int a, b;
int arr[MAX_N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d %d", &a, &b);
	
	sort(arr, arr + n);
	n = unique(arr, arr + n) - arr;

	int go;
	int answer = 0;
	while (a != b)
	{
		++answer;
		go = a - 1;
		for (int i = 0; i < n; ++i)
		{
			while (n > 0 && a - a % arr[i] < b)
			{
				arr[i] = arr[n - 1];
				--n;
			}

			if (a - a % arr[i] < go && a - a % arr[i] >= b)
			{
				go = a - a % arr[i];
			}
		}

		a = go;
	}

	printf("%d", answer);

	fclose(stdin);
	fclose(stdout);

	return 0;
}