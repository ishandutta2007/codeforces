#include <iostream>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

bool isPrime (ll n)
{
	for (ll i = 2; i*i <= n; ++i)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

int main()
{
	ll n;
	cin >> n;

	if (n == 2 or isPrime(n))
	{
		cout << 1;
		return 0;
	}

	if (n % 2 == 0 or isPrime(n-2))
	{
		cout << 2;
		return 0;
	}

	cout << 3;
}