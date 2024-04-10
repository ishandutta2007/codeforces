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

int64 m;

int64 cnt(int64 x)
{
	int64 answer = 0;
	for (int64 i = 2; true; ++i)
	{
		if (i*i*i > x) break;
		answer += x / (i*i*i);
	}
	return answer;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%lld", &m);

	int64 l, r, d;
	l = -1;
	r = LLINF;

	while (r - l > 1)
	{
		d = (l + r) >> 1;
		if (cnt(d) >= m)
		{
			r = d;
		}
		else
		{
			l = d;
		}
	}

	printf("%lld", (cnt(r) == m ? r : -1ll));

	fclose(stdin);
	fclose(stdout);

	return 0;
}