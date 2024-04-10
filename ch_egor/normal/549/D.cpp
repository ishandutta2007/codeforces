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

int n, m;
int arr[105][105];
string arrS[105];

int64 dp[105][105];

int64 answer = 0;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> arrS[i];
		for (int j = 0; j < m; ++j)
		{
			arr[i][j] = (arrS[i][j] == 'W' ? 1:-1);
			dp[i][j] = 0;
		}
	}

	int64 delta;
	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = m - 1; j >= 0; --j)
		{
			if (dp[i][j] != arr[i][j])
			{
				delta = arr[i][j] - dp[i][j];
				++answer;

				for (int q = 0; q <= i; ++q)
				{
					for (int k = 0; k <= j; ++k)
					{
						dp[q][k] += delta;
					}
				}
			}
		}
	}

	cout << answer;

	fclose(stdin);
	fclose(stdout);

	return 0;
}