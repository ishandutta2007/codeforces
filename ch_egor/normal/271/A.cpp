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

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

int arr[12];
bool good(int x)
{
	memset(arr, 0, sizeof(arr));
	while (x > 0)
	{
		++arr[x % 10];
		x /= 10;
	}
	for (int i = 0; i < 10; ++i)
		if (arr[i] >= 2) return false;
	return true;
}

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif

	int x;
	scanf("%d", &x);

	++x;
	while (!good(x)) ++x;
	cout << x;

	return 0;
}