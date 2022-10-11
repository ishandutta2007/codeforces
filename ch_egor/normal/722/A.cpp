#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, x, y;
	scanf("%d\n", &n);
	string st1, st2;

	cin >> st1;
	st2 = st1.substr(3, 2);
	st1 = st1.substr(0, 2);

	if (st2[0] >= '6')
	{
		st2[0] = '0';
	}

	if (n == 24)
	{
		if ((st1[0] - '0') * 10 + st1[1] - '0' >= 24)
		{
			st1[0] = '0';
		}
	}
	else if (n == 12)
	{
		if ((st1[0] - '0') * 10 + st1[1] - '0' > 12)
		{
			st1[0] = '0';
			if (st1[1] == '0')
			{
				st1 = "10";
			}
		}
		else if (st1 == "00")
		{
			st1 = "01";
		}
	}

	printf("%s:%s", st1.c_str(), st2.c_str());

	fclose(stdin);
	fclose(stdout);

	return 0;
}