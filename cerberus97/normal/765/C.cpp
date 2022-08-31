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

const int N = 1e5 + 5;

int main()
{
	ll k, a, b;
	cin >> k >> a >> b;

	if (a > b)
		swap(a, b);

	if (a < k and b < k)
		cout << -1;

	else if (a >= k and b >= k)
		cout << a/k + b/k;

	else if (b % k == 0)
		cout << b/k;

	else
		cout << -1;
}