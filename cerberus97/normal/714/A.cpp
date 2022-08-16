#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
	ll l1, r1, l2, r2, k;
	cin >> l1 >> r1 >> l2 >> r2 >> k;

	ll l = max(l1, l2);
	ll r = min(r1, r2);

	if (l > r)
		cout << 0;

	else if (l <= k and k <= r)
		cout << r-l;

	else
		cout << r-l+1;
}