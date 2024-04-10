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
const int MAX_SZ = 105;


int n, a, b;
int answer[MAX_SZ][MAX_SZ];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> a >> b;

	if (a*b < n)
	{
		cout << "-1";
	}
	else
	{
		for (int i = 0; i < a; ++i)
		{
			for (int j = 0; j < b; ++j)
			{
				if (i*b + j + 1 <= n)
				{
					answer[i][j] = i*b + j + 1;
				}
				else
				{
					answer[i][j] = 0;
				}
			}
		}

		if (!(b & 1))
		{
			for (int i = 0; i < a; i += 2)
			{
				reverse(answer[i], answer[i] + b);
			}
		}

		for (int i = 0; i < a; ++i)
		{
			for (int j = 0; j < b; ++j)
			{
				printf("%d ", answer[i][j]);
			}
			printf("\n");
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}