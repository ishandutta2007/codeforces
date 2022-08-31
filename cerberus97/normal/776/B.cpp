/*
Hanit Banga
*/

#include <iostream>
#include <vector>
#include "cmath"

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

bool isPrime(int n);

int main()
{
	int n;
	cin >> n;

	if (n <= 2)
	{
		cout << "1\n";
		for (int i = 0; i < n; ++i)
			cout << "1 ";

		return 0;
	}

	cout << "2\n";
	for (int i = 2; i <= n + 1; ++i)
	{
		if (isPrime(i))
			cout << "1 ";
		else
			cout << "2 ";
	}
}

bool isPrime(int n)
{
	int sq = sqrt(n);
	for (int i = 2; i <= sq; ++i)
		if (n % i == 0)
			return false;

	return true;
}