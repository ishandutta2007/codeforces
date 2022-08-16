#include <iostream>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

int main()
{
	int n, m;
	cin >> n >> m;

	int mn = 1e9 + 5;

	for (int i = 0; i < m; ++i)
	{
		int l, r;
		cin >> l >> r;

		if (r-l+1 < mn)
			mn = r-l+1;
	}

	int a[N];
	cout << mn << '\n';

	for (int i = 0; i < n; ++i)
		cout << i%mn << ' ';
}