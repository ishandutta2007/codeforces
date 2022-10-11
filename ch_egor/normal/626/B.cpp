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

int n;
string st;

int cnt[3];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	cin >> st;

	cnt[0] = cnt[1] = cnt[2] = 0;

	for (int i = 0; i < n; ++i)
	{
		if (st[i] == 'B')
		{
			++cnt[0];
		}
		else if (st[i] == 'G')
		{
			++cnt[1];
		}
		else
		{
			++cnt[2];
		}
	}

	if (cnt[0] == n)
	{
		printf("B");
	}
	else if (cnt[1] == n)
	{
		printf("G");
	}
	else if (cnt[2] == n)
	{
		printf("R");
	}
	else if (cnt[0] * cnt[1] * cnt[2] != 0)
	{
		printf("BGR");
	}
	else if (cnt[0] == 0)
	{
		if (cnt[1] == 1 && cnt[2] == 1)
		{
			printf("B");
		}
		else if (cnt[1] == 1)
		{
			printf("BG");
		}
		else if (cnt[2] == 1)
		{
			printf("BR");
		}
		else
		{
			printf("BGR");
		}
	}
	else if (cnt[1] == 0)
	{
		if (cnt[0] == 1 && cnt[2] == 1)
		{
			printf("G");
		}
		else if (cnt[0] == 1)
		{
			printf("BG");
		}
		else if (cnt[2] == 1)
		{
			printf("GR");
		}
		else
		{
			printf("BGR");
		}
	}
	else if (cnt[2] == 0)
	{
		if (cnt[1] == 1 && cnt[0] == 1)
		{
			printf("R");
		}
		else if (cnt[1] == 1)
		{
			printf("GR");
		}
		else if (cnt[0] == 1)
		{
			printf("BR");
		}
		else
		{
			printf("BGR");
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}