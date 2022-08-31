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

const int N = 2e5 + 5;

int a[N];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= n - i + 1; i += 2)
		swap(a[i], a[n - i + 1]);

	for (int i = 1; i <= n; ++i)
		cout << a[i] << ' ';
}