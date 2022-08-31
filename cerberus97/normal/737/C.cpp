#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 5;

int a[N];

int main()
{
	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int ans = 0;

	if (a[s-1])
	{
		a[s-1] = 0;
		++ans;
	}

	sort(a, a+n);
	int l = 1, r = n-1, sp = 0;

	while (!a[l] and l <= r)
	{
		++l;
		++sp;
		++ans;
	}

	for (int i = l; i <= r; ++i)
	{
		if (a[i] > a[i-1] + 1)
		{
			int temp = a[i] - a[i-1] - 1;

			if (temp <= sp)
			{
				sp -= temp;
				continue;
			}

			temp -= sp;
			sp = 0;

			if (temp >= r-i+1)
			{
				ans += r-i+1;
				break;
			}

			r -= temp;
			ans += temp;
		}
	}

	cout << ans;
}