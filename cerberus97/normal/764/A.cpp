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

int lcm(int n, int m);
int gcd(int n, int m);

int main()
{
	int n, m, z;
	cin >> n >> m >> z;

	cout << z/lcm(n, m);
}

int lcm(int n, int m)
{
	return (n / gcd(n, m)) * m;
}

int gcd(int n, int m)
{
	if (!m)
		return n;

	return gcd(m, n % m);
}