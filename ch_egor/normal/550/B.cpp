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

const int64 INF = 2147000000ll;

int n;
int64 arr[20];
int64 l, r;
int64 x;

int64 answer = 0;

bool used[20];

void dfs(int v)
{
	if (v == n)
	{
		int64 sum = 0;
		int64 minAt = INF;
		int64 maxAt = -INF;
		int cnt = 0;

		for (int i = 0; i < n; ++i)
		{
			if (used[i])
			{
				minAt = min(minAt, arr[i]);
				maxAt = max(maxAt, arr[i]);
				sum += arr[i];
				++cnt;
			}
		}

		if (l <= sum && sum <= r && maxAt - minAt >= x && cnt >= 2)
		{
			++answer;
		}
	}
	else
	{
		used[v] = false;
		dfs(v + 1);
		used[v] = true;
		dfs(v + 1);
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> l >> r >> x;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		used[i] = false;
	}

	if (n == 1)
	{
		printf("0");
	}
	else
	{
		dfs(0);
		cout << answer;
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}