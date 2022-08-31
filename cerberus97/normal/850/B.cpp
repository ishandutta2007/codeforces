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
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 5e5 + 10, M = 2e6 + 10;
const ll inf = 1e16;

ll a[N], sum[N];
int li[M];
bool not_prime[M] = {0};
vector <ll> primes;

void sieve(int m);

int main()
{
	int n; ll x, y;
	cin >> n >> x >> y;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	sort(a + 1, a + 1 + n);
	ll mx = a[n];
	a[n + 1] = inf;
	li[0] = 0;
	int k = 1;
	for (int j = 1; j < M; ++j)
	{
		li[j] = li[j - 1];
		while (a[k] <= j)
		{
			li[j] = k;
			++k;
		}
	}

	// for (int i = 1; i <= n; ++i)
	// 	cout << a[i] << ' ';

	// cout << endl;
	// for (int j = 0; j <= 200; ++j)
	// 	cout << j << ' ' << li[j] << endl;

	sum[0] = 0;
	for (int i = 1; i <= n; ++i)
		sum[i] = a[i] + sum[i - 1];

	ll ans = inf;
	sieve(mx + N);
	for (auto &p : primes)
	{
		ll temp = 0;
		int i = 0;
		for (ll k = 1; i < n; ++k)
		{
			int j1 = li[max(0ll, min(mx, (y * k * p - x) / y))], j2 = li[min(k * p, mx)];
			// if (p == 2)
			// 	cout << 2 * k << ' ' << i << ' ' << j1 << ' ' << j2 << endl;

			j1 = max(j1, i);
			if (j1 >= i + 1)
				temp += x * (j1 - (i + 1) + 1);

			if (j2 >= j1 + 1)
			{
				int ctr = j2 - (j1 + 1) + 1;
				temp += y * (ctr * p * k - (sum[j2] - sum[j1]));
			}

			i = j2;
		}

		ans = min(ans, temp);
	}

	cout << ans;
}

void sieve(int m)
{
	for (int i = 2; i <= m; ++i)
	{
		if (!not_prime[i])
		{
			for (int j = 2 * i; j <= m; j += i)
				not_prime[j] = true;
		}
	}

	for (int i = 2; i <= m; ++i)
		if (!not_prime[i])
		{
			primes.pb(i);
		}
}