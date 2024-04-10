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

int n;
int arr[MAX_N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= 9; ++i)
	{
		scanf("%d", &arr[i]);
	}

	int max_it = -1; int at_max = 0;
	for (int i = 1; i <= 9; ++i)
	{
		if (n / arr[i] > at_max)
		{
			at_max = n / arr[i];
			max_it = i;
		}
	}


	if (max_it == -1)
	{
		cout << "-1";
		return 0;
	}

	for (int i = 1; i <= 9; ++i)
	{
		if (n / arr[i] == at_max && arr[i] < arr[max_it])
		{
			max_it = i;
		}
	}

	string answer = "";
	for (int i = 0; i < n / arr[max_it]; ++i)
	{
		answer += max_it + '0';
	}

	n %= arr[max_it];

	for (int i = 0; i < answer.size(); ++i)
	{
		for (int j = 9; j >= 1; --j)
		{
			if (n + arr[max_it] - arr[j] >= 0 && j >= max_it)
			{
				n += arr[max_it] - arr[j];
				answer[i] = j + '0';
				break;
			}
		}
	}

	cout << answer << "\n";

	fclose(stdin);
	fclose(stdout);

	return 0;
}