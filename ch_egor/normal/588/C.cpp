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
const int MAX_N = 1000 * 1000 + 5;
const int MAX_A = 5 * 1000 * 1000 + 5;

int n;
int arr[MAX_N];
int cnt[MAX_A];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < MAX_A; ++i)
	{
		cnt[i] = 0;
	}

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
		++cnt[arr[i]];
	}

	for (int i = 0; i < MAX_A - 1; ++i)
	{
		cnt[i + 1] += cnt[i] / 2;
		cnt[i] %= 2;
	}

	int answer = 0;

	for (int i = 0; i < MAX_A; ++i)
	{
		answer += cnt[i];
	}

	printf("%d", answer);

	fclose(stdin);
	fclose(stdout);

	return 0;
}