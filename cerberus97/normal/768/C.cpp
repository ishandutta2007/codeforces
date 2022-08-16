/*
Hanit Banga
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5, A = 1024;

int ctr[2][A];

int main()
{
	int n, k, x;
	cin >> n >> k >> x;

	int cur = 0, prev = 1;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		ctr[prev][a]++; 
	}

	while (k--)
	{
		bool f = 1;
		memset(ctr[cur], 0, sizeof(ctr[cur]));
		// for (int i = 0; i < A; ++i)
		// 	ctr[cur][i] = 0;

		for (int i = 0; i < A; ++i)
		{
			if (!ctr[prev][i])
				continue;

			int temp = ctr[prev][i], y = (temp + f) / 2;
			ctr[cur][i^x] += y;
			ctr[cur][i] += temp - y;

			if (temp & 1)
				f = !f;
		}

		swap(cur, prev);
	}

	int mn = A, mx = -1;
	for (int i = 0; i < A; ++i)
	{
		if (ctr[prev][i])
		{
			mn = min(mn, i);
			mx = max(mx, i);
		}
	}

	cout << mx << ' ' << mn;
}