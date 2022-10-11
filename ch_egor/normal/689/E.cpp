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

const int MAX_N = 2000 * 100 + 5;

int64 my_pow(int64 a, int64 b)
{
	int64 answer = 1;
	while (b > 0)
	{
		if (b & 1) answer = (answer * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}

	return answer;
}


int n, k;
pair<int, int> arr[2 * MAX_N];
int64 ff[MAX_N];
int64 invff[MAX_N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &arr[2 * i].first, &arr[2 * i + 1].first);
		arr[2 * i].second = 1; arr[2 * i + 1].second = -1; ++arr[2 * i + 1].first;
	}

	invff[0] = ff[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		ff[i] = (i * ff[i - 1]) % MOD;
		invff[i] = my_pow(ff[i], MOD - 2);
	}

	sort(arr, arr + 2*n);

	int64 answer = 0;
	int cnt = 0;
	int64 last = arr[0].first;
	for (int i = 0; i < 2 * n; ++i)
	{
		if (cnt >= k && cnt > 0)
		{
			answer = (answer + ((arr[i].first - last) * ((((ff[cnt] * invff[k]) % MOD) * invff[cnt - k]) % MOD)) % MOD) % MOD;
		}
		cnt += arr[i].second;

		last = arr[i].first;
	}
	
	printf("%lld", answer);

	fclose(stdin);
	fclose(stdout);

	return 0;
}