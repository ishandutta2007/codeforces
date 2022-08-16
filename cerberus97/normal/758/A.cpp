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

const int N = 1e2 + 5;

int a[N];

int main()
{
	fast_cin();
	int n, mx = 0;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (a[i] > mx)
			mx = a[i];
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += mx - a[i];
	}
	cout << ans;
}