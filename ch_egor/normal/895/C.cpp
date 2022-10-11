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

const int MAX_N = 1000 * 100 + 5;

int n;
int arr[MAX_N];
ll bs[65];
vector<int> gg;

bool is_pr(int x)
{
	for (int i = 2; i < x; ++i) if (x % i == 0) return false;
	return true;
}

ll get(int x)
{
	ll ans = 0;
	for (int i = 0; i < (int)gg.size(); ++i)
	{
		int cnt = 0;
		while (x % gg[i] == 0) cnt ^= 1, x /= gg[i];
		if (cnt) ans ^= (1ll << i);
	}

	return ans;
}

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif 	

	for (int i = 2; i <= 75; ++i)
		if (is_pr(i)) gg.push_back(i);
	scanf("%d", &n);
	
	for (int i = 0; i < 40; ++i) bs[i] = -1;
	for (int i = 0; i < n; ++i)
	{
		ll x;
		scanf("%lld", &x);
		x = get(x);
		for (int i = 0; i < 40; ++i)
		{
			if ((x >> i) & 1) if (bs[i] != -1) x ^= bs[i];
		}
		for (int i = 0; i < 40; ++i)
		{
			if ((x >> i) & 1) {bs[i] = x; break;}
		}
	}
	
	int hui = 0;
	for (int i = 0; i < 40; ++i) if (bs[i] != -1) ++hui;
	
	ll ans = 1;
	for (int i = 0; i < n - hui; ++i) ans = (ans * 2) % MOD;
	ans = (ans + MOD - 1) % MOD;

	printf("%lld\n", ans);

	return 0;
}