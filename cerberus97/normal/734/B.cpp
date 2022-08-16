#include <iostream>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

int main()
{
	ll k2, k3, k5, k6;
	cin >> k2 >> k3 >> k5 >> k6;

	ll b = min(k2, min(k5, k6));
	ll ans = b*256;

	k2 -= b;

	b = min(k2, k3);
	ans += b*32;

	cout << ans;
}