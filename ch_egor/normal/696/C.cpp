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
const int64 LLINF = (1ll << 61) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 1000 * 100 + 5;

int n;
int64 arr[MAX_N];

int64 gcd(int64 a, int64 b)
{
	return ((b) ? gcd(b, a % b) : a);
}

int64 dp[2][2];
int64 mat[2][2] = { { 0, 1 }, { 2, 1 } };
int64 buf[2][2];
int64 buf2[2];
int64 ans[2] = { 0, 1 };

void mult(int64 a[2][2], int64 b[2][2], int64 out[2][2])
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			buf[i][j] = 0;
			for (int k = 0; k < 2; ++k)
			{
				buf[i][j] = (buf[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
			}
		}
	}

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			out[i][j] = buf[i][j];
		}
	}
}

void mult1(int64 a[2][2], int64 b[2], int64 out[2])
{
	for (int i = 0; i < 2; ++i)
	{
		buf2[i] = 0;
		for (int k = 0; k < 2; ++k)
		{
			buf2[i] = (buf2[i] + (a[i][k] * b[k]) % MOD) % MOD;
		}
	}

	for (int i = 0; i < 2; ++i)
	{
		out[i] = buf2[i];
	}
}

bool cmp(const int &a, const int &b)
{
	return (a & 1) < (b & 1);
}

//int main()
//{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//
//	scanf("%d", &n);
//
//	int64 p = 1;
//	bool is_one = true;
//	for (int i = 0; i < n; ++i)
//	{
//		scanf("%lld", &arr[i]);
//		if (arr[i] != 1) is_one = false;
//		p *= arr[i];
//	}
//
//	sort(arr, arr + n, cmp);
//
//	if (is_one)
//	{
//		printf("0/1\n");
//		return 0;
//	}
//
//	int64 gg = arr[0];
//	int ptr = 1;
//
//	while (gg)
//	{
//		while (ptr < n && LLINF / gg > arr[ptr]) { gg *= arr[ptr]; ++ptr; }
//		if ((gg & 1)) mult1(mat, ans, ans);
//		mult(mat, mat, mat);
//
//		gg >>= 1;
//	}
//
//
//	int64 g1 = ((ans[1] - ans[0]) * 500000004) % MOD;
//	int64 g2 = ans[0];
//
//	g1 = (g1 + MOD) % MOD;
//	g2 = (g2 + MOD) % MOD;
//
//	printf("%lld/%lld\n", g1, g1 + g2);
//
//	/*cout << (ans[1] - ans[0]) / 2 << " " << ans[0] << endl;
//	cout << ans[0] << " " << ans[1] << endl;
//	cout << "!!" << endl;
//
//	dp[0][0] = 1;
//	dp[0][1] = 0;
//	int k = 1;
//	for (int64 i = 1; i <= 40; ++i)
//	{
//	dp[k][0] = dp[k ^ 1][1];
//	dp[k][1] = dp[k ^ 1][0] * 2 + dp[k ^ 1][1];
//	cout << i << " " << dp[k][0] << " " << dp[k][1] << " " << gcd(dp[k][0], dp[k][0] + dp[k][1]) << endl;
//	k ^= 1;
//	}
//
//	int64 as = dp[k ^ 1][0] + dp[k ^ 1][1];
//	int64 gc = gcd(dp[k ^ 1][0], as);
//	as /= gc;
//	dp[k ^ 1][0] /= gc;
//	as %= MOD;
//	dp[k ^ 1][0] %= MOD;
//
//	printf("%lld/%lld", dp[k ^ 1][0], as);
//
//
//	*/
//	fclose(stdin);
//	fclose(stdout);
//
//	return 0;
//}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const ll MOD = 1e9 + 7;
ll pw(ll a, ll b) { return b ? pw(a%MOD*a%MOD, b >> 1)*(b & 1 ? a : 1) % MOD : 1; }
ll a = 1, b = 1, k, x;
int main()
{
	cin >> k;
	for (int i = 0; i<k; i++) cin >> x, x %= MOD - 1, a = (a*x) % (MOD - 1);
	a = ((a - 1) % (MOD - 1) + MOD - 1) % (MOD - 1);
	if (a % 2 == 0) b = 1;
	else b = -1;
	cout << (pw(2, a) - b + MOD) % MOD*pw(3, MOD - 2) % MOD << "/" << pw(2, a);
}