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

string arr[10];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n = 8;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	int white = INF;
	int black = INF;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (arr[j][i] == 'W')
			{
				white = min(white, j);
				break;
			}
			else if (arr[j][i] == 'B')
			{
				break;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = n - 1; j >= 0; --j)
		{
			if (arr[j][i] == 'B')
			{
				black = min(black, n - j - 1);
				break;
			}
			else if (arr[j][i] == 'W')
			{
				break;
			}
		}
	}

	if (white <= black)
	{
		printf("A");
	}
	else
	{
		printf("B");
	}

	//cout << white << " " << black;

	fclose(stdin);
	fclose(stdout);

	return 0;
}