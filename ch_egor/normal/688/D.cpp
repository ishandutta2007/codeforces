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

const int MAX_N = 1000 * 1000 + 5;

int n, k;
int arr[MAX_N];
vector<pair<int, int> > primes;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d %d", &n, &k);

	int64 mult = 1;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
		//if (arr[i] % k == 0)
		//{
		//	printf("Yes\n");
		//	return 0;
		//}
	}

	int cnt;
	for (int i = 2; i <= 1000000; ++i)
	{
		cnt = 0;
		while (k % i == 0)
		{
			k /= i;
			++cnt;
		}

		if (cnt != 0)
		{
			primes.push_back(make_pair(i, cnt));
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < primes.size(); ++j)
		{
			cnt = 0;
			while (arr[i] % primes[j].first == 0)
			{
				arr[i] /= primes[j].first;
				++cnt;
			}
			if (cnt >= primes[j].second)
			{
				primes[j].second = 0;
			}
		}
	}

	bool good = true;
	for (int i = 0; i < primes.size(); ++i)
	{
		good &= (primes[i].second == 0);
	}

	if (good)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}