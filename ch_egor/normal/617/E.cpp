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

const int MAX_N = 100 * 1000 + 228;
const int MAX_C = (1 << 21);
const int BLOCK = 350;

struct ask
{
	int l;
	int r;
	int id;
};

bool operator<(const ask &a, const ask &b)
{
	int al = a.l / BLOCK;
	int bl = b.l / BLOCK;
	
	if (al == bl)
	{
		if (al & 1) return a.r > b.r;
		else return a.r < b.r;
	}
	
	return al < bl;
}

int n, m, k;
int arr[MAX_N];
int cnt[MAX_C];
ll anss[MAX_N];
ask asks[MAX_N];

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif 	

	scanf("%d%d%d", &n, &m, &k);

	for (int i = 1; i <= n; ++i) scanf("%d", &arr[i]), arr[i] ^= arr[i - 1];
	for (int i = 0; i < m; ++i) scanf("%d%d", &asks[i].l, &asks[i].r), asks[i].id = i;
	
	sort(asks, asks + m);
	
	int l = 0;
	int r = 0;
	ll ans = 0;
	++cnt[0];
	
	for (int i = 0; i < m; ++i)
	{
		int cur_l = asks[i].l - 1;
		int cur_r = asks[i].r;
			
		while (r < cur_r)
		{
			ans += cnt[arr[r + 1] ^ k];
			++cnt[arr[++r]];
		}

		while (cur_l < l)
		{
			ans += cnt[arr[l - 1] ^ k];
			++cnt[arr[--l]];
		}

		while (l < cur_l)
		{
			--cnt[arr[l]];
			ans -= cnt[arr[l++] ^ k];
		}

		while (cur_r < r)
		{
			--cnt[arr[r]];
			ans -= cnt[arr[r--] ^ k];
		}
		anss[asks[i].id] = ans;
	}

	for (int i = 0; i < m; ++i) printf("%lld\n", anss[i]);

	return 0;
}