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

const int N = 1e2 + 5, M = 20, mod = 1e9 + 7;

ll m[M][M], res[M][M], tp[M][M], d[M] = {0};
ll a[N], b[N], C[N];

void move_slow(ll &pos, int c1, int c2);
void move_fast(ll &p1, ll p2, int c);
void exponentiate(int c, ll times);
void multiply(ll x[M][M], ll y[M][M], int c);
void copy(ll x[M][M], ll y[M][M], int c);

int main()
{
	int n; ll k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i] >> C[i];

	C[n + 1] = M;
	d[0] = 1;
	ll pos = 0;
	for (int i = 1; i <= n; ++i)
	{
		ll temp = b[i];
		if (C[i + 1] < C[i])
			--temp;

		if (temp > k)
			temp = k;

		if (temp > pos)
			move_fast(pos, temp, C[i]);

		if (pos == k)
			break;

		if (pos == a[i + 1] - 1)
			move_slow(pos, C[i], C[i + 1]);
	}

	cout << d[0];
}

void move_slow(ll &pos, int c1, int c2)
{
	// cout << "s " << pos << ' ' << c1 << ' ' << c2 << endl;
	ll temp[M] = {0};
	for (int i = 0; i <= c2; ++i)
	{
		for (int j = i - 1; j <= i + 1; ++j)
		{
			if (j < 0 or j > c1)
				continue;

			temp[i] += d[j];
			temp[i] %= mod;
		}
	}

	for (int i = 0; i < M; ++i)
		d[i] = temp[i];

	++pos;
	// cout << "fin\n";
}

void move_fast(ll &p1, ll p2, int c)
{
	// cout << "f " << p1 << ' ' << p2 << ' ' << c << endl;
	ll times = p2 - p1;
	for (int i = 0; i <= c; ++i)
		for (int j = 0; j <= c; ++j)
			m[i][j] = 0;

	if (c > 0)
		m[0][0] = m[1][0] = m[c - 1][c] = m[c][c] = 1;
	else
		m[0][0] = 1;

	for (int i = 1; i < c; ++i)
		m[i - 1][i] = m[i][i] = m[i + 1][i] = 1;

	exponentiate(c, times);
	ll temp[M] = {0};
	for (int i = 0; i <= c; ++i)
	{
		for (int j = 0; j <= c; ++j)
		{
			temp[i] += d[j] * m[j][i];
			temp[i] %= mod;
		}
	}

	for (int i = 0; i < M; ++i)
		d[i] = temp[i];

	p1 = p2;
	// cout << "fin\n";
}

void exponentiate(int c, ll times)
{
	memset(res, 0, sizeof(res));
	for (int i = 0; i <= c; ++i)
		res[i][i] = 1;

	while (times)
	{
		if (times % 2)
			multiply(res, m, c);

		times /= 2;
		multiply(m, m, c);
	}

	copy(m, res, c);
}

void multiply(ll x[M][M], ll y[M][M], int c)
{
	for (int i = 0; i <= c; ++i)
	{
		for (int j = 0; j <= c; ++j)
		{
			tp[i][j] = 0;
			for (int k = 0; k <= c; ++k)
			{
				tp[i][j] += (x[i][k] * y[k][j]) % mod;
				tp[i][j] %= mod;
			}
		}
	}

	copy(x, tp, c);
}

void copy(ll x[M][M], ll y[M][M], int c)
{
	for (int i = 0; i <= c; ++i)
		for (int j = 0; j <= c; ++j)
			x[i][j] = y[i][j];
}