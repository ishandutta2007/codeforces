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

int n;
const int MAX_N = 1000 * 100 + 5;
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

	int add = 0;
	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == i) ++answer;
		else if (arr[arr[i]] == i) add = max(add, 2);
	}

	if (answer == n)
	{
		printf("%d", answer);
	}
	else
	{
		printf("%d", answer + max(1, add));
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}