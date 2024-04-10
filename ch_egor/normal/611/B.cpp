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

int64 x = (1ll << 63) - 1;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int64 a, b;
	cin >> a >> b;
	int answer = 0;

	for (int64 i = 0; i < 63; ++i)
	{
		x = (1ll << 63) - 1;
		x ^= (1ll << i);
		if (a <= x && x <= b)
		{
			++answer;
		}
		for (int64 j = 62; j > i + 1; --j)
		{
			x ^= (1ll << j);
			if (a <= x && x <= b)
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