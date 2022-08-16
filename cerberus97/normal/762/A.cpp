/*
Hanit Banga
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

set <ll> divisors;

int main()
{
	ll n, k;
	cin >> n >> k;

	ll sq = sqrt(n);
	for (int i = 1; i <= sq; ++i)
	{
		if (n % i == 0)
		{
			divisors.insert(i);
			divisors.insert(n/i);
		}
	}

	if (divisors.size() < k)
	{
		cout << -1;
		return 0;
	}

	auto cur = divisors.begin();
	for (int i = 1; i < k; ++i)
		++cur;

	cout << *cur;
}