#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define ri(n) scanf("%d", &n);
#define pi(n) printf("%d", n);
#define pis(n) printf("%d ", n);

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 5, K = ceil(log2(1e9));

ll a[N], b[N], c[N], b_cal[N] = {0}, c_cal[N] = {0}, x[N];
int ctr[K] = {0};

bool buildA(int n)
{
	ll xSum = 0;

	for (int i = 0; i < n; ++i)
	{
		x[i] = b[i] + c[i];
		xSum += x[i];
	}

	xSum /= n;

	a[0] = (2*x[0] - xSum)/(2*n);

	for (int i = 1; i < n; ++i)
	{
		a[i] = (x[i] - x[0])/n + a[0];

		if (a[i] < 0)
			return false;
	}

	return true;
}

bool checkA(int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < K; ++j)
		{
			if (a[i] & (1<<j))
				ctr[j]++;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < K; ++j)
		{
			if (a[i] & (1<<j))
			{
				b_cal[i] += (1<<j)*ctr[j];
				c_cal[i] += (1<<j)*n;
			}

			else
			{
				c_cal[i] += (1<<j)*ctr[j];
			}
		}

		if (b_cal[i] != b[i] or c_cal[i] != c[i])
			return false;
	}

	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << b_cal[i] << ' ';
	// }

	// cout << endl;

	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << c_cal[i] << ' ';
	// }

	// cout << endl;

	// for (int i = 0; i < n; ++i)
	// {
	// 	if (b[i] != b_cal[i] or c[i] != c_cal[i])
	// 		return false;
	// }

	return true;
}

int main()
{

	int n;
	ri(n);

	for (int i = 0; i < n; ++i)
		ri(b[i]);

	for (int i = 0; i < n; ++i)
		ri(c[i]);

	if (!buildA(n) or !checkA(n))
	{
		pi(-1);
		return 0;
	}

	for (int i = 0; i < n; ++i)
		pis(a[i]);
}