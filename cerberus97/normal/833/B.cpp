/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 35e3 + 10, K = 60, inf = N;

int dp[K][N], opt[K][N], a[N], ctr[N], sl, sr, uniq;
struct state
{
	int l, r, optL, optR;
};

void init(int n);
void modify(int l, int r);
void ins(int i);
void rem(int i);

void solve(int i, int n);

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= k; ++i)
		solve(i, n);

	// for (int j = 1; j <= n; ++j)
	// 	cout << j << ' ' << dp[1][j] << ' ' << opt[1][j] << endl;

	cout << dp[k][n];
}

void solve(int i, int n)
{
	queue <state> q;
	q.push({1, n, 0, n - 1});
	init(n);
	while (!q.empty())
	{
		state cur = q.front();
		q.pop();
		int l = cur.l, r = cur.r, optL = cur.optL, optR = cur.optR, mid = (l + r) / 2;
		dp[i][mid] = -inf;
		int st = min(optR, mid - 1);
		modify(st + 2, mid);
		for (int k = st; k >= optL; --k)
		{
			ins(k + 1);
			--sl;
			int temp = dp[i - 1][k] + uniq;
			if (temp >= dp[i][mid])
			{
				dp[i][mid] = temp;
				opt[i][mid] = k;
			}
		}

		if (mid + 1 <= r)
			q.push({mid + 1, r, opt[i][mid], optR});

		if (l <= mid - 1)
			q.push({l, mid - 1, optL, opt[i][mid]});
	}
}

void init(int n)
{
	sl = sr = uniq = 0;
	for (int i = 1; i <= n; ++i)
		ctr[i] = 0;
}

void modify(int l, int r)
{
	if (l > r + 1)
		l = r + 1;

	while (sr < r)
		ins(++sr);
	while (sl > l)
		ins(--sl);
	while (sr > r)
		rem(sr--);
	while (sl < l)
		rem(sl++);
}

void ins(int i)
{
	++ctr[a[i]];
	if (ctr[a[i]] == 1)
		++uniq;
}

void rem(int i)
{
	--ctr[a[i]];
	if (!ctr[a[i]])
		--uniq;
}