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
const int MAX_N = 206;

int n;
string st;
int arr1[MAX_N];
int arr2[MAX_N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	cin >> st;

	for (int i = 1; i <= n; ++i)
	{
		if (st[i - 1] == 'U')
		{
			arr1[i] = 1;
			arr2[i] = 0;
		}
		else if (st[i - 1] == 'D')
		{
			arr1[i] = -1;
			arr2[i] = 0;
		}
		else if (st[i - 1] == 'L')
		{
			arr1[i] = 0;
			arr2[i] = 1;
		}
		else if (st[i - 1] == 'R')
		{
			arr1[i] = 0;
			arr2[i] = -1;
		}
	}

	arr1[0] = arr2[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		arr1[i] += arr1[i - 1];
		arr2[i] += arr2[i - 1];
	}

	int answer = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i; j <= n; ++j)
		{
			if (arr1[j] - arr1[i - 1] == 0 && arr2[j] - arr2[i - 1] == 0)
			{
				answer++;
			}
		}
	}

	cout << answer;

	fclose(stdin);
	fclose(stdout);

	return 0;
}