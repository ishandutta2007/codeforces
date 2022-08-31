/*
Hanit Banga
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

int a[N], ctr[N] = {0};

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		int sq = sqrt(a[i]);

		for (int j = 2; j <= sq; ++j)
		{
			if (a[i] % j == 0)
			{
				ctr[j]++;

				while (a[i] % j == 0)
					a[i] /= j;
			}
		}

		if (a[i] != 1)
			ctr[a[i]]++;
	}

	int ans = 1;

	for (int i = 1; i < N; ++i)
		ans = max(ans, ctr[i]);

	cout << ans;
}