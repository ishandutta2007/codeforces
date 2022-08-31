/*
Hanit Banga
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

int a[N];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a, a + n);
	for (int i = 0; i < n - 2; ++i)
	{
		if (a[i] + a[i + 1] > a[i + 2])
		{
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";
}