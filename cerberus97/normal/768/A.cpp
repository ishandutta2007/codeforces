/*
Hanit Banga
*/

#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5, inf = 1e9 + 5;

int a[N];

int main()
{
	int n;
	cin >> n;

	int mn = inf, mx = -1;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (mn < a[i] and a[i] < mx)
			++ans;
	}

	cout << ans;
}