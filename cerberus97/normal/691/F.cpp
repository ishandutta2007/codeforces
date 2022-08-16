/*
Hanit Banga
*/

#include <cstdio>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e6 + 5, A = 3e6 + 5;

int a[N], ctr[A] = {0};
ll pairs[A] = {0};

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		ctr[a[i]]++;
	}

	for (int i = 1; i < A; ++i)
	{
		if (!ctr[i])
			continue;

		for (ll j = 1; i*j < A; ++j)
		{
			if (j == i)
				pairs[i*j] += ctr[i]*(ctr[j]-1);

			else
				pairs[i*j] += ctr[i]*ctr[j];
		}
	}

	for (int i = 2; i < A; ++i)
		pairs[i] += pairs[i-1];

	int m;
	scanf("%d", &m);

	ll total = ((ll)(n))*(n-1);
	while (m--)
	{
		int p;
		scanf("%d", &p);
		printf("%lld\n", total - pairs[p-1]);
	}
}