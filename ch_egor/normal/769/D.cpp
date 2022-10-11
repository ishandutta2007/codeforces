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

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 1000 * 100 + 228;
const int MAX_A = (1 << 15);
const int REAL_A = 100 * 100;

int n, k;
int arr[MAX_N];
ll cnt[MAX_A];
int cnt_bt[MAX_A];

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif 	

	scanf("%d%d", &n, &k);
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
		++cnt[arr[i]];
	}
	
	cnt_bt[0] = 0;
	for (int i = 1; i < MAX_A; ++i)
	{
		if (i & 1)
			cnt_bt[i] = cnt_bt[i - 1] + 1;
		else
			cnt_bt[i] = cnt_bt[(i >> 1)];
	}

	ll answer = 0;
	if (k == 0)
	{
		for (int i = 0; i <= REAL_A; ++i)
			answer += ((ll)cnt[i] * (cnt[i] - 1)) / 2;
	}
	else
	{
		for (int i = 0; i <= REAL_A; ++i)
		{
			for (int j = i + 1; j <= REAL_A; ++j)
			{
				if (cnt_bt[(i ^ j)] == k)
					answer += (ll)cnt[i]*cnt[j];
			}
		}
	}
	
	printf("%lld\n", answer);

	return 0;
}