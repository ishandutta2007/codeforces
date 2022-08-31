/*
Hanit Banga
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

map <ll, ll> m;

int find(ll n, ll i);
ll len(ll n);

int main()
{
	ll n, l, r;
	cin >> n >> l >> r;
	ll ans = 0;
	for (ll i = l; i <= r; ++i)
		ans += find(n, i);

	cout << ans;
}

int find(ll n, ll i)
{
	if (n < 2)
		return n;

	ll temp = len(n/2);
	if (i <= temp)
		return find(n/2, i);
	else if (i == temp + 1)
		return (n % 2);
	else
		return find(n/2, i - temp - 1);
}

ll len(ll n)
{
	if (n < 2)
		return 1;

	if (m.find(n) != m.end())
		return m[n];

	m[n] = 1 + 2 * len(n/2);
	return m[n];
}