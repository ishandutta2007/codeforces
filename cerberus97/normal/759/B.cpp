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

const int N = 3e5 + 5;

ll f[N], t[N];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> t[i];

	f[0] = 0;
	f[1] = 20;
	cout << f[1] << '\n';

	for (int i = 2; i <= n; ++i)
	{
		f[i] = f[i - 1] + 20;

		int j = lower_bound(t + 1, t + 1 + n, t[i] - 89) - t;
		f[i] = min(f[i], f[j - 1] + 50);

		j = lower_bound(t + 1, t + 1 + n, t[i] - 1439) - t;
		f[i] = min(f[i], f[j - 1] + 120);

		cout << f[i] - f[i - 1] << '\n';
	}
}