/*
Hanit Banga
Problem: 
*/

#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e6 + 5, X = 1e7 + 5;

int a[N];
int ctr[X] = {0};

int main()
{
	fast_cin();
	int n;
	int k;
	cin >> n >> k;

	int mx = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		ctr[a[i]]++;
		mx = max(mx, a[i]);
	}

	int red = k-n;
	if (red > 0)
	{
		for (int i = mx; i >= 2; --i)
		{
			if (!ctr[i])
				continue;

			if (ctr[i] < red)
			{
				ctr[i/2] += ctr[i];
				ctr[(i+1)/2] += ctr[i];
				red -= ctr[i];
				ctr[i] = 0;
			}

			else
			{
				ctr[i/2] += red;
				ctr[(i+1)/2] += red;
				ctr[i] -= red;
				red = 0;
				break;
			}
		}

		if (red > 0)
		{
			cout << -1;
			return 0;
		}
	}

	int ans = 0;
	int p = 0, temp = 0;
	for (int i = mx; i >= 1; --i)
	{
		if (temp + ctr[i] >= k)
		{
			ans = i;
			p = k - temp;
			break;
		}

		else
			temp += ctr[i];
	}

	for (int i = mx; i >= 1; --i)
	{
		if (!ctr[i])
			continue;

		if (i/2 <= ans)
			break;

		if (ctr[i] < p)
		{
			ctr[i/2] += ctr[i];
			ctr[(i+1)/2] += ctr[i];
			p -= ctr[i];
			ctr[i] = 0;
		}

		else
		{
			ctr[i/2] += p;
			ctr[(i+1)/2] += p;
			ctr[i] -= p;

			++ans;

			while (ctr[ans] == 0)
				++ans;

			p = ctr[ans];
			++i;
		}
	}

	cout << ans;
}