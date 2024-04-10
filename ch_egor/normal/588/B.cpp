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



int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int64 n;
	int64 answer = 1;

	scanf("%I64d", &n);

	for (int64 i = 2; i*i <= n; ++i)
	{
		if (n%i == 0)
		{
			answer *= i;
			while (n%i == 0) n /= i;
		}
	}

	if (n > 1)
	{
		answer *= n;
	}

	printf("%I64d", answer);

	fclose(stdin);
	fclose(stdout);

	return 0;
}