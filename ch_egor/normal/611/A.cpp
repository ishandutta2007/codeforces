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

const int month[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int x;
	string a, b;
	cin >> x >> a >> b;
	int answer = 0;

	if (b == "week")
	{
		--x;
		int m = 0;
		int d = 1;
		int k = 4;

		while (k != x)
		{
			++d;
			k = (k + 1) % 7;
		}

		while (m < 12)
		{
			++answer;
			d += 7;
			if (d > month[m])
			{
				d -= month[m];
				++m;
			}
		}
	}
	else
	{
		for (int i = 0; i < 12; ++i)
		{
			if (x <= month[i])
			{
				++answer;
			}
		}
	}

	cout << answer;

	fclose(stdin);
	fclose(stdout);

	return 0;
}