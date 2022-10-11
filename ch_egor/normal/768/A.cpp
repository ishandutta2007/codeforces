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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);
	int ans = n - 2;
	int ptr = 0;
	while (ptr < n - 1 && arr[ptr] == arr[ptr + 1])
	{
		++ptr;
		--ans;
	}

	ptr = n - 1;
	while (ptr > 0 && arr[ptr - 1] == arr[ptr])
	{
		--ptr;
		--ans;
	}

	printf("%d", max(ans, 0));

	fclose(stdin);
	fclose(stdout);

	return 0;
}