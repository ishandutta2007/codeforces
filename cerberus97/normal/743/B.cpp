/*
Hanit Banga
Problem: 
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

ll getElem(ll n, ll k);

int main()
{
	ll n, k;
	cin >> n >> k;
	cout << getElem(n, k);
}

ll getElem(ll n, ll k)
{
	if (n == 1)
		return 1;

	ll mid = (1ll<<(n-1));

	if (k == mid)
		return n;

	if (k > mid)
		return getElem(n-1, k-mid);

	return getElem(n-1, k);
}